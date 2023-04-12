#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>

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

class Department
{
public:
    static string getDepartments(int idDepartment)
    {
        switch (idDepartment)
        {
        case 1:
            return "marketing"; // phong marketing
        case 2:
            return "sale"; // phong sale
        case 3:
            return "IT"; // phong cntt
        default:
            return "";
        }
    }
};

class Salary // class Luong
{
private:
    int coefficientsSalary[3]; // he so luong
    float basicSalary;         // luong co ban

public:
    Salary()
    {
        this->coefficientsSalary[0] = 1; // luong danh cho member
        this->coefficientsSalary[1] = 2; // luong danh cho leader
        this->coefficientsSalary[2] = 3; // luong danh cho manager
        this->basicSalary = 1000;
    }
    float totalSalary(int workingTime, int position) // tham so truyen (int) thoi gian lam viec , (int) chuc vu
    {
        switch (position)
        {
        case 3:
            return workingTime * this->basicSalary * this->coefficientsSalary[2]; // luong cua manager

        case 2:
            return workingTime * this->basicSalary * this->coefficientsSalary[1]; // luong cua leader

        default:
            return workingTime * this->basicSalary * this->coefficientsSalary[0]; // luong cua nhan vien (member)
        }
    }
};

class Employee : public Salary // lop nhan vien ke thua lop luong
{
private:
    int code, workingTime, position, department; // code(ma nhan vien), workingTime(so gio lam viec), position(chuc vu), department(phong ban)
    string name, gender, email, numberPone, birthday;
    float bonus; // tien thuong

public:
    Employee(int code, string name, string gender, int workingTime, string email, string numberPone, string birthday, int position, int department, float bonus) // truyen tham so ham khoi tao object
    {
        this->code = code;     // gan gia tri code cua class = code truyen vao tu tham so
        this->name = name;     // gan gia tri name cua class = name truyen vao tu tham so
        this->gender = gender; // gan gia tri gender cua class = gender truyen vao tu tham so
        this->workingTime = workingTime;
        this->email = email;
        this->numberPone = numberPone;
        this->birthday = birthday;
        this->position = position;
        this->department = department;
        this->bonus = bonus;
    }

    int getCode() // lay ra gia tri code cua nhan vien (vi code minh dang de la private)
    {
        return this->code;
    }

    string getName() // lay ra gia tri name cua nhan vien (vi name minh dang de la private)
    {
        return this->name;
    }

    string getGender() // lay ra gia tri gender cua nhan vien (vi gender minh dang de la private)
    {
        return this->gender;
    }

    string getEmail() // lay ra gia tri email cua nhan vien (vi email minh dang de la private)
    {
        return this->email;
    }

    string getNumberPhone() // lay ra gia tri numberphone cua nhan vien (vi phone minh dang de la private)
    {
        return this->numberPone;
    }

    string getBirthday() // lay ra gia tri birthday cua nhan vien (vi birthday minh dang de la private)
    {
        return this->birthday;
    }

    int getWorkingTime() // lay ra gia tri workingtime cua nhan vien (vi workingTime minh dang de la private)
    {
        return this->workingTime;
    }

    float getBonus() // lay ra gia tri bonus cua nhan vien (vi bonus minh dang de la private)
    {
        return this->bonus;
    }

    string getDepartment()
    {
        return Department::getDepartments(this->department); // goi den ham static trong class Department lay ra ten bo phan
    }

    string getPosition() // lay ra ten chuc vu dua vao position (3-manager / 2-leader / 1-member)
    {
        switch (this->position)
        {
        case 3:
            return "manager";
        case 2:
            return "leader";
        default:
            return "member";
        }
    }

    friend float getTotalSalary(Employee employee); // ham ban lay ra tong luong
};

float getTotalSalary(Employee employee)
{
    return employee.totalSalary(employee.workingTime, employee.position) + employee.bonus; // luong + thuong
}

vector<Employee> e; // vector duoc hieu nhu mang dong

class Admin
{

public:
    Admin()
    {
        this->seederEmployee();
    }
    void add()
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- Add Employee Details ---------------------------------------------"
             << endl;

