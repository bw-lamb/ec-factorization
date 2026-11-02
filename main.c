#include "ec.h"


int main()
{
	point_t expected = {.x = 5, .y = 482};
	point_t P = {.x = 0, .y = 1};
	point_t Q = {.x = -1, .y = -1};

	point_t r = ec_add(P, Q, 493);
	return 0;
}
