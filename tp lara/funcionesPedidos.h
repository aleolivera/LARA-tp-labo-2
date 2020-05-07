#ifndef FUNCIONESPEDIDOS_H_INCLUDED
#define FUNCIONESPEDIDOS_H_INCLUDED


//funciones varias
bool buscarCliente(int*id){
    struct cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return 0;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if (*id==reg.IDcliente){
            if(!reg.estado){
                fclose(p);
                return false;
            }
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
float buscarImporte(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return 0;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if (*id==reg.IDplato){
            if(!reg.estado){
                fclose(p);
                return -1;
            }
            fclose(p);
            return reg.imp;
        }
    }
    fclose(p);
    return -1;
}
//funciones de pantalla
void presentacionSubmenuPedidos(){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|              M E N U     P E D I D O S              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|            1) NUEVO PEDIDO                          |"<< endl;
cout << "|            2) MODIFICAR PEDIDO                      |"<< endl;
cout << "|            3) LISTAR PEDIDO POR ID                  |"<< endl;
cout << "|            4) LISTAR TODOS LOS PEDIDOS              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|            0) VOLVER AL MENU PRINCIPAL              |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
}

//funciones de validacion


//funciones de carga
int asignarIDpedido(){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |"<<endl;
        return -1;
    }
    if(fread(&reg,sizeof reg,1,p)==0){
        fclose(p);
        return 1;
        }
    else{
        fseek(p,-sizeof reg,2);
        fread(&reg,sizeof reg,1,p);
        fclose(p);
        return reg.IDcliente+1;
    }
}
bool cargarPedidoCliente(int*id){
    cout << "               ID CLIENTE: ";
    cin >>*id;
    if(buscarCliente(id)){
        return true;
    }
    return false;
}
bool cargarPedidoPlato(int*id,float*imp){
    cin>> *id;
    *imp=buscarImporte(id);
    if(*imp==-1){
        return false;
    };
    return true;
}
bool cargarPedidoCant(int*id){
    cin >> *id;
    if(*id<1){
        return false;
    }
    return true;
}
bool cargarPedidoFecha(struct pedido*reg){
    cout << "           FECHA DE PEDIDO " << endl;
    cout << "                      DIA: ";
    cin >> reg->fechaPedido.dia;
    cout << "                      MES: ";
    cin >> reg->fechaPedido.mes;
    cout << "                     ANIO: ";
    cin >> reg->fechaPedido.anio;
    if(!validarFecha(reg->fechaPedido.dia,reg->fechaPedido.mes,reg->fechaPedido.anio)){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      LA FECHA ";
        cout << reg->fechaPedido.dia << "/" << reg->fechaPedido.mes << "/" << reg->fechaPedido.anio;
        cout << " NO ES UNA FECHA VALIDA       |" << endl;
        return false;
    }
    return true;
}
bool cargarPedidoValoracion(float*valoracion){
    cin>> *valoracion;
    if(*valoracion<0&&*valoracion>10){
        return false;
    }
    return true;
}
bool modificarPedido(int*id){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb+");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDpedido){
            cin >> reg.estado;
            if(reg.estado<1||reg.estado>3){
                return false;
            }
            else{
                fseek(p,(ftell(p)-sizeof reg),0);
                fwrite(&reg,sizeof reg,1,p);
                fclose(p);
                return true;
            }
        }
    }
    fclose(p);
    return false;
}
bool cargarPedido(){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"ab");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |"<<endl;
        return false;
    }
    system("cls");
    cout << " ===================================================== "<< endl;
    cout << "|             INGRESO DE NUEVO PEDIDO                 |"<< endl;
    cout << " ===================================================== "<< endl;

    cout << "                        ID: ";
    reg.IDpedido=asignarIDpedido();
    cout << reg.IDpedido << endl;

    if(!cargarPedidoCliente(&reg.IDcliente)){
        cout << "NO SE PUDO ENCONTRAR EL NUMERO DE CLIENTE " << reg.IDcliente << endl;
        fclose(p);
        return false;
    }
    if(!cargarPedidoPlato(&reg.IDplato,&reg.imp)){
        cout << "NO SE PUDO ENCONTRAR EL NUMERO DE PLATO " << reg.IDplato << endl;
        fclose(p);
        return false;
    }
    if(!cargarPedidoCant(&reg.cantidad)){
        cout << "LA CANTIDAD NO PUEDE SER MENOR A 1" << reg.IDplato << endl;
        fclose(p);
        return false;
    }
    else{
        cout << "importe:" << reg.imp;
    }
    if(!cargarPedidoFecha(&reg)){
        cout << "LA FECHA NO ES UNA FECHA VALIDA." << endl;
        fclose(p);
        return false;
    }
    if(!cargarPedidoValoracion(&reg.valoracion)){
        cout << "LA VALORACION NO PUEDE SER MENOR A 1 NI MAYOR A 10" << endl;
        fclose(p);
        return false;
    }
    reg.estado=1;
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return true;
}

#endif // FUNCIONESPEDIDOS_H_INCLUDED
