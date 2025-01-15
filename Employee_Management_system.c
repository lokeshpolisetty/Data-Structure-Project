#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee {
    char Name[50];
    char Workplatform[50];
    int employeeid;
    char schedule[50];
    int days;
    int income;
    struct Employee* next;
};

struct Employee* head = NULL;

void create(int size) {
    struct Employee* ptr;
    for (int i = 1; i <= size; i++) {
        struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
        if (newNode == NULL) {
            printf("Memory allocation failed.");
            exit(1);
        }

        if (i == 1) {
            head = newNode;
            ptr = head;
        } else {
            ptr->next = newNode;
            ptr = ptr->next;
        }

        printf("Enter Employee %d Data into Database\n", i);
        printf("Name:\t");
        scanf("%s", ptr->Name);
        printf("WorkingPlatform:\t");
        scanf("%s", ptr->Workplatform);
        printf("Employee I'd No:\t");
        scanf("%d", &ptr->employeeid);
        printf("Working schedule\t");
        scanf("%s", ptr->schedule);
        printf("Enter No.of days in a month:\t");
        scanf("%d", &ptr->days);
        printf("Enter per day income:\t");
        scanf("%d", &ptr->income);
    }
    ptr->next = NULL;
}

void addEmployee() {
    struct Employee* newnode = (struct Employee*)malloc(sizeof(struct Employee));
    if (newnode == NULL) {
        printf("Memory allocation failed.");
        return;
    }

    printf("Name:\t");
    scanf("%s", newnode->Name);
    printf("WorkingPlatform:\t");
    scanf("%s", newnode->Workplatform);
    printf("Employee I'd No:\t");
    scanf("%d", &newnode->employeeid);
    printf("Working schedule\t");
    scanf("%s", newnode->schedule);
    printf("Enter No.of days in a month\t");
    scanf("%d", &newnode->days);
    printf("Enter per day income\t");
    scanf("%d", &newnode->income);

    newnode->next = head;
    head = newnode;
}

void deleteEmployee() {
    int key;
    printf("Enter employee ID to Delete\n");
    scanf("%d", &key);

    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    struct Employee* curr = head;
    struct Employee* prev = NULL;

    while (curr != NULL && curr->employeeid != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Employee not found in the database.\n");
        return;
    }

    if (prev == NULL) {
        head = head->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void display() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    struct Employee* ptr = head;

    while (ptr != NULL) {
        int monthlySalary = ptr->days * ptr->income;
        printf("--------------------\n");
        printf("Employee Data\n");
        printf("Name: %s\n", ptr->Name);
        printf("Working Platform: %s\n", ptr->Workplatform);
        printf("Employee ID: %d\n", ptr->employeeid);
        printf("Working Schedule: %s\n", ptr->schedule);
        printf("Days in Month: %d\n", ptr->days);
        printf("Per Day Income: %d\n", ptr->income);
        printf("Monthly Salary: %d\n", monthlySalary);
        printf("--------------------\n");

        ptr = ptr->next;
    }
}

void search() {
    int key, found = 0;
    printf("Enter an employee ID to search: ");
    scanf("%d", &key);

    struct Employee* ptr = head;

    while (ptr != NULL) {
        if (ptr->employeeid == key) {
            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (found)
     {
        int monthlySalary = ptr->days * ptr->income;
        printf("--------------------\n");
        printf("Employee Data\n");
        printf("Name: %s\n", ptr->Name);
        printf("Working Platform: %s\n", ptr->Workplatform);
        printf("Employee ID: %d\n", ptr->employeeid);
        printf("Working Schedule: %s\n", ptr->schedule);
        printf("Days in Month: %d\n", ptr->days);
        printf("Per Day Income: %d\n", ptr->income);
        printf("Monthly Salary: %d\n", monthlySalary);
        printf("--------------------\n");
    } 
    else
    {
        printf("Employee not found in the database.\n");
    }
}

int computeSalary(int employeeID) {
    struct Employee* ptr = head;
    int days = 0, income = 0, found = 0;

    while (ptr != NULL) {
        if (ptr->employeeid == employeeID) {
            days = ptr->days;
            income = ptr->income;
            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (found) {
        return days * income;
    } else {
        return -1; // Indicate employee not found
    }
}

int main() {
    int size, choice, key;

    printf("Enter Size: ");
    scanf("%d", &size);

    printf("1. Create database\n");
    printf("2. Display the Data from database\n");
    printf("3. Insert Employee Data\n");
    printf("4. Delete Employee Data\n");
    printf("5. Search an Employee in the database\n");
    printf("6. Calculate the salary of an Employee\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nSelect choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(size);
                break;
            case 2:
                display();
                break;
            case 3:
                addEmployee();
                break;
            case 4:
                deleteEmployee();
                printf("Employee Data Deleted\n");
                break;
            case 5:
                search();
                break;
            case 6:
                printf("Enter Employee ID to compute monthly salary: ");
                scanf("%d", &key);
                int salary = computeSalary(key);
                if (salary != -1) {
                    printf("Monthly salary for Employee ID %d: %d\n", key, salary);
                } else {
                    printf("Employee with ID %d not found in the database.\n", key);
                }
                break;
            case 7:
                printf("Exiting...");
                return 0;
            default:
               

 printf("Invalid choice\n");
        }
    }
    return 0;
}