#include "IRC_context.h"
#include <stdarg.h>
IRC_Context::IRC_Context(const std::string &channel) {
    UserInfo user_info("user_info");
    user_info >>= _conn;
    _channel=channel;
    _conn.join(_channel.c_str());
    //create_thread();
}

void IRC_Context::disconnect() {
    _conn.disconnect();
}

int IRC_Context::privmsg(const char *target, const char *message) {
    return _conn.privmsg(target,message);
}

int IRC_Context::privmsg(const char *fmt, ...) {
    va_list args;
    va_start(args,fmt);
    int result = _conn.privmsg(fmt,args);
    va_end(args);
    return result;
}

int IRC_Context::notice(const char *target, const char *message) {
    return _conn.notice(target,message);
}

int IRC_Context::notice(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int result = _conn.notice(fmt, args);
    va_end(args);
    return result;
}

int IRC_Context::join(const char *channel) {
    return _conn.join(channel);
}

int IRC_Context::part(const char *channel) {
    return _conn.part(channel);
}

int IRC_Context::kick(const char *channel, const char *nick) {
    return _conn.kick(channel,nick);
}

int IRC_Context::kick(const char *channel, const char *nick, const char *message) {
    return _conn.kick(channel,nick,message);
}

int IRC_Context::mode(const char *modes) {
    return _conn.mode(modes);
}

int IRC_Context::mode(const char *channel, const char * modes, const char * targets) {
    return _conn.mode(channel, modes, targets);
}

int IRC_Context::nick(const char *newnick) {
    return _conn.nick(newnick);
}

int IRC_Context::quit(const char *quit_message) {
    return _conn.quit(quit_message);
}

int IRC_Context::raw(const char *data) {
    return _conn.raw(data);
}

int IRC_Context::is_op(const char *channel, const char *nick) {
    return _conn.is_op(channel,nick);
}

int IRC_Context::is_voice(const char *channel, const char *nick) {
    return _conn.is_voice(channel,nick);
}

const char* IRC_Context::current_nick() {
    return _conn.current_nick();
}

bool IRC_Context::end_loop() {
    if(_message_loop_flag) {
        _message_loop_flag=0;
        _irc_thread->detach();
        if(_irc_thread!=NULL) {
            delete _irc_thread;
            _irc_thread=NULL;
        }
        return true;
    }
    else {
        return false;
    }
}
