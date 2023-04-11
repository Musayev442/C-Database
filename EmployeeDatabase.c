#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100

// Employee structure
struct Employee
{
    char name[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];
    int age;
    char job[MAX_JOB_LENGTH];
    struct Employee *next;
};

// Global variable to keep track of the number of employees
int numEmployees = 0;

// Function to create a new employee node
struct Employee *createEmployee(char *name, char *gender, int age, char *job)
{
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    if (newEmployee == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strncpy(newEmployee->name, name, MAX_NAME_LENGTH - 1);
    strncpy(newEmployee->gender, gender, MAX_NAME_LENGTH - 1);
    newEmployee->age = age;
    strncpy(newEmployee->job, job, MAX_JOB_LENGTH - 1);
    newEmployee->next = NULL;

    numEmployees++;

    return newEmployee;
}

// Function to insert a new employee at the beginning of the list
void insertEmployee(struct Employee **head, struct Employee *newEmployee)
{
    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        newEmployee->next = *head;
        *head = newEmployee;
    }
}

// Function to search for an employee based on the given criteria (name, age, gender)
struct Employee *searchEmployee(struct Employee *head, char *name, int age, char *gender)
{
    struct Employee *current = head;
    // current != NULL
    if ((strcmp(current->name, name) == 0) || (current->age == age) || (strcmp(current->gender, gender) == 0))
    {
        return current;
    }
    current = current->next;
    return NULL;
}

// Function to delete an employee based on the given criteria (name, age, gender)
void deleteEmployee(struct Employee **head, char *name, int age, char *gender)
{
    if (*head == NULL)
    {
        printf("Employee database is empty.\n");
        return;
    }

    struct Employee *current = *head;
    struct Employee *prev = NULL;
    while (current != NULL)
    {
        if ((strcmp(current->name, name) == 0) && (current->age == age) && (strcmp(current->gender, gender) == 0))
        {
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            numEmployees--;
            printf("Employee deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Employee not found.\n");
}

// Function to display the details of an employee
void displayEmployee(struct Employee *employee)
{
    printf("Name: %s\n", employee->name);
    printf("Gender: %s\n", employee->gender);
    printf("Age: %d\n", employee->age);
    printf("Job: %s\n", employee->job);
}

// Function to display the details of all employees in the database
void displayAllEmployees(struct Employee *head)
{
    if (head == NULL)
    {
        printf("Employee database is empty.\n");
        return;
    }
    struct Employee *current = head;
    while (current != NULL)
    {
        printf("Employee %d:\n", numEmployees);
        displayEmployee(current);
        printf("\n");
        current = current->next;
    }
}

// Function to free the memory allocated for the employee database
void freeEmployeeList(struct Employee *head)
{
    struct Employee *current = head;
    while (current != NULL)
    {
        struct Employee *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Employee *head = NULL;
    char choice;
    char name[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];
    int age;
    char job[MAX_JOB_LENGTH];
    while (1)
    {
        printf("Employee Database Management System:\n");
        printf("1. Add new employee\n");
        printf("2. Search employee\n");
        printf("3. Delete employee\n");
        printf("4. Display all employees\n");
        printf("q. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("You pressed: %c\n", choice);
            printf("Enter employee details:\n");
            printf("Name: ");
            scanf(" %[^\n]s", name);
            printf("Gender: ");
            scanf(" %[^\n]s", gender);
            printf("Age: ");
            scanf("%d", &age);
            printf("Job: ");
            scanf(" %[^\n]s", job);
            insertEmployee(&head, createEmployee(name, gender, age, job));
            printf("Employee added successfully.\n");
            break;
        case '2':
            printf("You pressed: %c\n", choice);
            printf("Enter search criteria:\n");
            printf("Name: ");
            scanf(" %[^\n]s", name);
            printf("Gender: ");
            scanf(" %[^\n]s", gender);
            printf("Age: ");
            scanf("%d", &age);
            struct Employee *searchResult = searchEmployee(head, name, age, gender);
            if (searchResult != NULL)
            {
                printf("Employee found:\n");
                displayEmployee(searchResult);
                printf("\n");
            }
            else
            {
                printf("Employee not found.\n");
            }
            break;
        case '3':
            printf("You pressed: %c\n", choice);
            printf("Enter employee details to delete:\n");
            printf("Name: ");
            scanf(" %[^\n]s", name);
            printf("Gender: ");
            scanf(" %[^\n]s", gender);
            printf("Age: ");
            scanf("%d", &age);
            deleteEmployee(&head, name, age, gender);
            break;
        case '4':
            printf("You pressed: %c\n", choice);
            printf("Employee database:\n");
            displayAllEmployees(head);
            break;
        case 'q':
            printf("You pressed: %c\n", choice);
            printf("Exiting...\n");
            freeEmployeeList(head);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
