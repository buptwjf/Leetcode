//
// Created by 86188 on 2023/5/15.
//

//#include <stdio.h>
#include <iostream>  // <iostream> 包括了 <stdio.h>

int main() {
    const char *str = "hello";
    printf("%c\n", *str); //输出首字符  h
    std::cout << *str << std::endl; // h

    printf("%s\n", str); //输出整串字符 hello
    std::cout << str << std::endl; // hello

    printf("%p\n", str);//输出字符串首字符地址  00007ff6a09da000

    printf("%p\n", &str);//输出指针str的地址  0000008be2dff768

}
