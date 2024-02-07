#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include <string>
#include <vector>
using namespace std;

class OfflineMsgModel
{
public:
    // 存储消息
    void insert(int userid, string msg);
    // 删除离线消息
    void remove(int userid);
    // 查询用户离线消息
    vector<string> query(int userid);
};

#endif
