
/*
 *Implementation of the Reverse Cuthill-Mckee Algorithm in c 
 *
 *Author: Doinakis Michail
 *e-mail: doinakis@ece.auth.gr
 * Main file modified https://math.nist.gov/MatrixMarket/mmio/c/example_read.c
 */

#include "../inc/globaldefines.h"
#include "../inc/rcm.h"
#include "../inc/queue.h"
#include "../inc/mmio.h"

struct timeval startwtime,endwtime;
double p_time;

int main(){

    int ret_code;
    FILE *f;
    int M, N, nz;   
    int *rows, *cols;
    // Note that the val variable is not use in this implementation but it could be used to calculate the weighted degree
    double *val;
    permutation *R = (permutation *)malloc(sizeof(permutation));
    

    if((f = fopen("./example_matrices/test.mtx", "r")) == NULL){
        printf("Could not open file. Check the file name and try again.");
        exit(1);
    }
      

    // Use mmio to find the size of the matrix and the non-zeros
    if ((ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz)) != 0){
        printf("File format should be market matrix. Could not read size of sparse matrix and non-zeros.");
        exit(1);
    }
        


    // Memory allocations 

    rows = (int *)malloc(nz*sizeof(int));
    cols = (int *)malloc(nz*sizeof(int));
    val = (double *)malloc(nz*sizeof(double));

    // Initialize a permutaion 
    permutationInit(R,N);

    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    for (int i=0; i<nz; i++)
    {
        ret_code = fscanf(f, "%d %d %lg\n", &rows[i], &cols[i], &val[i]);
        rows[i]--;  /* adjust from 1-based to 0-based */
        cols[i]--;
    }

    if (f != stdin) fclose(f);

    gettimeofday(&startwtime,NULL);
    R_Cuthill_Mckee(N,nz,rows,cols,R);
    gettimeofday(&endwtime,NULL);
    p_time = (double)((endwtime.tv_usec-startwtime.tv_usec)/1.0e6+endwtime.tv_sec-startwtime.tv_sec);

    for (int i=0; i<N; i++){
        fprintf(stdout, "%d ",R->perm[i]);

    }
    printf("Time %f\n",p_time);    
	
    // Deallocating the space that was malloced
    permutationDelete(R);
    free(rows);
    free(cols);
    free(val);

    return 0;
}