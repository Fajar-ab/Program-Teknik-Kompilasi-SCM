#include <iostream>
#include <stdio.h>
#include <conio.h>

# define MAX 200

struct Antrian {
    int kode[MAX];
    int masuk;
    int proses;
}A;

void menu();
void masukAntrian();
void printAntrian();

int main() {
    menu();

    return 0;
}

void menu() {

    bool a = true;

    while (true) {
        
        printf("\n<<< Menu Pilihan >>>\n");
        printf("1. Setting Parameter\n");
        printf("2. Masuk Antrian\n");
        printf("3. Proses Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda [1..4][ ]\b\b");
        char tekan = ' ';

        while (!(tekan>='1' && tekan<='4')) {
            tekan = getch();
        }

        printf("%c\n",tekan);
        switch (tekan) {
            case '1': 
                break;
            case '2':
                masukAntrian();
                break;
            case '3':
                A.proses++;
                break;
            case '4': 
                a = false;
        }
        system("cls");
        printAntrian();
    }

}

void masukAntrian() {
    
    if(A.masuk == 0) {
        A.kode[A.masuk] = 1;
        A.masuk++;
    }else {
        A.kode[A.masuk] = A.kode[A.masuk-1] + 1;
        A.masuk++;
    }
}

void printAntrian() {
    printf("\n<<<< Antian >>>>\n");

    for(int i = A.proses; i < A.masuk; i++) {
        if(i == A.proses) {
            printf("\nA%03d > PROSES", A.kode[i]);
        }
        printf("\nA%03d", A.kode[i]);
    }
    printf("\n\n");
}
    