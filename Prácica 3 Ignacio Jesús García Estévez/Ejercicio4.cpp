#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
int rango;
int mayor;
int menor;
MPI_Init(&argc, &argv); //inicialización entorno MPI
MPI_Comm_rank(MPI_COMM_WORLD, &rango); //rango del proceso
int numerosecreto;
if(rango==0){
numerosecreto=12;// le doy un valor a numerosecreto que solo sabe el proceso 0

}
MPI_Bcast(&numerosecreto, 1, MPI_INT,0, MPI_COMM_WORLD);
numerosecreto=numerosecreto+rango;//hago un broadcast a todos los procesos desde el 0 y lo recibo en los demas
MPI_Reduce(&numerosecreto, &mayor, 1, MPI_INT, MPI_MAX, 0,
MPI_COMM_WORLD);//hago un reduce para enviarle los datos al proceso 0 que se quedará con el mayor 
MPI_Reduce(&numerosecreto, &menor, 1, MPI_INT, MPI_MIN, 0,
MPI_COMM_WORLD);//los vuelvo a enviar para que se quede con el menor

if(rango==0){//imprimo desde el proceso 0 que es el unico que sabe estos nñumeros
cout<<"El numero mayor es: "<< mayor<< " "<<endl;
cout<<"El numero menor es: "<< menor<< endl;
}

MPI_Finalize(); //fin entorno MPI
return 0;
}
