#include "resources.h"

#include <cstdlib>

#include <thread>

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

    std::this_thread::sleep_for(std::chrono::seconds(n));
}

int access_res3() {
    return rand();
}