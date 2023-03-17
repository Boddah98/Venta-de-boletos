struct Sector{
	char* nombre;
	int espacios;
    	char inicial;
	int montoXasiento;
    	int montoRecaudado;
    	ListaAsientos* listaAsientos;
	struct Sector *sig;
}typedef Sector;

ListaAsientos* generarAsientos(char inicialP){}

Sector* crearVacuna(char* nombreP, int espaciosP, char inicialP, int montoXasientoP){
	Sector* sectorNuevo = (Sector*) malloc (sizeof(Sector));
	sectorNuevo-> nombre = nombreP;
    	sectorNuevo-> espacios = espaciosP;
    	sectorNuevo-> inicial = inicialP;
    	sectorNuevo-> montoXasiento = montoXasientoP;
    	sectorNuevo-> listaAsientos = generarAsientos(inicialP);
	sectorNuevo-> sig = NULL;
	return sectorNuevo;
}
