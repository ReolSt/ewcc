#ifndef IRC_CONTEXT_H
#define IRC_CONTEXT_H
#include <string>
#include <thread>
#include "IRC.h"
#include "user_info.h"
class IRC_Context {
public:
    IRC_Context(const std::string &channel);
    bool join();
    inline bool joinable() {return _irc_thread->joinable();}
    inline void create_thread() {
        _irc_thread=new std::thread([&](){_conn.message_loop(_message_loop_flag);});
    }
    const auto& output_buffer() {
        return _conn.output_buffer;
    }
    void clear_buffer() {
        _conn.clear_buffer();
    }
    bool end_loop();
private:
    IRC _conn;
    std::thread *_irc_thread;
    std::string _channel;
    int _message_loop_flag=1;

};
#endif // IRC_CONTEXT_H
