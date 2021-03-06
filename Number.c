#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "Number.h"
#include<string.h>

void init(number *l) {
    l->head = l->tail = NULL;
    l->len = 0;
    l->sign = 1;
    return;
}


void append(number *l, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else return;
    if(l->head == NULL){
        l->head = newnode;
        l->tail = newnode;
        l->len++;
        return;
    }
    p = l->head;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    newnode->prev = p;
    newnode->next = NULL;
    l->len++;
    l->tail = newnode;
    return;
}


void traverse(number *l){

    node *p = l->head;
    if (!(p))
        return ;
    if (l->sign == -1)
        printf("-");
    while (p){

        if (p->data >= 10){
            printf("%c",'A' + p->data - 10);
        }
        else
            printf("%d",p->data);

        p = p->next;
    }
    printf("\n");
    return;
}

int remov(number *l, int pos){
	int i;
	int data;
	node *p, *tmp;
	/* handle errors on position */
	if(pos < 0 || pos >= l->len)
		return 0;

    if(l->head == NULL) {
		return 0;
	}

	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;

	if(l->len == 1) {
		data = p->data;
		l->head = l->tail = p = NULL;
		l->len--;
		return data;
	}
	if(pos == 0) {
		data = p->data;
		p->next->prev = NULL;
		l->head = p->next;
		free(p);
		l->len--;
		return data;
	}
	if(pos == l->len - 1) {
		data = p->next->data;
		tmp = p->next;
		p->next = NULL;
		l->tail = p;
		free(tmp);
		l->len--;
		return data;
	}

	tmp = p->next;
	p->next = p->next->next;
	tmp->next->prev = p;
	data = tmp->data;
	free(tmp);
	l->len--;
	return data;
}
void insert_beg(number *l, int d){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else return;
    if (l->head == NULL){
        l->head = newnode;
        l->tail = newnode;
        l->len++;
        return ;
    }
    node *p = l->head;

    newnode->next = p;
    p->prev = newnode;

    newnode->prev = NULL;

    l->head = newnode;
    l->len++;

}




void insert_at(number *l, int i, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else return;

    if( i == 0){
        insert_beg(l,d);
        return;
    }

    int s = l->len;
    if(i >= s){
        append(l,d);
        return;
    }
    node *p = l->head;
    int j = 0;
    while(j < i-1) {
        p = p->next;
        j++;
    }
    newnode->next = p->next;
    p->next = newnode;
    p->next->prev = newnode;
    newnode->prev = p;
    l->len++;
    return;
}

void destroy(number *l){
    node *p = l->head;
    node * q;
    q = p;
    while(p){
        p = p->next;
        free(q);
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    l->sign = 1;
    return ;
}

int show(number *l, int pos) {
	node *p;
	if(pos <0 || pos > l->len)
		return 0;
	p = l->head;
	int i;
	for(i = 0; i < pos; i++)
		p = p->next;
	return p->data;
}

char *copyintostr(number *num){
    static char str[1000];
    static char c[1000];
    strcpy(str,"");
    node *p = num->head;
    int i = 0;
    while (p){
        strcat(str,itoa(p->data, c, 10));
        p = p->next;
        strcpy(c,"");
    }
    return str;
}


char *concat(char *str1,char *str2) {
    static char result[1000];
    strcpy(result,"");
    int i=0,j=0;
    while (str1[j] != '\0')
        result[i++] = str1[j++];
    j=0;
    while (str2[j] != '\0')
        result[i++] = str2[j++];
    result[i] = '\0';
    return result;
}
