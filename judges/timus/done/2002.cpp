#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
using namespace std;

#define MAX 1000

int main()
{
    int n;
    //char op[100];//, login[MAX], password[MAX];
    string op, login, password;
    set< string > users;
    map<string, string> pass;
    map<string, int> logged;

    scanf("%d", &n);
    while(n--)
    {
        //scanf(" %s ", op);
        cin >> op;
        //printf("op= %s\n", op);
        if(strcmp(op.c_str(), "register") == 0)
        {
            cin >> login >> password;
            //printf("login= %s, pass= %s\n", login.c_str(), password.c_str());
            if(users.find(login) != users.end()) puts("fail: user already exists");
            else
            {
                puts("success: new user added");
                users.insert(login);
                pass[login] = password;
                logged[login] = 0;
            }
        }
        else if(strcmp(op.c_str(), "login") == 0)
        {
            //scanf(" %s %s ", login, password);
            cin >> login >> password;
            if(users.find(login) == users.end()) puts("fail: no such user");
            else if(strcmp(pass[login].c_str(), password.c_str()) != 0) puts("fail: incorrect password");
            else if(logged[login]) puts("fail: already logged in");
            else
            {
                puts("success: user logged in");
                logged[login] = 1;
            }
        }
        else if(strcmp(op.c_str(), "logout") == 0)
        {
            //scanf(" %s ", login);
            cin >> login;
            if(users.find(login) == users.end()) puts("fail: no such user");
            else if(logged[login] == 0) puts("fail: already logged out");
            else
            {
                puts("success: user logged out");
                logged[login] = 0;
            }
        }
    }

    return 0;
}