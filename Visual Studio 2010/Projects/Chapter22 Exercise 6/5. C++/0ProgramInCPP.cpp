/* Implementation of Newton - Raphson iteration */
double SolveNewton (double (* pFunc) (double), double (* pFuncPrime) (double), double x, double precision = 1.0e-5)
{
	double step;
	
	do 
	{
		step = (*pFunc)(x) / (*pFuncPrime)(x);
		x -= step;
	} 
	while (fabs (step) > precision);
	
	return x;
}