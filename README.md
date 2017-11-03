 <h1>Repository Content</h1>

Exercises from

["Programming Principles and Practice Using C++"](http://www.stroustrup.com/Programming/)


<h2>Chapter 1</h2>

1. Compile a list of daily activities involving the use of computers.
2. Pick a favourite profession and the activities within it involving the use of computers.
3. Swap the lists from Ex 1 and Ex 2 with a friend and compare results.
4. List of activities not possible without computers.
5. List of programs that you have used.
6. List of activities not involving computers.
7. Five tasks for which computers will be used in the future.
8. Why do you like to be a programmer? ($100 < words < 500$)
9. What other role in computer industry do you like to play?
10. Do you think computers will ever be developed to be conscious, thinking, capable of competing with humans?
11. List of characteristics that good programmers share.
12. Identify five applications for computer programs mentioned in the chapter and one that you want to participate in.
13. How much memory would it take to store: this page, text, Shakespeare's work. (1 byte == 1 character; Estimate 20% precision)
14. How much memory (main, disk) does your computer have?


<h2>Chapter 2</h2>

1. Print `"Hello, programming!\nHere we go!"`.
2. Write pseudo code (instructions) directing "the computer" upstairs to the bathroom.
3. Write pseudo code (instructions) directing "the computer" from your house/dorm to work/university.
4. Write instructions for a food cooking recipe.
5. Write definition of each of the new terms covered in the first chapter.
 
<h2>Chapter 3</h2>

1. Do all _Try This_ examples in the chapter.
2. Miles to kilometers converter.
3. Check compiler response to illegal variable names (identifiers).
4. Define and read two `int`s. Find and print their _min_, _max_, _sum_, _difference_, _product_ and _ratio_.
5. Redo the Exercise 4 with floating point number variables `double`.
6. Read three `int`s and list them in increasing order.
7. Redo Exercise 6 with `string`s.
8. Check if `int` is _odd_ or _even_.
9. Read an `int` as digit / name and print it as name / digit.
10. Read an operation (`+, -, *, /`) and two (`double`) values and print the result. (Use `if` statements).
11. Read `pennies, nickels, dimes, quarters` and `half dollars` and print total sum of `cents`.

<h2>Chapter 4</h2>

1. Do all _Try This_ examples in the chapter.
2. Find _median_ (element in the middle of the sorted set). Modify `4.6.2`
3. Read `double` values and store them into a `vector`. Find _total sum_, _mean_ of all elements, _min_ and _max_. 
4. Write a number guessing game. (manual _Binary seach_ using `if` statements).
5. Implement a _simple calculator_ with few operations $(+, -, *, /, %)$.
6. Store the names of the digits [0, 9] in a `vector` and use it to convert digit to its name.
7. Modify Exercise 5 to accept either single digit or its name.
8. Calculate _Exponential growth_ after `n` turns.
9. Largest value held in `int` or `double`, _overflow_.
10. Implement a game _"Rock, Paper, Scissors."_. (use `switch` statements)
11. Find _prime numbers_ within $[1, 100]$. (Use `vector` that holds current previous primes.)
12. Find _prime numbers_ within $[min, max]$.
13. Implement _Sieve of Eratosthenes_ within $[1,100]$.
14. Modify Exercise 13 to interval  $[min, max]$.
15. Find first `n` _primes_. 
16. Find the _mode_ of a sequence of positive `int`s.
17. Find _min_, _max_ and _mode_ of sequence of `string`s.
18. Solve the _quadratic equation_ with coefficients `a`, `b` and `c`.
19. Read `name` and `value` pairs. Check name uniqueness.
20. Modify Exercise 19, so that when you type `name` it prints its `value`.
21. Modify Exercise 19, so that when you type an `int` value it prints the names with that score.

<h2>Chapter 5</h2>

1. Do all _Try This_ examples in the chapter.
2. Debug existing _Celsius_ to _Kelvin_ converter.
3. Choose appropriate `min` value and modify Ex. 2.
4. Handle the errors within `ctok()`.
5. Write a _Kelvin_ to _Celsius_ converter.
6. Write a _Celsius_  $<=>$  _Fahrenheit_ converter. (Estimate result.)
7. Solve the _quadratic equation_, `throw` an exception if _discriminant_ `< 0`.
8. Read `int`s (quit with `|`), store them in a `vector` and prompt the user to sum `n` of them.
9. Modify Ex. 8 and display error if result can't be stored in `int`.
10. Redo Ex. 8 with values of type `double`. Calculate the _differences of adjacent elements_.
11. Print the first `n` _Fibonacci numbers_. Find largest Fibonacci stored in `int`.
12. Implement _"Bulls and Cows"_.
13. Redo Ex. 12, but let each time the numbers be random. (Use `rand()` and `srand()`)
14. Read `(day-of-the-week, value)` pairs and store each day in a `vector<int>`. Print each day and its values.

<h2>Chapter 6</h2>

1. Do all _Try This_ examples in the chapter.
2. Modify the _calculator_ to evaluate expressions containing $(,)$ and ${,}$.
3. Add factorial operator `!`.
4. Rework Ex. 19 Ch. 4 using a `class Name_value`.
5. Expand the _English Grammar_ from _6.4.1_ to include `the`.
6. Write a program that checks if sentence is correct according to the _English Grammar_.
7. Write a _Grammar for Logical Epxressions_.
8. Redo _"Bulls and Cows"_ from Ex. 12 Ch. 5, to use four letters instead of four digits.
9. Write a program that reads digits and composes them into integers.
10. Calculate _permutations P(a, b)_ and _combinations C(a, b)_.
 
<h2>Chapter 7</h2>

1. Allow underscore `_` in the names of the user defined variable in the _calculator_.
2. Allow used defined variable value reassignment, by introducing an assignment `operator=`.
3. Allow the definition of `const` variables.
4. Define `class Symbol_table` and rewrite the calculator to use it.
5. Print result at newline `\n`.
6. Provide _help_ function in the calculator.
7. Change _help_ and _quit_ commands.
8. Fix the calculator grammar and add comments (document the code).
9. Define a `class Table` and rewrite the calculator to use it.
10. Suggest three improvements and implement one.
11. Modify the calculator to operate on `int` only.
12. Discuss the possible source of problems of introduction of assignment `operator=`.
13. Revisit two programs from Ch. 4 and Ch. 5, clean and comment them.

<h2>Chapter 8</h2>

1. Modify the _calculator_ to make the input stream an explicit parameter. Give `Token_stream` constructor a `istream&` parameter.
2. Write a function `print()` that prints a `vector` of `int`s; Include a `string` parameter label.
3. Find `n` _Fibonacci numbers_ and store them in a `vector`. Use function `print()` from Ex. 2 to print them.
4. Find the largest _Fibonacci_ number stored in `int`.
5. Write a function that _reverses_ the `int` elements of a `vector`.
6. Redo Ex. 5 using `string`s.
7. Read five `names` and five `ages`. Sort the `names` and match the `ages`. Print the result.
8. Implement a simple function `randint()`.(See _Knuth, The Art of Computer Programming, Volume 2_)
9. Write a function `rand_in_range(int a, int b)` that generates a pseudo-random number within $[a, b)$, using `randint()`.
10. Write a function that calculates the _sum of the products_ of the elements of two `vector`s. (Allow one vector with smaller size).
11. Write a function `maxv()` that returns the largest element of a vector argument.
12. Find _min_, _max_, _mean_ and _median_ of vector arguments. Return the result using `struct` or by _passing by reference_.
13. Improve `print_until_s()` from _8.5.2_. Test it. Write a function `print_until_ss()` that prints until the second occurrence of its argument `quit`.
14. Write a function that takes a `vector<string>` argument and returns `vector<int>` containing the number of character in each `string`. Also find _longest_ and _shortest_, lexicographically first and last `string`s. 
15. Can we declare a non-reference function argument `const`? Why would we? Test it.

<h2>Chapter 9</h2>

1. List sets of plausible operations for the examples of real-world objects in _§9.1_ (such as toaster).
2. Design and implement a `Name_pairs`, holding (`string name, double age`). Provide `sort()` operation.
3. Replace `Name_pair::print()` with a (global) `operator<<` and define `==` and `!=` for `Name_pairs`.
4. Indent the code from _§8.4_.
5. Implement a `class Book`, such as you can imagine as part of software for a library; with members for the `ISBN`, `title`, `author`, and `copyright date`. Create appropriate member functions.
6. Add operators `==`, `<<` for the `class Book`.
7. Create an `enum` type for the `class Book` called `Genre`. Have the types be `fiction`, `nonfiction`, `periodical`, `biography`, `children`.
8. Create a `class Patron` for tlle library. The class will have a `user's name`, `library card number`, and `library fees` (if owed). Create appropriate member functions.
9. Create a `class Library`. Include vectors of `Books` and `Patrons`. Include a `struct` called `Transaction`. Have it include a `Book`, a `Patron`, and a `Date`. Create appropriate member functions.
10. Implement `leapyear()` from _§9.8_.
11. Design and implement a set of useful helper function for the `class Date` such as `next_workday()` and `week_of_year()`.
12. Change the representation of a `Date` to be the number of days since _January I, 1970 (known as day 0),_ represented as a `long`, and reimplement the functions from _§9.8_.
13. Design and implement a rational number `class Rational`.
14. Design and implement a `class Money` for calculations involving `dollars` and `cents` where arithmetic has to be accurate to the last `cent` using _the 4/5 rounding rule_.
15. Refine the `class Money` by adding a `currency`. Provide a conversion table.
16. Give an example of a calculation where a `Rational` gives a mathematically better result than `Money`.
17. Give an example of a calculation where a `Rational` gives a mathematically better result than `double`.

<h2>Chapter 10</h2>

 1. Sum of all the numbers in a file of whites space-separated integers.
 2. Creates a file of data in the form of the temperature `Reading` type defined in §10.5. Fill the file with at least 50 temperature readings.
 3. Create a program that reads the data created in _Exercise 2_ into a `vector` and then calculates the mean and median of the temperatures in your data set.
 4. Modify _Exercise 2_ to include temperature unit suffix `C` - Celsius or `F` - Fahrenheit. Modify the function from _Exercise 3_ to firstly convert the temperature in Fahrenheit before calculating the statistics.
 5. Write the function `prin_year()` mentioned in §1O.11.2.
 6. Define a `Roman_int` class for holding Roman numerals (as ints) with a `operator<<` and `>>` . Provide `Roman_int` with an `as_int()` member.
 7. Make a version of the calculator from _Chapter 7_ that accepts Roman numerals.
 8. Write a program that accepts two file names and produces a new file that concatenates the two files.
 9. Write a program that takes two files containing sorted white space-separated words and merges them, preserving the order.
 10. Add a command `from x` to the calculator from _Chapter 7_ that makes it take input from a file `x`. Add a command `to y` that makes it write its output (both standard output and error output) to file `y`. Write a collection of test cases based on ideas from §7.3 and use that to test the calculator.
 11. Write a program that produces the sum of all the white space-separated integers in a text file.
 12. Write a program that given a file name and a word outputs each line that contains that word together with the line number.

<h2>Chapter 11</h2>

 1. Read a file, convert to lower case and write to another file.
 2. Remove all the vowels from a text file.
 3. Write a program that correctly interprets the base prefixes of integers, i.e. decimal (`none`), octal (`0`), hexadecimal (`0x`), converts them to decimal and prints them in a table in their initial and final format.
 4. Read a string and classify each of its characters, e.g. `isalpha()`, `isspace()`, etc.
 5. Replace punctuation with white space.
 6. Modify Ex. 5 to replace `don't` with `do not` and `can't` with `cannot`; to leave hyphens in between words intact.
 7. Use the knowledge from the previous exercises to create a dictionary from a multi-page text.
 8. Read and write a binary file.
 9. Write a function that accepts a string and returns a vector holding all the white space separated sub-strings of the argument.
 10. Expand Ex. 9 to include sub-string separation at any character passed as an additional argument.
 11. Reverse the order of characters in a text file.
 12. Reverse the order of words (white space separated) in a text file.
 13. Perform character classification on the contents of a text file.
 14. Read a file containing integers, format them to scientific representation with precision up to the eight digit after the decimal point and write them to another file, four per line in fields of width of 20 characters.
 15. Read a file containing integers, sort, count write the result in a table in another file.


<h2>Chapter 12</h2>

 1. Drill: Introduction to reduced GUI based on FLTK: include needed libraries, create `Simple_window`.
 2. Create a rectangle using class `Rectangle` and class `Polygon`, use different colours.
 3. Draw a `Rectangle` and place a `Text` object inside it.
 4. DraW your initials in different colours.
 5. Draw a Checkers board, with white and red squares.
 6. Draw a red 1/4-inch frame around a rectangle that is 3/4 the height and 2/4 the width of the screen.
 7. Draw a `Shape` not matching the size of the window and `Window`  not matching the size of the of the screen.
 8. Draw a picture of a house.
 9. Draw the Olympic five rings.
 10. Display an image and manipulate it.
 11. Draw the file diagram of Chapter 12.8, describing the hierarchy of source code dependencies.
 12. Draw a series of polygons, one inside the other.
 13. Draw a "star-like" pattern by connecting points of super-ellipse.
 14. Draw super-ellipses of multiple colours.
 
<h2>Chapter 13</h2>

 1. Drill: Introduction to `Graph_lib` members: draw `Simple_window`, `grid`, `Rectangle` & `Image` objects.
 2. Define an `Arc` which is a part of an Ellipse. Hint: `fl_arc()`.
 3. Draw a box with rounded corners. Define a class `Box`, consisted of four lines and four arcs.
 4. Define class `Arrow` that draws a line with an arrowhead.
 5. Define functions `n()`, `s()`, `e()`, `w()`, `center()`, `ne()`, `se()`, `sw()`, `nw()`. Each takes a `Rectangle` as argument and returns a `Point`. These functions define "connection points" on and in the rectangle. 
 6. Connection points with `Circles` and `Ellipses`.
 7. Write a program that draws a class diagram depicting dependency hierarchy.
 8. Make a RGB colour chart.
 9. Create a class `Hexagon`, where centre and distance from the centre to a corner point are the constructor arguments.
 10. Tile a part of a window using `Hexagon'; use at least six hexagons.
 11. Define a class `Regular_Polugon`. Use the centre and the number of sides (> 2) as a constructor arguments.
 12. Draw a 300 X 200 `Ellipse`, a 400 - pixels - long x axis and 200 - long y axis through the centre of the ellipse. `Mark` the foci. `Mark` a point on the ellipse and not on the axis and connect it to the foci with `Lines`.
 13. Draw a `Circle`. Move a `Mark` on the circle each time _Next_ is pushed.
 14. Draw the RGB colour chart without the lines around the colours.
 15. Define a `Right_Triangle` class. Draw an octagonal shape using eight right triangles of different colour.
 16. Tile a window with small right triangles.
 17. Tile a window with small hexagons.
 18. Tile a window with small hexagons of different colour.
 19. Define a class `Poly` that represents a polygon. Check if points constitute a polygon.
 20. Define a class `Star`. One parameter should be number of points. Draw few stars with different number of points and colours.
 
 
<h2>Chapter 14</h2>
 
 
 1. Drill: main features of OOP: interface & implementation inheritance ((abstract) base - derived classes), run - time polymorphism (virtual and pure virtual functions), encapsulation & data hiding (public, protected and private).
 2. Define classes `Smiley` and `Frowny`, both derived from `Circle`, with members `eyes` and `mouth`. Next, derive classes from `Smiley` and `Frowny` which adds an appropriate hat to each.
 3. Try to copy `Shape`. Comment the result.
 4. Define an abstract class and then try to instantiate an object of that class. Comment the result.
 5. Define a class `Immobile_Circle` that can't be moved.
 6. Define a `Striped_Rectangle` where instead of fill the rectangle is _"filled"_ with one-pixel-width lines. Play with line width and spacing.  
 7. Define a `Striped_Circle` using the technique from `Striped_Rectangle`.
 8. Define a `Striped_Polyline` using the technique from `Striped_Rectangle`.
 9. Define a class `Octagon` to be a regular octagon. Test all its functions.
 10. Define `Group` to be a container of `Shape`s with suitable operations applied to the members of `Group`. Use `Group` to define a checkers board where piece can be moved under program control.
 11. Define a `Pseudo_window` with rounded corners, label, control icons, fake contents such as image, within a `Simple_window`.
 12. Define a `Binary_tree` class derived from `Shape`. Give the number of levels as parameter, depict nodes as circles.
 13. Modify `Binary_tree` to draw its nodes using a virtual function. Derive a new class from `Binary_tree` that overrides the that virtual function to use different representation for a node (e.g. a triangle).
 14. Add an operation to `Binary_tree` that adds text to node. Choose a way to identify a node (by a string of directions `"lrlrl"`) for navigating left and right down a the tree (root is both `l` and `r`).
 15. Define a class `Iterator` with pure `virtual` function `next()` that returns a pointer to `double`. Now derive `Vector_iterator` and `List_iterator` from `Iterator` so that `next()` for the first yields a pointer to the next element of a `vector<double>` and the latter one to `list<double>`. You initialize a `Vector_iterator` with `vector<double>` and the first call to `next()` yields a pointer to the first element, if any. If there is no next element, return `0`. Test both by using a function `void print (Iterator)` to print the elements of vector and list of `double`s. 
 16. Define class `Controller` with four `virtual` functions `on()`, `off()`, `set_level(int)` and `show()`. Derive at least two classes from `Controller`. One should be a simple test class where `show()` prints out whether the class is set `on` or `off` and what the current `level` is. The second class should control the line colour of `Shape`; the exact meaning of of "level" is up to you.  
 17. Draw a class hierarchy for the `std::exception` C++ standard library. 
 
 
 <h2>Chapter 15</h2>
 
 
1. Drill 1: Function graphing. Draw a coordinate system and functions.
2. Drill 2: Class definition. Define a `class`, `const` access members, overload extraction `operator>>` and insertion operators. Check validity of class instantiation data.  
3. Implement an _iterative_ factorial function. Compare it to _recursive_, comment complexity?
4. Define a class just like `Function`, but one that stores its constructor arguments and allows reset of their value.
5. Modify the the previous class and add new constructor argument that controls precision.
6. Plot `sin(x)`, `cos(x)`, their sum and the sum of their squares on a single graph. Provide labels.
7. Animate the _Liebniz_ series: $1 - 1/3 + 1/5 - 1/7 + 1/9... = pi / 4$.
8. Design and implement a bar graph with basic data `std::vector` of `double`. Each value is represented by a "bar"'s height.
9. Modify the bar graph to allow labelling of individual bars and colour. 
10. Here is a collection of (height[cm], frequency[people]) data points: (170, 7) (175, 9) (180, 23) (185, 17) (190, 6) (195, 1). Place them in a file, read and plot them. What would be the best graphical representation? Do a bar graph.
11. Find another data set of heights (in inches (1 inch = 2.54 cm)) and plot them with the code from the previous exercise. Scaling from the data is a key idea.
12. Find a way of displaying a collection of labelled points.
13. Read a data file containing mean maximum temperatures for each month of the year, for two locations and plot them together.
 
 
 
<h2>Chapter 16</h2>
 
 
 
 1. Type the line - drawing program from §16.5 to §16.7. 
 2. Make `My_window` based on `Window` with two buttons `next` and `quit`.
 3. Make a 4 x 4 Checkers board with four square buttons. When pressed, every button performs simple action: prints own coordinates, changes colour; till another button is pressed.
 4. Define class with a `Button` that moves to a random position when pressed, together with an `Image` placed on it.
 5. Make a menu with items that draws a circle, a square, an equilateral triangle, and a hexagon respectively. Make an input box for giving coordinate pair, and place the shape made by pressing a menu item at that coordinate.
 6. Make a program that draws a shape of you choice and moves it to a new point each time you click "Next". The new point should be determined by a coordinate pair read from an input stream.
 7. Make an "Analog Clock", that is, a clock with hands that move; get the time from OS library; find functions that wait for short period of time.
 8. Make an image of an airplane "fly around" in a window. Have a "start" and "stop" button.
 9. Provide a currency converter. Read the conversion rates from file on start-up. Enter amount in an input window and provide a way of selecting currencies to convert to and from (e.g. a pair of menus).
 10. Modify the calculator from Chapter 7 to get its input from input box and to return its results to output box.
 11. Provide a program where one can choose among a set of functions (e.g. `sin(x)`, `log(x)`), provide parameters for those functions, and then graph them. 
 
 
 
<h2>Chapter 17</h2>
 
 
 
 1. Try This: apply `sizeof()` operator to the fundamental types and observe result. Analyse the behaviour of class constructors and destructors.
 2. Drill: operator `new` and free-store allocations. Pointers, references and their properties.
 3. What is the output format of a pointer value.
 4. How many bytes are there in `int`, `double`, `bool` and other built-in types?
 5. Write a function `void to_lower(char \*s)` that converts C-style string to lower case.
 6. Write a function `char\* strdup(char\*)` that copies C-style string on free store.
 7. Write a function `char\* find(const char\* s, const char\* x)`, that finds first occurrence of the C-style string `x` in `s`.
 8. Find a way to exhaust your machine's memory. Find what happens. Try using `new` or read documentation.
 9. Read individual characters, until an exclamation mark (!) is entered, from `std::cin` into an array allocated on the free store.
 10. Redo previous exercise using `std::string` instead of free store array.
 11. Write a program that determines address order in _heap_, _stack_ (and _static_) memory allocation.
 12. Redo Exercise 7 (here 9) and use `malloc()` - `free()` and `realloc()` to extend the input `char` array.
 13. Complete the "list of gods" from §17.10.1 and run it.
 14. Why are there two different definitions of `find()` in the doubly linked list class?
 15. Modify `Link` to hold a value `struct God`, with data members: `std::string`: name, mythology, vehicle and weapon. Write a `print_all()` and `add_ordered()` methods that places a new element in lexicographically right order. Make three list of Gods of different mythologies and then move them into ordered lists.
 
 
<h2>Chapter 18</h2>


 1. Constructor (default, parameter, copy and assignment) and destructor calls.
 2. Custom vector implementation, return by value and reading-only access.
 3. Drill: arrays and vectors.
 4. Write a function that copies a C-style string into free store memory and returns a pointer to it. Use dereference `operator *`, instead of subscripting `operator[]`; and no standard library functions.
 5. Write a function that finds the first occurrence of a C-style string `x` in `s`; without any standard library functions and with the use of the dereference `operator *` instead of subscripting `operator[]`.
 6. Write a function that compares C-style string and returns negative value if first argument lexicographically before the second, positive value otherwise and 0 of they match.
 7. Test the functions for non-zero terminated strings. Modify the functions to handle non-zero terminated strings.
 8. Write a function, `cat_dot()`, that concatenated two strings with a dot in between.
 9. Modify `cat_dot()` function to concatenate two strings, adding a separator in between, passed as third argument.
 10. Rewrite `cat_dot()` for c-style strings as input parameters; let it return a c-string on the heap.
 11. Rewrite all the functions from chapter §18.6 to check for palindrome by making a backward copy of the string and then comparing to the original.
 12. Consider the memory layout in §17.3 (text, static, stack and heap). Write a program the shows memory addresses growth in each of the different types of memory.
 13. Look at the "array solution" to the palindrome problem and fix it to handle: long strings by, either reporting for too long strings or allowing arbitrary long strings.
 14. Look up and implement a _skip list_. (Not an easy exercise).
 15. Implement a version of the game "Hunt the Wumpus". Make it work via the console.
 

<h2>Chapter 19</h2>

 1. Try this 1: Consider problems in function `resize()`: _"Out of range error"_ in vector element access.
 2. Try this 2: add `try-catch` blocks in function `suspicious()` at all the places where resources are released.
 3. Try this 3: modify function `reserve()` to use `auto_ptr`; compare solution to one where `vector_base` is used. 
    **Remark: impossible to implement using `auto_ptr` - no pointer arithmetic supported, can't access all elements.**
 4. Drill: exercises on `templates<\>`.
 5. Write a template function that _accumulates_ a `std::vector` of elements of an object of any type to which elements can be added.
 6. Write a template function that takes two `std::vector`s as arguments and returns their _inner product_.
 7. Write a template `class Pair` that can hold a pair of values of any type. Use this to implement a simple symbol table as the one used §7.8.
 8. Modify `class Link` from §17.9.3 to be a `template` with the type of a value as the template argument. Redo Exercise 13 Chapter 17 with `Link` of `God`.
 9. Define a `class Int` having a single member of type `int`. Define constructors, assignment, `operators +`, `-`, `/`, `*`, I/O `operators <`, `operator >>`.
 10. Define a template `class Number` of `T` having a single member of any valid numeric type. Define constructors, assignment, `operators+`, `-`, `/`, `\*`, I/O `operators <`, `operator >`.
 11. Redo Exercise 2, i.e. find the _inner product_ of two vectors of using types `Number` of `T`.
 12. Implement the allocator from §19.3.6 using `malloc()` and `free()`. Get the `vector` as defined by the end of §19.4 to work for a few simple test cases.
 13. Re-implement `vector::operator()` (§19.2.5) using an allocator §19.3.6 for memory management.
 14. Implement a simple `auto_ptr` supporting: constructor, destructor, `operator->`, `\*`, and `release()`.
 15. Design and implement a `counted_ptr` of `T` that is a type that holds a pointer to an object of type `T` and a pointer to a "use count (an `int`) shared by all counted pointers to the same object of type `T`. The use count should hold the number of counted pointers pointing to a given `T`.
 16. Design and implement a file handler that takes a string argument (file name), opens the file in the constructor and closes it in the destructor.
 17. Write a Tracer class where its constructor and destructor prints a string. Give the strings as constructor arguments. Experiment with Tracers as: local objects, global, objects allocated by `new`. Add copy constructor and copy assignment and observe where copying is done.
 18. Provide a simple GUI interface output to the "Hunt the Wumpus" from Chapter 18. Take the input from an input box and display a map of the part of the cave currently known to the player in a window.
 19. Modify the previous exercise to allow the user to mark rooms on the map based on knowledge and guesses, such as _"maybe bats"_ and _"bottomless pit"_.
 20. Define a vector so `sizeof( vector<int> )== sizeof( int * )`, that is, the vector itself consists only of a pointer to a representation consisting of the elements, the number of elements, and the `space` pointer.
 
 
<h2>Chapter 20</h2>

 1. Try this 1: modify the existing code and remove the ugliness.
 2. Try this 2: remove errors from the modified code.
 3. Try this 3: Write a function `void copy (int* f1, int* e2, int* f2)` that copies the elements of an array of ints defined by `[f1, e1)` into another `[f2: f2 + (e1- f1))`. Use only iterator operations and no subscript `operator[]`.
 4. Try this 4: find and remove the error in the code. 
 5. Try this 5: Implement `push_front()` for `vector` and compare it to `push_back()`.
 6. Try this 6: Modify the function `advance()` to accept negative argument.
 7. Try this 7: For each array of `char`, `vector` of `char`, `list` of `char`, and `string`, define one with the value `"Hello"`, pass it to a function as an argument, write out the number of characters in the string passed, try to compare it to "`Hello"`, copy the argument into another variable of the same type.
 8. Try this 8: Redo the previous Try This using containers of type `int`, initialized to `{ 1, 2, 3, 4, 5 }`.
 9. Drill: Use `std::array`, `std::vector`, `std::list`. Define `copy()` and `std::find()`.
 10. Do all the Try This exercises.
 11. Get the "Jack and Jill" example from §20.1.2 to work. Use input from a couple of small files to test it.
 12. Look the palindrome example from §18.6; redo the Jack and Jill example from §20.1.2 using that variety of techniques.
 13. Find and fix errors in Jack and Jill in §20.3.1 by using STL techniques throughout.
 14. Define `<operator` and `>operator` for `std::vector`.
 15. Write find and replace function for `class Document` based on §20.6.2.
 16. Find the lexicographically last string in an unsorted `std::vector<std::string>`.
 17. Define a function that counts the number of characters in `Document`.
 18. Define a function that counts the number of words in `Document`, where word is defined as: _"white space separated sequence of characters"_ or _"sequence of alphabetic characters"_. 
 19. Define a function that counts the number of words in `Document`, where the white space string is defined via function's argument.
 20. Give a list `std::list` of `int` as a (by - reference) parameter, make a `std::vector` `double` and copy the elements of the list into it. Verify the copy was correct and complete. Print the elements sorted in increasing value.
 21. Complete the definition of `List` from §20.4.1 - 2 and get `high()` example to run. Allocate a `List` to represent one past the end.
 22. Modify the solution to the previous exercise to use `0` to represent the (non- existent) one-past-the-end `Link (list<Elem> ::end())`; that way the size of empty list is equal to the size of simple pointer.
 23. Define a singly-linked list, `slist`, in the style of `std::list`. Which operations from `List` should be kept?  
 24. Define a `pvector` to be like `vector` of pointers except that it contains pointer to objects and its destructor deletes each object.
 25. Define an `ownership_vector` that holds pointers to objects like `pvector`, but provides a mechanism for the user to decide which objects are owned by the vector (i.e., which objects are `delete`d by the destructor).
 26. Define a range-checked iterator for `vector` (a random-access iterator).
 27. Define a range-checked iterator for `list` (a bidirectional iterator).
 28. Compare `vector` and `list`. Generate _N_ random `int` numbers in the range _[0, N)_. As each `int` is generated. insert it into a  `vector` of `int`. Keep the `vector` sorted; that is, a value is inserted after every previous value that is less than or equal to the new value and before every value that is larger than the new value; do the same for the `list`. Explain result. (§26.6.1 explains how to time a program.) 
 
 
 
 
<h2>Chapter 21</h2>
 
 
1. Try This 1: Write, test the functions `find()` and construct an argument for their being equivalent.
2. Try This 2: Why using implicit parameters could lead to obscure errors. List three examples where they should be avoided.
3. Try This 3: Define a `std::vector` of `Record`, initialize it with four Records of your choice, and compute their total price using the function in §21.5.2.
4. Try This 4: Write the example from §21.6.3 and get it to run.  
5. Try This 5: Write a small program using `#include <unordered_map>`.
6. Try This 6: Get the program from §21.7.2 to run and test with small files of few hundred words. Try (the not recommended) guessing of the input size (potentially leading to buffer overflow).
7. Drill 1: `algorithms` with `std::vector` and `std::list`.
8. Drill 2: `algorithms` with `std::map`.
9. Drill 3: `algorithms` with `std::vector<int>` and `std::vector<double>`.
10. Do all Try this exercises (in case you haven't).
11. Find a reliable STL documentation and list every standard library algorithm.
12. Implement `count()` yourself. Test it.
13. Implement `count_if()` yourself. Test it.
14. Reimplement `count()` and `count_if()` as if there is no `end()` iterator.
15. Redo §21.6.5 but with `std::set<Fruit*>` instead. Provide a comparison operation `Fruit_comparison`, for `std::set<Fruit*, Fruit_comparison>`.
16. Implement a `binary_search()` function for `std::vector` and `std::list`. Test it. How much do they resemble each other?
17. Take the word frequency example from §21.6.1 and and modify it to to output its lines in order of frequency.
18. Define an `Order` class with (customer) `name`, `address`, `data` and `vector` of `Purchase` members. `Purchase` is a class with (product) `name`, `unit prince`, and `count members`. Define a mechanism for reading and writing to and from file. Define a mechanism for printing orders. Create a file of at least 10 orders, read it into a `vector` of `Order`, sort it by name (of customer), and write it back to file. Create another file of at least ten `Orders`, of which about the third are the same as in the first file, read into a `list` of `Order`, sort by address of customer and write back out to file. Merge the two files into third using `std::merge()`;
19. Provide a GUI interface for entering `Order`s into files.  
20. Provide a GUI interface for querying a file of `Orders`; e.g., "Find all orders from Joe," "Find the total value of orders in file Hardware," and "List all orders in file Clothing."
21. "Clean up" a text file for use in a word query program; that is, replace punctuation with white space, put words into lower case, replace _"don't"_ with _"do not"_ (etc.), and remove plurals (e.g., ships becomes ship).
22. Using the output from the previous exercise to answer questions such as: _"How many occurrences of ship are there in a file?"_, _"Which word occurs most frequently?"_, _"Which is the longest word in the file?"_, _"Which is the shortest?"_, _"List all words starting with s."_, _"List all four-letter words."_
23. Provide a GUI for the previous exercise.


<h2>Chapter 22</h2>


1. Define programming.
2. Define programming language.
3. Which of the chapter vignettes were written by a scientist? Write a paragraph with the contribution of each scientist.
4. Which of the chapter vignettes were written not by a scientist?
5. Write a `"Hello, World!"` program in each of the languages mentioned in this chapter.
6. For each language mentioned in this chapter, look at a popular textbook and see what is used as the first complete program. Write that program in all of the other languages. Warning: This could easily be a 100 - program project.
7. Make a list of five modern languages that you think ought to be covered and write a page and a half - along the lines of the languages sections in this chapter.
8. What is C++ used for and why? Write a 10- to 20- page report.
9. What is C used for and why? Write a 10- to 20-page report.
10. Pick one language (not C or C++) and write a 10- to 20-page description of its origins, aims, and facilities. Give plenty of concrete examples. Who uses it and for what?
11. Who currently holds the Lucasian Chair in Cambridge?
12. Of the language designers mentioned in this chapter, who has a degree in mathematics? Who does not?
13. Of the language designers mentioned in this chapter, who has a Ph.D.? In which field? Who does not have a Ph.D.?
14. Of the language designers mentioned in this chapter, who has received tlle Turing Award? What is that? Find the actual Turing Award citations for the winners mentioned here.
15. Write a program that, given a file of (name,year) pairs, such as (Algol,1960) and (C,1974), graphs the names on a timeline.
16. Modify the program from the previous exercise so that it reads a file of (name,year,(ancestors)) tuples, such as (Fortran,19S6,()), (Algol,1960,(Fortran), and (C++,198S,(C,Simula)), and graphs them on a timeline with arrows from ancestors to descendants. Use this program to draw improved versions of the diagrams in §22.2.2 and §22.2.7. 



<h2>Chapter 23</h2>



1. Try this 1: What would be a better error handling? Modify Mail_file's constructor to handle likely formatting errors related to the use of "----" - (end of message indicator).
2. Try this 2: Write a brief explanation of the new terms used in the current section of the chapter.
3. Try this 3: Get the program from §23.8.7 to run and use it to try out some patterns, such as: `abc`, `x.*x`, `(.*)`, `\([^)]*\)`, `\w+ \w+( Jr\.)`.
4. Drill: Find out if `regex` is shipped as part of your standard library. Try: `std::regex` and `tr1::regex`. Get the program from §23.7.7 to run. Install boost library; set project options; and include needed headers. Use the program to test the pattern from §23.7.
5. Exercise 1: Get the Mail_file example to run with file of your creation. Be sure to test with error-causing messages, such as: ones with two addresses, multiple messages with same addresses or same subject, and empty message. Test with file containing something that is not a message, such as a file containing only ....
6. Add a `multimap` and have it hold subjects. Let the program take an input string from the keyboard and print out every message with that string as its subject.
7. Modify the email example from §23.4 to use regular expressions to find the subject and sender.  
8. Apply the previous program on real list of emails and extract the lines containing the subject.
9. Compare `std::multimap` against `std::unordered_multimap`, having in mind that the latter doesn't take advantage of ordering.
10. Write a program that finds dates in a file and displays the line containing the date and its number. Start with regular expression for simple formats like: `12/24/2017`. Add more formats later.
11. Write a program that finds redit card numbers in a file and displays the line containing the date and its number.
12. Write a program that finds a pattern in a file and displays the line containing the pattern and its number.
13. Using `eof()` (§B.7.2), it is possible to determine which line of a table is the last. Use that to (try to) simplify the table-checking program from §23.9. Be sure to test your program with files that end with empty lines after the table and with files that don't end with a newline at all.
14. Modify the table-checking program from §23.9 to write a new table where the rows with the same initial digit are merged.
15. Modify the table-checking program from §23.9 to see if the number of students is increasing or decreasing over the years in question.
16. Write a program, based on the program that finds lines containing dates, that finds all dates and reformats them to the ISO `yyyy/mm/dd` format. The program should take an input file and produce an output file that is identical to the input file except for the changed date formatting.
17. Does dot `(.)` match `'\n'`? Write a program to find out.
18. Write a program similar to the one in §23.8.7, have it read a file into memory (representing a line break with the newline character, `'\n'`), so that you can experiment with patterns spanning line breaks. Test it and document a dozen test patterns.  
19. Describe a pattern that cannot be expressed as a regular expression.
20. Prove that the pattern found in the previous exercise really isn't a regular expression.


<h2>Chapter 24</h2>

1. Try this 1: sum a the fraction `1/n` `n` times and observe the result. Is it `1`? Rounding Error.
2. Try this 2: Run the examples from §24.2 showing truncation, overflow and underflow examples due to intertype assignments, implicit conversion and algebraic calculations.
3. Drill 1: Print the size of a `char`, a `short`, an `int`, a `long`, a `float`, a `double`, an `int*`, and a `double*`. (use `sizeof`, not `limits`).
4. Drill 2: Print out the size as reported by `sizeof` of Matrix of `int`: `a(10)`, Matrix of int: `b(10)`, Matrix of double: `c(10)`, 2D Matrix of int: `d(10,10)`, 3D Matrix of int: `e(10, 10, 10)`.
5. Drill 3: Print out the elements of the matrices from the previous exercise.
6. Drill 4:  Write a program that takes ints from d n and outputs the `sqrt()` of each `int`, or "no square root" if `sqrt(x)` is illegal for `some` x (i.e., check your `sqrt()` return values).
7. Drill 5: Read ten floating-point values from input and put them into a `Matrix` of `double`. Matrix has no `push_back()` so be careful to handle an attempt to enter a wrong number of doubles. Print out the `Matrix`.
8. Drill 6: Compute a multiplication table for `[O, n) x [O,m)` and represent it as a 2D Matrix. Take `n` and `m` from `std::cin` and print out the table nicely (assume that `m` is small enough that the results fit on a line). 
9. Drill 7: Read ten `complex` of `double`s from `std::cin` and put them into a `Matrix`. Calculate and output the sum of the ten `complex` numbers.
10. Drill 8:  Read six `int`s into a `2D Matrix` of `int`, `m(2, 3)` and print them out.
11. The function arguments `f` for `a.apply(f)` and `apply(f,a)` are different. Write a `double()` function for each and use each to double the elements of an array `{ 1, 2, 3, 4, 5 }`. Define a single `double()` function that can be used for both `a.apply(double)` and `apply(double, a)`. Explain why it could be a bad idea to write every function to be used by `apply()` that way.
12. Do, the previous, Exercise 1 again, but with _function objects_, rather than functions. 
13. Write an `apply(f,a)` that can takes a `void f(T&)`, a `T f(const T&)`, and their function object equivalents. Hint: `Boost::bind`.
14. Get the Gaussian elimination program to work; that is, complete it, get it to compile, and test it with a simple example. 
15. Try the Gaussian elimination program with `A={ {O 1} {1 O} }` and `b={ 5 6 }` and watch it fail. Then, try `elim_with_partiat_pivot()`.
16.  In the Gaussian elimination example, replace the vector operations `dot_product()` and `scale_and_add()` with loops. Test, and comment on the clarity of the code.
17. Rewrite the Gaussian elimination program without using the Matrix library; that is, use built-in arrays or vectors instead of Matrices.
18. Animate the Gaussian Elimination. 
19. Rewrite the non-member `apply()` functions to return a `Matrix` of the return type of the function applied that is, `apply(f, a)` should return a `Matrix` of type `R` where `R` is the return type of `f`. Warning: The solution requires information about templates not available in this book. 
20. How random is your `rand()`? Write a program that takes two integers `n` and `d` as inputs and calls `randint(n)` `d` times, recording the result. Output the number of draws for each of `[0 : n)` and "eyeball" how similar tile counts are. Try with low values for `n` and with low values for `d` to see if drawing only a few random numbers causes obvious biases. 
21. Write a `swap_columns()` to match `swap_rows()` from §24.S.3. Obviously, to do that you have to read and understand some of the existing `Matrix` library code. Don't worry too much about efficiency: it is not possible to get `swap_columns()` to run as fast as `swap_rows()`.
22. Implement: `Matrix operator multiplication (2DMatrix&, 1DMatrix&);`, i.e. tensor-vector dot product and `Matrix operator+ (Matrix&, Matrix&);` for randomly multidimensional matrices. 

<h2>Chapter 25</h2>

1. Try This 1: Replace `333` in the example with `10` and run the example again. What result would you expect? What result did you get? 
2. Тry This 2: Before reading further, try to see how many errors you can find in `f()` in §25.4.3. Specifically, which of the calls of `poor()` could cause the program to crash?
3. Try This 3: Get the bits example to work and try out a few values to develop a feel for binary and hexadecimal representations. If you get confused about the representation of negative values, just try again after reading §25.5.3.  
4. Try This 4: Inspect the loop in §25.5.3 with signed `char` as loop variable and `unsigned char` as termination variable. Why it's infinite?
5. Try This 5: Draw out the bit patterns on a piece or paper. Using paper, then figure out what the answer would be for `si = 128` in §25.5.3. Then run the program to see if your machine agrees. 
6. Drill 1: Bit shifting and multiplication.
7. Drill 2: Unsigned short Bit manipulations.
8. Exercise 1: Do Try This Exercise.
9. Hexspeak.
10. Integer bit patterns.
11. Add the bitwise logical operators `&`, `|`, `^` , and `~` to the calculator from Chapter 7. 
12. Write an infinite loop. Execute it. 
13. Write an infinite loop that is hard to recognize as an infinite loop. A loop that isn't really infinite because it terminates after completely consuming some resource is acceptable.  
14. Write out the hexadecimal values from `0` to `400`; and from `-200` to `200`.
15. Write out the numerical values of each character on your keyboard.
16. Without using any standard headers (such as `limits` or documentation, compute the number of bits in an `int` and determine whether `char` is `signed` or `unsigned` on your implementation. 
17. Look at the bitfield example from §25.5.5. Write an example that initializes a `PPN`, then reads and prints each field value, then changes each field value (by assigning the field), and prints the result. Repeat this exercise, but store the `PPN` information in a 32-bit `unsigned` integer and use bit manipulation operators (§25.5.4) to access the bits in the word. 
18. Redo previous exercise using `bitset`.
19. Write out the clear text of the example from §25.5.6. 
20. Implement a simple `vector` that can hold at most `N` elements allocated from a pool. Test it for `N == 1000` and `integer` elements.  
21. Measure the time it takes to de / allocate `10000` objects of random sizes in `[10000:0)` - byte range. Do this twice: once deallocate in reverse order and once deallocate in random order.
22. Formulate 20 coding style rules (don't just copy those in §25.6). Apply them to a program of more than 300 lines that you recently wrote.
23. Proof that `Array_ref` handles inheritance correctly by trying to get a `Rectangle\*` into `std::vector<Circle\*>` using `Array_ref<Shape\*>`, without using casts or other operations involving undefined behaviour.


<h2>Chapter 26</h2>

1. Implement a _Binary Search_ algorithm by yourself. How do you know it is correct? 
2. Drill 1: Implement the input operator for `Test` from §26.3.2.2.
3. Drill 2: Complete a file of tests for the sequences from §26.3: empty sequence, single element, odd and even number, equal elements, different elements at end.
4. Drill 3: Based on §26.3.2.3, complete a program that generates (ordered): a very large sequence, ten sequences with random number of elements, ten sequences with elements: `0,1,2,...,9` random elements.
5. Drill 4: Repeat these tests for sequences of strings, such as: `{ Bohr Darwin Einstein Lavoisier Newton Turing }`.
6. Exercise 1: Run your binary search algorithm from §26.1 wilt the tests presented in §26.3.2.1.
7. Modify the testing of `binary_search()` to deal with arbitrary element types. Then, test it with `std::string` sequences and `float` sequences.
8. Repeat the exercise in §26.2.1 with the version of `binary_search` that takes a comparison criterion. Make a list of new opportunities for errors introduced by that extra argument.
9. Devise a format for test data so that you can define a sequence once and run several tests against.
10. Add a test to the set of `binary_search` tests to try to catch the (unlikely) error of a `binary_search` modifying the sequence.
11. Modify the calculator from _Chapter 7_ minimally to let it take input from a file and produce output to a file (or use your operating system's facilities for redirecting I/O ). Then devise a reasonably comprehensive test for it. 
12. Test the "simple text editor" from §20.6. 
13. Add a text-based interface to the graphics interface library from Chapters 12 - 15. For example, the string: "Circle(Point(O, 1), 15)" should generate a call `Circle(Point(O, 1), 15)`. Use this text interface to make a "kid 's drawing" of a two-dimensional house with a roof, two windows, and a door.
14. Add a text-based output format for the graphics interface library. For example, when a call `Circle(Point(0,1),15)` is executed, a string like: "Circle(Point(0,1),15)" should be produced on an output stream.
15. Use the text-based interface from Exercise 9 to write a better test for the graphical interface library.
16. Time the sum example from §26.6 with `m` being square matrices with dimensions `100`, `10.000`, `1.000.000`, and `10.000.000`. Use random element values in the range `[-10: 10)`. Rewrite the calculation of `v` to use a more efficient (not O(n^2)) algorithm and compare the timings.  
17. Write a program that generates random floating-point numbers and sorts them using `std::sort`. Measure the time used to sort `500,000` doubles and `5,000,000` doubles.  
18. Write a program that generates random length, within `[0,100)`, `std::string`s and sorts them using `std::sort`. Measure the time used to sort `500,000` and `5,000,000` strings. 
19. Repeat the previous exercise, except using a `std::map` rather than a `std::vector` so that we don't need to sort.

<h2>Chapter 27</h2>

1. Try This 1: Test `cat()`. Why `2`? We left a beginner's performance error in `cat()`; find it and remove it. We "forgot" to comment our code. Add comments suitable for someone who can be assumed to know the standard C - string functions. 
2. Is this implementation of `strcpy()` correct? Explain why.
3. Rewrite the intrusive list example in C++, showing how to make it shorter and easier to use without making the code slower or the objects bigger. 
4. Drill 1: Write a `"Hello, World!"` program in C, compile it, and run it.  
5. Define two variables holding `"Hello"` and `"World!"` respectively; concatenate them with a space in between; and output them as `Hello, World!`.
6. Define a C function that takes a `char*` parameter `p` and an `int` parameter `x` and prints out their values in this format: `p` is `"foo"` and `x` is `7`. Call it with a few argument pairs. 
7. Exercise 1: Implement versions of `strlen()`, `strcmp()`, and `strcpy()`.
8. Complete the intrusive list example in §27.9 and test it using every function.
9. "Pretty up" the intrusive list example in §27.9 as best you can to make it convenient to use. Do catch / handle as many error's as you can. It is fair game to change the details of the `struct` definitions, to use macros, whatever.
10. If you didn't already, write a C++ version of the intrusive list example in §27.9 and test it using every function.
11. Compare the results of Exercises 3 and 4.
12. Change the representation of `Link` and `List` from §27.9 without changing the user interface provided by the functions. Allocate `Link`s in an array of `Link`s and have the members: `first`, `last`, `prev`, and `next` be `int`s (indices into the array).  
13. What are the advantages and disadvantages of intrusive containers compared to C++ standard (non-intrusive) containers? Make lists of pros and cons. 
14. What is the lexicographical order on your machine? Write out every character on your keyboard together with its integer value; then, write the characters out in the order determined by their integer value.
15. Using only C facilities, including the C standard library, read a sequence of words from stdin and write them to stdout in lexicographical order. Hint: The C sort function is called `qsort()`; look it up somewhere. Alternatively, insert the words into an ordered list as you read them. There is no C standard library list.
16. Make a list of C language features adopted from C++ or C with Classes (§27.1). 
17. Make a list of C language features not adopted by C++.
18. Implement a (C-style string, `int`) lookup table with operations such as `find (struct table*, const char*)`, `insert (struct table*, const char*, int)`, and `remove (struct table*, const char*)`. The representation of the table could be an array of a struct pair or a pair of arrays (`const char* []` and `int*`); you choose. Also choose return types for your functions. Document your design decisions.  
19. Write a program that does the equivalent of `string s`; `cin >> s`; in C; that is, define an input operation that reads an arbitrarily long sequence of white space - terminated characters into a zero - terminated array of `char`s.
20. Write a function that takes an array of `int`s as its input and finds the smallest and the largest elements; It should also compute the median and mean. Use a `struct` holding the results as the return value.
21. Simulate single inheritance in C. Let each "base class" contain a pointer to an array of pointers to functions (to simulate virtual functions as free standing functions taking a pointer to a "base class" object as their first argument); see §27.2.3. Implement "derivation" by making the "base class" the type of the first member of the derived class. For each class, initialize the array of "virtual functions" appropriately. To test the ideas, implement a version of "the old Shape example" with the base and derived `draw()` just printing out the name of their class. Use only language features and library facilities available in standard C.
22. Use macros to obscure (simplify the notation for) the implementation in the previous exercise.
 
 

===



<h2>Additional dependencies:</h2>

For the first few chapters:

http://www.stroustrup.com/Programming/std_lib_facilities.h

For chapters 12 - 15, in some exercises in chapters 21, 22, 26:

http://www.stroustrup.com/Programming/FLTK/

For chapter 24:

http://www.stroustrup.com/Programming/Matrix/


Files structure and code style:
---
Each file starts with:
<pre>
/*
    TITLE          [brief_title]       	         [file_name.extension]
    Book name and author.
    COMMENT
        Objective: [exercise intent]
            Input: [expected]
           Output: [expected]
           Author: [name]
             Date: [date of last modification]
*/
</pre>
For the sake of clarity _braces_ ,`{ }`, are on a new line:

<pre>
int main() 
{

    // Code
        // indentation
            // is
                // 4
                    // spaces.
        
}
</pre>


---


MIT License

Copyright (c) [year] [fullname]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Names of _variables_ and _functions_ start with lower case and contain upper case or underscore `"_"`, in case of complex names; _classes_ and _namespaces_ start with upper case. Example:

<pre>

namespace MyExample 
{

    int var;

    int func (int par);
    
    int res_var;
    
    class ObjectOriented
    {
    
    };

}

</pre>


File organization:
---

1.Main (Execution) files, `FileName.cpp`, contain the included compiler libraries<br>
   and custom libraries, followed by the `main()` function;<br> 
   Global variables are avoided.

2.Header files, `FileName.h` contain guards using the file name in upper case:

<pre>
#ifnded FILE_NAME_H
#define FILE_NAME_H

// declarations

#include "FileNameDef.cpp"
#endif
</pre>

3.Implementation files `FileNameDef.cpp` contain class/function implementations,<br>
  separated either by:

`----------------------------`<br>

or 

`===========================` <br>

with comments before the body of definition:

<pre>
/*
    Function:
    Use:
    
    Description
*/
</pre>

Files naming convention:
---

`Chapter[number]TryThis[number].cpp`

`Chapter[number]Drill[number].cpp`

`Chapter[number]Exercise[number].cpp`       

`Chapter[number]Exercise[number].h`          

`Chapter[number]Exercise[number]Def.cpp`    


---

OS: Windows 7, Windows 10<br>
IDE: Visual Studio 2010, CodeBlocks


