int roundUpto2digit(int cents){
	// convert cents to string
	string lenmeasurement = to_string(cents);
	// measure its length, corresponding to digits
	double len = lenmeasurement.length();
	double base = 10;
	double numberOfTruncateDigits = 2;
	// truncate via division by 10 to the power of number of truncated digits
	double exponent = len - numberOfTruncateDigits;
	// round up the result
	return ceil(double(cents) / pow(base, exponent));
}