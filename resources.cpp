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

#include "resources.h"

void access_res1(const std::string& out, int n, int id) {
    std::cout << '\n' << id << ':' << out << std::endl;
    long fact = 1;
    for(int i = 1; i <= n; ++i)
        fact *= i;
    
    std::cout << "The factorial is " << fact << std::endl;
}

void access_res2(int m) {

    std::this_thread::sleep_for(std::chrono::milliseconds(m));
}

void access_res3() {
    int random_number = rand();
    std::cout << '\n' << "Generated random number: " << random_number << std::endl;

}

void do_accessX(int fn, int id){
    int random = 1 + (rand() % fn);
    float wait = (3+(rand()%100));
    switch(random){
        case 1:
            access_res1("Bananai yra gerai", (1+(rand()%6)), id);
            break;
        case 2:
            printf("\nLaukiam: %.3f s\n", wait/1000);
            access_res2(wait);
            break;
        case 3:
            access_res3();
            break;
    }
}