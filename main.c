#include "ec.h"


int main()
{
	point_t expected = {.x = 370, .y = 307};
	point_t P = {.x = 0, .y = 1};
	point_t r = ec_add(P, P, 493);
	return 0;
}
