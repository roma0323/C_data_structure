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

void ADDQUEUE(){                    //檢查重複代號
    char number;
    int amount;
    printf("input\n"); 
    scanf(" %c %d",&number,&amount);
 
    if(queue.front==(queue.rear+1)%MAXQUEUE){
        printf("full\n");                           //最後要拿掉
        return;
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
int main(){
    
    int input_mode=0;
    while(input_mode!=-1){
        scanf("%d",&input_mode);

    switch(input_mode){
        case 1:
            printf("mode1\n");
            ADDQUEUE();
            break;
        case 2:
            printf("mode2\n");
            break;
        case 3:
            printf("mode3\n");
            break;
        case 4:
            printf("mode4\n");
            DELETEQUEUE();
            break;
        case -1:
            break;
        default:
            printf("error");
    }
    }
    
        

   


    queue.front=0;
    queue.rear=0;

    

    return 0;
}