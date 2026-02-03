// Phone directory with dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
    char name[50];
    char phone_number[20];
} Contact;

Contact *addContact(Contact *contacts_array, int *current_size, const Contact *new_contact)
{
    Contact *new_array = (Contact *)malloc((*current_size + 1) * sizeof(Contact));

    if (new_array == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return contacts_array;
    }

    for (int i = 0; i < *current_size; i++)
    {
        new_array[i] = contacts_array[i];
    }

    new_array[*current_size] = *new_contact;
    (*current_size)++;

    if (contacts_array != NULL)
    {
        free(contacts_array);
    }

    return new_array;
}

void displayContacts(const Contact *contacts_array, int size)
{
    if (size == 0)
    {
        printf("No contacts\n");
        return;
    }

    printf("\nPhone Directory (%d contacts):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s | %s\n", i + 1,
               contacts_array[i].name,
               contacts_array[i].phone_number);
    }
}

Contact *findContact(Contact *contacts_array, int size, const char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(contacts_array[i].name, name) == 0)
        {
            return &contacts_array[i];
        }
    }
    return NULL;
}

void cleanupContacts(Contact **contacts_array, int *size)
{
    if (*contacts_array != NULL)
    {
        free(*contacts_array);
        *contacts_array = NULL;
        *size = 0;
    }
}

int main()
{
    Contact *directory = NULL;
    int num_contacts = 0;
    int choice;

    do
    {
        printf("\n1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
        {
            Contact new_contact;
            printf("Name: ");
            if (fgets(new_contact.name, sizeof(new_contact.name), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

            if (strlen(new_contact.name) == 0)
            {
                printf("Error: Name cannot be empty\n");
                break;
            }

            printf("Phone: ");
            if (fgets(new_contact.phone_number, sizeof(new_contact.phone_number), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = '\0';

            if (strlen(new_contact.phone_number) == 0)
            {
                printf("Error: Phone cannot be empty\n");
                break;
            }

            directory = addContact(directory, &num_contacts, &new_contact);
            printf("Contact added\n");
            break;
        }

        case 2:
            displayContacts(directory, num_contacts);
            break;

        case 3:
        {
            char search_name[50];
            printf("Search name: ");
            if (fgets(search_name, sizeof(search_name), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            search_name[strcspn(search_name, "\n")] = '\0';

            Contact *found = findContact(directory, num_contacts, search_name);
            if (found != NULL)
            {
                printf("%s | %s\n", found->name, found->phone_number);
            }
            else
            {
                printf("Not found\n");
            }
            break;
        }

        case 4:
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    cleanupContacts(&directory, &num_contacts);

    return 0;
}