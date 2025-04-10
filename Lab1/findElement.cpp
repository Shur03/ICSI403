#include<stdio.h>
/*
Husnegtiin hamgiin ih, hamgiin baga elementiig zereg olno.
Арга 2
1. Хүснэгтийн элементүүдийн тоо тэгш, сондгойг тогтооно.
2. Хэрэв тэгш бол эхний 2 элементийг жишиж их, багыг нь олж хадгална. Харин сондгой бол эхний элементийг хамгийн их бас хамгийн бага элемент гэж үзэж хадгална. Үүний үр дүнд хүснэгтэнд авч үзэээгүй элементүүдийн хосын тоо нь тэгш тоо байна.
3. Хүснэгтийн авч үзээгүй элементүүдээс дэс дарааллан 2 элемент бүрийг хооронд нь жишиж, хамгийн их багатай жиших үйлдийг давтана.

*/
findMaxMin(int arr[], int N, int *max, int *min){
    if(N%2==0){
        if(arr[0] >= arr[1]){
            *max = arr[0];
            *min = arr[1];
        }
        else{
            *max = arr[1];
            *min = arr[0];
        }
         for (int i = 2; i < N; i++) {
        if (arr[i] > *max) {
            *max = arr[i];  
        }
        if (arr[i] < *min) {
            *min = arr[i]; 
        }
    }
    }
    else{
        *max = arr[0];
        *min = arr[0];

         for (int i = 1; i < N; i++) {
        if (arr[i] > *max) {
            *max = arr[i];  
        }
        if (arr[i] < *min) {
            *min = arr[i];  
        }
    }
    }

}
int main(){
int N, max,min;
printf("Enter the number of elements in the array:");
scanf("%d", &N);
int  arr[N];
 printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
 findMaxMin(arr, N, &max, &min);
    
    // Print the results
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    
    return 0;
}