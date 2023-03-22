#define TRUE  1
#define FALSE 0

struct Sitio{
	char* nombre;
	char* ubicacion;
    char* sitioWeb;
	struct Sitio *sig;
}typedef Sitio;

Sitio* crearSitio (char* nombreP, char* ubicacionP, char* sitioWebP){
	Sitio* sitioNuevo = (Sitio*) malloc (sizeof(Sitio));
	sitioNuevo-> nombre = nombreP;
    sitioNuevo-> ubicacion = ubicacionP;
    sitioNuevo-> sitioWeb = sitioWebP;
	sitioNuevo-> sig = NULL;
	return sitioNuevo;
}

struct ListaSitios{
	Sitio* primero;
	Sitio* ultimo;
	int vacio;
	int contador;
}typedef ListaSitios;

ListaSitios* crearListaSitios(){
	ListaSitios* listaNueva = (ListaSitios*) malloc (sizeof(ListaSitios));
	listaNueva-> primero = NULL;
	listaNueva-> ultimo = NULL;
	listaNueva-> vacio = TRUE;
	listaNueva-> contador = 0;
	return listaNueva;
}

void agregarSitio(Sitio* sitio, ListaSitios* lista){
	if (lista-> vacio == TRUE){
		lista-> primero = sitio;
		lista-> ultimo = sitio;
		lista-> vacio = FALSE;

	}else{
		lista-> ultimo-> sig = sitio;
		lista-> ultimo = sitio;
	}
	lista-> contador++;
}

void imprimirListaSitios(ListaSitios *lista) {
	Sitio* sitioActual = lista->primero;

	if(sitioActual != NULL) {
		while(sitioActual != NULL){
			printf("Nombre: %s \nUbicacion: %s\nSitio Web: %s\n\n", sitioActual->nombre, sitioActual->ubicacion, sitioActual->sitioWeb);
			sitioActual = sitioActual->sig;
		}
	} else {
		printf("No se ha agregado ningun sitio por ahora...\n\n");
	}
}