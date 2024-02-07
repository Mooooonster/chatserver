#ifndef PUBLIC_H
#define PUBLIC_H
// server和client的公共文件

enum EnMsgType
{
    LOGIN_MSG = 1,//登录消息
    LOGIN_MSG_ACK,
    LOGINOUT_MSG,
    REG_MSG, //注册消息
    REG_MSG_ACK,
    ONE_CHAT_MSG,//聊天消息
    ADD_FRIEND_MSG,
    //组群消息
    CREATE_GROUP_MSG,
    ADD_GROUP_MSG,
    GROUP_CHAT_MSG,
};
#endif