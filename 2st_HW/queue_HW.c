#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQUEUE 6
struct queue_mode{

    struct guest_mode{
        char number;
        int amount ;
    };

    int item[MAXQUEUE];
    int front ,rear;

    struct guest_mode guest[MAXQUEUE]; 
}queue,queue2;

void ADDQUEUE(){                   
    char number;
    int amount;
    printf("input\n"); 
    scanf(" %c %d",&number,&amount);
    
    if(queue.front==(queue.rear+1)%MAXQUEUE){       //full
        printf("full\n");                           
        return;
    }
    for(int i=0;i<MAXQUEUE;i++){    
        if(queue.guest[i].number==number){       //same number
        printf("same\n");                           
        return;
        }        
    }    

    

    queue.guest[(++queue.rear)%MAXQUEUE].amount=amount;
    queue.guest[(queue.rear)%MAXQUEUE].number=number;
    for(int i=0;i<MAXQUEUE;i++){
        printf("%c %d,",queue.guest[i].number,queue.guest[i].amount);
    }
    printf("\n");
}
void DELETEQUEUE(){
    if(queue.front==queue.rear){
        printf("empty\n");                              //最後要拿掉
        return;
    }
    queue.guest[(++queue.front)%MAXQUEUE].amount=0;
    queue.guest[(queue.front)%MAXQUEUE].number='N';

    for(int i=0;i<MAXQUEUE;i++){
        printf("%c %d,",queue.guest[i].number,queue.guest[i].amount);
    }
        printf("\n");

}
void COUNTTOTAL(){
    int total=0;
    for(int i=0;i<MAXQUEUE;i++){
        total+=queue.guest[i].amount;
    }
    printf("total is %d",total);
    printf("%d\n",total);
}
void SHOWFIRST(){
    printf("%c\n",queue.guest[queue.front+1].number);
}
int main(){
    
    int input_mode=0;
    while(input_mode!=-1){
        scanf("%d",&input_mode);

    switch(input_mode){
        case 1:
            ADDQUEUE();
            break;
        case 2:
            COUNTTOTAL();
            break;
        case 3:
            SHOWFIRST();
            break;
        case 4:
            DELETEQUEUE();
            break;
        case -1:
            break;
        default:
            printf("error\n");
    }
    }
    
    queue.front=0;
    queue.rear=0;

    return 0;
}