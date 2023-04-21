#include <iostream>

using namespace std;

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
