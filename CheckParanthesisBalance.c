#include <stdio.h>
#include <stdlib.h>


struct Stack{
    int size;
    int top;
    char* arr;
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
int push(struct Stack* ptr,char data){
    if(isFull(ptr)){
        printf("Stack overflow,can't push more\n");
        return 0;
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = data ;
        printf("Element %c successfullt pushed\n",data);
    }
}

char pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow,can't pop more\n");
        return -1;
    }
    else{
        
        char val = ptr->arr[ptr->top];
        ptr->top--;
        //printf("Element successfullt popped\n");
        return val;
    }
}
char peek(struct Stack* ptr,char i){
    int result = ptr->top - i +1 ;
    if(result < 0){
        printf("Invalid peek\n");
        return -1;
    }
    else{
        return ptr->arr[result];
    }
}
 char stackTop(struct Stack *ptr){
     return ptr->arr[ptr->top];
 }
 int stackBottom(struct Stack *ptr){
     return ptr->arr[0];
 }
 void StackTraversal(struct Stack* ptr){
     for(int i = 0;i<=ptr->top;i++){
         printf("The stack element is %c\n",ptr->arr[i]);
     }
 }
int isBalanceParanthesis(struct Stack* ptr, struct Stack* temp){
     for(int i = 0;i<=ptr->top;i++){
         printf("The stack element is %c\n",ptr->arr[i]);
         if(ptr->arr[i] == '('){
            push(temp,'(');
        }
        else if(ptr->arr[i] == ')'){
            char x = pop(temp);
            printf("successfully Popped %c\n",x);
        }

     }
   
        
    
    if(isEmpty(temp)){
        printf("Paranthesis match!! Hence Balance");
    }
    else{
        printf("Paranthesis  DONOT match!! Hence NO Balance");
    }
    
}

int main()
{
  struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
  //to push and pop the paranthesis ( and )
  struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
   s->size = 15;
   s->top=-1;
   s->arr = (char*)malloc(s->size * sizeof(char));
   temp->size = 15;
   temp->top=-1;
   temp->arr = (char*)malloc(temp->size * sizeof(char));
   push(s,'3');
   push(s,'*');
   push(s,'2');
   push(s,'-');
   push(s,'(');
   push(s,'8');
   push(s,'+');
   push(s,'1');
   push(s,')');
   //printf("Element  %d successfullt popped\n",pop(s));
   //printf("Peek Element is %d \n",peek(s,5));
   //printf("Peek Element is %d \n",peek(s,7));
   //printf("Stack Top  Element is %d \n",stackTop(s));
   //printf("Stack Bottom  Element is %d \n",stackBottom(s));
  // push(temp,'1');
   if(isEmpty(s)){
       printf("Stack is empty\n");
   }
   else{
       printf("NOt empty\n");
   }
   printf("This is top of stack %d\n",s->top);
   isBalanceParanthesis(s,temp);
   //StackTraversal(s);
   
    return 0;
}