        Employee employee = createEmployee(rand()); // goi den ham createEmployee de khoi tao 1 doi tuong employee
        e.push_back(employee);                      // them employee vao vector
        this->show();                               // goi den ham show ra list table employee
    }

    void show()
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- List Employee ---------------------------------------------"
             << endl;

        this->titleTable();                // goi den ham show title cua bang danh sach employee
        for (int i = 0; i < e.size(); i++) // show du lieu cua danh sach employee
        {
            this->dataTable(i); // goi den ham show du lieu danh sach employee
        }
    }

    void update() // ham update 1 employee
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- Update Employee Details ---------------------------------------------"
             << endl;
        if (e.size() <= 0) // check xem co du lieu employee hay chua e.size() check do dai mang dong
        {
            cout << "\t\t\t\t\t\tNo Data" << endl;

            return;
        }

        int code; // khai bao bien ma nhan vien
        cout << "Enter code of employee which you want to update: ";
        cin >> code;                       // nhap ma nhan vien ban can update du lieu
        for (int i = 0; i < e.size(); i++) // lap tu phan tu dau tien den do dai cua vector // e.size() lay ra do dai cua vector
        {
            if (e[i].getCode() == code) // check xem ma nhan vien vua nhap co ton tai khong - neu ton tai thi ban dau thuc hien sua
            {
                e[i] = createEmployee(code); // gan du lieu nhan vien vua nhap

                this->show(); // goi den ham lay ra danh sach nhan vien
                break;        // thoat khoi vong lap for
            }
            else
            {
                cout << "No employee any code has been: " << code;
            }
        }

        return;
    }

    void deleted() // ham xoa nhan vien
    {
        int code; // khai bao bien ma nhan vien can xoa
        cout << "Enter code of employee which you want to deleted: ";
        cin >> code; // nhap ma nhan vien can xoa

        for (int i = 0; i < e.size(); i++)
        {
            if (e[i].getCode() == code)
            {
                e.erase(e.begin() + i); // ham xoa tai item cua vector tai vi tri i

                break; // thoat ra khoi vong lap for
            }
            else
            {
                cout << "No employee any code has been: " << code;
            }
        }

        this->show();
    }

    void search() // ham tim kiem
    {
        int code;     // khai bao bien ma nhan vien
        string name;  // khai bao bien ten nhan vien
        int switcher; // khai bao bien option chon search theo ma nhan vien (1) hoac theo ten
        int i = 0;
        cout << "Choose Options: 1-Search with code, 2-search with name: ";
        cin >> switcher;

        if (switcher == 1) // truong hop chon search theo ma nhan vien
        {
            cout << "Enter employee code: ";
            cin >> code; // khai bao bien dau vao ma nhan vien

            // title search
            cout << "\n-------------------------------------------------------------------------------------------------------"
                 << endl;
            cout << "------------------------------------- List Employee Search Code----------------------------------------------"
                 << endl;

            // table search
            this->titleTable();
            for (i; i < e.size(); i++) // duyet vong for
            {
                if (e[i].getCode() == code) // check code trung voi code nhap vao de tim kiem
                {
                    this->dataTable(i); // show data vua tiem kiem
                }

                break;
            }
        }
        else if (switcher == 2) // voi truong hop chon search ten
        {
            cout << "Enter employee name: ";
            cin >> name; // nhap ten van tim kiem

            // table search
            this->titleTable();

            for (i; i < e.size(); i++)
            {
                if (e[i].getName() == name) // check nhung nhan vien co ten bang voi ten vua nhap
                {
                    this->dataTable(i); // show ra danh sach nhung nhan vien vua tim kiem theo ten
                }
            }
        }
        else
        {
            cout << "Please enter 1/2";
        }
    }

    void titleTable() // ten cot cua danh sach nhan vien
    {
        cout << left << setw(5) << "No:" << left << setw(15) << "Code" << left //  setw- dung de thay doi do rong du lieu xuat ra // muc dich de can chinh table cho dep
             << setw(10) << "Name" << left << setw(10) << "Gender" << setw(20) << "WorkingTime"
             << setw(20) << "Email" << setw(20) << "Phone" << setw(15) << "Birthday" << setw(15) << "Position"
             << setw(15) << "Department" << setw(10) << "Bonus"
             << setw(15) << "TotalSalary" << endl;
    }

    void dataTable(int i) // show ra du lieu danh sach nhan vien
    {
        cout << left << setw(5) << i + 1                  // so thu tu i bat dau chay tu 0 nen de i+1
             << left << setw(15) << e[i].getCode()        // show ra ma nhan vien
             << left << setw(10) << e[i].getName()        // show ra ten nhan vien
             << left << setw(10) << e[i].getGender()      // show ra gioi tinh nhan vien
             << left << setw(20) << e[i].getWorkingTime() // show ra thoi gian nhan vien di lam
             << left << setw(20) << e[i].getEmail()       // show ra email nhan vien
             << left << setw(20) << e[i].getNumberPhone() // show ra sdt nhan vien
             << left << setw(15) << e[i].getBirthday()    // show ra sinh nhat nhan vien
             << left << setw(15) << e[i].getPosition()    // show ra chuc vu nhan vien
             << left << setw(15) << e[i].getDepartment()  // show phong ban cua nhan vien
             << left << setw(15) << e[i].getBonus()       // show ra tien thuong
             << left << setw(15) << getTotalSalary(e[i])  // show ra tong luong cua nhan vien // goi den ham ban getTotalSalary
             << endl;
    }

    Employee createEmployee(int code) // function tra ve 1 doi tuong employee duoc khoi ta nhan vao bien code
    {
        int workingTime, position, department;            // khai bai thoi gian lam viec , chuc vu , phong ban
        string name, gender, email, numberPone, birthday; // khai bao ten gioi tinh, ....
        float bonus;                                      // khai bao tien thuong

        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee gender: ";
        cin >> gender;
        cout << "Enter employee workingTime: ";
        cin >> workingTime;
        cout << "Enter employee email: ";
        cin >> email;
        cout << "Enter employee numberPone: ";
        cin >> numberPone;
        cout << "Enter employee birthday: ";
        cin >> birthday;
        cout
            << "Enter employee position(1-member/2-leader/3-manager): ";
        cin >> position;
        cout
            << "Enter employee department(1-marketing/2-sale/3-IT): ";
        cin >> department;
        cout
            << "Enter employee bonus: ";
        cin >> bonus;

        Employee employee(code, name, gender, workingTime, email, numberPone, birthday, position, department, bonus); // khoi tao 1 doi tuong nhan vien

        return employee;
    }

    void seederEmployee() // ham tao ra 3 doi tuong nhan vien mau
    {
        for (int i = 0; i < 3; i++)
        {
            Employee employee(rand(), "user", "boy", 18, "user@gmail.com", "0929045888", "15/06/2000", 1, 1, 1.2);
            e.push_back(employee);
        }
    }

    void menu()
    {
    menustart:
        int choice;
        system("cls");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| EMPLOYEE MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Add Employee" << endl;
        cout << "\t\t\t 2. Show Employee" << endl;
        cout << "\t\t\t 3. Update Employee" << endl;
        cout << "\t\t\t 4. Search Employee" << endl;
        cout << "\t\t\t 5. Delete Employee" << endl;
        cout << "\t\t\t 6. Exit\n"
             << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
        cout << "\t\t\t............................" << endl;
        cout << " Enter Your Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            this->add();
            break;
        case 2:
            this->show();
            break;
        case 3:
            this->update();
            break;
        case 4:
            this->search();
            break;
        case 5:
            this->deleted();
            break;
        case 6:
            cout << "\n\t\t\t Program Is Exit";
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
        }
        getch();
        goto menustart;
    }
};

int main()
{
    Auth auth;        // khoi tao object auth
    Auth *au = &auth; // gan con tro class
    au->login();      // tro den ham login

    Admin admin;
    admin.menu();

    return 0;
}
