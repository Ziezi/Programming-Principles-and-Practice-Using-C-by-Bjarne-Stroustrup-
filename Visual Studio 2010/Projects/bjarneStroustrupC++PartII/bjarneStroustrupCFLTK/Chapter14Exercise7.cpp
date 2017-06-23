/*
	TITLE		   Stripped_Closed_Polyline	      Chapter14Exercise7.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the closed polyline is
		           "filled" by drawing varying-pixel-wide-spaced
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output:  
		   Author: 28.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"

#include <iostream> 
#include <vector>
#include <algorithm>

#define PI 3.14159265358979323846

#include "Chapter14Exercise7.h"

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 7";

	Simple_window sw(tl, width, height, label);

	// Generate points for the poly-line
	vector<Point> polyPoints;
	generatePoints(polyPoints);

	// Create a poly-line
    Striped_closed_polyline scp;
	for (auto it = polyPoints.begin(); it != polyPoints.end(); ++it)
	{
		scp.add(*it);
	}

	sw.attach(scp);
	 
	// Create a list of all edges from two consecutive points entered in their natural sequence
	vector<Edge> polyEdges;
	Point first = scp.point(0);
	Point last = scp.point(scp.number_of_points()-1);
	polyEdges.push_back(Edge(last, first));

	for (size_t i = 1; i < scp.number_of_points(); ++i) 
	{
		polyEdges.push_back(Edge(scp.point(i-1), scp.point(i)));
	}

	// Sort the list by increasing yMax (ordinate of the end point)
	std::sort(polyEdges.begin(), polyEdges.end());

	// find global Ymin and Ymax of the poly-line (used for validity test)
	int polyYmin = polyEdges[0].yMin;
	int polyYmax = polyEdges[polyEdges.size() - 1].yMax;

	// find global Xmin and Xmax of the poly-line (end coordinates of the horizontal scan-line)
	vector<Point> polyPoints2;
	for (size_t i = 0; i < scp.number_of_points(); ++i) 
	{
		polyPoints2.push_back(scp.point(i)); 
	}

	sort(polyPoints2.begin(), polyPoints2.end(), XLessThan());
	int polyXmin =  polyPoints2[0].x;
	int polyXmax =  polyPoints2[polyPoints2.size() - 1].x;

	// find intersection points between the horizontal line and the poly-line
	int spacing = 10;
	vector<Point> intersections;
	for (size_t i = 0; i < polyEdges.size(); ++i)
	{
		for (size_t j = polyEdges[i].yMin; j < polyEdges[i].yMax; j += spacing)
		{
			Edge horizontal(Point(polyXmin, j), Point(polyXmax, j));

			// check if polyEdge not horizontal
			if (polyEdges[i].start.y != polyEdges[i].end.y)
			{
				Point s = intersectPoint(polyEdges[i], horizontal);
				// check if point is not a valid intersection

				int noIntersection = -1;
				if(s.x != noIntersection && s.y != noIntersection) intersections.push_back(s);
			}
		}
	}

	// sort intersection points by their y-coordinate (form a sequence of pair-points making horizontal lines)
	std::sort(intersections.begin(), intersections.end(), YLessThan());

	// make scan-lines
	vector<Edge>horizontalLines;
	for (size_t i = 1; i < intersections.size(); i += 2)
	{
		// test if points inside the poly-line
		if (((intersections[i-1].x >= polyXmin && intersections[i-1].x <= polyXmax) || 
			(intersections[i-1].y >= polyYmin && intersections[i-1].y <= polyYmax)) &&
			((intersections[i].x >= polyXmin && intersections[i].x <= polyXmax) || 
			(intersections[i].y >= polyYmin && intersections[i].y <= polyYmax)))
		{
			horizontalLines.push_back(Edge(intersections[i-1], intersections[i]));
		}
	}

	try
	{ 
		// form horizontal lines
		for (size_t i = 1; i < intersections.size(); i += 2)
		{
			if (((intersections[i-1].x >= polyXmin && intersections[i-1].x <= polyXmax) || 
			     (intersections[i-1].y >= polyYmin && intersections[i-1].y <= polyYmax)) &&
		      	((intersections[i].x >= polyXmin && intersections[i].x <= polyXmax) || 
			     (intersections[i].y >= polyYmin && intersections[i].y <= polyYmax)))
			{ 
				Graph_lib::Line* l = new Graph_lib::Line(intersections[i-1], intersections[i]);

				sw.attach(*l);
			}
		} 

		sw.wait_for_button();

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
		getchar();
	}
}
