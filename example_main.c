#include <stdio.h> 
#include "example.h" // Podlinkowanie pliku nagłowkowego z deklaracją funkcji

int main()
{
    int x = 5, y = 3;
    printf("Add: %d\n", add(x, y));
    printf("Multiply: %d\n", multiply(x, y));
    return 0;
}