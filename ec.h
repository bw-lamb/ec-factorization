#pragma once

int mod_inverse(int a, int m);

typedef struct point
{
	int x, y;
} point_t;

int ec_slope(point_t a, point_t b, int n);
int ec_eq(point_t a, point_t b);
point_t ec_add(point_t P, point_t Q, int n);
point_t ec_mult(point_t P, int k, int n);
int ec_factorize(int x, int n);
