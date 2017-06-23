/*
	TITLE		   Calculator GUI			       Chapter16Exercise9.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Modify the calculator from Chapter 7
				   to get its input from input box and
				   to return its results to output box.  
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#ifndef _Chapter16Exercise9_h_
#define _Chapter16Exercise9_h_

class Calculator_GUI: Window
{
public:
	Calculator_GUI();

private:
	Text* result_text;

	// controls
	In_box input_expression;
	Out_box output_expression;
	Button evaluate;

	// callback
	static void cb_evaluate(Address, Address pw) { reference_to<Calculator_GUI>(pw).evaluate_pressed(); }

	// action
	void evaluate_pressed();
};

//-----------------------------------------------------------------------------------------------------------

Calculator_GUI::Calculator_GUI()
	: Window (Point(300, 300), 500, 500, "Chapter 16 Exercise 9"),
	result_text(new Text(Point(x_max() / 2, y_max() / 2), "none")),
	input_expression(Point(x_max() / 2 - 150, 0), 300, 20, "Input: "),
	output_expression(Point(x_max() / 2 - 150, 60), 300, 20, "Result: "),
	evaluate(Point(x_max() / 2 - 35, 30), 70, 20, "Evaluate", cb_evaluate)
{
	attach(*result_text);
	attach(input_expression);
	attach(output_expression);
	attach(evaluate);
}

//-----------------------------------------------------------------------------------------------------------

void Calculator_GUI::evaluate_pressed()
{
	// get input, insert in string stream, initialize calculator input stream
	std::string input = input_expression.get_string();
	std::istringstream iss(input);
    Token_stream tts(iss); 

	// define output streams
	std::ostringstream oss; // output stream
	std::ostringstream ess; // error stream

	calculate(tts, oss, std::cerr); // use calculator to evaluate input expression

	std::string result = oss.str();

	// display result
	output_expression.put(result); // ^J artefact of the put() implementation

	// display result as a text on window
	detach(*result_text);
	delete result_text;

	result = "Result = " + result;
	result_text = new Text(Point(x_max() / 2 - 8 * result.size(), y_max() / 2), result);
	result_text->set_font_size(25);
	attach(*result_text);
	redraw();
}

#endif