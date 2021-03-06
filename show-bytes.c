﻿#include <stdio.h>
#include "show-bytes.h"

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void* x) {
	show_bytes((byte_pointer)&x, sizeof(void*));
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float)ival;
	int* pval = &val;
	show_int(ival); // 39 30 00 00 小端显示
	show_float(fval); // 00 e4 40 46 4位存储int和float类型
	show_pointer(pval);// 4位存储指针类型，值和地址值有关，不固定
}