#include <iostream>
#include <vector>
#include "salary.cpp"
#include "department.cpp"

using namespace std;

class Employee : public Salary // lop nhan vien ke thua lop luong
{
private:
    int code, workingTime, position, department; // code(ma nhan vien), workingTime(so gio lam viec), position(chuc vu), department(phong ban)
    string name, gender, email, numberPhone, birthday;
    float bonus; // tien thuong

public:
    Employee(int code, string name, string gender, int workingTime, string email, string numberPhone, string birthday, int position, int department, float bonus) // truyen tham so ham khoi tao object
    {
        this->code = code;     // gan gia tri code cua class = code truyen vao tu tham so
        this->name = name;     // gan gia tri name cua class = name truyen vao tu tham so
        this->gender = gender; // gan gia tri gender cua class = gender truyen vao tu tham so
        this->workingTime = workingTime;
        this->email = email;
        this->numberPhone = numberPhone;
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
        return this->numberPhone;
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

