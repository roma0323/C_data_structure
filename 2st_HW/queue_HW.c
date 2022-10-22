#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQUEUE 6
struct queue_mode{

    struct guest_mode{
        char number[10];
        int amount ;
    };

    int item[MAXQUEUE];
    int front ,rear;

    struct guest_mode guest[MAXQUEUE]; 
}queue,queue2;

void ADDQUEUE(int element_item){                    //檢查重複代號
    if(queue.front==(queue.rear+1)%MAXQUEUE){
        printf("full\n");                           //最後要拿掉
        return;
    }
    queue.item[(++queue.rear)%MAXQUEUE]=element_item;
    for(int i=0;i<MAXQUEUE;i++){
        printf("%d,",queue.item[i]);
    }
    printf("\n");
}
void DELETEQUEUE(){
    if(queue.front==queue.rear){
        printf("empty\n");                              //最後要拿掉
        return;
    }
    queue.item[(++queue.front)%MAXQUEUE]=-1;     //刪除過後設為-1
    for(int i=0;i<MAXQUEUE;i++){
        printf("%d,",queue.item[i]);
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
            break;
        case 2:
            printf("mode2\n");
            break;
        case 3:
            printf("mode3\n");
            break;
        case 4:
            printf("mode4\n");
            break;
        case -1:
            break;
        default:
            printf("error");
    }
    }
    
        

    queue.guest[1].amount=255;
    printf("%d\n",queue.guest[1].amount);
    strcpy( queue.guest[1].number, "5" );
    //queue.guest[1].number="5";
    printf("%s\n",queue.guest[1].number);
    //printf("%d\n",queue.guest[1].number);
    //printf("%cn\n",queue.guest[1].number);


    queue.front=0;
    queue.rear=0;
    // ADDQUEUE(11);
    // ADDQUEUE(222);
    // ADDQUEUE(333);
    // ADDQUEUE(4);
    // ADDQUEUE(5);
    

    // ADDQUEUE(6);
    // DELETEQUEUE();
    // ADDQUEUE(6);
    // DELETEQUEUE();
    // DELETEQUEUE();
    // DELETEQUEUE();
    // DELETEQUEUE();
    // DELETEQUEUE();
    // DELETEQUEUE();

    

    

    return 0;
}