struct Evento{
	char* nombre;
	char* productora;
    	char* fecha;
    	Sitio* sitioEvento;
	struct Evento *sig;
}typedef Evento;

Evento* crearEvento(char* nombreP, char* productoraP, char* fechaP, Sitio* sitioEventoP){
	Evento* eventoNuevo = (Evento*) malloc (sizeof(Evento));
	eventoNuevo-> nombre = nombreP;
    	eventoNuevo-> productora = productoraP;
    	eventoNuevo-> fecha = fechaP;
    	eventoNuevo-> sitioEvento = sitioEventoP;
	eventoNuevo-> sig = NULL;
	return eventoNuevo;
}

struct ListaEventos{
	Evento* primero;
	Evento* ultimo;
	int vacio;
	int contador;
}typedef ListaEventos;

ListaEventos* crearListaEventos(){
	ListaEventos* listaNueva = (ListaEventos*) malloc (sizeof(ListaEventos));
	listaNueva-> primero = NULL;
	listaNueva-> ultimo = NULL;
	listaNueva-> vacio = TRUE;
	listaNueva-> contador = 0;
	return listaNueva;
}

void agregarEvento(Evento* evento, ListaEventos* lista){
	if (lista-> vacio == TRUE){
		lista-> primero = evento;
		lista-> ultimo = evento;
		lista-> vacio = FALSE;

	}else{
		lista-> ultimo-> sig = evento;
		lista-> ultimo = evento;
	}
	lista-> contador++;
}
