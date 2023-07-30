//
// Created by 86188 on 2023/7/26.
//
#include "vector"
#include "queue"
#include "iostream"
using namespace std;

int main() {
    char* i[2] = {0};
    char buf[10];
    char* p = buf;
    buf[0] = 'a';
    buf[1] = 'b';
    buf[2] = 'c';
    buf[3] = 0;
    buf[4] = 'd';
    i[0] = p;
    cout << i[0];
    cout << "===";
    return 0;
}