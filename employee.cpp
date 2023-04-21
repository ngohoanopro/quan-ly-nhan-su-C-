#include "employee.hpp"

using namespace std;

float getTotalSalary(Employee employee)
{
    return employee.totalSalary(employee.workingTime, employee.position) + employee.bonus; // luong + thuong
}
