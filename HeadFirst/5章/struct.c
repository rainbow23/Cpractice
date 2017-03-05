#include <stdio.h>

typedef struct{
	const char *description;
	float value;
} swag;

typedef struct {
	swag *swag2;
	const char *sequence;
} combination;

typedef struct {
	combination *numbers;
	const char *make;
}safe;


int main() {
	swag swag_ = {"GOLD!", 1000000.0};
	combination combination_ = {&swag_, "6502"};
	safe safe_ = {&combination_, "RAMACON250"};
		
	//printf("中身＝ %f\n", safe_.numbers->swag2->value);
	printf("nakami = %f\n", (*(*safe_.numbers).swag2).value);
	//printf("nakami = %s\n", safe_.numbers->sequence);

	return 0;
}
