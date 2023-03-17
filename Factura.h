struct Factura{
    int id;
	char* nombreEvento;
	char* fechaCompra;
	char* cliente;
	int subTotal;
	struct Factura *sig;
}typedef Factura;

Factura* crearFactura(int idP, char* nombreEventoP, char* fechaCompraP, char* clienteP, int subTotalP){
	Factura* facturaNueva = (Factura*) malloc (sizeof(Factura));
	facturaNueva-> id = idP;
	facturaNueva-> nombreEvento = nombreEventoP;
	facturaNueva-> fechaCompra = fechaCompraP;
	facturaNueva-> cliente = clienteP;
	facturaNueva-> subTotal = subTotalP;
	facturaNueva-> sig = NULL;
	return facturaNueva;
}

struct ListaFacturas{
	Factura* primero;
	Factura* ultimo;
	int vacio;
	int contador;
}typedef ListaFacturas;

ListaFacturas* crearListaFacturas(){
	ListaFacturas* listaNueva = (ListaFacturas*) malloc (sizeof(ListaFacturas));
	listaNueva-> primero = NULL;
	listaNueva-> ultimo = NULL;
	listaNueva-> vacio = TRUE;
	listaNueva-> contador = 0;
	return listaNueva;
}

void agregarVacuna(Factura* factura, ListaFacturas* lista){
	if (lista-> vacio == TRUE){
		lista-> primero = factura;
		lista-> ultimo = factura;
		lista-> vacio = FALSE;

	}else{
		lista-> ultimo-> sig = factura;
		lista-> ultimo = factura;
	}
	lista-> contador++;
}
