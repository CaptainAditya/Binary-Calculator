
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "list.h"


/*
void init(list *l) {
    *l = NULL;
    return;
}

int isempty(list l){
    if(l == NULL)
        return 1;
    else
        return 0;
 }

void append(list *l, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

int length(list l){
    int len = 0;
    node* p  = l;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void destroy(list *l){
    node *p = *l;
    node * q;
    q = p;
    while(p){
        p = p->next;
        free(q);
    }
    *l = NULL;
    return ;
}
void traverse(list l){
    printf("[");
    node *p;
    p = l;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");

    return;
}

int search(list l, int d) {
    node *p ;
    p = l;

    while(p) {
        if(p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}

void Remove(list *l , int d){
    node *p = *l, *q;
    while(p && p->data != d){
        q = p;
        p = p->next;
    }
    if(p && *l == p){
        *l = p->next;
        free(p);
        return;
    }
    if(p){
        q->next = p->next;
        free(p);
        return;
    }
}

int pops(list *l){
    node *p = *l;
    if(!p)
        return INT_MAX;
    int k = p->data;
    *l = p->next;
    free(p);
    return k;
}
void insert_beg(list *l, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *l;
    *l = newnode;
    return;
}
void reverse(list *l){

}

void insert_at(list *l, int i, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;

    if( i == 0){
        insert_beg(l,d);
        return;
    }

    int s = length(*l);
    if(i >= s){
        append(l,d);
        return;
    }
    node *p = *l;
    int j = 0;
    while(j < i-1) {
        p = p->next;
        j++;
    }
    newnode->next = p->next;
    p->next = newnode;
    return;


}

list Union(list L1, list L2){
    list L3;
    node *p = L1;
    node *q = L2;
    while (p){
        append(&L3,p->data);
        p = p->next;
    }
    while (q){
        if (!search(L3,q->data))
            append(&L3,q->data);
        q = q->next;
    }
    return L3;
}

list intersection(list L1,list L2){
    list L3;
    node *p = L1;
    while (p){
        if (search(L2,p->data))
            append(&L3,p->data);
        p = p->next;
    }
    return L3;
}
*/





