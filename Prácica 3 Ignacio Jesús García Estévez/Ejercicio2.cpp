#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;


int recv_data; //buffer recepción
int suma;

int size;
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
MPI_Comm_size(MPI_COMM_WORLD, &size);//tamaño 
int miarray[size];
int bufferrec[size];
if(rango==0){
for(int i=0;i<size;i++){
miarray[i]=i;
}
}
MPI_Scatter(&miarray, 1, MPI_INT, &recv_data, 1, MPI_INT, 0,MPI_COMM_WORLD); //envío y recepción de datos
suma= recv_data + rango;//hago la suma del rango con el dato recibido
MPI_Gather(&suma, 1, MPI_INT, &bufferrec, 1,
MPI_INT, 0, MPI_COMM_WORLD);// envío los datos al buferrec 
if(rango==0){//en el proceso 0 imprimo los datos que solo el proceso 0 sabe
for (int i=0;i<size;i++){
cout << miarray[i];

}
cout << endl;
for (int j=0;j<size;j++){
cout << bufferrec[j];

}
cout << endl;
}


MPI_Finalize(); //fin entorno MPI
return 0;
}
