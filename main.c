#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* reserveMemory(int size);
void initMemory(int* ptr, int size);
void printMemoryContent(int* ptr, int size);

int main(void)
{
    int size;

    printf("Wie gross soll der zu reservierende Speicher sein?\nEingabe: ");
    scanf("%d", &size);

    int* ptr = (int*)reserveMemory(size);

    if(ptr == NULL)
    {
        printf("Fehler beim reservieren des Speichers!");
    }

    initMemory(ptr, size);

    printMemoryContent(ptr, size);

    free(ptr);

    system("pause");

    return EXIT_SUCCESS;
}

void* reserveMemory(int size)
{
    return malloc(size * sizeof(int));
}

void initMemory(int* ptr, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
    }
}

void printMemoryContent(int* ptr, int size)
{
    printf("Speicher:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d \n", ptr[i]);
    }
}
