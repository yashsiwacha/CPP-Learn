// Phone Directory - dynamic contact management using pointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
typedef struct Contact
{
    char name[50];
    char phone_number[20];
} Contact;

// Function to add a new contact to the dynamic array
// Reallocates memory to accommodate new contact
Contact *addContact(Contact *contacts_array, int *current_size, const Contact *new_contact)
{
    // Allocate new array with space for one more contact
    Contact *new_array = (Contact *)malloc((*current_size + 1) * sizeof(Contact));

    if (new_array == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return contacts_array; // Return old array unchanged
    }

    // Copy existing contacts to new array
    for (int i = 0; i < *current_size; i++)
    {
        new_array[i] = contacts_array[i];
    }

    // Add new contact at the end
    new_array[*current_size] = *new_contact;
    (*current_size)++; // Increment size

    // Free old array memory
    if (contacts_array != NULL)
    {
        free(contacts_array);
    }

    return new_array; // Return pointer to new array
}

// Function to display all contacts in the directory
void displayContacts(const Contact *contacts_array, int size)
{
    if (size == 0)
    {
        printf("No contacts in directory.\n");
        return;
    }

    printf("\n=== Phone Directory (%d contacts) ===\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d. Name: %s | Phone: %s\n", i + 1,
               contacts_array[i].name,
               contacts_array[i].phone_number);
    }
    printf("=====================================\n");
}

// Function to search for a contact by name
Contact *findContact(Contact *contacts_array, int size, const char *name)
{
    // Linear search through array
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
        printf("Memory freed successfully.\n");
    }
}

int main()
{
    Contact *directory = NULL;
    int num_contacts = 0;
    int choice;

    printf("=== Dynamic Phone Directory ===\n");

    do
    {
        printf("\n1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n')
                ; // Clear buffer
            continue;
        }
        while (getchar() != '\n')
            ; // Clear buffer

        switch (choice)
        {
        case 1:
        {
            Contact new_contact;
            printf("Enter name (max 49 chars): ");
            if (fgets(new_contact.name, sizeof(new_contact.name), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

            // Validate name is not empty
            if (strlen(new_contact.name) == 0)
            {
                printf("Error: Name cannot be empty\n");
                break;
            }

            printf("Enter phone number (max 19 chars): ");
            if (fgets(new_contact.phone_number, sizeof(new_contact.phone_number), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = '\0';

            // Validate phone is not empty
            if (strlen(new_contact.phone_number) == 0)
            {
                printf("Error: Phone number cannot be empty\n");
                break;
            }

            directory = addContact(directory, &num_contacts, &new_contact);
            printf("Contact added successfully!\n");
            break;
        }

        case 2:
            displayContacts(directory, num_contacts);
            break;

        case 3:
        {
            char search_name[50];
            printf("Enter name to search: ");
            if (fgets(search_name, sizeof(search_name), stdin) == NULL)
            {
                printf("Error reading input\n");
                break;
            }
            search_name[strcspn(search_name, "\n")] = '\0';

            Contact *found = findContact(directory, num_contacts, search_name);
            if (found != NULL)
            {
                printf("Found: %s | Phone: %s\n",
                       found->name,
                       found->phone_number);
            }
            else
            {
                printf("Contact not found.\n");
            }
            break;
        }

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    // Free allocated memory using cleanup function
    cleanupContacts(&directory, &num_contacts);
    printf("Goodbye!\n");

    return 0;
}