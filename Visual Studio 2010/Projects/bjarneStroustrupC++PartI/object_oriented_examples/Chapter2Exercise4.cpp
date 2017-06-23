/* 
   TITLE           Cooking recepie manual		Chapter2Exercise4.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Pseudocode; 
		           Initial algorithmic approach to task; 
				   Cooking Recepie intstructions.
			Input: -
		   Output: -
           Author: Chris B. Kirov
			 Date: 10.04.2014		   
*/
#include "../../std_lib_facilities.h"
int main()
{
#def meal 
#def food : meat(type,size), vegetables(type,size), spices(type,size), salt(type, quantity), water(quantity), oil(quantity), rice(type, quantity)
#def instruments : hotp_late(temperature, time, turn, mixing), frying pan(temperature, time, turn, mixing), cooker(temperature, time, turn, mixing)fork, spoon, bowl, dish
#def notions : type, temperature(Celcius), time(Minutes), quantity(Kg) size(Small, Big), piece(number, size), attention(cutting, burnig, breaking)
#def actions : mix(Slow, Fast, spoon), cut(size), cooking, turn, 


	meal(food, instruments, notions, actions)
		attention(breaking)
		put in bowls:											// cooking instructin start
		meat(chicken, 500)							// ingredients
		vegetables(pepper, 100), vegetables(onion, 100), vegetables(onion, 100), vegetables(garlic, 100), vegetables(tomato*, 100)
		spices(black pepper, 10), spices(red pepper, 10), spices(oregano, 10)
		salt(small, 20)
		oil(100)
		rice(250)
		put in cooker:
		water(500)
		
													// actual cooking: cuting, mixing, etc
		attention(cutting)
		cut(big) : meat, vegetables
		attention(breaking)
		put in bowl
		mix() : meat, vegetables, spices, salt
		attention(burnig)
		hot_plate(100, 30, 2, slow) : frying pan() : mix()

		attention(breaking)
		mix() : water, rice, oil(05), salt()
		attention(burnig)
		hot_plate(100, 30, 2, slow) : cooker() : mix()
													// serving
		attention(breaking)
		dish(fried chicken, boiled rice)

	return 0;
}