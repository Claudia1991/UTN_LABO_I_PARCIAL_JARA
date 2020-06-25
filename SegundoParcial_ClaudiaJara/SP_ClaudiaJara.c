#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "Item.h"
#include "LinkedList.h"
#include "defines.h"
#include "Menu.h"

int main() {
	setbuf(stdout, NULL);
	char nameFile[SIZE_CHAR_ARRAY];
	FILE *pFile;
	LinkedList *listaVentaArticulos = ll_newLinkedList();
	printf(":::::::::: INICIO DISTRIBUIDORA ::::::::::\n");
	do {
		switch (ShowMainMenu()) {
		case LOAD_TEXT:
			printf(":::Inicio::: cargar archivo\n \n");
			GetString(nameFile,
					"Ingrese el nombre del archivo para levantar los datos: ",
					":::ERROR::: ingrese nuevamente\n", RETRIES);
			strcat(nameFile, ".csv");
			pFile = fopen(nameFile, "r");
			if (pFile == NULL) {
				printf(
						":::ERROR::: No se pudo abrir el archivo en modo lectura.\n");
				pFile = fopen(nameFile, "r+");
				if (pFile == NULL) {
					printf(
							":::ERROR::: No se pudo abrir el archivo en modo escritura, verifique el nombre.\n");
				}
			} else {
				parser_fromText(pFile, listaVentaArticulos);
				printf(":::EXITO::: Se leyo el archivo correctamente.\n");
			}
			printf(":::FIN::: cargar archivo\n \n");
			break;
		case SORT_LIST:
			printf(":::INICIO::: Ordenar Lista\n \n");
			if (!ll_isEmpty(listaVentaArticulos)) {
				ll_sort(listaVentaArticulos, item_OrderListItemsByItem, ORDER_ASC);
				printf(":::EXITO::: Lista ordenada\n \n");
			} else {
				printf(":::ERROR::: La lista de articulos esta vacia.\n");
			}
			printf(":::FIN::: Ordenar Lista\n \n");
			break;
		case SHOW:
			printf(":::INICIO::: Mostrar Lista\n \n");
			if (!ll_isEmpty(listaVentaArticulos)) {
				eItem *auxItem;
				for (int i = 0; i < ll_len(listaVentaArticulos); i++) {
					auxItem = (eItem*) ll_get(listaVentaArticulos, i);
					if (auxItem != NULL) {
						item_show(auxItem);
					}
				}
			} else {
				printf(":::ERROR::: La lista de articulos esta vacia.\n");
			}
			printf(":::FIN::: Mostrar Lista\n \n");
			break;
		case DO_DISCOUNT:
			printf(":::INICIO::: Aplicar descuento\n \n");
			if (!ll_isEmpty(listaVentaArticulos)) {
				ll_map(listaVentaArticulos, item_DoDiscount);
			} else {
				printf(":::ERROR::: La lista de articulos esta vacia.\n");
			}
			printf(":::FIN::: Aplicar descuento---\n \n");
			break;
		case DO_FILE:
			printf(":::INICIO::: Crear archivo mapeado\n \n");
			if (!ll_isEmpty(listaVentaArticulos)) {
				pFile = fopen(SOURCE_DATA, "w");
				if (pFile != NULL) {
					fputs(HEADER, pFile);
					printf(":::[EXITO]::: Insercion header archivo.\n");
					int id, idSection, price;
					char item[SIZE_CHAR_ARRAY], measure[SIZE_CHAR_ARRAY];
					eItem *currentItem;

					for(int i =0; i <ll_len(listaVentaArticulos); i++){
						currentItem = (eItem*) ll_get(listaVentaArticulos, i);
						if((!item_getId(currentItem, &id)	&& !item_getItem(currentItem, item)	&& !item_getPrice(currentItem, &price)
								&& !item_getMeasure(currentItem, measure) && !item_getIdSection(currentItem, &idSection))){
							fprintf(pFile, DATA_FORMAT_SAVE, id, item, measure ,price, idSection);
						}
					}
					printf(":::[EXITO]::: Proceso finalizado.\n");
				} else {
					printf(":::[ERROR]::: En la apertura de archivo.\n");
				}
				fclose(pFile);
			} else {
				printf(":::ERROR::: La lista de articulos esta vacia.\n");
			}
			printf(":::FIN::: Crear archivo mapeado\n \n");
			break;
		case EXIT:
			ll_clear(listaVentaArticulos);
			ll_deleteLinkedList(listaVentaArticulos);
			printf("---------- FIN DISTRIBUIDORA ----------\n");
			exit(EXIT_SUCCESS);
			break;

		}
	} while (1);
	return EXIT_SUCCESS;
}
