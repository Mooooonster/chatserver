#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include "json.hpp"
#include <muduo/net/TcpServer.h>
#include <unordered_map>
#include <functional>
#include <mutex>
#include "usermodel.hpp"
#include "groupmodel.hpp"
#include "offlinemessagemodel.hpp"
#include "friendmodel.hpp"
#include "redis.hpp"
using namespace std;
using namespace muduo;
using namespace muduo::net;
using json = nlohmann::json;

using MsgHandler=std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;;
//聊天服务业务-》单例模式
class ChatService
{
public:
    //获取单例对象接口函数
    static ChatService* instance();
    //登录业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //处理业务
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //一对一聊天
    void onechat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //添加好友业务
    void addFriend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //正常退出业务
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //异常退出事件
    void clientCloseException(const TcpConnectionPtr &conn);
    //创建群聊
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //加入群聊
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //群聊消息
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //redis回调处理
    void handleRedisSubscribeMessage(int userid, string msg);
    //服务器异常退出
    void reset();
    //获取消息对应的处理器
    MsgHandler getHandler(int msgid);
private:
    /* data */
    ChatService();
    //消息id及其对应的事件处理方法
    unordered_map<int,MsgHandler> _msgHandlerMap;

    //存储在线用户的通信连接
    unordered_map<int,TcpConnectionPtr> _userConnMap;

    //定义互斥锁，保障线程安全
    mutex _connMutex;

    //数据操作类对象
    UserModel _userModel;
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;

    Redis _redis;    
};


#endif