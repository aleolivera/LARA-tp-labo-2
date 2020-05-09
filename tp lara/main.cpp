#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <ctime>
using namespace std;
#include "structs.h"
#include "funciones.h"
#include "funcionesClientes.h"
#include "funcionesPedidos.h"
#include "funcionesConfig.h"

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
                            mensageExito("EL PLATO SE HA CARGADO CON EXITO");

                        }
                        else{
                            errorPie("EL PLATO NO SE HA ODIDO CARGAR");
                            cin.ignore();
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
                        cin.ignore();
                        if(modificarPlato(&id)){
                            mensageExito("PLATO MODIFICADO EXITOSAMENTE");
                        }
                        else{
                            errorPie("EL PLATO NO SE HA PODIDO MODIFICAR");
                            cin.ignore();
                        }
                        break;
                    case 3:
                        cout << " ===================================================== "<< endl;
                        cout << "|                  LISTAR PLATO                       |"<< endl;
                        cout << "         INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(!listarPlatoID(&id)){
                            errorPie("EL PLATO NO SE ENCUENTRA EN EL ARCHIVO");
                            cin.ignore();
                        }
                        break;
                    case 4:
                        cout << " ===================================================== "<< endl;
                        cout << "|        INGRESE EL ID DEL RESTAURANTE: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(!listarPlatoRes(&id)){
                            errorPie("NO SE ENCONTRO EL RESTAURANTE");
                            cin.ignore();
                        }
                        break;
                    case 5:
                        system("cls");
                        listarTodosPlatos();
                        cin.ignore();;
                        break;
                    case 6:
                        cout << " ===================================================== "<< endl;
                        cout << "|                ELIMINAR PLATO                       |"<< endl;
                        cout << "         INGRESE EL ID DEL PLATO: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        cin.ignore();
                        if(bajaPlato(&id)){
                            mensageExito("EL PLATO SE HA ELIMINADO EXITOSAMENTE");
                        }
                        else{
                            errorPie("NO SE ENCONTRO NINGUN PLACO CON ESE ID");
                        }
                        break;
                    case 0:
                        break;
                }
                cin.get();
                break;
            case 2:
                presentacionSubmenuCL();
                cin >> op;
                system("cls");
                switch (op){
                    case 1:
                        if(cargarCliente()){
                            mensageExito("EL CLIENTE SE HA CARGADO EXITOSAMENTE");
                        }
                        else{
                            errorPie("EL CLIENTE NO SE PUDO CARGAR");
                        }
                        cin.ignore();
                        break;
                    case 2:
                        cout << " ===================================================== "<< endl;
                        cout << "|              MODIFICAR CLIENTE                       |"<< endl;
                        cout << "|      INGRESE EL ID DEL CLIENTE: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        cin.ignore();
                        if(modificarCliente(&id)){
                            mensageExito("CLIENTE MODIFICADO EXITOSAMENTE");
                        }
                        else{
                            errorPie("EL CLIENTE NO SE HA PODIDO MODIFICAR");
                        }
                        cin.ignore();
                        break;
                    case 3:
                        cout << " ===================================================== "<< endl;
                        cout << "|                  LISTAR CLIENTE                      |"<< endl;
                        cout << "        INGRESE EL ID DEL CLIENTE: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(!listarClienteID(&id)){
                            errorPie("EL CLIENTE NO SE ENCUENTRA EN EL ARCHIVO");
                        }
                        cin.ignore();
                        break;
                    case 4:
                        listarTodosClientes();
                        cin.ignore();
                        break;
                    case 5:
                        cout << " ===================================================== "<< endl;
                        cout << "|              ELIMINAR CLIENTE                       |"<< endl;
                        cout << "       INGRESE EL ID DEL CLIENTE: ";
                        cin >> id;
                        cout << endl;
                        cout << " ===================================================== "<< endl;
                        if(bajaCliente(&id)){
                            mensageExito("EL CLIENTE SE HA ELIMINADO EXITOSAMENTE");
                        }
                        else{
                            errorPie("NO SE ENCONTRO NINGUN CLIENTE CON ESE ID");
                        }
                        cin.ignore();
                        break;
                    case 0:
                        break;
                }
                cin.get();
                break;
            case 3:
                presentacionSubmenuPedidos();
                cin >> op;
                system("cls");
                switch(op){
                case 1:
                    if(cargarPedido()){
                        mensageExito("EL PEDIDO SE HA CARGADO CON EXITO");

                    }
                    else{
                        errorPie("EL PEDIDO NO SE HA PODIDO CARGAR");
                        cin.ignore();
                    }
                    break;
                case 2:
                    cout << " ===================================================== "<< endl;
                    cout << "|              MODIFICAR PEDIDO                       |"<< endl;
                    cout << "|       INGRESE EL ID DEL PEDIDO: ";
                    cin >> id;
                    cout << endl;
                    cout << " ===================================================== "<< endl;
                    cin.ignore();
                    switch(modificarPedido(&id)){
                        case 1:
                            cout << "|                                                     |"<< endl;
                            cout << "|         ESTADO DEL PEDIDO: EN CURSO                 |"<< endl;
                            cout << "|                                                     |"<< endl;
                            cout << " ===================================================== "<< endl;
                            break;
                        case 2:
                            cout << "|                                                     |"<< endl;
                            cout << "|         ESTADO DEL PEDIDO: COMPLETADO               |"<< endl;
                            cout << "|                                                     |"<< endl;
                            cout << " ===================================================== "<< endl;
                            break;
                        case 3:
                            cout << "|                                                     |"<< endl;
                            cout << "|         ESTADO DEL PEDIDO: CANCELADO                |"<< endl;
                            cout << "|                                                     |"<< endl;
                            cout << " ===================================================== "<< endl;
                            break;
                        case 0:
                            errorPie("LOS ESTADOS SE INGRESAN CON 1, 2 o 3");
                            break;
                    }
                    cin.ignore();
                    break;
                case 3:
                    cout << " ====================================================== "<< endl;
                    cout << "|                   LISTAR PEDIDO                      |"<< endl;
                    cout << "         INGRESE EL ID DEL PEDIDO: ";
                    cin >> id;
                    cout << endl;
                    cout << " ======================================================"<< endl;
                    if(!listarPedidoID(&id)){
                        errorPie("EL PEDIDO NO SE ENCUENTRA EN EL ARCHIVO");
                    }
                    cin.ignore();
                    break;
                case 4:
                    listarTodosPedidos();
                    cin.ignore();
                    break;
                case 0:
                    break;
                }
                cin.get();
                break;
            case 4:
                cout << "UNDER CONSTRUCTION." << endl;
                cin.ignore();
                cin.get();
                break;
            case 5:
                PresentacionSubmenuConfig();
                cin >> op;
                system("cls");
                switch(op){
                    case 1:
                        if (realizarBackup()){
                            mensageExito("BACKUP COMPLETADO");
                        }
                        else{
                            errorPie("BACKUP CANCELADO");
                        }
                        break;
                    case 2:
                        if (restaurarBackup()){
                            mensageExito("RESTAURACION COMPLETADA");
                        }
                        else{
                            errorPie("RESTAURACION CANCELADA");
                        }
                        break;
                    case 0:
                        break;
                }
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
