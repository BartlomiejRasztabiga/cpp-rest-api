//
// Created by rasztabigab on 20.07.2017.
//

#include <cstdio>
#include "UserService.h"


UserService::UserService() {
    this->users = new User[100];
    this->usersSize = 0;
}

UserService::~UserService() {
/*    for (int i = 0; i < usersSize; ++i) {
        delete users[i];
    }*/

    delete [] users;
}

User *UserService::getAllUsers() {
    return users;
}

int UserService::getUsersSize() {
    return usersSize;
}

void UserService::addUser(User &user) {
    users[usersSize] = user;
    usersSize++;
}

User UserService::getUser(int id) {
    for (int i = 0; i < usersSize; ++i) {
        if (users[i].getId() == id) {
            return users[i];
        }
    }

    User nullUser(0);
    return nullUser;

}


