#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

const char ARCHIVOPLATOS[11]="platos.dat";
const char ARCHIVOCLIENTES[13]="clientes.dat";
const char ARCHIVOPEDIDOS[12]="pedidos.dat";
const int TAMCELDACLIENTE=30;
const int TAMCELDAPLATO=30;

struct plato{
    int IDplato;
    char nombre[50];
    float costo;
    float imp;
    int TiempoPrep;
    int IDrestaurante;
    int comision;
    int categoria;
    bool estado;
};

struct fecha{
    int dia, mes, anio;
};

struct cliente{
    int IDcliente;
    char apellidos [50];
    char nombres [50];
    char mail [50];
    char domicilio[100];
    int CP;
    fecha nacimiento;
    bool estado;
};

struct pedido{
    int IDpedido;
    int IDcliente;
    int IDplato;
    int cantidad;
    float imp;
    fecha fechaPedido;
    float valoracion;
    int estado;
};
#endif // STRUCTS_H_INCLUDED
