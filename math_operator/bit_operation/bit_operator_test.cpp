#include <vector>
#include <iostream>

using namespace std;

int main() {
    int a = 8;
    int b = a & 0x07;
    std::cout << b << endl;
    cout << a % 8 << endl;
}

