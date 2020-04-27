#include <stdio.h>
#include <stdint.h>
#include "tmult_ok.h"

int tmult_ok(int x, int y)
{
	//ʹ��64λ��ʾ���������ֻҪ�˻�ǿ������ת��Ϊ32λ���Ƿ�ı��Ǹ�ֵ
	//�ɼ�������ֵ��Χ�Ǵ��ڽضϺ��ֵ�ģ���֤��һ��������ͬ
	int64_t product64 = (int64_t)x * y; //��֮ǰ��Ҫǿ������ת������Ȼint*int�ͻ�����ض���
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
