#ifndef USERMODEL_H
#define USERMODEL_H

#include "user.hpp"
//User表的数据操作类
class UserModel
{
private:
    /* data */
public:
    bool insert(User &user);
    User query(int id);
    bool updateState(User user);

    //用户状态信息重置
    void resetState();
};

#endif