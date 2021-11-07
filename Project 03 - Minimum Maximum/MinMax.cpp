#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*====================================
 | Program cari data Minimum Maksimum |
 | Menggunakan Data Random            |
 | Dibuat : Fajar Fadilah             |
 | NPM    : 2019010012                |
 ====================================*/

double data[100], dataMin, dataMax, totalData = 0, rataRata;
int jmlData, i;

int main() {
  printf("Berapa jumlah data = "); scanf("%i", &jmlData);

  srand(time(0));

  for (i=0; i<jmlData; i++) {
      data[i] = rand() % 200;
      totalData += data[i];
  }

  printf("Data = \n");

  for (i=0; i<jmlData; i++) {
     printf("%8.2f",data[i]);
  }

  dataMin = data[0];
  dataMax = data[0];

  for (i=1; i<jmlData; i++) {
     if (data[i] < dataMin) {
        dataMin = data[i];
     }

     if (data[i] > dataMax) {
        dataMax = data[i];
     }

  }

  rataRata = totalData / jmlData;

  printf("\n");
  printf("Data minimum   = %8.2f\n",dataMin);
  printf("Data maximum   = %8.2f\n",dataMax);
  printf("Total Data     = %8.2f\n",totalData);
  printf("Rata-rata Data = %8.2f\n",rataRata);

}
