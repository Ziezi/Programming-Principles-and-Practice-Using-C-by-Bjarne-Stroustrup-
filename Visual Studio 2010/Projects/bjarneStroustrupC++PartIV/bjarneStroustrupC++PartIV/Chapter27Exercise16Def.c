/* 
	TITLE	       Use macros to obscure ineritance in C    Chapter27Exercise16Def.c 
	COMMENT
		Objective: Use macros to obscure (simplify the notation for)
				   the implementation in the previous exercise.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 21.06.2017
*/

//-----------------------------------------------------------------------------------------------

Shape_func_table sh_tbl  = { base_draw };

//-----------------------------------------------------------------------------------------------

void base_draw (struct Shape* self)
{
	VTABLE(self) = &sh_tbl;						// setup draw
	printf("Shape::name -> %s\n", NAME(self));
}

//-----------------------------------------------------------------------------------------------

Circle_func_table c_tbl = { derived_draw };

//-----------------------------------------------------------------------------------------------

void derived_draw (struct Circle* self)
{
	VTABLE(self) = (Shape_func_table*) &c_tbl;
	printf("Circle::name -> %s\n", NAME(self));
	printf("Circle::radius -> %f\n", RADIUS(self));
}

//-----------------------------------------------------------------------------------------------

void draw(struct Shape* self)	 
{
	switch (TYPE(self))
	{
		case shape:
		{
			base_draw(self);
			break;
		}
		case circle:
		{
			derived_draw((Circle*) self);
			break;
		}
		default:
		{
			perror("draw::No such object type!\n");
			exit(-1);
		}
	}
}