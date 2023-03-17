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
