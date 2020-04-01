#include <stdio.h>
#include <mpi.h>
int main (int argc, char *argv[])
{
    int id, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Hello world, I'm %d, and total is %d \n", id, size);
    MPI_Finalize();
    return 0;
}