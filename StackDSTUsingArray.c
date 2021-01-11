/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct Stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack *ptr){
    if(ptr->top == (ptr->size -1)){
        return 1;
    }
    return 0;
}
int push(struct Stack* ptr,int data){
    if(isFull(ptr)){
        printf("Stack overflow,can't push more\n");
        return 0;
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = data ;
        printf("Element %d successfullt pushed\n",data);
    }
}

int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow,can't pop more\n");
        return -1;
    }
    else{
        
        int val = ptr->arr[ptr->top];
        ptr->top--;
        //printf("Element successfullt popped\n");
        return val;
    }
}
int peek(struct Stack* ptr,int i){
    int result = ptr->top - i +1 ;
    if(result < 0){
        printf("Invalid peek\n");
        return -1;
    }
    else{
        return ptr->arr[result];
    }
}
 int stackTop(struct Stack *ptr){
     return ptr->arr[ptr->top];
 }
 int stackBottom(struct Stack *ptr){
     return ptr->arr[0];
 }


int main()
{
  struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
   s->size = 6;
   s->top=-1;
   s->arr = (int*)malloc(s->size * sizeof(int));
   push(s,1);
   push(s,23);
   push(s,23);
   push(s,32);
   push(s,21);
   push(s,231);
   push(s,2);
   push(s,233);
   printf("Element  %d successfullt popped\n",pop(s));
   printf("Peek Element is %d \n",peek(s,5));
   printf("Peek Element is %d \n",peek(s,7));
   printf("Stack Top  Element is %d \n",stackTop(s));
   printf("Stack Bottom  Element is %d \n",stackBottom(s));
   
   if(isEmpty(s)){
       printf("Stack is empty");
   }
   else{
       printf("NOt empty");
   }
   
   
    return 0;
}
