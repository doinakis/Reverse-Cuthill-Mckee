
/*
 *Implementation of the Reverse Cuthill-Mckee Algorithm in c 
 *
 *Author: Doinakis Michail
 *e-mail: doinakis@ece.auth.gr
 * Main file modified https://math.nist.gov/MatrixMarket/mmio/c/example_read.c
 */

#include "../inc/globaldefines.h"
#include "../inc/rcm_cilk.h"
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
    permutation *R = (permutation *)malloc(5*sizeof(permutation));
    if(R == NULL)
        printf("Couldn't allocate memory for the permutation.File: main_cilk Function: main");

    if((f = fopen("./example_matrices/paper/delaunay_n24.mtx", "r")) == NULL){
        printf("Could not open file. Check thee file name and try again.");
        exit(1);
    }
      

    // Use mmio to find the size of the matrix and the non-zeros
    if ((ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz)) != 0){
        printf("File format should be market matrix. Could not read size of sparse matrix and non-zeros.");
        exit(1);
    }
        


    // Memory allocations 

    rows = (int *)malloc(nz*sizeof(int));
    if(rows == NULL)
        printf("Couldn't allocate memory for rows matrix.File: main_cilk Function: main");
    cols = (int *)malloc(nz*sizeof(int));
    if(cols == NULL)
        printf("Couldn't allocate memory for cols matrix.File: main_cilk Function: main");
    val = (double *)malloc(nz*sizeof(double));
    if(val == NULL)
        printf("Couldn't allocate memory for rows matrix.File: main_cilk Function: main");

    // Initialize a permutation 
    for(int i=0;i<5;i++){
        permutationInit(&R[i],N);
    }
    

    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    for (int i=0; i<nz; i++)
    {
        ret_code = fscanf(f, "%d %d %lg\n", &rows[i], &cols[i], &val[i]);
        rows[i]--;  /* adjust from 1-based to 0-based */
        cols[i]--;
    }
    printf("done reading\n");
    if (f != stdin) fclose(f);

    for(int i=0;i<5;i++){
        gettimeofday(&startwtime,NULL);
        R_Cuthill_Mckee_cilk(N,nz,rows,cols,&R[i]);
        gettimeofday(&endwtime,NULL);
        printf("done\n");
        p_time += (double)((endwtime.tv_usec-startwtime.tv_usec)/1.0e6+endwtime.tv_sec-startwtime.tv_sec);
    }
    p_time = p_time*1/5;
    printf("Time %f\n",p_time);    
    // Deallocating the space that was malloced
    permutationDelete(R);
    free(rows);
    free(cols);
    free(val);

    return 0;
}