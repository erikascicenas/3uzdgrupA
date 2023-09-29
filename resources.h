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
 * sleep
 * \param n length
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
