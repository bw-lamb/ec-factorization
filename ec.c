#include "ec.h"
#include "def.h"

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

int ec_slope(point_t a, point_t b, int n, int *m)
{
	int rise, run, rise_inv, run_inv;

	if(ec_eq(a, b))
	{
		rise = (3 * a.x * a.x + A) % n;
		run = (2 * a.y) % n;
		run_inv = mod_inverse(run, n);
		*m = (rise * run_inv) % n;
	}
	else
	{
		rise = (b.y - a.y) % n;
		run = (b.x - a.x) % n;
		rise_inv = mod_inverse(rise, n);
		*m = (rise_inv * run) % n;
	}

	if(run_inv == -1)
	{
	}
	else if(rise_inv == -1)
	{

	}

	return 0;
}

int ec_eq(point_t a, point_t b)
{
	return a.x == b.x && a.y == b.y;
}

int ec_add(point_t P, point_t Q, int n, point_t *sum)
{
	int m;

	int res = ec_slope(P, Q, n, &m);
	// Failure to invert part of slope
	if(res)
	{
		return res;
	}
		
	int x3 = (m * m - P.x - Q.x) % n;
	if(x3 < 0 && mod_inverse(x3, n) == 1)
	{
		while(x3 < 0)
		{
			x3 += n;
		}
	}
	
	int y3 = ((m * (P.x - x3 % n)) - P.y) % n;
	if(y3 < 0 && mod_inverse(y3, n) == 1)
	{
		while(y3 < 0)
		{
			y3 += n;
		}
	}

	sum->x = x3; 
	sum->y = y3;
	return 0;
}

int ec_mult(point_t P, int k, int n, point_t *out)
{
	point_t ret = P;

	for(int i = 0; i < k - 1; i++)
	{
	 	int res = ec_add(ret, P, n, &ret);
		// Invertible factor in slope
		if(res)
		{
			return res;
		}
	}

	*out = ret;
	return 0;
}

int ec_factorize(int n)
{
	point_t P = {.x = 0, .y = 2};
	int factor = 0;

	for(int k = 2, done = 0; done != 1; k++)
	{
		point_t sum;
		int res = ec_mult(P, k, n, &sum);
		if(0)
		{
		}
	}

	return factor;
}

