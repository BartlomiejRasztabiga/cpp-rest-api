//
// Created by rasztabigab on 20.07.2017.
//

#ifndef CPP_REST_API_USERSERVICE_H
#define CPP_REST_API_USERSERVICE_H


#include "User.h"

class UserService {
public:
    UserService();
    ~UserService();
    User* getAllUsers();
    int getUsersSize();
    void addUser(User &user);
    User getUser(int id);
    void updateUser(int id, User &user);
    int deleteUser(int id);

private:
    User *users;
    int usersSize;
};


#endif //CPP_REST_API_USERSERVICE_H
