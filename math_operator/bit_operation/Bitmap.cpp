//
// Created by 86188 on 2023/5/15.
//

/*
 * 实现位图的过程
 */
//#include <cstring> // 不能使用 string
#include <string.h>
#include <cstdio>

class Bitmap {
private:
    unsigned char *M;  // 位图的起始位置
    int N;  // 位图所放的空间为 M[]， 容量为 N * 8 比特
protected:
    void init(int n) {
        M = new unsigned char[N = (n + 7) / 8]; // 内存对齐，必须是 8 的倍数
        memset(M, 0, N);
    }

public:
    Bitmap(int n = 8) { init(n); }

    ~Bitmap() { delete[] M, M = nullptr; }

    // 将某一位设置为 1
    void set(int k);

    // 将某一位设置为 0
    void clear(int k);

    // 将位图进行扩充，满足数组下标为 k
    void expand(int k);

    // 测试某一位是否为 1
    bool test(int k);

    // 将位图的前 n 位转为 C 风格的字符串
    char *bit2cstring(int n);

    // 前 n 位输出出来
    void print(int n);

};


inline void Bitmap::set(int k) {
    expand(k);
    M[k >> 3] |= 0x80 >> (k & 0x07);  // M[k / 8] |= 0x80 >> (k % 8) 一样 0x80 = 1000 0000
}

inline void Bitmap::clear(int k) {
    expand(k);
    M[k >> 3] &= ~(0x80 >> (k & 0x07));
}

inline void Bitmap::expand(int k) {
    if (k < 8 * N) {
        return;
    }
    int oldN = N;
    unsigned char *oldM = M;
    init(2 * k);
    memcpy_s(M, N, oldM, oldN);
}

inline bool Bitmap::test(int k) {
    expand(k);
    return M[k >> 3] & (0x80 >> (k & 0x07));
}

inline char *Bitmap::bit2cstring(int n) {
    expand(n - 1);
    char *s = new char[n + 1];
    s[n] = '\0';
    for (int i = 0; i < n; i++) {
        s[i] = test(i) ? '1' : '0';  // 这里是字符 应该用 ''
    }
    return s;
}

inline void Bitmap::print(int n) {
    expand(n - 1);
    for (int i = 0; i < n; i++) {
        printf(test(i) ? "1" : "0"); // 这里是字符串用 ""
    }
}

int main() {
    Bitmap bm(2);
    bm.expand(9);
    bm.set(12);
    bm.set(13);
    bm.set(14);
    const char *s = bm.bit2cstring(16);
    printf("%s\n", s);
    bm.clear(13);
    bm.print(16);

    return 0;
}