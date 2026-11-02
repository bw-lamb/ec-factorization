#include <criterion/criterion.h>

#include "ec.h"

Test(ModInverse, Small)
{
	int five_inv = mod_inverse(5, 3);
	cr_assert(five_inv == 2);
}

Test(EC_Add, PneqQ)
{
	point_t expected = {.x = 3, .y = 8};
	point_t P = {.x = -2, .y = 0};
	point_t Q = {.x = 0, .y = 2};

	point_t r = ec_add(P, Q, 13);
	cr_assert(ec_eq(expected, r));
}

Test(EC_Add, PeqQ)
{
	point_t expected = {.x = 10, .y = 3};
	point_t P = {.x = 0, .y = 2};
	
	point_t r = ec_add(P, P, 13);
	cr_assert(ec_eq(expected, r));
}

Test(EC_Mult, Small)
{
	point_t expected = {.x = 10, .y = 3};
	point_t P = {.x = 0, .y = 2};

	point_t r = ec_mult(P, 2, 13);
	cr_assert(ec_eq(expected, r));
}

Test(EC_Factor, Small)
{
	int n = ec_factorize(10, 13);
	cr_assert(n == 2 || n == 5);
}
