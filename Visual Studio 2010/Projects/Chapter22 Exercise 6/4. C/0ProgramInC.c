



/* qsort: sort v[left]...v[right] into increasing order */
void qsort (void *v[], int left, int right, int (* comp) (void *, void *))
{
	int i, last;
	
	void swap (void *v[], int, int);
	
	/* do nothing if arrays elements < 2 */
	if (left >= right)
	{
		retutn; 
	}
	
	swap (v, left, (left + right) / 2);
	last = left;
	
	for (i = left + 1; i <= right; i++)
	{
		if ((*comp) (v[i], v[left]) < 0)
		{
			 swap (v, ++last, i);
		}
	}
	
	swap (v, left, last);
	
	qsort (v, left, last-1, comp);
	qsort (v, last+1, right, comp);
}