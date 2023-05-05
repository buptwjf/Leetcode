#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

void func(void *i) {
    cout << "func1" << endl;
}

void func(int i) {
    cout << "func2" << endl;
}

int main(int argc, char const *argv[]) {
    int a = 10;
    int &b = a;
    cout << &b << endl;
    cout << &a << endl;
    int c = 5;
    int &d = c;
    b = d;
    cout << a << endl;
    c = 7;
    cout << a << endl;
    const int e = 5;
    const int *p1 = &e;
    int const *p4 = &e;
    int const const *p2 = &e;
    const int *const p3 = &e;
//    int* const p4 = &e;

    return 0;
}
