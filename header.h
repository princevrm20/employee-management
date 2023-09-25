#include "header.c"

int getIdFromUser();
Employee employeeInput(int id);
int addEmployee(Employee empArr[],int top,int size,int id);
Employee deleteEmployee(Employee empArr[],int top,int id);
void displayEmployee(Employee empArr[],int top,int id);
void displayAllEmployees(Employee empArr[], int top);
void updateEmployee(Employee empArr[],int top, int id);
float netPay(Employee empArr[],int top, int id);
int isDateValid(int dd, int mm, int yyyy);
int isYearLeap(int yyyy);
int isSalaryValid(float sal);