#include <stdio.h>

/*加法是否溢出*/
int tadd_ok(int x, int y)
{
	printf("in tadd_ok x=%d, y=%d\n", x, y);
	int sum = x + y;
	int neg_over = x < 0 && y < 0 && sum >= 0;
	int pos_over = x >= 0 && y >= 0 && sum < 0;
	return !neg_over && !pos_over;
}

void test_tadd_ok()
{
	int x = 2147483647;
	int y = 1;
	//正溢出
	printf("x=%d, y=%d, add_ok=%d\n", x, y, tadd_ok(x, y));
	//负溢出
	x = -2147483647 - 1;
	y = -1;
	printf("x=%d, y=%d, add_ok=%d\n", x, y, tadd_ok(x, y));
	//正常
	x = 100;
	y = 200;
	printf("x=%d, y=%d, add_ok=%d\n", x, y, tadd_ok(x, y));
}