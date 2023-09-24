int main() {
    int b = 0;
    int i = 12;
    const int j = 13;
    int *const ip1 = &i; // ip1 只能指向 i
    // int* const ip2 = &j;  // 错误，j 是一个常量, ip2 不是指向常量的指针

    // ip1 = &b; // 错误！ip1 只能指向 i
    *ip1 = b; // 没问题，ip1 指向的位置的值可以改变

    i = 5; // 没问题，i 不受任何影响
    return 0;
}
