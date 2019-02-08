#ifndef IRC_CONTEXT_H
#define IRC_CONTEXT_H
#include <string>
#include <sstream>
#include <thread>
#include "IRC.h"
#include "user_info.h"
class IRC_Context {
public:
    IRC_Context(const std::string &channel);
    ~IRC_Context() {
        end_loop();
    }
    inline bool joinable() {return _irc_thread->joinable();}
    inline void create_thread() {
        _irc_thread=new std::thread([&](){_conn.message_loop(_message_loop_flag);});
    }
    void disconnect();
    int privmsg(const char *target, const char *message);
    int privmsg(const char *fmt, ...);
    int notice(const char *target, const char *message);
    int notice(const char *fmt, ...);
    int join(const char *channel);
    int part(const char *channel);
    int kick(const char *channel, const char * nick);
    int kick(const char *channel, const char * nick, const char * message);
    int mode(const char *modes);
    int mode(const char *channel, const char * modes, const char * targets);
    int nick(const char *newnick);
    int quit(const char *quit_message);
    int raw(const char *data);
    int is_op(const char *channel, const char *nick);
    int is_voice(const char *channel, const char *nick);
    const char * current_nick();
    const auto& output_buffer() {
        return _conn.output_buffer();
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
