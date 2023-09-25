#include "functions.c"
#include <stdio.h>
#define size 100


int main()
{
    int autoId = 100;
    int choice = 1;
    int res, id;
    float netPayment;
    Employee empArr[size];
    int top = 0;
    do
    {
        printf("Press 1 to add an employee\n");
        printf("Press 2 to delete an employee\n");
        printf("Press 3 to display an employee\n");
        printf("Press 4 to display all employee\n");
        printf("Press 5 to update employee details\n");
        printf("Press 6 to get employee net pay\n");
        printf("Press 7 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            res = addEmployee(empArr, top, size, autoId);
            if (res)
            {
                top++;
                printf("\n\nEmployee added successfully!!\n\n");
                printf("Your auto generated employee id is = %d\n\n",autoId);
                autoId++;
            }
            else
            {
                printf("Unable to add employee!!!!\n\n");
            }
            break;
        case 2:
            id = getIdFromUser();
            Employee e = deleteEmployee(empArr, top, id);
            if (e.id != id)
            {
                printf("Employee not found!!!!\n\n");
            }
            else
            {
                printf("\n\nEmployee with id = %d deleted successfully!!\n", id);
                printf("id = %d First Name = %s Last Name = %s Hire Date = %d/%d/%d Basic Salary = %.2f\n\n", e.id, e.firstName, e.lastName, e.Date.dd, e.Date.mm, e.Date.yyyy, e.basicSal);
                top--;
                if (top < 0)
                    top = 0;
            }
            break;
        case 3:
            id = getIdFromUser();
            displayEmployee(empArr, top, id);
            break;
        case 4:
            displayAllEmployees(empArr, top);
            break;
        case 5:
            id = getIdFromUser();
            updateEmployee(empArr, top, id);
            break;
        case 6:
            id = getIdFromUser();
            netPayment = netPay(empArr,top,id);
            if((int)netPayment!=-1){
                printf("The net pay of employee with id = %d is = %.2f\n\n",id,netPayment);
            }
            else{
                printf("Employee not found!!!!\n\n");
            }
            break;
        case 7:
            break;
        default:
            printf("Wrong Input!!!! Try again\n\n");
            break;
        }
    } while (choice != 7);
    return 0;
}