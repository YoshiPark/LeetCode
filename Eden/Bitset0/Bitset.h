#ifndef AAA
#define AAA
#include<iostream>
#include<cstring>
class Bitset {
    private:
        int n;
        bool a[1000];
    public:
        Bitset() {
            memset(a, 0, sizeof(a));
        }
        void set_size(int x) {
            n = x;
        }
        void set(int x) {
            a[x] = 1;
        }
        void print() {
            for (int i = 0; i < n; i++) {
                if (a[i])
                    std::cout << 1;
                else
                    std::cout << 0;
            }
            std::cout << std::endl;
        }
};
#endif
