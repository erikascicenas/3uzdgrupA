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
#include <iostream>
#include <thread>
#include <cstdlib>

#include "resources.h"

void worker(int id);

int main() {
	const int WORKERS = 6;

	std::thread threads[WORKERS];

	for(int i = 0; i < WORKERS; ++i)
		threads[i] = std::thread(worker, i);

	for(int i = 0; i < WORKERS; ++i)
		threads[i].join();

	return 0;
}

void worker(int id) {
	for(unsigned int iter = 0; true; ++iter) {
		lock_res1.lock();
		access_res1("I locked 1.", 18, id);
		lock_res2.lock();
		access_res2(200);
		lock_res3.lock();
		lock_res1.unlock();
		if(iter >= 20 && access_res3() >= RAND_MAX*0.75) {
			std::cerr << "THREAD " << id << ": beginning dead lock." << std::endl;
			lock_res1.lock();
			access_res1("We locked 1 again.", 40, id);
			access_res2(5000);
			lock_res1.unlock();
		}
		lock_res2.unlock();
		lock_res3.unlock();
	}
}
