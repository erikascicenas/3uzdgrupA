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
#ifndef RESOURCES_H
#define RESOURCES_H

#include <atomic>
#include <string>

class SpinLock {
    private:
    std::atomic_flag m_lock = ATOMIC_FLAG_INIT;
    
    public:
    void lock() {
        while(m_lock.test_and_set()) {/*nop*/}
    }

    void unlock() {
        m_lock.clear();
    }
};

/**
 * Output string to printf while also computing a factorial to simulate a critical section (the computed factorial is output as well). Function does not handle acquiring or freeing the lock.
 * \param out string to output first
 * \param n   number whose factrorial we compute
 * \param id  id of thread
*/
void access_res1(const std::string& out, int n, int id);

/**
 * Sleep for m milliseconds
 * \param m number of milliseconds
*/
void access_res2(int m);


/**
 * Generate one random number
*/
int access_res3();


/**
 * Randomly executes one of the above defined functions
 * \param fn number of functions
 * \param id id of thread
*/
void do_accessX(int fn, int id);

#endif //RESOURCES_H
