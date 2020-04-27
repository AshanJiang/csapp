#include <stdio.h>
#include <limits.h>
#include "tsub_ok.h"
#include "tadd_ok.h"
#include "show-bytes.h"
/* 判断x-y是否溢出 */
int buggy_tsub_ok(int x, int y)
{
	return tadd_ok(x, -y);
}

/* x-y不溢出，则返回1 */
int tsub_ok(int x, int y)
{
	//TODO:家庭作业
	return 0;
}

void test_buggy_tsub_ok()
{
	int x = 1;
	int y = -2147483647 - 1;
	//使用-TMin时会出错
	printf("x=%d, y=%d, 应该溢出, tsub_ok=0\n", x, y);
	printf("x=%d, y=%d, buggy_tsub_ok=%d\n", x, y, buggy_tsub_ok(x, y));
}

void test_tsub_ok()
{
	int x = 1;
	int y = -2147483647 - 1;
	printf("x=%d, y=%d, tsub_ok=%d\n", x, y, tsub_ok(x, y));
	x = -1;
	printf("x=%d, y=%d, tsub_ok=%d\n", x, y, tsub_ok(x, y));
}