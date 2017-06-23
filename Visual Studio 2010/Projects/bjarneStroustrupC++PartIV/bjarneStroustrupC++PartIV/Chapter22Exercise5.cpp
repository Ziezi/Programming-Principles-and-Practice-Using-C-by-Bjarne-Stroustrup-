/*
TITLE		   Hello World 			Chapter22Exercise5.cpp
COMMEN
	Objective: Write a "Hello, World!" program in each 
			   of the languages mentioned in this chapter.
		Input:
	   Output:
	   Author: Chris B. Kirov
	     Date: 08.03.2017
*/

// Ada

with Ada.Text_IO; use Ada.Text_IO;
procedure Hello is
begin
  Put_Line ("Hello, world!");
end Hello;

//----------------------------------------------------------

// Algol 68

main: 
(
  printf($"Goodbye, World!"l$)
)

//----------------------------------------------------------

// BCPL ?

GET "LIBHDR"

WRITEF("Hello World!")

//----------------------------------------------------------

// C

#include <stdio.h>
int main( int argc, char *argv[] )
{
     puts( "Hello World!" );
     return 0;
}

//----------------------------------------------------------

// C++

#include <iostream>
int main() 
{
    using namespace std;
    cout << "Hello, World!" << endl;
    return 0;
}

//----------------------------------------------------------

// COBOL

program-id. hello-world.
 
procedure division.
  display "Hello, World!"
 
  goback

//----------------------------------------------------------

// Fortran

write(*,*) "Hello world!"
end

//----------------------------------------------------------

// LISP

(format t "Hello world!~%")

//----------------------------------------------------------

// Pascal 

program HelloWorld(output);
begin
  Write('Hello, world!')
  {no ";" is required after the last statement of a block -
   adding one adds a "null statement" to the program;}
end.

//----------------------------------------------------------

// Scheme

(let ((hello0 (lambda() (display "Hello world") (newline))))
  (hello0))

//----------------------------------------------------------

// Simula
Begin
   OutText ("Hello World!");
   Outimage;
End;

//----------------------------------------------------------



