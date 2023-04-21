//#include <iostream>
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(int argc, char** argv) {
//	return 0;
//}

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "auth.cpp"
#include "admin.cpp"

using namespace std;

int main()
{
    Auth auth;        // khoi tao object auth
    Auth *au = &auth; // gan con tro class
    au->login();      // tro den ham login

    Admin admin;
    admin.add();
    admin.menu();

    return 0;
}

