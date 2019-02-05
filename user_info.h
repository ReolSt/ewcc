#ifndef USER_INFO_H
#define USER_INFO_H
#include <iostream>
#include <fstream>
#include <string>
#include "IRC.h"
class UserInfo {
public:
    inline UserInfo(){}
    inline UserInfo(const std::string &file_name) {
        load(file_name);
    }
    friend std::istream& operator>>=(std::istream &, UserInfo &);
    friend UserInfo& operator>>=(UserInfo&, IRC&);
    friend UserInfo& operator&(UserInfo&, std::string);
    friend UserInfo& operator>>=(std::string , UserInfo &);
    inline bool is_loaded() {return _loaded;}
private:
    void load(const std::string &file_name);
    std::string _nick[3];
    std::string _password;
    bool _loaded=0;
};
#endif // USER_INFO_H
