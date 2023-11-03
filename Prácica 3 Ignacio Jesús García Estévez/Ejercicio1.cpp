#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;
int miarray[5];
int recv_data; //buffer recepción
int suma;
int bufferrec[5];
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
if(rango==0){
 int miarray[5] = {2,3,4,5,1};



}
MPI_Scatter(&miarray, 1, MPI_INT, &recv_data, 1, MPI_INT, 0,MPI_COMM_WORLD); //envío y recepción de datos
suma= recv_data + rango;//hago la suma del rango con el dato recibido
MPI_Gather(&suma, 1, MPI_INT, &bufferrec, 1,
MPI_INT, 0, MPI_COMM_WORLD);// envío los datos al buferrec 
if(rango==0){//en el proceso 0 imprimo los datos que solo el proceso 0 sabe
for (int i=0;i<5;i++){
cout << miarray[i];

}
cout << endl;
for (int j=0;j<5;j++){
cout << bufferrec[j];

}
cout << endl;
}


MPI_Finalize(); //fin entorno MPI
return 0;
}
