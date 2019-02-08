#ifndef IRC_STL_H
#define IRC_STL_H
#include <stdio.h>
#include <stdarg.h>
#include <functional>
#include <string>
#include <deque>
#include <fstream>
#define __CPIRC_VERSION__	0.1
#define __IRC_DEBUG__ 1

#define IRC_USER_VOICE	1
#define IRC_USER_HALFOP	2
#define IRC_USER_OP		4

struct irc_reply_data
{
    std::string nick;
    std::string ident;
    std::string host;
    std::string target;
};

struct irc_command_hook
{
    std::string irc_command;
    std::function<int (const std::string &, irc_reply_data*, void*)> function;
};

struct channel_user
{
    std::string nick;
    std::string channel;
    char flags;
};

class IRC_STL
{
public:
    IRC_STL();
    ~IRC_STL();
    int start(const std::string &server, int port, const std::string &nick, const std::string &user, const std::string &name, const std::string &pass);
    void disconnect();
    int privmsg(const std::string &target, const std::string &message);
    int privmsg(const std::string &fmt, ...);
    int notice(const std::string &target, const std::string &message);
    int notice(const std::string &fmt, ...);
    int join(const std::string &channel);
    int part(const std::string &channel);
    int kick(const std::string &channel, const std::string & nick);
    int kick(const std::string &channel, const std::string & nick, const std::string & message);
    int mode(const std::string &modes);
    int mode(const std::string &channel, const std::string & modes, const std::string & targets);
    int nick(const std::string &newnick);
    int quit(const std::string &quit_message);
    int raw(const std::string &data);
    void hook_irc_command(const std::string &cmd_name, int (*function_ptr)(const std::string &, irc_reply_data*, void*));
    int message_loop();
    int message_loop(int &flag);
    int is_op(const std::string &channel, const std::string &nick);
    int is_voice(const std::string &channel, const std::string &nick);
    const std::string & current_nick();
    void clear_buffer();
private:
    void call_hook(const std::string & irc_command, const std::string &params, irc_reply_data* hostd);
    /*void call_the_hook(irc_command_hook* hook, const std::string & irc_command, const std::string &params, irc_host_data* hostd);*/
    void parse_irc_reply(char *data);
    void split_to_replies(char *data);
    void insert_irc_command_hook(irc_command_hook* hook, const std::string &cmd_name, int (*function_ptr)(const std::string &, irc_reply_data*, void*));
    void delete_irc_command_hook(irc_command_hook* cmd_hook);
    int irc_socket;
    bool connected;
    bool sentnick;
    bool sentpass;
    bool sentuser;
    std::string cur_nick;
    std::ofstream dataout;
    std::ifstream datain;
    std::deque<channel_user> chan_users;
    irc_command_hook* hooks;
    std::deque<std::string> _obuf;
    void insert_to_buffer(const std::string&);
};

#endif // IRC_STL_H
