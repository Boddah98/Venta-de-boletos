struct Asiento{
	char* id;
	int estado;
	struct Asiento *sig;
}typedef Asiento;

Asiento* crearAsiento(char* idP){
	Asiento* asientoNuevo = (Asiento*) malloc (sizeof(Asiento));
	asientoNuevo-> id = idP;
    asientoNuevo-> ocupado = FALSE;
	asientoNuevo-> sig = NULL;
	return asientoNuevo;
}

struct ListaAsientos{
	Asiento* primero;
	Asiento* ultimo;
	int vacio;
	int contador;
}typedef ListaAsientos;

ListaAsientos* crearListaAsientos(){
	ListaAsientos* listaNueva = (ListaAsientos*) malloc (sizeof(ListaAsientos));
	listaNueva-> primero = NULL;
	listaNueva-> ultimo = NULL;
	listaNueva-> vacio = TRUE;
	listaNueva-> contador = 0;
	return listaNueva;
}

void agregarAsiento(Asiento* asiento, ListaAsientos* lista){
	if (lista-> vacio == TRUE){
		lista-> primero = asiento;
		lista-> ultimo = asiento;
		lista-> vacio = asiento;

	}else{
		lista-> ultimo-> sig = asiento;
		lista-> ultimo = asiento;
	}
	lista-> contador++;
}
