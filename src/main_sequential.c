
#include "../inc/globaldefines.h"
#include "../inc/rcm.h"
#include "../inc/queue.h"


struct timeval startwtime,endwtime;
double p_time;

int main(void){
    // Number of nodes in the graph 
    // int n = 2713;
    size_t size;
    // Initialize the adjacency matrix
    int *matrix = (int *)malloc(N*N*sizeof(int));
    permutation *R = (permutation *)malloc(sizeof(permutation));
    permutationInit(R);
    // Read the matrix
    // FILE *fp = fopen("./example_matrices/matrix_barbell.bin", "rb");
    // size = fread(matrix, sizeof(int), N * N, fp);
    // if(size!=N*N) exit(EXIT_FAILURE);
    // fclose(fp);
    // Initialize a permutation queue
    //queue *permutation = queueInit();

    // Matrix as input for reordering 
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
    // Visual representation of the original matrix
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matrix(i,j) = help[i][j];
            if(matrix(i,j)==1){
                printf("\u25CF ");
            }else{
                printf("\u25CB ");
            }
        }
        printf("\n");
    }
    gettimeofday(&startwtime,NULL);
    R_Cuthill_Mckee(N,matrix,R);
    gettimeofday(&endwtime,NULL);
    p_time = (double)((endwtime.tv_usec-startwtime.tv_usec)/1.0e6+endwtime.tv_sec-startwtime.tv_sec);
    printf("Time %f\n",p_time);
    printf("The permutation of the matrix is: ");
    for(int i=0; i<N; i++){
        printf("%d ",R->perm[i]);
    }
    printf("\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(matrix(R->perm[i],R->perm[j]) || i == j){
                printf("\u25CF ");
            }else{
                printf("\u25CB ");
            }
        }
        printf("\n");
    }
    permutationDelete(R);
    free(matrix);
    
    return 0;
    
}
