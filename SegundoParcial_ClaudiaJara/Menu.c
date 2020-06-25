#include "Menu.h"


int ShowMainMenu(){
	int option;

	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Ordenar la lista.\n");
	printf("3. Mostrar la lista\n");
	printf("4. Aplicar descuento\n");
	printf("5. Generar archivo de salida [mapeado.csv]\n");
	printf("6. SALIR\n");

	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-6)\n",LOAD_TEXT,EXIT ,RETRIES);
	return option;
}

