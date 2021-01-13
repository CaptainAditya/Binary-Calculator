
#include <stdio.h>
#include "num-conversion-func.h"


number *decimaltobinary(number *num){

    number *temp,*temp1,*result,*two;
    result = (number *)malloc(sizeof(number));
    two = (number *)malloc(sizeof(number));
    init(result);
    init(two);
    append(two,2);
    temp = num;
    while (checkzero(temp)) {


        temp1 =  modulus(temp,two);

        insert_beg(result,temp1->head->data);

        temp = division(temp,two);


    }
    if (!(result->tail))
        append(result,0);
    return result;
}

number *decimaltooctal(number *num){

    char divide[10] = " / 8";
    char modulas[10] = " % 8";
    char str[1000];
    number *temp,*temp1,*result,*eight;

    result = (number *)malloc(sizeof(number));
    eight = (number *)malloc(sizeof(number));

    init(eight);
    append(eight, 8);

    init(result);
    temp = num;

    while (checkzero(temp)) {

        temp1 = modulus(temp,eight);

        insert_beg(result,temp1->head->data);

        temp = division(temp,eight);

    }
    return result;
}

number *decimaltohexa(number *num){


    number *temp,*temp1,*result,*a,*sixteen;

    a = (number *)malloc(sizeof(number));
    sixteen = (number *)malloc(sizeof(number));

    init(sixteen);
    init(a);
    append(a,1);
    append(a,0);
    append(sixteen,1);
    append(sixteen, 6);

    result = (number *)malloc(sizeof(number));
    init(result);
    temp = num;

    while (checkzero(temp)) {

        temp1 = modulus(temp,sixteen);
        if (compare(temp1,a) >= 0){
            insert_beg(result,atoi(copyintostr(temp1)));
        }

        else{
            insert_beg(result,temp1->head->data);

        }

        temp = division(temp,sixteen);

    }
    return result;
}


number *binarytodecimal(number *num){

    number *result;
    result = (number*)malloc(sizeof(number));
    init(result);
    append(result,0);


    number *mul = (number*)malloc(sizeof(number));
    number *two = (number *)malloc(sizeof(number));
    init(mul);
    init(two);
    append(two,2);
    append(mul,1);
    node *p = num->tail;
    while (p){
        if (p->data){
            result = addition(result,mul);
            mul = multiplication(mul,two);
        }
        else
            mul = multiplication(mul,two);
        p = p->prev;

    }

    return result;
}

number *binarytooctal(number *num){

    number *result;
    result = (number*)malloc(sizeof(number));
    init(result);

    number *temp = (number*)malloc(sizeof(number));
    init(temp);

    node *p = num->tail;
    int i=0;
    while (p){

        if (i==3){
            insert_beg(result,binarytodecimal(temp)->head->data);
            i = 0;
            destroy(temp);
        }

        else{

            insert_beg(temp,p->data);
            i++;
            p = p->prev;

        }


    }

    if (temp->head){
        insert_beg(result,binarytodecimal(temp)->head->data);
    }

    return result;
}

number *binarytohexa(number *num){

    number *result;
    result = (number*)malloc(sizeof(number));
    init(result);

    number *temp = (number*)malloc(sizeof(number));
    init(temp);

    number *a = (number *)malloc(sizeof(number));
    init(a);

    append(a,1);
    append(a,0);

    node *p = num->tail;
    int i=0;
    while (p){

        if (i==4){
            temp = binarytodecimal(temp);
            if (compare(temp,a) >= 0){
                insert_beg(result,atoi(copyintostr(temp)));
            }
            else{
                insert_beg(result,temp->head->data);
            }
            i = 0;
            destroy(temp);
        }

        else{
            insert_beg(temp,p->data);
            i++;
            p = p->prev;

        }
    }

    if (temp->head){
        temp = binarytodecimal(temp);
        if (compare(temp,a) >= 0){
            insert_beg(result,atoi(copyintostr(temp)));
        }
        else{
            insert_beg(result,temp->head->data);
        }

    }

    return result;
}


number *octaltobinary(number *num){

    number *result, *temp;
    result = (number*)malloc(sizeof(number));
    init(result);


    number *temp1 = (number*)malloc(sizeof(number));
    init(temp1);

    node *p = num->tail;
    int i=0;
    while (p){


        append(temp1, p->data);

        temp = decimaltobinary(temp1);

        node *q = temp->tail;

        while (q){
            insert_beg(result,q->data);
            q = q->prev;
            i++;
        }
        if (i!=3){
            while (i!=3){
                insert_beg(result, 0);
                i++;
            }

        }
        i = 0;
        p = p->prev;
        destroy(temp1);

    }

    return result;
}

number *octaltodecimal(number *num){

    number *result;
    result = (number*)malloc(sizeof(number));
    init(result);
    append(result,0);

    number *con = (number *)malloc(sizeof(number));
    init(con);
    number *mul = (number*)malloc(sizeof(number));
    number *eight = (number *)malloc(sizeof(number));
    init(mul);
    init(eight);
    append(eight,8);
    append(mul,1);

    node *p = num->tail;

    while (p){
        append(con,p->data);
        result = addition(result,multiplication(con, mul));


        mul = multiplication(mul,eight);
        p = p->prev;
        destroy(con);

    }

    return result;
}

number *octaltohexa(number *num){
    number *result;

    result = binarytohexa(octaltobinary(num));

    return result;
}


number *hexatobinary(number *num){

    number *result, *temp;
    result = (number*)malloc(sizeof(number));
    init(result);


    number *temp1 = (number*)malloc(sizeof(number));
    init(temp1);

    node *p = num->tail;
    int i=0;
    while (p){
        append(temp1, p->data);
        temp = decimaltobinary(temp1);


        node *q = temp->tail;
        while (q){
            insert_beg(result,q->data);
            q = q->prev;
            i++;
        }
        if (i!=4){
            while (i != 4){
                insert_beg(result, 0);
                i++;
            }

        }
        i = 0;
        p = p->prev;
        destroy(temp1);

    }

    return result;
}

number *hexatodecimal(number *num){

    number *result;
    result = (number*)malloc(sizeof(number));
    init(result);
    append(result,0);

    number *con = (number *)malloc(sizeof(number));
    init(con);
    number *mul = (number*)malloc(sizeof(number));
    number *sixteen = (number *)malloc(sizeof(number));
    init(mul);
    init(sixteen);
    append(sixteen,1);
    append(sixteen,6);
    append(mul,1);

    node *p = num->tail;

    while (p){
        append(con,p->data);
        result = addition(result,multiplication(con, mul));


        mul = multiplication(mul,sixteen);
        p = p->prev;
        destroy(con);

    }

    return result;
}

number *hexatooctal(number *num){

    number *res =  hexatobinary(num);
    res = binarytooctal(res);
    return res;
}



