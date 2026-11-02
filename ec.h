#pragma once

int mod_inverse(int a, int m);

typedef struct point
{
	int x, y;
} point_t;

int ec_slope(point_t a, point_t b, int n, int *m);
int ec_eq(point_t a, point_t b);
int ec_add(point_t P, point_t Q, int n, point_t *out);
int ec_mult(point_t P, int k, int n, point_t *out);
int ec_factorize(int n, int *rem);
