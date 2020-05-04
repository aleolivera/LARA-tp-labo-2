#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

const char ARCHIVOPLATOS[11]="platos.dat";
const char ARCHIVOCLIENTES[13]="clientes.dat";
const char ARCHIVOPEDIDOS[12]="pedidos.dat";
const char REGISTROSPROGRAMA[22]="registrosprograma.dat";

struct regPrograma{
    int conCL;
};

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
    int dia;
    int mes;
    int anio;
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

#endif // STRUCTS_H_INCLUDED
