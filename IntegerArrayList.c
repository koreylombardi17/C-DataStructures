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

// list of prototypes
ArrayList * createArrayList();
void printArrayList(ArrayList *);
void printArrayListData(ArrayList *);
void append(ArrayList *, int);
void expand(ArrayList *);
int get(ArrayList *, int);
void removeElement(ArrayList *, int);

int main()
{
    // instantiate the ArrayList
    ArrayList * al;
    // method uses calloc to dynamically store memory for ArrayList
    al = createArrayList();

    // append some values to the ArrayList and print the values
    append(al, 8);
    append(al, 12);
    append(al, 3);
    append(al, 21);
    append(al, 4);
    printArrayList(al);

    // remove int stored at ArrayList index 1
    removeElement(al, 1);
    // print the ArrayList values
    printArrayList(al);

    // get int stored at ArrayList index 3
    int temp = get(al, 3);
    // print the value stored inside of temp
    printf("Number stored at index 3: %d\n", temp);

    // append a few values to the ArrayList and print the values
    append(al, 10);
    append(al, 2);
    append(al, 3);
    append(al, 11);
    append(al, 10);
    append(al, 16);
    printArrayList(al);

    // remove int stored at ArrayList index 0
    removeElement(al, 0);
    // print the ArrayList values
    printArrayList(al);

    // successful exit
    return 0;
}

// calloc memory for arraylist and populate fields
ArrayList * createArrayList()
{
    ArrayList * ret = calloc(1, sizeof(ArrayList));
    ret->size = 0;
    ret->cap = 8;
    ret->arr = calloc(ret->cap, sizeof(int));
    return ret;
}

// add a number to an existing ArrayList
void append(ArrayList * list, int number)
{
    int index = list->size;
    if(index >= list->cap)
    {
        expand(list);
    }
    list->arr[index] = number;
    list->size = list->size + 1;
}

// realloc memory by a multiple of two
void expand(ArrayList * list)
{
    list->cap = list->cap * 2;
    list = realloc(list->arr, list->cap * sizeof(int));
}

// get int at a specific index
int get(ArrayList * list, int index)
{
    if(index < list->size)
    {
        return list->arr[index];
    }
    else
    {
        printf("Error, index out of bounds");
        return -1;
    }
}

// remove int from a specific index
void removeElement(ArrayList * list, int index)
{
    int listSize = list->size;

    if(index < listSize)
    {
        for(int i = index; index < listSize; i++)
        {
            if(i == listSize - 1)
            {
                list->arr[i] = 0;
                break;
            }
            list->arr[i] = list->arr[i + 1];
        }
        list->size = list->size - 1;
    }
}

// nicely display the values contained inside ArrayList
void printArrayList(ArrayList * list)
{
    printf("ArrayList: ");
    for(int i = 0; i < list->size; i++){
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

// print useful information to help understand the architecture of the ArrayList
void printArrayListData(ArrayList * list)
{
    printf("Size of list using size variable:\t %d\n", list->size);
    printf("Size of cap using cap variable:\t\t %d\n", list->cap);
}


