#include <stdio.h>
#include <stdlib.h>
#include "Number.h"

int main(){


    number *ans, *temp;
    temp = (number*)malloc(sizeof(number));
    init(temp);


    char cont;
    int choice, choice2;
    do{
        printf("*****************MAIN MENU******************");
        printf("\n\tFor Expression press 1");
        printf("\n\tTo check prime or not press 2\n");
        printf("\tFor conversion of base press 3\n");
        printf("\tTo exit the Calculator press 4\n");
        printf("********************************************");
        printf("\nEnter CHOICE :");
        scanf("%d",&choice);

        if (choice == 1){

                char s[1000];

                fflush(stdin);
                printf("Enter Expression \n");

                fgets(s, 1000, stdin);
                s[strlen(s)-1] = '\0';
                ans = infix(s);
                if (ans == NULL)
                    continue;
                traverse(ans);
                fflush(stdin);

        }

        else if (choice == 2){

                    char s1[1000];
                    printf("Enter Number :");
                    scanf("%s", s1);

                    ans = strtonum(s1);

                    if (isPrime(ans))
                        printf("The number is prime\n");
                    else
                        printf("The number is not prime\n");

        }

        else if (choice == 3){
               printf("**********************************************\n");

                    printf("\tTo Enter Binary Number press 1\n");
                    printf("\tTo Enter Decimal Number press 2\n");
                    printf("\tTo Enter Octal Number press 3\n");
                    printf("\tTo Enter Hexadecimal Nummber press 4\n");
                    printf("\tTo Exit press 5\n");

                     printf("*********************************************\n");

                    printf("Enter Choice :");
                    scanf("%d",&choice2);


                    if (choice2 == 1){

                            char s1[1000];

                            printf("Enter Binary Number :");

                            scanf("%s", s1);

                            ans =  strtonum(s1);

                            copy(temp,ans);

                            printf("Decimal Conversion :");

                            traverse(binarytodecimal(temp));

                            copy(temp,ans);

                            printf("Octal Conversion :");

                            traverse(binarytooctal(temp));

                            copy(temp,ans);

                            printf("Hexa Conversion :");

                            traverse(binarytohexa(temp));

                    }

                    else if (choice2 == 2){

                            char s1[1000];

                            printf("Enter Decimal Number :");

                            scanf("%s", s1);

                            ans =  strtonum(s1);

                            copy(temp,ans);

                            printf("Binary Conversion :");

                            traverse(decimaltobinary(temp));

                            copy(temp,ans);

                            printf("Octal Conversion :");

                            traverse(decimaltooctal(temp));

                            copy(temp,ans);

                            printf("Hexa Conversion :");

                            traverse(decimaltohexa(temp));

                    }

                    else if (choice2 == 3){

                            char s1[1000];

                            printf("Enter Octal Number :");
                            scanf("%s", s1);

                            ans =  strtonum(s1);

                            copy(temp,ans);

                            printf("Binary Conversion :");

                            traverse(octaltobinary(temp));

                            copy(temp,ans);

                            printf("Decimal Conversion :");

                            traverse(octaltodecimal(temp));

                            copy(temp,ans);

                            printf("HexaDecimal Conversion :");

                            traverse(octaltohexa(temp));

                    }

                    else if (choice2 == 4){

                            char s1[1000];

                            printf("Enter Hexadecimal Number :");

                            scanf("%s", s1);

                            ans =  strtonum(s1);

                            copy(temp,ans);

                            printf("Binary Conversion :");

                            traverse(hexatobinary(temp));

                            copy(temp,ans);

                            printf("Decimal Conversion :");

                            traverse(hexatodecimal(temp));

                            copy(temp,ans);

                            printf("Octal Conversion :");

                            traverse(hexatooctal(temp));

                    }

            }
    }while (choice != 4);

    printf("Thank You!");
}

