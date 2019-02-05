#ifndef MUTEXDATA_H
#define MUTEXDATA_H
#include <mutex>
#include <thread>
#include <functional>
template <typename T>
class MutexData
{
public:
    inline MutexData(){}
    inline MutexData(T data) {
        _data=data;
    }
    inline T &data() {return _data;}
    inline void lock() {_mutex.lock();}
    inline bool try_lock() {return _mutex.try_lock();}
    inline void unlock() {_mutex.unlock();}
    inline std::thread::native_handle_type native_handle() {
        return _mutex.native_handle();
    }
    inline void access(std::function<void ()> func) {
        lock();
        func();
        unlock();
    }
private:
    std::mutex _mutex;
    T _data;
};

#endif // MUTEXDATA_H
