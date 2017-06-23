struct Fitab {
	// Object for fitting a straight line y = a + b*x to a set of points (xi, yi), with or without available
	// errors sigma i . Call one of the two constructors to calculate the fit. The answers are then available
	// as the variables a, b, siga, sigb, chi2, and either q or sigdat.
	int ndata;
	double a, b, siga, sigb, chi2, q, sigdat; // Answers.
    vector<double> &x, &y, &sig;
    Fitab(vector<double> &xx, vector<double> &yy, vector<double> &ssig)
		: ndata(xx.size()), x(xx), y(yy), sig(ssig), chi2(0.), q(1.), sigdat(0.) 
	{
		// Constructor. Given a set of data points x[0..ndata-1], y[0..ndata-1] with individual
		// standard deviations sig[0..ndata-1], sets a,b and their respective probable uncertainties
		// siga and sigb, the chi-square chi2, and the goodness-of-fit probability q (that the fit
		// would have chi2 this large or larger).
		Gamma gam;
		int i;
		double ss=0., sx=0., sy=0., st2=0., t, wt, sxoss; b=0.0; 
		
		for (i=0;i < ndata; i++) { // Accumulate sums ...
			wt = 1.0 / SQR(sig[i]); //...with weights
			ss += wt;
			sx += x[i]*wt;
			sy += y[i]*wt;
		}
		sxoss = sx/ss;
		
		for (i=0; i < ndata; i++) {
			t = (x[i]-sxoss) / sig[i];
			st2 += t*t;
			b += t*y[i]/sig[i];
		}
		b /= st2; // Solve for a, b, sigma-a, and simga-b.
		a = (sy-sx*b) / ss;
		siga = sqrt((1.0+sx*sx/(ss*st2))/ss);
		sigb = sqrt(1.0/st2); // Calculate chi2.
		for (i=0;i<ndata;i++) chi2 += SQR((y[i]-a-b*x[i])/sig[i]);
		
		if (ndata>2) q=gam.gammq(0.5*(ndata-2),0.5*chi2); // goodness of fit
	}
	
    Fitab(vector<double> &xx, vector<double> &yy)
		: ndata(xx.size()), x(xx), y(yy), sig(xx), chi2(0.), q(1.), sigdat(0.) 
	{
		// Constructor. As above, but without known errors (sig is not used). The uncertainties siga
		// and sigb are estimated by assuming equal errors for all points, and that a straight line is
		// a good fit. q is returned as 1.0, the normalization of chi2 is to unit standard deviation on
		// all points, and sigdat is set to the estimated error of each point.
		int i;
		double ss,sx=0.,sy=0.,st2=0.,t,sxoss;
		b=0.0; // Accumulate sums ...
		for (i=0; i < ndata; i++) {
			sx += x[i]; // ...without weights.
			sy += y[i];
		}
		ss = ndata;
		sxoss = sx/ss;
		for (i=0;i < ndata; i++) {
			t = x[i]-sxoss;
			st2 += t*t;
			b += t*y[i];
		}
		b /= st2;  // Solve for a, b, sigma-a, and sigma-b.
		a = (sy-sx*b)/ss;
		siga=sqrt((1.0+sx*sx/(ss*st2))/ss);
		sigb=sqrt(1.0/st2); // Calculate chi2.
        for (i=0;i<ndata;i++) chi2 += SQR(y[i]-a-b*x[i]);
		
		if (ndata > 2) sigdat=sqrt(chi2/(ndata-2)); 
		// For unweighted data evaluate typical
		// sig using chi2, and adjust
		// the standard deviations.
		siga *= sigdat;
		sigb *= sigdat;
	}
};	



struct Gamma : Gauleg18 {  
	// Object for incomplete gamma function. 
	// Gauleg18 provides coefficients for Gauss-Legendre quadrature.
	static const Int ASWITCH=100; When to switch to quadrature method.
	static const double EPS;   // See end of struct for initializations.
	static const double FPMIN; 
    double gln;
    double gammp(const double a, const double x) {
		// Returns the incomplete gamma function P(a,x)
		if (x < 0.0 || a <= 0.0) throw("bad args in gammp");
		if (x == 0.0) return 0.0;
		else if ((Int)a >= ASWITCH) return gammpapprox(a,x,1); // Quadrature.
		else if (x < a+1.0) return gser(a,x); // Use the series representation.
		else return 1.0-gcf(a,x); // Use the continued fraction representation.
	}
	
