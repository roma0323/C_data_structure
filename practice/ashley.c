#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */

int generate_que (){
    int min = 0;
    int max = 9;
    int x = rand() % (max - min + 1) + min;
    int y = rand() % (max - min + 1) + min;
    int answer =x*y;
    printf("%d*%d=?\n", x,y);
    return answer;
}

int main()
{   
    int *a;         //*代表指向的位置的數值(最末端)  沒有 代表指向的位置(要指哪)
    int b = 5;
    a = &b;
    *a = 7;

    char Astring [] = "abcd";               //%c 單個字符
    printf("word:%s\n",Astring);
    printf("word:%c\n",Astring[1]);

    char *pointerstring = "qwer";
    printf("word:%s\n",pointerstring);
    printf("word:%c\n",pointerstring[1]);
    printf("change ascii code:%c\n",pointerstring[1]+1);

    printf("%d\n",*a);
    printf("%p\n\n",a);
    
    int arr[6]={4,5,2,3,8,2};
    printf("%p\n",&arr[0]);
    printf("%p\n",&arr[1]);
    printf("%p\n",&arr);
    printf("%p\n",arr);
    printf("%p\n",&arr+1);
    printf("%p\n",arr+1);
    
    return 0;
}


