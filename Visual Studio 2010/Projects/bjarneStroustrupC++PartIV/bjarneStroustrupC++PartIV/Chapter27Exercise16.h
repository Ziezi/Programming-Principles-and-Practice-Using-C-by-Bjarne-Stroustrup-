/* 
	TITLE	       Use macros to obscure ineritance in C    Chapter27Exercise16.c 
	COMMENT
		Objective: Use macros to obscure (simplify the notation for)
				   the implementation in the previous exercise.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 21.06.2017
*/
#ifndef Chapter27Exercise16_h
#define Chapter27Exercise16_h

//-----------------------------------------------------------------------------------------------

struct Shape;								// forward declaration to be used in the virtual function table
typedef enum { shape = 1, circle } Type;	// type of the objects
void draw(struct Shape* self);				// "generic" function draw
void base_draw (struct Shape* self);		// specific, class Shape "member" function 

//-----------------------------------------------------------------------------------------------

typedef struct 
{
	void (*draw) (struct Shape*);

} Shape_func_table;

//-----------------------------------------------------------------------------------------------

typedef struct Shape_data
{
	Type type;
	char* name;
	Shape_func_table* v_tbl;

} Shape_data;

//-----------------------------------------------------------------------------------------------

typedef struct Shape
{
	union		// placing the "inherited" data into a union removes the need of explicit casting
	{
		Shape_data shape;

	} base;

} Shape;

//-----------------------------------------------------------------------------------------------

#define GETSHAPE(self) (&(self)->base.shape)	// macro performing typesafe(-like) casting
#define TYPE(self) (GETSHAPE(self)->type)		// accessors: getters & setters
#define NAME(self) (GETSHAPE(self)->name)		
#define VTABLE(self) (GETSHAPE(self)->v_tbl)

//-----------------------------------------------------------------------------------------------

struct Circle;
void derived_draw (struct Circle* self);		// override draw

//-----------------------------------------------------------------------------------------------

typedef struct 
{
	void (*draw) (struct Circle*);

} Circle_func_table;

//-----------------------------------------------------------------------------------------------

typedef struct Circle_data
{
	union
	{
		Shape_data shape;

	} base; 

	double radius;

} Circle_data;

//-----------------------------------------------------------------------------------------------

typedef struct Circle
{
	union
	{
		Shape_data shape;
		Circle_data circle;

	} base;

} Circle;

//-----------------------------------------------------------------------------------------------

#define GETCIRCLE(self) (&(self)->base.circle)
#define RADIUS(self) (GETCIRCLE(self)->radius) 

//-----------------------------------------------------------------------------------------------

#include "Chapter27Exercise16Def.c"

#endif