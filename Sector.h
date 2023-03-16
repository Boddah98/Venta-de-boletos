struct Sector{
	char* nombre;
	int espacios;
    char inicial;
    int monto;
    ListaAsientos* listaAsientos;
	struct Sector *sig;
}typedef Sector;

ListaAsientos* generarAsientos(char inicialP){}

Sector* crearVacuna(char* nombreP, int espaciosP, char inicialP, int montoP){
	Sector* sectorNuevo = (Sector*) malloc (sizeof(Sector));
	sectorNuevo-> nombre = nombreP;
    sectorNuevo-> espacios = espaciosP;
    sectorNuevo-> inicial = inicialP;
    sectorNuevo-> inicial = montoP;
    sectorNuevo-> listaAsientos = generarAsientos(inicialP);
	sectorNuevo-> sig = NULL;
	return sectorNuevo;
}