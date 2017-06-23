/*
	TITLE		   Coding Style Rules     					   Chapter25Exercise16.cpp
	COMMENT
		Objective: Formulate 20 coding style rules (don't just copy those in §25.6). 
				   Apply them to a program of more than 300 lines that you recently wrote.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.05.2017
*/

// Question 62  + 10 additional

/*
	1. Be carefule what happens between new and delete, i.e. exception throw control.
	2. Define destructors in derived classes when virtual desrtuctor is presen in based class.
	3. Don't confuse new[] and delete[] with their single object counter parts; same for smart_ptr.
	4. Warning with returning local objects by reference.
	5. Using shared_ptr when resources have multiple acess increases the possibility of errors - double free, etc.
	6. Handle exceptions in destructor.
	7. Auto_ptr usage with caution:
		- copy an STL container and the source is left with invalid data.
		- never use auto_ptr as function argument: copy leads to value passed to be invalidated, after the function call.
		- auto_ptr requires copy and assignment constructors that not only copy the source but transfer it safely and 
		  invalidates the source.
	8. Warning with invalidated references and iterators. Don't modify containers after defining an iterator or a reference.
	9. Pass objects by reference, not by value.
	10. Use keyword "explicit" to avoid implicit convertions during object initialization.
	11. Use RAII when dealing with resources of dynamic nature.
	12. Have in mind the The Rule of Three : If you need to explicitly declare either the destructor, copy constructor or 
		copy assignment operator yourself, you probably need to explicitly declare all three of them.
	13. Use copy-and-swap idiom, especially in classes with the need of deep copy.
	14. Check pointer / iterator validity before using (/after returing) them. Don't dereference a possibly null pointer.
	15. A function should return either a valid result or throw and exception - consider ill-formed input.
	16. Prefer using STL vector by default unless you have a reason to use a different container.
	17. Use guards in header files to avoid cyclical/recursive dependancies.
	18. Prefer compile-time checking to run-time checking.
	19. Catch run-time errors early.
	20. Make interfaces precisely and strongly typed.
*/