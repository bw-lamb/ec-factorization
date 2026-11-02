#include "ec.h"

int mod_inverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    // Base case for m = 1
    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        // Return -1 if a and m are not coprime (no inverse exists)
        if (m == 0) {
            return -1; 
        }
        
        int q = a / m;
        int t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m;
        a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0) {
        x += m0;
    }

    return x;
}

int ec_slope(point_t a, point_t b, int n)
{
	int m, rise, run;

	if(ec_eq(a, b))
	{
		rise = (3 * a.x * a.x + 1) % n;
		run = (2 * a.y) % n;
		m = (rise * mod_inverse(run, n)) % n;
	}
	else
	{
		rise = (b.y - a.y) % n;
		run = (b.x - a.x) % n;
		m = (mod_inverse(rise, n) * run) % n;
	}

	return m;
}

int ec_eq(point_t a, point_t b)
{
	return a.x == b.x && a.y == b.y;
}

point_t ec_add(point_t P, point_t Q, int n)
{
	int m = ec_slope(P, Q, n);

	int x3 = (m * m - P.x - Q.x) % n;
	int y3 = ((m * (P.x - x3 % n)) - P.y) % n;

	// This probably isn't correct?
	while(x3 < 0)
	{
		x3 += n;
	}	
	while(y3 < 0)
	{
		y3 += n;
	}

	return (point_t){.x = x3, .y = y3};
}

point_t ec_mult(point_t P, int k, int n)
{
	point_t ret = P;

	for(int i = 0; i < k; i++)
	{
		ret = ec_add(ret, ret, n);
	}

	return ret;
}
