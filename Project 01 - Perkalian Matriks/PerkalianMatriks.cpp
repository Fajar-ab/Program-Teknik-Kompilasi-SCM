#include <stdio.h>

/*===========================
 | Program perkalian Matriks |
 | Menggunakan Input Data    |
 | Dibuat : Fajar Fadilah    |
 | NPM    : 2019010012       |
 ===========================*/

double matriksA[10][10], matriksB[10][10], matriksC[10][10];
int brsA, kolA, kolB, i, j, k;

int main() {
  printf("Jumlah baris Matriks A = "); scanf("%i", &brsA);
  printf("Jumlah kolom Matriks A = "); scanf("%i", &kolA);
  printf("Jumlah baris Matriks B = %i\n", kolA);
  printf("Jumlah kolom Matriks B = "); scanf("%i", &kolB);


  for (i=0; i<brsA; i++) {
    for (j=0; j<kolA; j++) {
      printf("Matriks A[%i][%i] = ", i+1, j+1); scanf("%lf", &matriksA[i][j]);
    }
  }

  for (i=0; i<kolA; i++) {
    for (j=0; j<kolB; j++) {
      printf("Matriks B[%i][%i] = ", i+1, j+1); scanf("%lf", &matriksB[i][j]);
    }
  }


  printf("Matriks A = \n");

  for (i=0; i<brsA; i++) {
    for (j=0; j<kolA; j++) {
      printf("%8.2f",matriksA[i][j]);

    }
    printf("\n");
  }

  printf("Matriks B = \n");

  for (i=0; i<kolA; i++) {
    for (j=0; j<kolB; j++) {
      printf("%8.2f",matriksB[i][j]);

    }
    printf("\n");
  }

  for (i=0; i<brsA; i++) {
    for (j=0; j<kolB; j++) {
      matriksC[i][j] = 0.0;
      for (k=0; k<kolA; k++) {
        matriksC[i][j] = matriksC[i][j] + matriksA[i][k] * matriksB[k][j];
      }
    }
  }

  printf("Matriks C = \n");

  for (i=0; i<brsA; i++) {
    for (j=0; j<kolB; j++) {
      printf("%12.2f",matriksC[i][j]);

    }
    printf("\n");
  }

}
