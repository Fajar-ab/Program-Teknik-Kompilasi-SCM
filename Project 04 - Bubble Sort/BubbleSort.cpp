#include <stdio.h>
#include <stdlib.h>

void printArr(double *arr, int n);
void bubbleSort(double *arr, int n);

int main() {
    int n;

    printf("Masukkan jumlah data : ");
    scanf("%d", &n);

    double angka[n];

    for(int i=0; i<n; i++) {
        angka[i] = (double) (rand() % 1000) / 100;
        // angka[i] = ((double) (rand() % 100 / 100) * (1 + rand());
    }

    printf("\nAngka sebelum di sorting : \n");
    printArr(angka, n);

    bubbleSort(angka, n);

    printf("\nAngka sesudah di sorting : \n");
    printArr(angka, n);

    return 0;
}

void printArr(double *arr, int n) {
    for(int i=0; i<n; i++) {
        printf(" %8.2f ", arr[i]);
    }
}

void bubbleSort(double *arr, int n) {
    double temp;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortFlag(double *arr, int n) {
    double temp;
    int flag;
    for(int i = 0; i<n; i++) {
        flag = 0;
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
    }
}
