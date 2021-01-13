#include<stdio.h>
#include "Number.h"
#include<stdlib.h>

int compare(number *a,number *b);
number* addition(number *n1,number *n2);
number* subtraction(number *n1,number *n2);
void make_empty_list(number *newn,int size) ;
number* multiplication(number *n1,number *n2);
number *division(number *l1, number *l2);
number *modulus(number *l1, number *l2);
number *factorial(number *a);
number *power(number *a, number *b);
