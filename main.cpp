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
            return "marketing"; //phong marketing
        case 2:
            return "sale"; // phong sale
        case 3:
            return "IT";    // phong cntt
        default:
            return "";
        }
    }
};

class Salary
{
private:
    int coefficientsSalary[3];
    float basicSalary;

public:
    Salary()
    {
        this->coefficientsSalary[0] = 1;
        this->coefficientsSalary[1] = 2;
        this->coefficientsSalary[2] = 3;
        this->basicSalary = 1000;
    }
    float totalSalary(int workingTime, int position)
    {
        switch (position)
        {
        case 3:
            return workingTime * this->basicSalary * this->coefficientsSalary[2];

        case 2:
            return workingTime * this->basicSalary * this->coefficientsSalary[1];

        default:
            return workingTime * this->basicSalary * this->coefficientsSalary[0];
        }
    }
};

class Employee : public Salary
{
private:
    int code, workingTime, position, department;
    string name, gender, email, numberPone, birthday;
    float bonus; // tien thuong

public:
    Employee(int code, string name, string gender, int workingTime, string email, string numberPone, string birthday, int position, int department, float bonus)
    {
        this->code = code;
        this->name = name;
        this->gender = gender;
        this->workingTime = workingTime;
        this->email = email;
        this->numberPone = numberPone;
        this->birthday = birthday;
        this->position = position;
        this->department = department;
        this->bonus = bonus;
    }

    int getCode()
    {
        return this->code;
    }

    string getName()
    {
        return this->name;
    }

    string getGender()
    {
        return this->gender;
    }

    string getEmail()
    {
        return this->email;
    }

    string getNumberPhone()
    {
        return this->numberPone;
    }

    string getBirthday()
    {
        return this->birthday;
    }

    int getWorkingTime()
    {
        return this->workingTime;
    }
    
    float getBonus()
    {
    	return this->bonus;
	}

    string getDepartment()
    {
        return Department::getDepartments(this->department);
    }

    string getPosition()
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

    friend float getTotalSalary(Employee employee);
};

float getTotalSalary(Employee employee)
{
    return employee.totalSalary(employee.workingTime, employee.position) + employee.bonus;
}

vector<Employee> e;

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

        Employee employee = createEmployee(rand());
        e.push_back(employee);
        this->show();
    }

    void show()
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- List Employee ---------------------------------------------"
             << endl;

        this->titleTable();
        for (int i = 0; i < e.size(); i++)
        {
            this->dataTable(i);
        }
    }

    void update()
    {
        cout << "\n-------------------------------------------------------------------------------------------------------"
             << endl;
        cout << "------------------------------------- Update Employee Details ---------------------------------------------"
             << endl;
        if (e.size() <= 0)
        {
            cout << "\t\t\t\t\t\tNo Data" << endl;

            return;
        }

        int code;
        cout << "Enter code of employee which you want to update: ";
        cin >> code;
        for (int i = 0; i < e.size(); i++)
        {
            if (e[i].getCode() == code)
            {
                e[i] = createEmployee(code);

                this->show();
                break;
            }
            else
            {
                cout << "No employee any code has been: " << code;
            }
        }

        return;
    }

    void deleted()
    {
        int code;
        cout << "Enter code of employee which you want to deleted: ";
        cin >> code;

        for (int i = 0; i < e.size(); i++)
        {
            if (e[i].getCode() == code)
            {
                e.erase(e.begin() + i);

                break;
            }
            else
            {
                cout << "No employee any code has been: " << code;
            }
        }

        this->show();
    }

    void search()
    {
        int code;
        string name;
        int switcher;
        int i = 0;
        cout << "Choose Options: 1-Search with code, 2-search with name: ";
        cin >> switcher;

        if (switcher == 1)
        {
            cout << "Enter employee code: ";
            cin >> code;

            // title search
            cout << "\n-------------------------------------------------------------------------------------------------------"
                 << endl;
            cout << "------------------------------------- List Employee Search Code----------------------------------------------"
                 << endl;

            // table search
            this->titleTable();
            for (i; i < e.size(); i++)
            {
                if (e[i].getCode() == code)
                {
                    this->dataTable(i);
                }

                break;
            }
        }
        else if (switcher == 2)
        {
            cout << "Enter employee name: ";
            cin >> name;

            // table search
            this->titleTable();

            for (i; i < e.size(); i++)
            {
                if (e[i].getName() == name)
                {
                    this->dataTable(i);
                }
            }
        }
        else
        {
            cout << "Please enter 1/2";
        }
    }

    void titleTable()
    {
        cout << left << setw(5) << "No:" << left << setw(15) << "Code" << left
             << setw(10) << "Name" << left << setw(10) << "Gender" << setw(20) << "WorkingTime"
             << setw(20) << "Email" << setw(20) << "Phone" << setw(15) << "Birthday" << setw(15) << "Position"
             << setw(15) << "Department" << setw(10) << "Bonus"
             << setw(15) << "TotalSalary" << endl;
    }

    void dataTable(int i)
    {
        cout << left << setw(5) << i + 1
             << left << setw(15) << e[i].getCode()
             << left << setw(10) << e[i].getName()
             << left << setw(10) << e[i].getGender()
             << left << setw(20) << e[i].getWorkingTime()
             << left << setw(20) << e[i].getEmail()
             << left << setw(20) << e[i].getNumberPhone()
             << left << setw(15) << e[i].getBirthday()
             << left << setw(15) << e[i].getPosition()
             << left << setw(15) << e[i].getDepartment()
             << left << setw(15) << e[i].getBonus()
             << left << setw(15) << getTotalSalary(e[i])
             << endl;
    }

    Employee createEmployee(int code)
    {
        int workingTime, position, department;
        string name, gender, email, numberPone, birthday;
        float bonus;

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

        Employee employee(code, name, gender, workingTime, email, numberPone, birthday, position, department, bonus);

        return employee;
    }

    void seederEmployee()
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
            add();
            break;
        case 2:
            show();
            break;
        case 3:
            update();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
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
    Auth auth;
    Auth *au = &auth;
    au->login();

    Admin admin;
    admin.menu();

    return 0;
}
