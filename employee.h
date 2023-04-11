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

// Function to create a new employee node
struct Employee *createEmployee(char *name, char *gender, int age, char *job);

// Function to search for an employee based on the given criteria (name, age, gender)
struct Employee *searchEmployee(struct Employee *head, char *name, int age, char *gender);
