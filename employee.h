#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100

// Employee structure
struct Employee
{
    char name[MAX_NAME_LENGTH];
    char gender;
    int age;
    char job[MAX_JOB_LENGTH];
    struct Employee *next;    
};


// Function to add a new employee to the database
void addEmployee(struct Employee **head, char *name, char gender, int age, char *jobDescription);

// Function to modify employee data in the database
void modifyEmployee(struct Employee *head, char *name, char gender, int age, char *jobDescription);

// Function to delete an employee from the database based on name
void deleteEmployee(struct Employee **head, char *name, int age, char gender);

// Function to print the details of all employees
void printEmployees(struct Employee* head);

