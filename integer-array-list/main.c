#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayList ArrayList;

// ArrayList architecture
typedef struct ArrayList
{
    int size, cap;
    int * arr;
} ArrayList;

// Prototypes
ArrayList * createArrayList();
void printArrayList(ArrayList *);
void printArrayListData(ArrayList *);
void append(ArrayList *, int);
void expand(ArrayList *);
void get(ArrayList *, int);
void removeValue(ArrayList *, int);
void freeMemory(ArrayList *);

int main()
{
    // Instantiate the ArrayList
    ArrayList * arrayList;

    // Create ArrayList
    arrayList = createArrayList();

    // Get input from user
    int caseInput = 0;
    int value = 0;
    printf("Enter:\n");

    while(caseInput != -1)
    {
        // Display menu of options
        printf("1 to insert a value\n");
        printf("2 to delete a value\n");
        printf("3 to retrieve a value\n");
        printf("4 to print ArrayList\n");
        printf("5 to exit\n");

        scanf("%d", &caseInput);
        switch(caseInput)
        {
        case 1:
            printf("value to insert:");
            scanf("%d", &value);
            append(arrayList, value);
            break;

        case 2:
            printf("value to delete:");
            scanf("%d", &value);
            removeValue(arrayList, value);
            break;

        case 3:
            printf("value to retrieve:");
            scanf("%d", &value);
            get(arrayList, value);
            break;

        case 4:
            printArrayList(arrayList);
            break;

        case 5:
            printArrayListData(arrayList);
            caseInput = -1;
            break;
        }
        printf("\n");
    }

    // Free created memory
    freeMemory(arrayList);

    // Exit Program
    return 0;
}

// Creates ArrayList
ArrayList * createArrayList()
{
    ArrayList * ret = calloc(1, sizeof(ArrayList));
    ret->size = 0;
    ret->cap = 8;
    ret->arr = calloc(ret->cap, sizeof(int));
    return ret;
}

// Append to ArrayList
void append(ArrayList * list, int number)
{
    // Location where int will be appended
    int index = list->size;

    // If ArrayList reach capacity, expand ArrayList
    if(index >= list->cap)
    {
        expand(list);
    }
    list->arr[index] = number;
    list->size++;
}

// Reallocate memory by a multiple of two
void expand(ArrayList * list)
{
    list->cap = list->cap * 2;
    int * newList = realloc(list->arr, list->cap * sizeof(int));
    list->arr = newList;
}

// Get int at a specific index
void get(ArrayList * list, int value)
{
    for(int i = 0; i < list->size; i++)
    {
        if(list->arr[i] == value)
        {
            printf("%d exist in ArrayList\n", value);
            return;
        }
    }
    printf("%d does not exist in ArrayList\n", value);
}

// Remove int from a specific index
void removeValue(ArrayList * list, int value)
{
    int size = list->size;

    for(int i = 0; i < size; i++)
    {
        if(list->arr[i] == value)
        {
            for(int j = i; j < size; j++)
            {
                list->arr[j] = list->arr[j+1];
            }
            list->size--;
            printf("Value deleted successfully\n");
            return;
        }
    }
    printf("Value not found\n");
}

// Free up the memory
void freeMemory(ArrayList * list)
{
    free(list->arr);
    free(list);
}

// Display the values contained inside ArrayList
void printArrayList(ArrayList * list)
{
    printf("ArrayList: ");
    for(int i = 0; i < list->size; i++)
    {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

// Print ArrayList data
void printArrayListData(ArrayList * list)
{
    printf("Size of list: %d\n", list->size);
    printf("Size of cap: %d\n", list->cap);
}


