#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>
#include <limits.h>
#include "std.h"

#define N 10

int vector_frecuencias[N][2];
int num_diferentes = 0;

void PedirDatos(Tipo_medida *Valores)
{
    printf("Tamaño de muestra (ARR): \n");
          //  scanf(" %lf",&Valores -> TamMuestra); 
          Valores->TamMuestra=N;
            printf ("El tamaño es: %i",N);
            
}

void open_document (Tipo_medida Valores){

    char NombreArchivo[100];
        FILE *Archivo;

            Archivo = fopen("data.csv","rt");
  
                if(Archivo==NULL)
                    {
                        printf("El archivo no existe\n");
                        printf("Saliendo del programa...");
                        exit(0);
                    }
                else
                    {
                    for(int i=0; i<=N;i++)
                        {
                        fscanf (Archivo, "%lf \n", &Valores.numeros[i]);
                        //fscanf (Archivo, "%f \n", &num[i]);
                        }
                    }
            fclose(Archivo);
            
}

void inicializa_vector_frencuencias() {
	for (int i = 0; i < 10; i++) {
		vector_frecuencias[i][0] = 0;
		vector_frecuencias[i][1] = 0;
	}
}

void calculo_frecuencias (Tipo_medida *Valores)
{
   int existe = false;
	int j;
        inicializa_vector_frencuencias();
        for (int i = 0; i < 10; i++) {
            for (j = 0; j < num_diferentes; j++) {
                if (vector_frecuencias[j][0] == Valores->numeros[i]) {
                    existe = true;
                    break;
                }
            }
            if (existe) {
                vector_frecuencias[j][1]++;
                existe = false;
            }
            else {
                vector_frecuencias[j][0] = Valores->numeros[i];
                vector_frecuencias[j][1]++;
                num_diferentes++;
            }
	    }       
}

int frecuencia_modal() {
	int fModal = INT_MIN;
	for (int i = 0; i < num_diferentes; i++) {
		if (vector_frecuencias[i][1] > fModal) {
			fModal = vector_frecuencias[i][1];
		}
	}
	return fModal;
}

void moda(Tipo_medida *Valores)
{
     int existe = false;
	int j;
        inicializa_vector_frencuencias();
        for (int i = 0; i < 10; i++) {
            for (j = 0; j < num_diferentes; j++) {
                if (vector_frecuencias[j][0] == Valores->numeros[i]) {
                    existe = true;
                    break;
                }
            }
            if (existe) {
                vector_frecuencias[j][1]++;
                existe = false;
            }
            else {
                vector_frecuencias[j][0] = Valores->numeros[i];
                vector_frecuencias[j][1]++;
                num_diferentes++;
            }
	    }       

    int fModal= frecuencia_modal();

	printf("Modas:\n");
	for (int i = 0; i < num_diferentes; i++) {
		if (vector_frecuencias[i][1] == fModal) {
			printf("%i \t %i\n",vector_frecuencias[i][0], vector_frecuencias[i][1]);
		}
	}
}

void imprime_frecuencias (Tipo_medida *Valores)
{
     //Valores->num_diferentes=0;
    printf("Frecuencias: \n");
	for (int i = 0; i < num_diferentes; i++) {
		printf("%i \t %i\n", vector_frecuencias[i][0], vector_frecuencias[i][1]);
	}

   /*int i;
        char NombreArchivo[100];
            FILE *Archivo;
                Archivo = fopen("resultados.txt","rt");

                /*for(i = 0; i<6;i++)
                    {
                    fprintf(Archivo,"%d %d\n",vector_frecuencias[i][0], vector_frecuencias[i][1]);
                    }*/
            //fclose(Archivo);

}



void Imprimir_vector(Tipo_medida *Valores)
{
    for (int i = 0; i < N; i++) {
		printf("%d - %.1f \n",i+1, Valores->numeros[i]);
	}
}

void media_aritmetica (Tipo_medida *Valores)
{
    float suma = 0;
	for (int i = 0; i < N; i++) {
		suma += Valores->numeros[i];
		//suma = suma+vector[i];
	}
    printf("\n-----------------------------------------------\n");
     printf("\n El valor de la media aritmetica es: ");
    printf (" %.2f ", Valores->media= suma/N);
}


