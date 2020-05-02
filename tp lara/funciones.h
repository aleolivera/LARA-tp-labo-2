#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void presentacionMenu (){
cout << "MENÚ PRINCIPAL" << endl;
cout << "--------------" << endl;
cout << "1) PLATOS" << endl;
cout << "2) CLIENTES" << endl;
cout << "3) PEDIDOS" << endl;
cout << "4) REPORTES" << endl;
cout << "5) CONFIGURACIÓN" << endl;
cout << "----------------------" << endl;
cout << "0) SALIR DEL PROGRAMA" << endl;
}
void presentacionSubmenu (){
cout << "    MENÚ PLATOS "<< endl;
cout << "------------------"<< endl;
cout << "1) NUEVO PLATO"<< endl;
cout << "2) MODIFICAR PLATO"<< endl;
cout << "3) LISTAR PLATO POR ID"<< endl;
cout << "4) PLATOS POR RESTAURANT"<< endl;
cout << "5) LISTAR TODOS LOS PLATOS"<< endl;
cout << "6) ELIMINAR PLATO"<< endl;
cout << "--------------------------------"<< endl;
cout << "0) VOLVER AL MENÚ PRINCIPAL"<< endl;
}
void acomodarInt(int n,int longitud,bool porcentaje){
    int t, div=1, cifras=0, margenIzq,margenDer;
    bool b=true;
    while(b){
        cifras++;
        t= n/div;
        if(t<10){
            b=false;
        }
        else{
            div=div*10;
        }
    }
    if(longitud%2==0){
        cout << " ";
    }
    if(cifras%2==0){
        cout <<" ";
    }
    margenIzq=(longitud-cifras)/2;
    margenDer=margenIzq;

    while (margenIzq>0){
        cout <<" ";
        margenIzq--;
    }
    cout << n;
    if(porcentaje){
        cout << "%";
    }
    while (margenDer>0){
        cout <<" ";
        margenDer--;
    }
}
void acomodarChar(struct plato*reg,int longitud){
    int con;
    con=strlen(reg->nombre);
//    cout << *cadena << endl;
//    cout << con << endl;
//    cin.get();
    cout << reg->nombre;
    while (con<longitud){
        cout <<" ";
        con++;
    }
}
void acomodarFloat(float n,int longitud){
    float t;
    int decimales,div=1,con=0;
    bool b=true;
    while(b){
        con++;
        t= n/div;
        if(t<10){
            b=false;
            }

        else{
            div=div*10;
        }
    }
    decimales=(int)n;
    if(decimales-n!=0){
        con+=3;
    }
    while (con<longitud){
        cout <<" ";
        con++;
    }
    cout <<"$" << n;
}
void registroHorizontal(struct plato*reg){
    cout << "|";
    acomodarInt(reg->IDplato,7,false);
    cout << "|";
    acomodarChar(reg,30);
    cout << "|";
    acomodarFloat(reg->costo,6);
    cout << "|";
    acomodarFloat(reg->imp,8);
    cout << "|";
    acomodarInt(reg->TiempoPrep,11,false);
    cout << "|";
    acomodarInt(reg->IDrestaurante,12,false);
    cout << "|";
    acomodarInt(reg->comision,9,true);
    cout << "|";
    acomodarInt(reg->categoria,11,false);
    cout << "|";
    if(reg->estado){
        cout <<"  DISPONIBLE ";
    }
    else{
        cout <<"NO DISPONIBLE";
    }
    cout << "|"<< endl;
}
void mostrarReg(struct plato*reg){
    cout << "                   ID: " << reg->IDplato << endl;
    cout << "               NOMBRE: " << reg->nombre << endl;
    cout << " COSTO DE PREPARACION: " << reg->costo << endl;
    cout << "     IMPORTE DE VENTA: " << reg->imp <<endl;
    cout << "TIEMPO DE PREPARACION: " << reg->TiempoPrep << endl;
    cout << "       ID RESTAURANTE: " << reg->IDrestaurante << endl;
    cout << " COMISION RESTAURANTE: " << reg->comision << endl;
    cout << "         ID CATEGORIA: " << reg->categoria << endl;
    cout << "               ESTADO: ";
    if(reg->estado){
        cout << "DISPONIBLE" << endl;
    }
    else{
        cout << "NO DISPONIBLE" << endl;
    }
}
int buscarRegID(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO." << endl;
        return 0;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if (*id==reg.IDplato){
            fclose(p);
            return (ftell(p)/sizeof reg);
        }
    }
    fclose(p);
    return -1;
}
int validarID(int id){
    if (id==0){
        system("cls");
        cout << "EL CERO NO SE ADMITE COMO ID DE PLATO." << endl;
        return -1;
    }
    else{
        struct plato reg;
        FILE*p;
        p=fopen(ARCHIVOPLATOS,"rb");
        if(p==NULL){
            system("cls");
            cout << "NO SE PUDO ABRIR EL ARCHIVO." << endl;
            fclose(p);
            return -1;
        }
        while(fread(&reg,sizeof reg,1,p)==1){
            if (id==reg.IDplato){
                system("cls");
                cout << "EL ID DEL PLATO ESTA REPETIDO, VUELVA A INTENTARLO." << endl;
                fclose(p);
                return -1;
            }
        }
        fclose(p);
    }
    return 1;
}
bool bajaPlato(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb+");
    if(p==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO." << endl;
        cin.get();
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if (*id==reg.IDplato){
            reg.estado=false;
            fseek(p,(ftell(p)-sizeof reg),0);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool validarImporte(struct plato*reg){
    if(reg->imp < reg->costo){
        system("cls");
        cout << "EL IMPORTE DE VENTA NO PUEDE SER MENOR QUE EL COSTO DEL PLATO." << endl;
        return false;
    }
    else if(reg->imp < 0){
        system("cls");
        cout << "EL IMPORTE DE VENTA NO PUEDE SER MENOR A 0" << endl;
        return false;
    }
    return true;
}
bool cargarPlatos(){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"ab");
    if(p==NULL){
        system("cls");
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }
    system("cls");
    cout << "INGRESO DE PLATOS." << endl<< endl;
    cout << "ID: ";
    cin >> reg.IDplato;
    if (validarID(reg.IDplato)==-1){
        fclose(p);
        return false;
    }
    cout << "NOMBRE DEL PLATO: ";
    cin.ignore();
    cin.getline(reg.nombre,49);
    if (reg.nombre[0]=='\0'){
        system("cls");
        cout << "TODOS LOS PLATOS DEBE TENER UN NOMBRE." << endl;
        fclose(p);
        return false;
    }
    cout << "COSTO DE PREPARACION: $";
    cin >> reg.costo;
    if (reg.costo<0){
        system("cls");
        cout << "EL COSTO DE PREPARACION DEBE SER MAYOR A 'CERO'." << endl;
        fclose(p);
        return false;
    }
    cout << "IMPORTE DE VENTA: $";
    cin >> reg.imp;
    if (!validarImporte(&reg)){
        fclose(p);
        return false;
    }
    cout << "TIEMPO DE PREPARACION (MINUTOS): ";
    cin >> reg.TiempoPrep;
    if(reg.TiempoPrep<0){
        system("cls");
        cout << "EL TIEMPO DE PREPARACION NO PUEDE SER UN NUMERO NEGATIVO." << endl;
        fclose(p);
        return false;
    }
    cout << "ID DEL RESTAURANTE: ";
    cin >> reg.IDrestaurante;
    if (reg.IDrestaurante<0){
        system("cls");
        cout << "EL ID DEL RESTAURANTE DEBE SER MAYOR A 'CERO'." << endl;
        fclose(p);
        return false;
    }
    cout << "COMISION DEL RESTAURANTE: %";
    cin >> reg.comision;
    if (reg.comision<0 || reg.comision>100){
        system("cls");
        cout << "EL PORCENTAJE DE LA COMISION DEBE SER UN VALOR DE 0% A 100%."<< endl;
        fclose(p);
        return false;
    }
    cout << "ID DE LA CATEGORIA: ";
    cin >> reg.categoria;
    if (reg.categoria<0){
        system("cls");
        cout << "EL ID DE LA CATEGORIA DEBE SER MAYOR A 'CERO'." << endl;
        fclose(p);
        return false;
    }
    reg.estado=true;
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return true;
}
bool modificarPlato(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb+");
    if(p==NULL){
        system("cls");
        cout << "EL ARCHIVO NO SE PUDO ABRIR." << endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDplato){
            cout << "IMPORTE DE VENTA: ";
            cin >> reg.imp;
            cout << "TIEMPO DE PREPARACION: ";
            cin >> reg.TiempoPrep;
            fseek(p,(ftell(p)-sizeof reg),0);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool listarPlatoID(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        cout << "NO SE PUEDE ABRIR EL ARCHIVO."<< endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDplato){
            mostrarReg(&reg);
            fclose(p);
            return true;
        }
    }
    return false;
}
bool listarPlatoRes(int*restaurante){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        cout << "EL ARCHIVO NO SE PUDO ABRIR." << endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*restaurante==reg.IDrestaurante){
            mostrarReg(&reg);
            cout << endl;
        }
    }
    fclose(p);
    return true;
}
void listarTodosPlatos(){
    struct plato reg;
    bool saltoLinea=false;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO." << endl;
    }

    cout << "                                         LISTA    DE    PLATOS                                                          " << endl;
    cout << " ______________________________________________________________________________________________________________________ " << endl;
    cout << "| PLATO |              NOMBRE          | COSTO | IMP VTA |PREPARACION| RESTAURANT | COMISION | CATEGORIA |    ESTADO   |" << endl;
    cout << "|¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯¯|" << endl;

    while(fread(&reg,sizeof reg,1,p)==1){
        if(saltoLinea){
        cout << endl;
        }
        registroHorizontal(&reg);
        saltoLinea=true;
    }

    cout << "|_______|______________________________|_______|_________|___________|____________|__________|___________|_____________|";
    cin.ignore();
    cin.get();
}

#endif // FUNCIONES_H_INCLUDED
