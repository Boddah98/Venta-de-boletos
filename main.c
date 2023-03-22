#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SitioEvento.h"

Sitio* leerSitio(char* linea){
	char* token = strtok(linea, ",");
	char* nombre = malloc((20)*sizeof(char));
	char* ubicacion = malloc((20)*sizeof(char));
	char* sitioWeb = malloc((20)*sizeof(char));

	if (token != NULL) {
		strcpy(nombre, token);
		token = strtok(NULL, ",");
		if(token != NULL){
			strcpy(ubicacion, token);
			token = strtok(NULL, ",");
			if(token != NULL){
				strcpy(sitioWeb, token);	
				Sitio* sitioNuevo = crearSitio(nombre, ubicacion, sitioWeb);
				return sitioNuevo;
			}else {
				return NULL;
			}
		}else {
			return NULL;
		}
	}else {
		return NULL;
	}
}

int cargarSitios(char* direccion, ListaSitios* listaSitios){
	//Leemos las lineas primero.
    FILE *archivo = fopen(direccion, "r");
    if (archivo == NULL)
    {
        return FALSE;
    }

	char buffer[100]; //Tamaño de la linea a leer.

    while (fgets(buffer, 100, archivo)){
		Sitio* sitioNuevo = leerSitio(buffer);// Aqui se lee una linea, y se extrae los atributos del sitio de evento, para poder guardarlos un nuevo objeto de tipo Sitio.
		if(sitioNuevo != NULL) {
			agregarSitio(sitioNuevo, listaSitios);
		} else {
			printf("Advertencia: Una linea del archivo de texto ha sido omitida, debido a que no cumple con el formato establecido (nombre,ubicacion,sitio web).\n");
		}
	}    
    fclose(archivo);
	return TRUE;
}

void gestionSitiosEvento(ListaSitios* listaSitios){
	char direccion[50];

	printf("\n--------------------\n|Gestion de eventos|\n--------------------\nPara poder cargar nuevos sitios de evento, por favor ingrese la direccion en donde se encuentra ubicado el archivo de texto que continene los sitios de evento.\n\n");
	printf("Ingrese una direccion: ");
	scanf(" %[^\t\n]s", &direccion);
	if (cargarSitios(direccion, listaSitios)) {
		printf("Se ha finalizado la carga de los sitios correctamente\n\n");
	} else {
		printf("Error: No se pudo abrir el archivo ubicado en la direccion: %s\n\n", direccion);
	}
}

int main() {
    int salir = FALSE;
	int opcion;
	char c;

	ListaSitios* listaSitios = crearListaSitios();

	printf("\n-------------------------------------------\n|Bienvenido al sistema de venta de boletos|\n-------------------------------------------\n\n");
	while (salir != TRUE){
		printf("Por favor seleccione una opcion:\n   1)Gestion de sitios de evento\n   2)Gestion de espacios sitio de eventos\n   3)Gestion de eventos\n   4)Estado de evento\n   5)Lista de Facturas\n   6)Estadisticas\n   7)Salir\nIngrese un numero: ");
		if (scanf("%i", &opcion) != 1 ){
			while ((c = getchar()) != '\n' && c != EOF) { }
			printf("Error: Por favor ingrese unicamente numeros enteros.\n\n");
    	}else {
			switch (opcion)
			{
			case 1:
				gestionSitiosEvento(listaSitios);
				break;

			case 2:
				printf("Selecciono la opcion 2.\n\n");
				break;

			case 3:
				printf("Selecciono la opcion 3.\n\n");
				break;
            
			case 4:
				printf("Selecciono la opcion 4.\n\n");
				break;

            case 5:
				printf("Selecciono la opcion 5.\n\n");
				break;

            case 6:
				printf("Selecciono la opcion 6.\n\n");
				break;

            case 7:
				printf("El programa ha sido finalizado correctamente.\n\n");
                salir = TRUE;
				break;
                	
			default:
				while ((c = getchar()) != '\n' && c != EOF) { }
				printf("Error: Por favor ingrese una opcion valida.\n\n");
				break;
			}
		}
	}
	return 0;
}