void mediana(Tipo_medida *Valores)
{
    int i,j,aux;
    int rango;
    Valores->rango=rango;
	for ( i = 0; i < N - 1; i++) {
		for ( j = i + 1; j < N; j++) {
			if (Valores->numeros[i] > Valores->numeros[j]) {
				aux = Valores->numeros[i];
				Valores->numeros[i] = Valores->numeros[j];
				Valores->numeros[j] = aux;
			}
		}
	}
    printf("\n\n-----------------------------------------------\n");
    printf ("\nOrden ascendente: \n");
    for (i=0;i<10;i++)
    {
        printf ("%.1f, ", Valores->numeros[i]);
    }

   printf("\n-----------------------------------------------\n");
    Valores->rango= Valores->numeros[N-1]-Valores->numeros[0];
    printf ("\nEl valor del Rango: %.1f",Valores->rango);

    int pos = N / 2;
	float m = 0.0;
	if (10 % 2 == 0) {
		m = (float)(Valores->numeros[pos - 1] + Valores->numeros[pos]) / 2.0;
	}
	else {
		m = Valores->numeros[pos - 1];
	}
    Valores->mediana=m;
	//return m;
    printf("\n\n-----------------------------------------------\n");
        printf("\nEl valor de la mediana es: %f", Valores->mediana );
}

void varianza (Tipo_medida *Valores)
{
    	//float media = Valores->media;
	float var = 0;
	for (int i = 0; i <N; i++) {
		var += pow(Valores->numeros[i] - Valores->media, 2);
        //printf ("\n %.1f - %0.1f\n", Valores->numeros[i], Valores->media);
	}
    //printf ("Var--- %.1f", var);
	var = var/(N-1);
	//return var;
    Valores->varianza=var;
    printf("\n\n-----------------------------------------------\n");
    printf ("\nLa varianza es: %.4f\n", Valores->varianza);
}

void desviacion_estandar (Tipo_medida *Valores)
{
    Valores->desviacion_estandar= sqrt(Valores->varianza);

        printf("\n-----------------------------------------------\n");
        printf ("\nLa desviacion estandar es: %.3f\n", Valores->desviacion_estandar);
}

void distancia_intercuatil (Tipo_medida *Valores)
{
    int P1, P3;
    float Dist;
    float Q1,Q3;

        P1= (N+1)/4;
        P3= 3*(N+1)/4;

        Q1= Valores->numeros[P1]+ 0.25*(Valores->numeros[P1+1]-Valores->numeros[P1]);
        Q3= Valores->numeros[P3]+ 0.75*(Valores->numeros[P3+1]-Valores->numeros[P3]);

            Dist= Q3-Q1; 
            Valores->distancia_intercuartil=Dist;
            printf("\n-----------------------------------------------\n");
            printf ("\nLa distancia interculinaria o intercuatil es: %.1f\n", Valores->distancia_intercuartil);
            printf("\n-----------------------------------------------\n");
      //return Dist; 
}

void ImprimirArch(Tipo_medida Valores)
{
    char NombreArchivo[100];
        FILE *Archivo;
        fflush(stdin);
        puts("Introduce el nombre del archivo: ");
        gets (NombreArchivo);
            Archivo = fopen(NombreArchivo,"rt");
  
                if(Archivo==NULL)
                    {
                        printf("El archivo no existe\n");
                        printf("Saliendo del programa...");
                        fclose(Archivo);
                        //exit(0);
                    }
                else
                    {
                        Archivo = fopen(NombreArchivo,"wt");
                    for(int i=0; i<num_diferentes;i++)
                        {
                        fprintf (Archivo, "%d %d \n", vector_frecuencias[i][0], vector_frecuencias[i][1]);
                        }
                    }
            fclose(Archivo);
        
}

void Graficar()
{
  int i;
  char *AbrirGnuPlot[] = {"set title \"TDA_STADISTICS HISTOGRAM\"",
			  "set ylabel \"----Frecuancia--->\"",
			  "set xlabel \"----Numeros--->\"",
			  "plot \"result.txt\" with lines"
  };
  FILE *VentanaGnuPlot = popen ("gnuplot -persist", "w");
  for (i=0; i<4; i++)
    fprintf(VentanaGnuPlot, "%s \n", AbrirGnuPlot[i]);
}