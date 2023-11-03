#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;
int size;
int bufferrec[3]; //buffe recepción

MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
MPI_Comm_size(MPI_COMM_WORLD, &size);//tamaño 


int miarray[3]={rango,(rango+1),(rango+2)};//iniacializo el array en cada proceso y le guardo los datos


MPI_Reduce(&miarray, &bufferrec, 3, MPI_INT, MPI_SUM, 0,
MPI_COMM_WORLD);//hago un reduce para enviarle los datos sumandolos todos al proceso 0
if(rango==0){
cout<<bufferrec[0]<<" ";
cout<<bufferrec[1]<< " ";
cout<<bufferrec[2]<<endl;//muestro el buffer recivido en el proceso 0 
}

MPI_Finalize(); //fin entorno MPI
return 0;
}
