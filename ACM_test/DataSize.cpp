//
// Created by 86188 on 2023/4/29.
//
#include <iostream>
#include <iomanip>
namespace test01 {
    void showIntSize() {
        std::cout << "int: size = " << sizeof(short) << std::endl;  //  字节大小 2
        std::cout << "int: Byte = " << sizeof(short) * 8 << std::endl;  // 16
        std::cout << "**********************************" << std::endl;
        std::cout << "int: size = " << sizeof(int) << std::endl;  //  字节大小 4
        std::cout << "int: Byte = " << sizeof(int) * 8 << std::endl;  // 32
        std::cout << "**********************************" << std::endl;
        std::cout << "long: size = " << sizeof(long ) << std::endl;  //  字节大小 4
        std::cout << "long: Byte = " << sizeof(long) * 8 << std::endl;  // 32
        std::cout << "**********************************" << std::endl;
        std::cout << "long long: size = " << sizeof(long long ) << std::endl;  //  字节大小 8
        std::cout << "long long: Byte = " << sizeof(long long) * 8 << std::endl;  // 64
        std::cout << "**********************************" << std::endl;

        std::cout << "INT16_MAX = " << INT16_MAX << std::endl; // 32767
        std::cout << "INT16_MIN = " << INT16_MIN << std::endl; // -32768
        std::cout << "INT32_MAX = " << INT32_MAX << std::endl; // 2147483647 ≈ 2^10e9  20 亿
        std::cout << "INT32_MIN = " << INT32_MIN << std::endl; // -2147483648
        std::cout << "INT64_MAX = " << INT64_MAX << std::endl; // 9223372036854775807
        std::cout << "INT64_MIN = " << INT64_MIN << std::endl; // -9223372036854775808
    }

    void showDoubleSize() {
        std::cout << "double: size = " << sizeof(double ) << std::endl;  //  字节大小 8
        std::cout << "double: Byte = " << sizeof(double) * 8 << std::endl;  // 64
        std::cout << "float: size = " << sizeof(float ) << std::endl;  //  字节大小 4
        std::cout << "float: Byte = " << sizeof(float) * 8 << std::endl;  // 32
    }


}

int main() {
    test01::showIntSize();
    test01::showDoubleSize();

    return 0;
}