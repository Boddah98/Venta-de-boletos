struct Sector{
	char* nombre;
	int espacios;
    char* inicial;
	int montoXasiento;
    int montoRecaudado;
    ListaAsientos* listaAsientos;
	struct Sector *sig;
}typedef Sector;

ListaAsientos* generarAsientos(char* inicialP, int espaciosP){
	ListaAsientos* listaAsientos = crearListaAsientos();

	char idNuevo[10];
	int cont = 0;
	while(cont < espaciosP){
		sprintf(idNuevo, "%s%d", inicialP, cont);
		char* idNuevoT = malloc((strlen(idNuevo)+1)*sizeof(char));
		strcpy(idNuevoT, idNuevo);

		Asiento* asientoNuevo = crearAsiento(idNuevoT);
		agregarAsiento(asientoNuevo, listaAsientos);
		cont++;
		//strcpy(idNuevo, "");
	}
	return listaAsientos;
}

Sector* crearSector(char* nombreP, int espaciosP, char* inicialP, int montoXasientoP){
	Sector* sectorNuevo = (Sector*) malloc (sizeof(Sector));
	sectorNuevo-> nombre = nombreP;
    sectorNuevo-> espacios = espaciosP;
    sectorNuevo-> inicial = inicialP;
    sectorNuevo-> montoXasiento = montoXasientoP;
    sectorNuevo-> listaAsientos = generarAsientos(inicialP, espaciosP);
	sectorNuevo-> sig = NULL;
	return sectorNuevo;
}

struct ListaSectores{
	Sector* primero;
	Sector* ultimo;
	int vacio;
	int contador;
}typedef ListaSectores;

ListaSectores* crearListaSectores(){
	ListaSectores* listaNueva = (ListaSectores*) malloc (sizeof(ListaSectores));
	listaNueva-> primero = NULL;
	listaNueva-> ultimo = NULL;
	listaNueva-> vacio = TRUE;
	listaNueva-> contador = 0;
	return listaNueva;
}

void agregarSector(Sector* sector, ListaSectores* lista){
	if (lista-> vacio == TRUE){
		lista-> primero = sector;
		lista-> ultimo = sector;
		lista-> vacio = FALSE;

	}else{
		lista-> ultimo-> sig = sector;
		lista-> ultimo = sector;
	}
	lista-> contador++;
}