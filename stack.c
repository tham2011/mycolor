#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

struct STACK
{
    int items [MAX_SIZE];
    int top;
};
void initializestack (struct STACK* stack)
{
    stack->top=-1;

}
bool isfull(struct STACK* stack){
    return stack->top == MAX_SIZE -1;

}
bool isempty(struct STACK*stack){
    return stack->top == -1;
}
void push (struct STACK* stack, int value){
    if (isfull(stack)){
        printf(" stack da day khoong the them phan tu.\n");

    } 
    else {
        stack ->top++;
        stack-> items[stack->top] = value;
    }
}
int pop (struct STACK* stack){
    if ( isempty(stack)){
        printf( " stack da rong khong the lay phan tu ra khoi stack");
        return -1;
    
    }
    else{
        int popped = stack->items[stack->top];
        stack->top--;
        return popped;
    }
}
void deletement(struct STACK* stack,int value){
    int temp[MAX_SIZE];
    int index =0;
    while(!isempty(stack))
    {
        int current =pop (stack);
        if (current!= value){
            temp[index]=current;
            index++;
        }
    }
    for (int i=index-1; i>=0;i--){
        push(stack, temp[i]);
    }
    printf("\n");

 
void displayStack(struct STACK *stack)
{
    if(isempty(stack)){
        printf("Stack rong.\n");
    }else{
        printf("Phan tu stack thu:");
        for(int i = 0 ; i<=stack->top;i++){
            printf("%d",stack->items[i]);

        }
        printf("\n");
    }
}

}
int main(){
    struct STACK stack;
    initializestack(&stack);
    int choice, element,value;
    do{
        printf("\n Thao tac tren satck:\n");
        printf("1. them 1 phan tu \n");
        printf("2. Lay mot phan tu ra khoi sTack\n");
        printf("3. Xoa mot phan tu\n");
        printf("4. Hien thi stack\n");
        printf("5. Thoat \n");
        printf("Lua chon cua banr:");
        scanf("%d",&choice);
    
    switch(choice){
        case1:
        printf (" nhap gia trij phan tu can them: ");
        scanf("%d",&element);
        push(&stack, element);
        break;
        case2:
        printf("popped element: %d\n",pop(&stack));
        break;
        case3:
        printf("nhap phan tu muon xao:");
        scanf("%d", &value);
        deleteelement(&stack, value);
        break;
        case4:
        displaySatck(stack);
        break;
        case5:
        printf ("thoat khoi chuong trinh.\n");
        break;
        default:
        printf("lua cho khong hop le\n");
    }
    }while (choice !=5);
      return 0;
    
    
}
