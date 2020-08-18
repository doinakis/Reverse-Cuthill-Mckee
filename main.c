#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <stdbool.h>
#include "rcm.h"
#include "queue.h"
#include <limits.h>

struct timeval startwtime,endwtime;
double p_time;

int main(void){
    int n = 10;

    int *matrix = (int *)malloc(n*n*sizeof(int));
    queue *permutation = queueInit();

    int help[10][10] = {
        { 1, 1, 0, 0, 0, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 0, 0, 1, 0 },
        { 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
        { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
        { 1, 0, 0, 1, 0, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 },
    };
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix(i,j) = help[i][j];
            if(matrix(i,j)==1){
                printf("■ ");
            }else{
                printf("□ ");
            }
        }
        printf("\n");
    }

    Cuthill_Mckee(n,matrix,permutation);
    printf("The permutation of the matrix is: ");
    for(int i=0; i<10; i++){
        printf("%d ",permutation->buf[i].num);
    }
    R_Cuthill_Mckee(n,permutation);
    
    printf("The permutation of the matrix is: ");
    for(int i=0; i<10; i++){
        printf("%d ",permutation->buf[i].num);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            if(matrix(permutation->buf[i].num,permutation->buf[j].num)){
                printf("■ ");
            }else{
                printf("□ ");
            }
        }
        printf("\n");
    }
    queueDelete(permutation);
    free(matrix);
    
    return 0;
    
}