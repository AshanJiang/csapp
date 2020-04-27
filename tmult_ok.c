#include <stdio.h>
#include <stdint.h>
#include "tmult_ok.h"

int tmult_ok(int x, int y)
{
	//使用64位表示不会溢出，只要乘积强制类型转换为32位看是否改变那个值
	//成绩溢出后的值范围是大于截断后的值的，保证了一定不会相同
	int64_t product64 = (int64_t)x * y; //乘之前就要强制类型转换，不然int*int就会溢出截断了
	return product64 == (int)product64;
}

int tmult_ok_2(int x, int y)
{
	int p = x * y;
	return !x || p / x == y;
}

void test_tmult_ok()
{
	int x = 2147483647;
	int y = 2;
	printf("x=%d, y=%d, tmult_ok=%d\n", x, y, tmult_ok(x, y));
	x = -2147483647 - 1;
	printf("x=%d, y=%d, tmult_ok=%d\n", x, y, tmult_ok(x, y));
	x = 21;
	y = 12;
	printf("x=%d, y=%d, tmult_ok=%d\n", x, y, tmult_ok(x, y));
}
