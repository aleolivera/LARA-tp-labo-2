#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

const char ARCHIVOPLATOS[11]="platos.dat";
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

#endif // STRUCTS_H_INCLUDED
