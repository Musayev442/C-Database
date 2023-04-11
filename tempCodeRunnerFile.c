void modifyEmployee(struct Employee *head, const char *name)
// {
//     if (head == NULL)
//     {
//         printf("Employee database is empty.\n");
//         return;
//     }

//     struct Employee *current = head;
//     int found = 0;
//     while (current != NULL)
//     {
//         if (strcmp(current->name, name) == 0)
//         {
//             printf("Employee found:\n");
//             displayEmployee(current);
//             printf("\n");

//             printf("Enter updated employee details:\n");
//             char newName[MAX_NAME_LENGTH];
//             char newGender;
//             int newAge;
//             char newJob[MAX_JOB_LENGTH];

//             printf("New Name: ");
//             scanf(" %[^\n]s", newName);
//             printf("New Gender: ");
//             scanf(" %c", newGender);
//             printf("New Age: ");
//             scanf("%d", &newAge);
//             printf("New Job: ");
//             scanf(" %[^\n]s", newJob);

//             strcpy(current->name, newName);
//             current->gender = newGender;
//             current->age = newAge;
//             strcpy(current->job, newJob);

//             printf("Employee data updated successfully.\n");
//             found = 1;
//             break;
//         }
//         current = current->next;
//     }

//     if (!found)
//     {
//         printf("Employee not found.\n");
//     }
// }

