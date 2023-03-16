struct Evento{
	char* nombre;
	char* productora;
    char* fecha;
    Sitio* sitioEvento;
	struct Evento *sig;
}typedef Evento;

Evento* crearVacuna(char* nombreP, char* productoraP, char* fechaP, Sitio* sitioEventoP){
	Evento* eventoNuevo = (Evento*) malloc (sizeof(Evento));
	eventoNuevo-> nombre = nombreP;
    eventoNuevo-> productora = productoraP;
    eventoNuevo-> fecha = fechaP;
    eventoNuevo-> sitioEvento = sitioEventoP;
	eventoNuevo-> sig = NULL;
	return eventoNuevo;
}