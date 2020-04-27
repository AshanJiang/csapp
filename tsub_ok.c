#include <stdio.h>
#include <limits.h>
#include "tsub_ok.h"
#include "tadd_ok.h"
#include "show-bytes.h"
/* �ж�x-y�Ƿ���� */
int buggy_tsub_ok(int x, int y)
{
	return tadd_ok(x, -y);
}

/* x-y��������򷵻�1 */
int tsub_ok(int x, int y)
{
	//TODO:��ͥ��ҵ
	return 0;
}

void test_buggy_tsub_ok()
{
	int x = 1;
	int y = -2147483647 - 1;
	//ʹ��-TMinʱ�����
	printf("x=%d, y=%d, Ӧ�����, tsub_ok=0\n", x, y);
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