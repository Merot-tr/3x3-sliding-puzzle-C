#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
int main(){
   int oyun[M][M],i,j;
    srand(time(NULL));
    for(i=0;i<M;i++){
            for(j=0;j<M;j++){
            if(i==0 && j==0 || i==0 && j==1 || i==0 && j==2 || i==1 && j==0 || i==1 && j==1 || i==1 && j==2 || i==2 && j==0 || i==2 && j==1){
                oyun[i][j]=rand()%8+1;
                printf("[%d]", oyun[i][j]);
            }
            else{do{
            printf("[ ]");
             oyun[i][j]=0;

            }while(oyun[i][j]!=0);}
        }
        printf("\n");
   }

    return 0;
}