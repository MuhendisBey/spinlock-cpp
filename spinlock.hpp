#include <atomic>

class SpinLock 
{
public:
    SpinLock(int lockOnCreate = false)
    {
        if (lockOnCreate)
        {
             while (locked.test_and_set(std::memory_order_acquire)) { ; }
        }
    }
    
    ~SpinLock()
    {
         locked.clear(std::memory_order_release);
    }
    
    void lock() 
    {
        while (locked.test_and_set(std::memory_order_acquire)) { ; }
    }
    void unlock() 
    {
        locked.clear(std::memory_order_release);
    }
    
private:
    std::atomic_flag locked = ATOMIC_FLAG_INIT ;
};
