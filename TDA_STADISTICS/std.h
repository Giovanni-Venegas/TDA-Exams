
/*
----------std.h

@Creado por: Giovanni Josue Venegas Ramirez 
@Profesor: Angeles Ruiz Cesar Arturo
@fecha: 13/10/2020

*/

/*Estructura que sera utilizada para lois datos estadisticos*/

typedef struct Stadistics
{
    double *numeros;
    double TamMuestra;
    double media, mediana, moda, varianza, desviacion_estandar, rango, distancia_intercuartil;
} Tipo_medida;

/*
*Esta funcion abre el file y guarda los datos en el array
*
*@param
*   files(FILE *)
*   array[][](float *)
*   
*/

void PedirDatos(Tipo_medida *Valores); // Pedimos datos iniciales de la señal;

void open_document (Tipo_medida Valores);

void inicializa_vector_frencuencias();

void Imprimir_vector (Tipo_medida *Valores);

void calculo_frecuencias (Tipo_medida *Valores);

void media_aritmetica (Tipo_medida *Valores);

int frecuencia_modal();

void moda(Tipo_medida *Valores);

void imprime_frecuencias (Tipo_medida *Valores);

void mediana (Tipo_medida *Valores);

void varianza (Tipo_medida *Valores);

void desviacion_estandar (Tipo_medida *Valores);

void distancia_intercuatil (Tipo_medida *Valores);

void ImprimirArch(Tipo_medida Valores); // Imprimir el muestreo del tiempo y de todos los valores de la funcion evaluada en determinada frecuencia;

void Graficar(); // Grafica en gnuplot el archivo de texto que tiene los valores de la señal decodificada;
//void Cargando(char Mensaje[]); // Menú de carga -> estado en el cual se encuentra el programa;