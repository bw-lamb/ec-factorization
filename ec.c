#include "ec.h"

int mod_inverse(int x, int n)
{
	if(x == 0)
	{
		return 0;
	}


}

slope_t ec_slope(point_t a, point_t b, int n)
{
	slope_t m;

	if(ec_eq(a, b))
	{
		m.rise = (3 * a.x * a.x) % n;
		m.run = (2 * a.y) % n;
	}
	else
	{
		m.rise = (b.y - a.y) % n;
		m.run = (b.x - a.x) % n;
	}

	return m;
}

int ec_eq(point_t a, point_t b)
{
	return a.x == b.x && a.y == b.y;
}

point_t ec_add(point_t P, point_t Q, int n)
{
	slope_t m = ec_slope(P, Q, n);

	int x3 = ((m.rise * m.rise - P.x - P.y) / (m.run * m.run)) % n;
	int y3 = (((m.rise * (P.x - x3)) - P.y) / m.run) % n;

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
