#include "IRC_context.h"
IRC_Context::IRC_Context(const std::string &channel) {
    UserInfo user_info("user_info");
    user_info >>= _conn;
    _channel=channel;
    _conn.join(_channel.c_str());
    //create_thread();
}

bool IRC_Context::join() {
    _irc_thread->join();
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
