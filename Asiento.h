struct Asiento{
	char* id;
	int estado;
	struct Asiento *sig;
}typedef Asiento;

Asiento* crearVacuna(char* idP){
	Asiento* asientoNuevo = (Asiento*) malloc (sizeof(Asiento));
	asientoNuevo-> id = idP;
    	asientoNuevo-> ocupado = 0;
	asientoNuevo-> sig = NULL;
	return asientoNuevo;
}
