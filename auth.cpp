#include <iostream>

using namespace std;

class Auth
{
private:
    string userName, password;

public:
    Auth()
    {
        this->userName = "admin";
        this->password = "admin@123456";
    }

    bool login()
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- Login System Admin ---------------------------------------------"
             << endl;

        string user, pass;

        cout << "Enter user name: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;

        if (this->userName == user && this->password == pass)
        {
            return true;
        }

        cout << "Login faild!";
        this->login();
    }
};
