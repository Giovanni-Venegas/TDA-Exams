///Declaracion de librerias

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>
#include <limits.h>
#include "std.h"


//Declaracion de la estructura


int main (void)
{
    system("clear");
    printf ("Primer Examen Parcial de Taller de Desarrollo de Aplicaciones\n");
    printf ("                    TDA_STADISTICS");
    printf("\n-----------------------------------------------\n");
    Tipo_medida Senal;
    PedirDatos(&Senal);
    printf("\n-----------------------------------------------\n");
    
    Senal.numeros= (double *) malloc (sizeof (Tipo_medida)*Senal.TamMuestra); 
    //Senal.vector_frecuencias= (double **) malloc (sizeof (Tipo_medida)*Senal.TamMuestra);
    open_document(Senal);
    printf ("Valores recolectados del fichero seleccionado\n\n");
    Imprimir_vector(&Senal);

     
     media_aritmetica(&Senal);
     mediana(&Senal);
     varianza(&Senal);
     desviacion_estandar(&Senal);
     distancia_intercuatil(&Senal);

     moda(&Senal);
     imprime_frecuencias(&Senal);

     ImprimirArch(Senal);
     Graficar();
    return 0;

}