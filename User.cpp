//
// Created by rasztabigab on 20.07.2017.
//

#include "User.h"

User::User() {
    this->id = 0;
}

User::User(char *name) {
    this->name = name;
}

User::User(int id) {
    this->id = id;
}

User::~User() {
    delete[] name;
}

char *User::getName() {
    return name;
}

void User::setName(char *name) {
    this->name = name;
}

int User::getId() {
    return id;
}

void User::setId() {
    this->id = nextId;
    this->nextId++;
}

void User::setId(int id) {
    this->id = id;
}

int User::nextId = 1;
