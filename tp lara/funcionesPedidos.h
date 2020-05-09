#ifndef FUNCIONESPEDIDOS_H_INCLUDED
#define FUNCIONESPEDIDOS_H_INCLUDED


//funciones varias
bool buscarCliente(int*id){
    struct cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if (*id==reg.IDcliente){
            if(!reg.estado){
                errorEncabezado("EL CLIENTE NO ESTA DISPONIBLE");
                fclose(p);
                return false;
            }
            fclose(p);
            return true;
        }
    }
    errorEncabezado("NO SE ENCONTRO EL CLIENTE");
    fclose(p);
    return false;
}
float buscarImporte(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        errorArchivo();
        return -1;
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
    return -2;
}
bool guardarPedido(struct pedido*reg){
    FILE*p=fopen(ARCHIVOPEDIDOS,"ab");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    fwrite(reg,sizeof reg,1,p);
    fclose(p);
    return true;
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
void listarPedido(struct pedido*reg){
int espacios;
    cout << " ====================================================== "<< endl;
    cout << "|             ID PEDIDO: " << reg->IDpedido;
    espacios=TAMCELDACLIENTE-contarCifrasInt(reg->IDpedido);
    ponerEspacios(&espacios);
    cout << "|" << endl;
    cout << "|            ID CLIENTE: " << reg->IDcliente;
    espacios=TAMCELDACLIENTE-contarCifrasInt(reg->IDcliente);
    ponerEspacios(&espacios);

    cout << "|" << endl;
    cout << "|              ID PLATO: " << reg->IDplato;
    espacios=TAMCELDACLIENTE-contarCifrasInt(reg->IDplato);
    ponerEspacios(&espacios);

    cout << "|" << endl;
    cout << "|               IMPORTE: " << reg->imp;
    espacios=TAMCELDACLIENTE-contarCifrasFloat(reg->imp);
    ponerEspacios(&espacios);

    cout << "|" << endl;
    cout << "|                 FECHA: ";
    if(reg->fechaPedido.dia<10) cout << "0";
    cout << reg->fechaPedido.dia << "/";
    if(reg->fechaPedido.mes<10) cout << "0";
    cout << reg->fechaPedido.mes <<"/" << reg->fechaPedido.anio;
    cout << "                    |" << endl;

    cout << "|            VALORACION: " << reg->valoracion;
    espacios=TAMCELDACLIENTE-contarCifrasFloat(reg->valoracion);
    ponerEspacios(&espacios);

    cout << "|" << endl;
    cout << "|                ESTADO: ";
    switch(reg->estado){
    case 1:
        cout << "PEDIDO EN CURSO               |" << endl;
        break;
    case 2:
        cout << "PEDIDO COMPLETADO             |" << endl;
        break;
    case 3:
        cout << "PEDIDO CANCELADO              |" << endl;
        break;
    }
    cout << " ====================================================== "<< endl;

}
bool listarPedidoID(int*id){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDpedido){
            listarPedido(&reg);
            fclose(p);
            return true;
        }
    }
    return false;
}

void listarTodosPedidos(){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb");
    if(p==NULL){
        errorArchivo();
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        listarPedido(&reg);
    }
}

//funciones de carga
int asignarIDpedido(){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb+");
    if(p==NULL){
        errorArchivo();
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
        return reg.IDpedido+1;
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
        errorEncabezado("EL PLATO ES NO ESTA DISPONIBLE");
        return false;
    }
    if(*imp==-2){
        errorEncabezado("EL PLATO ES INEXISTENTE");
        return false;
    }
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
    cout << "           FECHA DE PEDIDO DD/MM/AAAA" << endl;
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
bool cargarEstado(int*estado){
    cout << "                   ESTADO: ";
    cin >>*estado;
    if(*estado<1||*estado>3){
        return false;
    }
    return true;
}
int modificarPedido(int*id){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"rb+");
    if(p==NULL){
        errorArchivo();
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDpedido){
            if(!cargarEstado(&reg.estado)){
                fclose(p);
                return 0;
            }
            fseek(p,(ftell(p)-sizeof reg),0);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            return reg.estado;
        }
    }
    fclose(p);
    return 0;
}
bool cargarPedido(){
    struct pedido reg;
    FILE*p=fopen(ARCHIVOPEDIDOS,"ab");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    cout << " ===================================================== "<< endl;
    cout << "|             INGRESO DE NUEVO PEDIDO                 |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "                 ID PEDIDO: ";
    reg.IDpedido=asignarIDpedido();
    cout << reg.IDpedido << endl;
    if(!cargarPedidoCliente(&reg.IDcliente)){
        fclose(p);
        return false;
    }
    cout << "                 ID PLATO : ";
    if(!cargarPedidoPlato(&reg.IDplato,&reg.imp)){
        errorEncabezado("NO SE PUDO ENCONTRAR EL PLATO");
        fclose(p);
        return false;
    }
    cout << "                 CANTIDAD :";
    if(!cargarPedidoCant(&reg.cantidad)){
        errorEncabezado("LA CANTIDAD NO PUEDE SER MENOR A 1");
        fclose(p);
        return false;
    }
    cout << "                  IMPORTE :" << reg.imp << endl;
    if(!cargarPedidoFecha(&reg)){
        errorEncabezado("LA FECHA NO ES UNA FECHA VALIDA.");
        fclose(p);
        return false;
    }
    cout << "               VALORACION :";
    if(!cargarPedidoValoracion(&reg.valoracion)){
        errorEncabezado("LA VALORACION NO PUEDE SER MENOR A 1 NI MAYOR A 10");
        fclose(p);
        return false;
    }
    reg.estado=1;
    cout << "                    ESTADO: PEDIDO EN CURSO";
    cin.ignore();
    cin.get();
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return true;
}

#endif // FUNCIONESPEDIDOS_H_INCLUDED
