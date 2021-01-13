
#include <stdio.h>
#include<string.h>
#include "Number.h"

number *strtonum(char *str){
    number *num = (number *)malloc(sizeof(number));
    init(num);

    int i = 0;
    while (i<strlen(str)){

        if (str[i] >= 65){
            append(num, (int) str[i] - 65 + 10);
        }
        else {
            append(num, (int) str[i] - '0');
        }
        i++;
    }
    return num;
}

