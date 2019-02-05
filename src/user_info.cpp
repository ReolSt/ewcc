#include "user_info.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
std::istream& operator>>=(std::istream &stream, UserInfo &user_info) {
    for(auto &i : user_info._nick) {
        stream >> i;        
    }
    stream >> user_info._password;
    return stream;
}
UserInfo& operator>>=(UserInfo &user_info, IRC &conn) {
    conn.start("irc.chat.twitch.tv",6667,
               user_info._nick[0].c_str(),
               user_info._nick[1].c_str(),
               user_info._nick[2].c_str(),
               user_info._password.c_str());

    return user_info;
}
UserInfo& operator>>=(std::string file_name, UserInfo &user_info) {
    user_info.load(file_name);
    return user_info;
}

UserInfo& operator&(UserInfo &user_info, std::string file_name) {
    user_info.load(file_name);
    return user_info;
}

void UserInfo::load(const std::string &file_name) {
    std::ifstream user_info_stream;
    user_info_stream.open(file_name);
    user_info_stream >>= *this;
    user_info_stream.close();
    _loaded=1;
    try {
        user_info_stream.open(file_name);
        user_info_stream >>= *this;
        user_info_stream.close();
        _loaded=1;
    }
    catch (std::ifstream::failure e) {
        std::cerr << "ifstream File Exception\n";
    }
}
