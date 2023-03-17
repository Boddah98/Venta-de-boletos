struct Sitio{
	char* nombre;
	char* ubicacion;
    char* sitioWeb;
	struct Sitio *sig;
}typedef Sitio;

Sitio* crearSitio (char* nombreP, char* ubicacionP, Pais* sitioWebP){
	Sitio* sitioNuevo = (Sitio*) malloc (sizeof(Sitio));
	sitioNuevo-> nombre = nombreP;
    sitioNuevo-> ubicacion = ubicacionP;
    sitioNuevo-> sitioWeb = sitioWebP;
	sitioNuevo-> sig = NULL;
	return sitioNuevo;
}

///Hola