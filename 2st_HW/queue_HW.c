#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQUEUE 6
struct queue_mode{
    int item[MAXQUEUE];
    int front ,rear;
}queue,queue2;
struct guest_mode{
    char number[100];
    int amount ;
}guest;
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
    queue.front=0;
    queue.rear=0;
    ADDQUEUE(11);
    ADDQUEUE(222);
    ADDQUEUE(333);
    ADDQUEUE(4);
    ADDQUEUE(5);
    

    ADDQUEUE(6);
    DELETEQUEUE();
    ADDQUEUE(6);
    DELETEQUEUE();
    DELETEQUEUE();
    DELETEQUEUE();
    DELETEQUEUE();
    DELETEQUEUE();
    DELETEQUEUE();

    

    

    return 0;
}