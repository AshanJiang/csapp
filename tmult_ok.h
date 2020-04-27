#pragma once
//2.36 不使用除法而使用64位精度
int tmult_ok(int x, int y);
//2.35使用除法直接就可以验证乘法是否溢出
int tmult_ok_2(int x, int y);
void test_tmult_ok();