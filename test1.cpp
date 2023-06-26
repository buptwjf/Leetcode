//
// Created by 86188 on 2023/6/13.
//
#include <iostream>
#include "stdio.h"
using namespace std;

int main(){
    char buf[10];
    char* p_buf;
    p_buf = buf;
    buf[0] = '1';
    buf[1] = '2';
    buf[2] = '0';
    buf[3] = '2';
    buf[4] = 0;
    char* bufs[2];
    bufs[1] = p_buf;
    printf("%s\n", bufs[1]);
    p_buf = p_buf+5;
    buf[5] = 'a';
    buf[6] = 'b';
    buf[7] = '\0';
    bufs[2] = p_buf;
    printf("%s\n", bufs[2]);
    printf("%s\n", bufs[1]);

}