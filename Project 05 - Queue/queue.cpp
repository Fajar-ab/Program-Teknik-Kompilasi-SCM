#include <iostream>
#include <stdio.h>
#include <conio.h>

#define MAX 200

struct Antrian{
    int kode[MAX];
    int masuk = -1;
    int proses = -1;   
};

Antrian antrian;

void masukAntrian();
void prosesAntrian();
void printAntrian();


void masukAntrian() {
    if(antrian.masuk == -1) {
        antrian.masuk++;
        antrian.kode[antrian.masuk] = 1;
    }else {
        antrian.masuk++;
        antrian.kode[antrian.masuk] = antrian.kode[antrian.masuk - 1] + 1;
    }

    printAntrian();
}

void prosesAntrian() {
    antrian.proses += 1;
    printAntrian();
}

void printAntrian() {
    system("cls");
    printf("\n<<< Antrian >>>\n\n");

    if(antrian.proses == -1) {
        for(int i=0; i <= antrian.masuk; i++){
            printf("A%03d\n", antrian.kode[i]);
        }
    }else if(antrian.proses >= 0){
        for(int i = antrian.proses; i <= antrian.masuk; i++) {
            if(i == antrian.proses) {
                printf("A%03d -> proses\n", antrian.kode[i]);
                // continue;
            }else {
                printf("A%03d\n", antrian.kode[i]);
            }
        }
    }
}

int main() {
    bool a = true;

    while (a) {
        
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
                prosesAntrian();
                break;
            case '4': 
                a = false;
        }
        
    }
}
