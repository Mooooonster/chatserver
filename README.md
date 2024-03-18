# ChatServer
集群聊天服务器和客户端代码源码 

实现功能：注册、登录、加好友、查看离线消息、一对一群聊、创建群、加入群、群聊

技术栈为 Redis MySQL Muduo库 Nginx

## 环境要求
Ubuntu Linux环境18.04

JSON开发库（JSON for Modern C++）

Boost和Muduo网络库开发环境

安装Redis环境（hiredis）

安装Nginx

安装CMake环境
## 编译方式

```
cd build
rm -rf *
cmake ..
make
```
