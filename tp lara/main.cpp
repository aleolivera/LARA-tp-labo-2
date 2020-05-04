#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
using namespace std;
#include "structs.h"
#include "funciones.h"
#include "funcionesClientes.h"

int main()
{
    bool salir=false;
    int op;
    int id;
    while(!salir){
        system("color 0a");
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
                            cout << endl << endl;
                            system("color 2f");
                            cout << " ===================================================== "<< endl;
                            cout << "|        EL PLATO SE HA CARGADO CON EXITO             |"<< endl;
                            cout << " ===================================================== "<< endl;

                        }
                        else{
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|        EL PLATO NO SE HA PODIDO CARGAR              |" << endl;
                            cout << " ===================================================== "<< endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 2:
                        cout << " ===================================================== "<< endl;
                        cout << "|               MODIFICAR PLATO                       |"<< endl;
                        cout << "|        INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(modificarPlato(&id)){
                            system("cls");
                            cout << endl << endl;
                            system("color 2f");
                            cout << " ===================================================== "<< endl;
                            cout << "|        PLATO MODIFICADO EXITOSAMENTE                |"<< endl;
                            cout << " ===================================================== "<< endl;
                        }
                        else{
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|        EL PLATO NO SE HA PODIDO MODIFICAR           |" << endl;
                            cout << " ===================================================== "<< endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 3:
                        cout << " ===================================================== "<< endl;
                        cout << "|                  LISTAR PLATO                       |"<< endl;
                        cout << "         INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(!listarPlatoID(&id)){
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|      EL PLATO NO SE ENCUENTRA EN EL ARCHIVO         |" << endl;
                            cout << " ===================================================== "<< endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 4:
                        cout << " ===================================================== "<< endl;
                        cout << "|        INGRESE EL ID DEL RESTAURANTE: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(!listarPlatoRes(&id)){
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|        NO SE ENCONTRO EL RESTAURANTE                |" << endl;
                            cout << " ===================================================== "<< endl;
                            cin.ignore();
                            cin.get();
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
                        cout << " ===================================================== "<< endl;
                        cout << "|                ELIMINAR PLATO                       |"<< endl;
                        cout << "         INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(bajaPlato(&id)){
                            cout << endl << endl;
                            system("color 2f");
                            cout << " ===================================================== "<< endl;
                            cout << "|       EL PLATO SE HA ELIMADO EXITOSAMENTE           |"<< endl;
                            cout << " ===================================================== "<< endl;

                        }
                        else{
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|     NO SE ENCONTRO NINGUN PLATO CON ESE ID          |" << endl;
                            cout << " ===================================================== "<< endl;
                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 0:
                        break;
                }
                break;
            case 2:
                presentacionSubmenuCL();
                cin >> op;
                system("cls");
                switch (op){
                    case 1:
                        if(cargarCliente()){
                            system("cls");
                            cout << endl << endl;
                            system("color 2f");
                            cout << " ===================================================== "<< endl;
                            cout << "|      EL CLIENTE SE HA CARGADO CON EXITO             |"<< endl;
                            cout << " ===================================================== "<< endl;
                            cin.ignore();

                        }
                        else{
                            cout << endl << endl;
                            system("color 4f");
                            cout << " ===================================================== "<< endl;
                            cout << "|      EL CLIENTE NO SE HA PODIDO CARGAR              |" << endl;
                            cout << " ===================================================== "<< endl;
                            cin.ignore();
                        }
                        break;
                    case 2:
//                        cin >> id;
//                        if(modificarCliente(&id)){
//                            cout << "hecho";
//                        }
//                        else{
//                            cout << "no hecho";
//                        }
                        cin.ignore();
                        cin.get();
                        break;
                    case 3:
//                        listarClientes();
//                        cin.ignore();
//                        cin.get();
//                        break;
                    case 4:
                        listarTodosClientes();
                        cin.ignore();
                        cin.get();
                        break;
                    case 5:
//                        if(eliminarCliente(*id)){
//                            cout << "hecho";
//                        }
//                        else{
//                            cout << "no hecho";
//                        }
//                        cin.ignore();
//                        cin.get();
                        break;
                    case 0:
                        break;
                }
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
