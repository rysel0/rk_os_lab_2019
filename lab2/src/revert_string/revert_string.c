#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "revert_string.h"

void RevertString(char *str)
{
    int first = 0;
    int last = strlen(str) - 1;
    char temp;

    while (first < last) {
      
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;

        first++;
        last--;
    }
}
// void RevertString(char *str)
// {
//     char* temp = malloc(sizeof(char) * (strlen(str)));
    
//     for (int i = strlen(str) - 1; i >= 0; i--) {
//         temp[strlen(str) - 1 - i] = str[i];
//     }
//     strcpy(str, temp);
// }
