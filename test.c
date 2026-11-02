#include <criterion/criterion.h>

#include "ec.h"

Test(ModInverse, Small)
{
	int five_inv = mod_inverse(5, 3);
	cr_assert(five_inv == 2);
}

Test(EC_Add, PeqQ)
{
	point_t expected = {.x = 370, .y = 307};
	point_t P = {.x = 0, .y = 1};
	
	point_t r = ec_add(P, P, 493);
	cr_assert((ec_eq(expected, r)));
}
