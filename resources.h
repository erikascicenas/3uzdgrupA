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
    public:
    void lock() {
        while(m_lock.test_and_set()) {/*nop*/}
    }

    void unlock() {
        m_lock.clear();
    }

    private:
    std::atomic_flag m_lock = ATOMIC_FLAG_INIT;
};

/**
 * Use this to lock function access_res1
*/
extern SpinLock lock_res1;
/**
 * Output string to stdout whilst also computing a factorial to simulate a critical section. Function does not handle acquiring or freeing the lock.
 * \param out string to output first
 * \param n number of which we compute and output the factorial of n.
 * \param id id of thread
*/
void access_res1(const std::string& out, int n, int id);

/**
 * Use this to lock function access_res2
*/
extern SpinLock lock_res2;
/**
 * sleep for n milliseconds
 * \param n number of milliseconds
*/
void access_res2(int n);

/**
 * Use this to lock function access_res2
*/
extern SpinLock lock_res3;
/**
 * Generate one random number
*/
int access_res3();

#endif //RESOURCES_H
