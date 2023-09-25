#include "header.h"

int getIdFromUser()
{
    int id;
    printf("\nEnter the employee id: ");
    scanf("%d", &id);
    return id;
}

Employee employeeInput(int id)
{
    Employee emp;
    emp.id = id;
    printf("\nEnter first name: ");
    scanf("%s", emp.firstName);
    printf("Enter last name: ");
    scanf("%s", emp.lastName);
    int dd, mm, yyyy;
    printf("Enter hire date(dd mm yyyy): ");
    scanf("%d%d%d", &dd, &mm, &yyyy);
    while (!isDateValid(dd, mm, yyyy))
    {
        printf("\nPlease enter valid date(dd mm yyyy) : ");
        scanf("%d%d%d", &dd, &mm, &yyyy);
    }
    emp.Date.dd = dd;
    emp.Date.mm = mm;
    emp.Date.yyyy = yyyy;
    float sal;
    printf("Enter the basic salary: ");
    scanf("%f", &sal);
    while (!isSalaryValid(sal))
    {
        printf("Enter the valid basic salary: ");
        scanf("%f", &sal);
    }
    emp.basicSal = sal;
    return emp;
}

int addEmployee(Employee empArr[], int top, int size, int id)
{
    if (top < size)
    {
        Employee emp = employeeInput(id);
        empArr[top] = emp;
        return 1;
    }
    return 0;
}

Employee deleteEmployee(Employee empArr[], int top, int id)
{
    Employee e;
    for (int i = 0; i < top; i++)
    {
        Employee emp = empArr[i];
        if (emp.id == id)
        {
            for (; i < top - 1; i++)
            {
                empArr[i] = empArr[i + 1];
            }
            return emp;
        }
    }
    e.id = -1;
    return e;
}

void displayEmployee(Employee empArr[], int top, int id)
{
    for (int i = 0; i < top; i++)
    {
        Employee emp = empArr[i];
        if (emp.id == id)
        {
            printf("\n--------------------------------------------------------------\n");
            printf("Employee Details are: \n");
            printf("Id = %d\nFirst Name = %s\nLast Name = %s\nBasic Salary = %.2f\n Hire Date = %d/%d/%d\n", emp.id, emp.firstName, emp.lastName, emp.basicSal, emp.Date.dd, emp.Date.mm, emp.Date.yyyy);
            printf("--------------------------------------------------------------\n\n");
            return;
        }
    }
    printf("\nEmployee Not Found!!!\n\n");
}

void displayAllEmployees(Employee empArr[], int top)
{
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nAll Employee Details are: \n");
    for (int i = 0; i < top; i++)
    {
        Employee emp = empArr[i];
        printf("S.No = %d  Id = %d  First Name = %s  Last Name = %s  Basic Salary = %.2f  Hire Date = %d/%d/%d\n", i + 1, emp.id, emp.firstName, emp.lastName, emp.basicSal, emp.Date.dd, emp.Date.mm, emp.Date.yyyy);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

float netPay(Employee empArr[], int top, int id)
{
    for (int i = 0; i < top; i++)
    {
        float TA, DA, PF, grossPay;
        Employee emp = empArr[i];
        if (id == emp.id)
        {
            DA = (40 * emp.basicSal) / 100;
            TA = (10 * emp.basicSal) / 100;
            PF = (5 * emp.basicSal) / 100;
            grossPay = emp.basicSal + DA + TA - PF;
            return grossPay;
        }
    }
    return -1;
}

void updateEmployee(Employee empArr[], int top, int id)
{
    for (int i = 0; i < top; i++)
    {
        Employee emp = empArr[i];
        if (emp.id == id)
        {
            printf("\nEnter First Name: ");
            scanf("%s", emp.firstName);
            printf("Enter Last Name: ");
            scanf("%s", emp.lastName);
            printf("Enter Basic Salary: ");
            float sal;
            scanf("%f", &sal);
            while (!isSalaryValid(sal))
            {
                printf("Enter the valid basic salary: ");
                scanf("%f", &sal);
            }
            emp.basicSal = sal;
            empArr[i] = emp;
            printf("Details Updated Successfully!!\n\n");
            displayEmployee(empArr, top, id);
            return;
        }
    }
    printf("Employee Not Found!!!!\n\n");
}

int isDateValid(int dd, int mm, int yyyy)
{
    if (dd <= 0 || dd > 31 || mm <= 0 || mm > 12 || yyyy <= 1990 || yyyy > 2023)
        return 0;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = isYearLeap(yyyy);
    if (res)
    {
        if (mm == 2 && dd <= 29)
            return 1;
        else if (dd <= daysInMonth[mm - 1])
            return 1;
    }
    else
    {
        if (dd <= daysInMonth[mm - 1])
            return 1;
    }
    return 0;
}

int isYearLeap(int yyyy)
{
    if (yyyy % 400 == 0 || ((yyyy % 4 == 0) && (yyyy % 100 != 0)))
        return 1;
    return 0;
}

int isSalaryValid(float sal)
{
    if (sal <= 0)
        return 0;
    return 1;
}