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
