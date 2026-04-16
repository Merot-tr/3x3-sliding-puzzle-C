#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 3

int main() {
    int oyun[M][M], i, j;
    int bosSatir = 2, bosSutun = 2;
    srand(time(NULL));

    int sayac = 1;
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            if (i == 2 && j == 2) {
                oyun[i][j] = 0;
            } else {
                oyun[i][j] = sayac++;
            }
        }
    }

    int hamleSayisi = 0;
    while (hamleSayisi < 100) {
        int yon = rand() % 4;
        int yeniS = bosSatir, yeniK = bosSutun;

        if (yon == 0) yeniS--;
        else if (yon == 1) yeniS++;
        else if (yon == 2) yeniK--;
        else if (yon == 3) yeniK++;

        if (yeniS >= 0 && yeniS < M && yeniK >= 0 && yeniK < M) {
            oyun[bosSatir][bosSutun] = oyun[yeniS][yeniK];
            oyun[yeniS][yeniK] = 0;
            bosSatir = yeniS;
            bosSutun = yeniK;
            hamleSayisi++;
        }
    }

    printf("   0  1  2\n");
    for (i = 0; i < M; i++) {
        printf("%d ", i);
        for (j = 0; j < M; j++) {
            if (oyun[i][j] == 0) {
                printf("[ ]");
            } else {
                printf("[%d]", oyun[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
