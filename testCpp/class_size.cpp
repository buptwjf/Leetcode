//
// Created by 86188 on 2023/9/26.
//

#include "usr.h"

class MyClass {
    void test() { std::cout << "MyStuct" << std::endl; };
    int a; // 4 + 4
    double b; // 8
    char c; // 1 -> 8 整体对齐
    // 8 + 8 + 8
};

class MyClass1 {
    void test() { std::cout << "MyStuct" << std::endl; };

    virtual void test1() { std::cout << "test1" << std::endl; };

    virtual void test2() { std::cout << "test2" << std::endl; };

    virtual void test3() = 0;

    int a; // 4 + 4
    double b; // 8
    char c; // 1 -> 8 整体对齐
    // 8 + 8 + 8 + 8(虚指针)
};

class MyClass2 : public MyClass1 {
    int d;
    static int e;

    void test1() { std::cout << "test1" << std::endl; };

    static void test4() { std::cout << "test1" << std::endl; };
};


class MyClass3 {
    void test() { std::cout << "MyStuct" << std::endl; };
    double b;
    char c; // 1+3
    int a;
    // 8 + 4 + 4
};

class MyClass4 {
    virtual void test() { std::cout << "MyStuct" << std::endl; };
    char c; // 1+7 整体对齐
};




struct MyStruct {
    void test() { std::cout << "MyStuct" << std::endl; };

    int a;
    double b;
    char c;
};


int main() {
    std::cout << sizeof(MyClass) << std::endl; // (1+7) + 8 + (4+4) <- 整体对齐（必须是 8 的倍数）
    std::cout << sizeof(MyClass1) << std::endl; //  32  24 + 8(虚函数指针)
    std::cout << sizeof(MyClass2) << std::endl; //  32  24 + 8 + 0 (int d, static 不占用)
    std::cout << sizeof(MyClass3) << std::endl; //  16 = 8 + 4 + 4 (int d, static 不占用)
    std::cout << sizeof(MyClass4) << std::endl; //  16 = 8 + (1+7) 整体对齐
    std::cout << sizeof(struct MyStruct) << std::endl; // 24
}