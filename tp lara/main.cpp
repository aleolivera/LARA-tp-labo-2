#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
using namespace std;
#include "structs.h"
#include "funciones.h"

int main()
{
    bool salir=false;
    int op;
    int id;
    while(!salir){
        system("cls");
        presentacionMenu();
        cin >> op;
        system("cls");
        switch(op){
            case 1:
                presentacionSubmenu();
                cin >> op;
                system("cls");
                switch(op){
                    case 1:
                        if(cargarPlatos()){
                            system("cls");
                            cout << "EL PLATO SE HA CARGADO CON EXITO." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        else{
                            cout << "EL PLATO NO SE HA PODIDO CARGAR." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        break;
                    case 2:
                        cout << "INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        if(modificarPlato(&id)){
                            system("cls");
                            cout << "PLATO MODIFICADO EXITOSAMENTE." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        else{
                            cout << "EL PLATO ID(" << id << ") NO SE PUDO MODIFICAR." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        break;
                    case 3:

                        cout << "LISTAR PLATO" << endl;
                        cout << "INGRESE EL ID DEL PLATO: " << endl<< endl;
                        cin >> id;
                        system("cls");
                        if(!listarPlatoID(&id)){
                            cout << "EL PLATO (ID "<< id << ") NO SE ENCUENTRA EN EL ARCHIVO." << endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 4:
                        cout << "INGRESE EL ID DEL RESTAURANTE: " << endl;
                        cin >> id;
                        system("cls");
                        if(!listarPlatoRes(&id)){
                            cout << "NO SE ENCONTRO EL RESTAURANTE " << id<< "." << endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 5:
                        system("cls");
                        listarTodosPlatos();
                        cin.ignore();
                        cin.get();
                        break;
                    case 6:
                        cout << "INGRESE EL ID DEL PLATO: " << endl;
                        cin >> id;
                        system("cls");
                        if(bajaPlato(&id)){
                            cout << "EL PLATO ID: " << id << " SE HA ELIMINADO CORRECTAMENTE." << endl;
                            cin.ignore();
                            cin.get();
                        }
                        else{
                            cout << "NO SE ENCONTRO NINGUN PLATO CON ID: " << id << endl;
                            cin.ignore();
                            cin.get();
                        }
                        break;
                    case 0:
                        break;
                }
                break;
            case 2:
                cout << "UNDER CONSTRUCTION." << endl;
                cin.ignore();
                cin.get();
                break;
            case 3:
                cout << "UNDER CONSTRUCTION." << endl;
                cin.ignore();
                cin.get();
                break;
            case 4:
                cout << "UNDER CONSTRUCTION." << endl;
                cin.ignore();
                cin.get();
                break;
            case 5:
                cout << "UNDER CONSTRUCTION." << endl;
                cin.ignore();
                cin.get();
                break;
            case 0:
                cout << "HASTA PRONTO!!" << endl;
                cin.ignore();
                cin.get();
                salir=true;
                break;
        }

    }


    return 0;
}
