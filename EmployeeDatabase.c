#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

// Global variable to keep track of the number of employees
int numEmployees = 0;

// Function to create a new employee node
struct Employee *createEmployee(char *name, char gender, int age, char *job)
{
  struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
  if (newEmployee == NULL)
  {
    
    printf("Memory allocation failed.\n");
    exit(1);
  }
  strcpy(newEmployee->name, name);
  newEmployee->gender = gender;
  newEmployee->age = age;
  strcpy(newEmployee->job, job);
  newEmployee->next = NULL;
  return newEmployee;
}

// Function to add a new employee at the end of the list
void addEmployee(struct Employee **head, char *name, char gender, int age, char *job)
{
  struct Employee *newEmployee = createEmployee(name, gender, age, job);

  if (*head == NULL)
  {
    *head = newEmployee;
  }
  else
  {
    struct Employee *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newEmployee;
  }
  printf("\n");
  printf("Employee added successfully.\n");
}

// Function to delete an employee based on the given criteria (name, age, gender)
void deleteEmployee(struct Employee **head, char *name, int age, char gender)
{
  printf("\n");
  if (*head == NULL)
  {
    printf("Employee database is empty.\n");
    return;
  }

  struct Employee *current = *head;
  struct Employee *prev = NULL;
  while (current != NULL)
  {
    if ((strcmp(current->name, name) == 0) && (current->age == age) && (current->gender == gender))
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

// Function to print the details of all employees in the database
void printEmployees(struct Employee *head)
{
  printf("\n");
  if (head == NULL)
  {
    printf("No employees found in the database.\n");
    return;
  }

  printf("Employee Database:\n");
  struct Employee *current = head;
  while (current != NULL)
  {
    printf("Name: %s\n", current->name);
    printf("Gender: %c\n", current->gender);
    printf("Age: %d\n", current->age);
    printf("Job: %s\n", current->job);
    printf("--------------------\n");
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
  char gender;
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
      printf("\n");
      printf("You pressed: %c\n", choice);
      printf("Enter employee details:\n");
      printf("Name: ");
      scanf(" %[^\n]s", name);
      printf("Gender: ");
      scanf(" %c", &gender);
      printf("Age: ");
      scanf("%d", &age);
      printf("Job: ");
      scanf(" %[^\n]s", job);
      addEmployee(&head, name, gender, age, job);
      break;
    case '2':

      break;
    case '3':
      printf("\n");
      printf("You pressed: %c\n", choice);
      printf("Enter employee details to delete:\n");
      printf("Name: ");
      scanf(" %[^\n]s", name);
      printf("Gender: ");
      scanf(" %c", &gender);
      printf("Age: ");
      scanf("%d", &age);
      deleteEmployee(&head, name, age, gender);
      break;
    case '4':
      printf("\n");
      printf("You pressed: %c\n", choice);
      printEmployees(head);
      break;
    case 'q':
      printf("\n");
      printf("You pressed: %c\n", choice);
      freeEmployeeList(head);
      printf("Exiting...\n");
      exit(0);
    default:
      printf("\n");
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
