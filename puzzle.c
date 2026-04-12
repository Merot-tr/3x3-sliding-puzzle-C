#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
int main(){
   int oyun[M][M],i,j;
    srand(time(NULL));
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            oyun[i][j]=rand()%10;
            printf("[%d]", oyun[i][j]);
        }
    }
    return 0;
}