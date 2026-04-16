#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 3

int hamleYap(int oyun[M][M], int *bosSatir, int *bosSutun, int secilenSatir, int secilenSutun) {

    if (secilenSatir < 0 || secilenSatir >= M || secilenSutun < 0 || secilenSutun >= M) {
        printf("Gecersiz koordinat!\n");
        return 0;
    }

    if (oyun[secilenSatir][secilenSutun] == 0) {
        printf("Bos hucre secilemez!\n");
        return 0;
    }

    int satirFarki = secilenSatir - *bosSatir;
    int sutunFarki = secilenSutun - *bosSutun;

    if ((satirFarki == 0 && (sutunFarki == 1 || sutunFarki == -1)) ||
        (sutunFarki == 0 && (satirFarki == 1 || satirFarki == -1))) {
        
        oyun[*bosSatir][*bosSutun] = oyun[secilenSatir][secilenSutun];
        oyun[secilenSatir][secilenSutun] = 0;

        *bosSatir = secilenSatir;
        *bosSutun = secilenSutun;

        return 1;
    } 

    printf("Gecersiz hamle!\n");
    return 0; 
}

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

    int secilenS, secilenK;
    
    while (1) {
        printf("\nKaydirmak istediginiz tasin satir ve sutununu girin (Ornek: 1 2): ");

        if (scanf("%d %d", &secilenS, &secilenK) != 2) {
            printf("Hatali giris!\n");
            while(getchar() != '\n');
            continue;
        }

        if (hamleYap(oyun, &bosSatir, &bosSutun, secilenS, secilenK)) {
            printf("\n--- Yeni Durum ---\n");
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
        }
    }

    return 0;
}
