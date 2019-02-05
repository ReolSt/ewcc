#ifndef MUTEXLIST_H
#define MUTEXLIST_H
#include <mutex>
#include <vector>
#include <deque>
#include <thread>
#include <functional>
template <typename TYPE, template<typename ELEM, typename = std::allocator<ELEM>> class LIST>
class MutexList {
public:
    inline MutexList(){}
    inline void lock() {_mutex.lock();}
    inline bool try_lock() {return _mutex.try_lock();}
    inline void unlock() {_mutex.unlock();}
    inline std::thread::native_handle_type native_handle() {
        return _mutex.native_handle();
    }
    inline LIST<TYPE> &list() {
        return _list;
    }
    inline void access(std::function<void ()> func) {
        lock();
        func();
        unlock();
    }
    TYPE& operator[](const int i) {
        return _list[i];
    }
private:
    std::mutex _mutex;
    LIST<TYPE> _list;
};
template <typename TYPE>
using MutexStdVector = MutexList<TYPE,std::vector>;
#endif // MUTEXLIST_H