	double gammq(const double a, const double x) {
		// Returns the incomplete gamma function Q(a,x) = 1 - P(a,x)
		if (x < 0.0 || a <= 0.0) throw("bad args in gammq");
		if (x == 0.0) return 1.0;
		else if ((Int)a >= ASWITCH) return gammpapprox(a,x,0); // Quadrature.
		else if (x < a+1.0) return 1.0-gser(a,x); // Use the series representation.
		else return gcf(a,x); // Use the continued fraction representation.
	}
	double gser(const Doub a, const Doub x) {
		// Returns the incomplete gamma function P(a,x) evaluated by its series representation.
		// Also sets ln (gamma) as gln. User should not call directly.
		double sum,del,ap;
		gln=gammln(a);
		ap=a;
		del=sum=1.0/a;
		for (;;) {
			++ap;
			del *= x/ap;
			sum += del;
			if (fabs(del) < fabs(sum)*EPS) {
				return sum*exp(-x+a*log(x)-gln);
			}
		}
	}
	double gcf(const Doub a, const Doub x) {
		// Returns the incomplete gamma function Q(a, x) evaluated 
		// by its continued fraction representation. 
		// Also sets ln (gamma) as gln. User should not call directly.
		int i;
		double an,b,c,d,del,h;
		gln=gammln(a);
		b=x+1.0-a; // Set up for evaluating continued fraction
				   // by modified Lentz’s method with with b0 = 0.
		c=1.0/FPMIN;
		d=1.0/b;
		h=d;
		for (i=1;;i++) { 
			// Iterate to convergence.
			an = -i*(i-a);
			b += 2.0;
			d=an*d+b;

			if (fabs(d) < FPMIN) d=FPMIN;
			c=b+an/c;
			if (fabs(c) < FPMIN) c=FPMIN;
			d=1.0/d;
			del=d*c;
			h *= del;
			if (fabs(del-1.0) <= EPS) break;
		}
		return exp(-x+a*log(x)-gln)*h; Put factors in front.
	}
	double gammpapprox(double a, double x, int psig) {
		// Incomplete gamma by quadrature. Returns P(a,x) or Q(a, x), 
		// when psig is 1 or 0, respectively. User should not call directly.
		int j;
		double xu,t,sum,ans;
		double a1 = a-1.0, lna1 = log(a1), sqrta1 = sqrt(a1);
		gln = gammln(a);
		// Set how far to integrate into the tail:
		if (x > a1) xu = MAX(a1 + 11.5*sqrta1, x + 6.0*sqrta1);
		else xu = MAX(0.,MIN(a1 - 7.5*sqrta1, x - 5.0*sqrta1));
		sum = 0;
		for (j=0;j<ngau;j++) { // Gauss-Legendre.
			t = x + (xu-x)*y[j];
			sum += w[j]*exp(-(t-a1)+a1*(log(t)-lna1));
		}
		ans = sum*(xu-x)*exp(a1*(lna1-1.)-gln);
		return (psig?(ans>0.0? 1.0-ans:-ans):(ans>=0.0? ans:1.0+ans));
	}
	double invgammp(Doub p, Doub a);
	// Inverse function on x of P(a,x) .
};
const Doub Gamma::EPS = numeric_limits<Doub>::epsilon();
const Doub Gamma::FPMIN = numeric_limits<Doub>::min()/EPS


struct Gauleg18 {
	// Abscissas and weights for Gauss-Legendre quadrature.
	static const Int ngau = 18;
	static const Doub y[18];
	static const Doub w[18];
};
const Doub Gauleg18::y[18] = {0.0021695375159141994,
	0.011413521097787704,0.027972308950302116,0.051727015600492421,
	0.082502225484340941, 0.12007019910960293,0.16415283300752470,
	0.21442376986779355, 0.27051082840644336, 0.33199876341447887,
	0.39843234186401943, 0.46931971407375483, 0.54413605556657973,
	0.62232745288031077, 0.70331500465597174, 0.78649910768313447,
	0.87126389619061517, 0.95698180152629142};
const Doub Gauleg18::w[18] = {0.0055657196642445571,
	0.012915947284065419,0.020181515297735382,0.027298621498568734,
	0.034213810770299537,0.040875750923643261,0.047235083490265582,
	0.053244713977759692,0.058860144245324798,0.064039797355015485
	0.068745323835736408,0.072941885005653087,0.076598410645870640,
	0.079687828912071670,0.082187266704339706,0.084078218979661945,
	0.085346685739338721,0.085983275670394821};



double Gamma::invgammp(double p, double a) { 
	// Returns x such that P(a,x) =  p for an argument p between 0 and 1.
	int j;
	double x,err,t,u,pp,lna1,afac,a1=a-1;
	const double EPS=1.e-8; // Accuracy is the square of EPS.
	gln=gammln(a);
	if (a <= 0.) throw("a must be pos in invgammap");
	if (p >= 1.) return MAX(100.,a + 100.*sqrt(a));
	if (p <= 0.) return 0.0;
	if (a > 1.) {   
		lna1=log(a1);
		afac = exp(a1*(lna1-1.)-gln);
		pp = (p < 0.5)? p : 1. - p;
		t = sqrt(-2.*log(pp));
		x = (2.30753+t*0.27061)/(1.+t*(0.99229+t*0.04481)) - t;
		if (p < 0.5) x = -x;
		x = MAX(1.e-3,a*pow(1.-1./(9.*a)-x/(3.*sqrt(a)),3));
	} else {  
		t = 1.0 - a*(0.253+a*0.12); and (6.2.9).
		if (p < t) x = pow(p/t,1./a);
		else x = 1.-log(1.-(p-t)/(1.-t));
	}
	for (j=0;j<12;j++) {
		if (x <= 0.0) return 0.0; // x too small to compute accurately.
		err = gammp(a,x) - p;
		if (a > 1.) t = afac*exp(-(x-a1)+a1*(log(x)-lna1));
		else t = exp(-x+a1*log(x)-gln);
		u = err/t;
		x -= (t = u/(1.-0.5*MIN(1.,u*((a-1.)/x - 1)))); // Halley’s method.
		if (x <= 0.) x = 0.5*(x + t); // Halve old value if x tries to go negative.
		if (fabs(t) < EPS*x ) break;
	}
	return x;
}














		
		
		