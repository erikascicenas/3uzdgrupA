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
#include <cstdlib> // might be useless needs more testing
#include <fstream> // might be useless needs more testing
#include <chrono>  // might be useless needs more testing
#include <string>  // might be useless needs more testing
#include <thread>
#include <iostream>

#include "resources.h"

void access_res1(const std::string &out, int n, int id)
{
    std::ofstream failas(std::string("file.") + std::to_string(id), std::ios_base::app);
    failas << id << " " << out.c_str() << "\n";
    // printf("%i, %s", id, out.c_str());// Output the id of the thread and given string
    long fact = 1;
    for (int i = 1; i <= n; ++i) // Compute factorial of given number n
        fact *= i;
    failas << "and the factorial is " << fact << "\n";
    // printf(" and the factorial is %li\n", fact); // Output computed factorial
}

void access_res2(int m)
{

    std::this_thread::sleep_for(std::chrono::milliseconds(m)); // Sleep for given number of milliseconds
}

int access_res3()
{
    return rand();
}

void do_accessX(int fn, int id)
{
    int random = 1 + (rand() % fn);  // Generate a random number in range [1, fn]
    int wait = (3 + (rand() % 100)); // How much time should access_res2 wait for
    std::string bananai = "Bananai yra gerai";
    std::ofstream failas(std::string("file.") + std::to_string(id), std::ios_base::app);

    switch (random)
    {
    case 1:
        access_res1(bananai, (int)(1 + (rand() % 6)), id);
        break;
    case 2:
        failas << "Waiting: " << wait << "ms\n";
        // fprintf("Waiting: %i ms\n", wait);
        access_res2(wait);
        break;
    case 3:
        int random_number = access_res3();
        failas << "Generated random number: " << random_number << "\n";
        // printf("Generated random number: %i\n", random_number);
        break;

        // Any future functions can be added here
    }
}