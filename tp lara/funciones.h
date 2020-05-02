#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void presentacionMenu (){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                M E N U     P L A T O S              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|       1) PLATOS               //``--.._             |"<< endl;
cout << "|       2) CLIENTES            ||  (_)  _ ``-._       |"<< endl;
cout << "|       3) PEDIDOS             ||    _ (_)    ``-.    |"<< endl;
cout << "|       4) REPORTES            ||   (_)   __..-``     |"<< endl;
cout << "|       5) CONFIGURACION        \\__..--``            |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
}
void presentacionSubmenu (){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                M E N U     P L A T O S              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|             1) NUEVO PLATO                          |"<< endl;
cout << "|             2) MODIFICAR PLATO                      |"<< endl;
cout << "|             3) LISTAR PLATO POR ID                  |"<< endl;
cout << "|             4) PLATOS POR RESTAURANT                |"<< endl;
cout << "|             5) LISTAR TODOS LOS PLATOS              |"<< endl;
cout << "|             6) ELIMINAR PLATO                       |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|             0) VOLVER AL MENU PRINCIPAL             |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
}
int contarCifrasInt(int n){
    int t, div=1, cifras=0;
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
    return cifras;
}
int contarCifrasFloat(float n){
    float t;
    int div=1,cifras=0,decimales;
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
    decimales=(int)n;
    if(decimales-n!=0){
        cifras+=3;
    }
    return cifras;
}
void acomodarInt(int n,int longitud,int tipo){
    int cifras=0, margenIzq,margenDer;
    cifras=contarCifrasInt(n);
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
    switch(tipo){
        case 1:
            cout << "%";
            break;
        case 2:
            cout << "min";
            margenDer=margenDer-3;
            break;
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
    int cifras;
    cifras=contarCifrasFloat(n);
    while (cifras<longitud){
        cout <<" ";
        cifras++;
    }
    cout <<"$" << n;
}
void registroHorizontal(struct plato*reg){
    cout << "|";
    acomodarInt(reg->IDplato,7,0);
    cout << "|";
    acomodarChar(reg,30);
    cout << "|";
    acomodarFloat(reg->costo,6);
    cout << "|";
    acomodarFloat(reg->imp,8);
    cout << "|";
    acomodarInt(reg->TiempoPrep,11,2);
    cout << "|";
    acomodarInt(reg->IDrestaurante,12,0);
    cout << "|";
    acomodarInt(reg->comision,9,1);
    cout << "|";
    acomodarInt(reg->categoria,11,0);
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
    int espacios;
    cout << " ===================================================== "<< endl;
    cout << "|                   ID: " << reg->IDplato;
    espacios=30-contarCifrasInt(reg->IDplato);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|               NOMBRE: " << reg->nombre;
    espacios=30-strlen(reg->nombre);
    while(espacios>0){
        cout << " ";
        espacios--;
        }

    cout << "|" << endl;
    cout << "| COSTO DE PREPARACION: " << reg->costo;
    espacios=30-contarCifrasFloat(reg->costo);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|     IMPORTE DE VENTA: " << reg->imp;
    espacios=30-contarCifrasFloat(reg->imp);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|TIEMPO DE PREPARACION: " << reg->TiempoPrep;
    espacios=30-contarCifrasInt(reg->TiempoPrep);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|       ID RESTAURANTE: " << reg->IDrestaurante;
    espacios=30-contarCifrasInt(reg->IDrestaurante);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "| COMISION RESTAURANTE: " << reg->comision << "%";
    espacios=30-contarCifrasInt(reg->comision)-1;
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|         ID CATEGORIA: " << reg->categoria;
    espacios=30-contarCifrasInt(reg->categoria);
    while(espacios>0){
    cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|               ESTADO: ";
    if(reg->estado){
        cout << "DISPONIBLE                    |" << endl;
    }
    else{
        cout << "NO DISPONIBLE                 |" << endl;
    }
    cout << " ===================================================== "<< endl;
}
int buscarRegID(int*id){
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      EL CERO NO SE ADMITE COMO NUMERO DE ID         |" << endl;
        cout << " ===================================================== "<< endl;
        return -1;
    }
    else{
        struct plato reg;
        FILE*p;
        p=fopen(ARCHIVOPLATOS,"rb");
        if(p==NULL){
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
            cout << " ===================================================== "<< endl;
            fclose(p);
            return -1;
        }
        while(fread(&reg,sizeof reg,1,p)==1){
            if (id==reg.IDplato){
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|    EL ID DEL PLATO YA FUE ASIGNADO A OTRO PLATO     |" << endl;
            cout << " ===================================================== "<< endl;
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "| EL IMPORTE DE VENTA NO PUEDE SER MENOR AL COSTO     |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    else if(reg->imp < 0){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      EL IMPORTE DE VENTA NO PUEDE SER CERO          |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarPlatos(){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"ab");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    system("cls");
    cout << " ===================================================== "<< endl;
    cout << "|            INGRESO DE NUEVO PLATO                   |"<< endl;
    cout << " ===================================================== "<< endl;

    cout << "                        ID: ";
    cin >> reg.IDplato;
    if (validarID(reg.IDplato)==-1){
        fclose(p);
        return false;
    }
    cout << "          NOMBRE DEL PLATO: ";
    cin.ignore();
    cin.getline(reg.nombre,49);
    if (reg.nombre[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        TODOS LOS PLATOS DEBEN TENER UN NOMBRE       |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }
    cout << "      COSTO DE PREPARACION: $";
    cin >> reg.costo;
    if (reg.costo<0){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|    EL COSTO DE PREPARACION DEBE SER MAYOR A CERO    |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }
    cout << "          IMPORTE DE VENTA: $";
    cin >> reg.imp;
    if (!validarImporte(&reg)){
        fclose(p);
        return false;
    }
    cout << "    MINUTOS DE PREPARACION: ";
    cin >> reg.TiempoPrep;
    if(reg.TiempoPrep<0){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|  EL TIEMPO DE PREPARACION NO DEBE SER MENOR A CERO  |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }
    cout << "        ID DEL RESTAURANTE: ";
    cin >> reg.IDrestaurante;
    if (reg.IDrestaurante<1){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|     EL ID DEL RESTAURANTE DEBE SER MAYOR A CERO     |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }
    cout << "  COMISION DEL RESTAURANTE: %";
    cin >> reg.comision;
    if (reg.comision<0 || reg.comision>100){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "| EL VALOR DE LA COMISION DEBE SER ENTRE 0% y 100%    |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }
    cout << "        ID DE LA CATEGORIA: ";
    cin >> reg.categoria;
    if (reg.categoria<1){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      EL ID DE LA TEGORIA DEBE SER MAYOR A CERO      |" << endl;
        cout << " ===================================================== "<< endl;
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDplato){
            cout << "          IMPORTE DE VENTA: $";
            cin >> reg.imp;
            if (!validarImporte(&reg)){
            fclose(p);
            return false;
        }
            cout << "    MINUTOS DE PREPARACION: ";
            cin >> reg.TiempoPrep;
            if(reg.TiempoPrep<0){
                system("cls");
                cout << endl << endl;
                system("color 4f");
                cout << " ===================================================== "<< endl;
                cout << "|  EL TIEMPO DE PREPARACION NO DEBE SER MENOR A CERO  |" << endl;
                cout << " ===================================================== "<< endl;
                fclose(p);
                return false;
            }
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
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
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return;
    }

    cout << "                                         LISTA    DE    PLATOS                                                          " << endl;
    cout << " ______________________________________________________________________________________________________________________ " << endl;
    cout << "| PLATO |              NOMBRE          | COSTO | IMP VTA |PREPARACION| RESTAURANT | COMISION | CATEGORIA |    ESTADO   |" << endl;
    cout << "|¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯¯¯¯|" << endl;

    while(fread(&reg,sizeof reg,1,p)==1){
        if(saltoLinea){
        cout << "|       |                              |       |         |           |            |          |           |             |" << endl;
        }
        registroHorizontal(&reg);
        saltoLinea=true;
    }

    cout << "|_______|______________________________|_______|_________|___________|____________|__________|___________|_____________|";
}

#endif // FUNCIONES_H_INCLUDED
