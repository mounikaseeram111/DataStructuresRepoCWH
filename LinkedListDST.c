/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct node *next;
};

void linkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertionAtTheBegin(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    
    return head;
    
}

struct Node* insertionAtTheEnd(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    
    
    return head;
    
}



struct Node* insertionAtIndex(struct Node *head,int data,int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while(i != index){
        p=p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    
    return head;
    
}


struct Node* insertionAfterNode(struct Node *head,int data,struct Node *node){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
    
    
    return head;
    
}

struct Node* deletionAtTheBegin(struct Node *head){
    struct Node *ptr = head;

    head = head->next;
    free(ptr);
    
    return head;
    
}

struct Node* deletionAtIndex(struct Node *head,int index){
     struct Node *p = head;
     int i = 0 ;
     while(i != index-1){
        p=p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    
    return head;
    
}

struct Node* deletionAtEnd(struct Node *head){
     struct Node *prev = head;
     struct Node *ptr = head->next;
     while(ptr->next != NULL){
        
        ptr=ptr->next;
        prev = prev->next;
    }
    struct Node *q = prev->next;
    prev->next = NULL;
    free(q);
    
    return head;
    
}

struct Node* deletionAtGivenElement(struct Node *head,int data){
     struct Node *prev = head;
     struct Node *ptr = head->next;
     while(ptr->data != data){
        
        ptr=ptr->next;
        prev = prev->next;
    }
    struct Node *q = prev->next;
    prev->next = ptr->next;
    free(q);
    
    return head;
    
}








int main()
{
    //define linked list nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    //declare linked list nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth= (struct Node*)malloc(sizeof(struct Node));
    
    //fill data and next ptr 
    
    head -> data = 7;
    head -> next = second;
    
    second -> data = 20;
    second -> next = third;
    
    third -> data =100;
    third -> next = fourth;
    
    fourth -> data=23;
    fourth -> next = NULL;
    
    printf("Linked list travarsel before insertion\n");
    linkedlistTraversal(head);
    
    printf("Linked list travarsel after insertion\n");
    //head = insertionAtTheBegin(head,122);
    //head = insertionAtTheEnd(head,122);
    //head = insertionAtIndex(head,122,2);
    head = insertionAfterNode(head,122,second);
    linkedlistTraversal(head);
    
    printf("Linked list travarsel after Deletion\n");
    //head = deletionAtTheBegin(head);
    //head = deletionAtIndex(head,2);
    //head = deletionAtEnd(head);
    head = deletionAtGivenElement(head,100);
    
    linkedlistTraversal(head);

    return 0;
}
