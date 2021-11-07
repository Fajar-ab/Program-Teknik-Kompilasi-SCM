#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX 200

int intArray[MAX];// = {4,6,3,2,1,9,7};
int data;

void printline(int count) {
    int i;

    for(i = 0;i < count-1;i++) {
        printf("=");
    }

    printf("=\n");
}

void display() {
    int i;
    printf("[");

    for(i = 0;i < data;i++) {
        printf("%d ",intArray[i]);
    }

    printf("]\n");
}

void swap(int num1, int num2) {
    int temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

int partition(int left, int right, int pivot) {
    int leftPointer = left -1;
    int rightPointer = right;

    while(true) {
        while(intArray[++leftPointer] < pivot) {
            //do nothing
        }
        
        while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
            //do nothing
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            printf(" item swapped :%d,%d\n", intArray[leftPointer],intArray[rightPointer]);
            swap(leftPointer,rightPointer);
        }
    }

    printf(" pivot swapped :%d,%d\n", intArray[leftPointer],intArray[right]);
    swap(leftPointer,right);
    printf("Updated Array: "); 
    display();
    return leftPointer;
}

void quickSort(int left, int right) {
    if(right-left <= 0) {
        return;   
    } else {
        int pivot = intArray[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left,partitionPoint-1);
        quickSort(partitionPoint+1,right);
    }        
}

void arrRandom() {

    printf("Masukkan bayak data : ");
    scanf("%i", &data);

    for (int i = 0; i < data; i++){
        intArray[i] = rand() % 100;
    }   
}

int main() {
    arrRandom();
    printf("\nInput Array: ");
    display();
    printline(data);
    quickSort(0,data-1);
    printf("Output Array: ");
    display();
    printline(data);
} 