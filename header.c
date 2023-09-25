#include <stdio.h>

typedef struct Employee
{
    int id;
    char firstName[20];
    char lastName[20];
    struct
    {
        int dd;
        int mm;
        int yyyy;
    } Date;
    float basicSal;
} Employee;

