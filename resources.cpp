/*
    3 Lygiagrečiųjų skaičiavimų namų darbas A grupės 1 užduotis -- sukurti deadlock
    Copyright (C) 2023 Erikas Cicėnas, Austėja Jurgaitytė, Justinas Minkevičius & Julius Visockas

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <cstdlib>
#include <thread>
#include <iostream>
#include <chrono>
#include <string>

#include "resources.h"

void access_res1(const std::string& out, int n, int id) {
    printf("%i, %s", id, out.c_str());// Output the id of the thread and given string
    long fact = 1;
    for(int i = 1; i <= n; ++i) // Compute factorial of given number n
        fact *= i;
    
    printf(" and the factorial is %li\n", fact); // Output computed factorial
}

void access_res2(int m) {

    std::this_thread::sleep_for(std::chrono::milliseconds(m)); // Sleep for given number of milliseconds
}

int access_res3() {
    return rand();
}

void do_accessX(int fn, int id){
    int random = 1 + (rand() % fn); // Generate a random number in range [1, fn]
    int wait = (3+(rand()%100));  // How much time should access_res2 wait for
    switch(random){
        case 1:
            access_res1("Bananai yra gerai", (1+(rand()%6)), id);
            break;
        case 2:
            printf("%i: Laukiam: %i ms\n", id, wait);
            access_res2(wait);
            break;
        case 3:
            int random_number = access_res3();
            printf("%i: Generated random number: %i\n", id, random_number);
            break;
        
        // Any future functions can be added here
    }
}