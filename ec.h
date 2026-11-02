#pragma once

typedef struct point
{
	int x, y;
} point_t;

typedef struct slope
{
	int rise, run;
} slope_t;

slope_t ec_slope(point_t a, point_t b, int n);
int ec_eq(point_t a, point_t b);
point_t ec_add(point_t P, point_t Q, int n);
point_t ec_mult(point_t P, int k, int n);
