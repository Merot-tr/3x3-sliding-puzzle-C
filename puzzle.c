#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
int main(){
   int oyun[M][M],i,j;
    srand(time(NULL));
    printf("  0  1  2\n");
    for(i=0;i<M;i++){
        printf("%d", i);
            for(j=0;j<M;j++){
            if(i==0 && j==0 || i==0 && j==1 || i==0 && j==2 || i==1 && j==0 || i==1 && j==1 || i==1 && j==2 || i==2 && j==0 || i==2 && j==1){
             int kontrol;
             do{
                 
                 oyun[i][j]=rand()%8+1;
                 kontrol=0;

                 for(int k=0;k<=i;k++){
                   int sinir;
                     if(k==i){
                         sinir=j;
                     }
                     else{
                         sinir=M;
                     }
                     for(int l=0;l<sinir;l++){
                         if(oyun[i][j]==oyun[k][l]){
                             kontrol=1;
                             break;
                         }
                 }
                    if(kontrol==1){
                             break;
                         } 
            }}while(kontrol==1);
                printf("[%d]",oyun[i][j]);
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