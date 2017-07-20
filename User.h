//
// Created by rasztabigab on 20.07.2017.
//

#ifndef CPP_REST_API_USER_H
#define CPP_REST_API_USER_H


class User {
public:
    ~User();
    User();
    User(char *name);
    User(int id);
    char *getName();
    void setName(char *name);
    int getId();
    void setId();
    void setId(int id);

private:
    static int nextId;
    int id;
    char *name;
};


#endif //CPP_REST_API_USER_H
