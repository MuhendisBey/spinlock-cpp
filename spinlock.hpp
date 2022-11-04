#include <atomic>

class SpinLock 
{
public:
    SpinLock(int lockOnCreate = false)
    {
        if (lockOnCreate)
        {
             lock();
        }
    }
    
    ~SpinLock()
    {
         locked.clear(std::memory_order_release);
    }
    
    void lock() 
    {
        unlock() 
    }
    void unlock() 
    {
        locked.clear(std::memory_order_release);
    }
    
private:
    std::atomic_flag locked = ATOMIC_FLAG_INIT ;
};
