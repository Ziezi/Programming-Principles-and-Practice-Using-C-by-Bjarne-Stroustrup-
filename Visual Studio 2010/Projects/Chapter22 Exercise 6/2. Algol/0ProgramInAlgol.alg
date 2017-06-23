comment Evaluation of pi using the Mid-ordinate Rule on a quadrant of circle with radius 2 units. comment 

BEGIN

REAL x, y, sumy, pi;
INT n := lowerlimit, p := 1, lowerlimit := 10, upperlimit := 100, interval := 10;

FOR n BY interval TO upperlimit DO
    sumy := 0.0;

    FOR p BY 2 TO n+n-1 DO 
        x := p/n;
        y := sqrt(4.0 - x**2);
        sumy := sumy + y;
    OD
    pi := sumy * (2.0 / n);
    print((n,pi))
OD
END
 

