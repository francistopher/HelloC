#include <stdio.h>
#include <stdlib.h>
#include "leak_detector.h"

int main(void)
{
    char* hello = (char*)malloc(sizeof(char) * 6);
    hello[0] = 'H';
    hello[1] = 'E';
    hello[2] = 'L';
    hello[3] = 'L';
    hello[4] = 'O';
    hello[5] = '\0'; 
    printf("%s\n", hello);
    free(hello);
    return 0;
}
