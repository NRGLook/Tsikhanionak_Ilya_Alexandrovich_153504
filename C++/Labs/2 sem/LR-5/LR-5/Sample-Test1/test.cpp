#include "pch.h"

int task2(int size) {
    int* A = new int[size];

    //���������� 1,2,3,

    HINSTANCE load;
    load = LoadLibrary(L"DynamicLIb.dll");
    typedef bool (*elementexist)(int*, int, int);
    elementexist elementExist;
    elementExist = (elementexist)GetProcAddress(load, "elementExist");


    int ret = ��������;

    //��������

    return ret;
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(, 1);
  EXPECT_TRUE(true);
}