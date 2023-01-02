#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int num);
void quickSort(int arr[], int low, int high);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int k = low ;
    for(int i = low; i < high; i++){
        if(arr[high] >= arr[i]){
            swap(&arr[i], &arr[k]);
            k++;
        }
    }
    swap(&arr[high], &arr[k]);
    return k;
}

void quickSort(int arr[], int low, int high){
    if(high > low){
        int middle = partition(arr, low, high);
        quickSort(arr, low, middle - 1); // left side of the array
        quickSort(arr, middle + 1, high);
    }
}

void bubbleSort(int arr[], int num){
    clock_t start, end;
    double total;
    start = clock();
    for(int i = 0 ; i < num - 1; i++){
        for(int j = 0 ; j < num - i - 1; j ++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    }
    end = clock();
    total = (double)(end - start)/ CLOCKS_PER_SEC;
    // print
    for(int i = 0 ; i < num ; i ++){
        printf("%d ", arr[i]);    
    }    
    printf("\nbubble sort: %f sec\n", total);

}




int main(){
    int num;
    scanf("%d", &num);
    while(num != -1){
        int arr_b[num];
        int arr_q[num];
        for(int i = 0; i < num ; i++){
            int temp;
            scanf("%d", &temp);
            arr_b[i] = temp;
            arr_q[i] = temp;
        }
        bubbleSort(arr_b, num);

        clock_t start, end;
        double total;
        start = clock();
        quickSort(arr_q, 0, num-1);
        end = clock();
        total = (double)(end - start)/ CLOCKS_PER_SEC;
        printf("quick sort: %f sec\n", total);
        scanf("%d", &num);
    }
}