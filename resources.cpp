#include "resources.h"

#include <cstdlib>

#include <iostream>

SpinLock lock_res1;

SpinLock lock_res2;

SpinLock lock_res3;

void access_res1(const std::string& out, int n, int id) {
    std::cout << '\n' << id << ':' << out << std::endl;
    long fact = 1;
    for(int i = 1; i <= n; ++i)
        fact *= i;
    
    std::cout << "The factorial is " << fact << std::endl;
}

void access_res2(int n) {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 1000000; ++j)
            i*i*j*j*i*j;
}

int access_res3() {
    return rand();
}