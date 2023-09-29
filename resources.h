#ifndef RESOURCES_H
#define RESOURCES_H

#include <mutex>
#include <string>

/**
 * Use this to lock function access_res1
*/
volatile std::mutex lock_res1;
/**
 * Output string to stdout whilst also computing a factorial to simulate a critical section. Function does not handle acquiring or freeing the lock.
 * \param out string to output first
 * \param n number of which we compute and output the factorial of n.
 * \exception std::runtime_error thrown when lock is not acquired by any thread.
*/
void access_res1(std::string out, int n);

#endif //RESOURCES_H
