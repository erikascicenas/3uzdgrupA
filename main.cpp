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
