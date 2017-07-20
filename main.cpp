#include <cstdio>
#include <cstring>
#include "UserService.h"

void getMethod(char *uri, UserService &userService);
void postMethod(char *uri, char *data, UserService &userService);
char* getUriElement(char *uri, short index);
int getIdFromUri(char *uri);

int main() {
    UserService *userService = new UserService();

    while (true) {
        char *uri = new char[100];
        char *method = new char[100];
        char *data = new char[100];

        std::printf("Enter URI \n");
        std::gets(uri);

        //Check if uri is quit, then quit loop
        if (strcmp(uri, "quit") == 0) break;

        std::printf("Enter method \n");
        std::gets(method);

        if (strcmp(method, "POST") == 0 || strcmp(method, "PUT") == 0) {
            std::printf("Enter data \n");
            std::gets(data);
        }

        if (strcmp(method, "GET") == 0) {
            getMethod(uri, *userService);
        } else if (strcmp(method, "POST") == 0) {
            postMethod(uri, data, *userService);
        } else if (strcmp(method, "PUT") == 0) {

        } else if (strcmp(method, "DELETE") == 0) {

        } else {
            std::printf("Nie rozpoznano takiej metody http: %s \n", method);
        }

        delete [] uri;
        delete [] method;

    }

    return 0;
}

void getMethod(char *uri, UserService &userService) {
    if (strcmp(uri, "/user") == 0) {
        User *users = userService.getAllUsers();
        for (int i = 0; i < userService.getUsersSize(); ++i) {
            printf("%s \n", users[i].getName());
        }
    } else if (strstr(uri, "/user/") != NULL) {
        User user = userService.getUser(getIdFromUri(uri));
        if (user.getId() == 0) {
            printf("404 User not exists \n");
            return;
        }
        printf("%s \n", user.getName());
    }

    //TODO GETy na ID
}

void postMethod(char *uri, char *data, UserService &userService) {
    if (strcmp(uri, "/user") == 0) {
        User *user = new User();
        user->setName(data);
        user->setId();

        userService.addUser(*user);
        std::printf("Added user: %d %s \n", user->getId(), user->getName());
    } else if (strstr(uri, "/user/") != NULL) {
        printf("405 Method not allowed \n");
        return;;
    }
}

int getIdFromUri(char *uri) {
    char* userId = getUriElement(uri, 1);
    int id = *userId - '0';

    return id;
}

char* getUriElement(char *uri, short index)
{
    char *token;
    token = strdup(uri);
    token = strtok(token, "/");

    while (token != NULL) {
        if (!index--) {
            return token;
        }
        token = strtok(NULL, "/");
    }

    return NULL;
}
