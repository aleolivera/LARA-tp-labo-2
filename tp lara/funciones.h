#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//funciones varias
void errorArchivo(){
    cout << endl << endl;
    system("color 4f");
    cout << " ===================================================== "<< endl;
    cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |"<<endl;
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
    if(n-decimales!=0){
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
int buscarRegID(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        errorArchivo();
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
struct fecha fechaActual(){
    time_t t;
    t=time(NULL);
    struct tm*f;
    struct fecha aux;
    f=localtime(&t);
    aux.dia=f->tm_mday;
    aux.mes=f->tm_mon+1;
    aux.anio=f->tm_year+1900;
    return aux;
}
void ponerEspacios(int*espacios){
     while(*espacios>0){
        cout << " ";
        *espacios-=1;
        }
}

//funciones de impresion de pantalla
void mostrarFechaActual(struct fecha*actual){
    cout << actual->dia <<"/" << actual->mes <<"/" << actual->anio << endl;
}
void presentacionMenu (){
struct fecha aux;
aux=fechaActual();
cout << " ===================================================== "<< endl;
cout << "|                       L A R A          ";
if(aux.dia/10<1) cout << "0"<< aux.dia << "/";
else cout << aux.dia << "/";
if(aux.mes/10<1) cout << "0"<< aux.mes << "/"<< aux.anio << "   |"<< endl;
else cout << aux.mes << "/"<< aux.anio << "   |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                M E N U     P L A T O S              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|       1) PLATOS               //``--.._             |"<< endl;
cout << "|       2) CLIENTES            ||  (_)  _ ``-._       |"<< endl;
cout << "|       3) PEDIDOS             ||    _ (_)    ``-.    |"<< endl;
cout << "|       4) REPORTES            ||   (_)   __..-``     |"<< endl;
cout << "|       5) CONFIGURACION        \\__..--``             |"<< endl;
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
void mostrarReg(struct plato*reg, int TAM){
    int espacios;
    cout << " ===================================================== "<< endl;
    cout << "|                   ID: " << reg->IDplato;
    espacios=TAM-contarCifrasInt(reg->IDplato);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|               NOMBRE: " << reg->nombre;
    espacios=TAM-strlen(reg->nombre);
    while(espacios>0){
        cout << " ";
        espacios--;
        }

    cout << "|" << endl;
    cout << "| COSTO DE PREPARACION: " << reg->costo;
    espacios=TAM-contarCifrasFloat(reg->costo);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|     IMPORTE DE VENTA: " << reg->imp;
    espacios=TAM-contarCifrasFloat(reg->imp);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|TIEMPO DE PREPARACION: " << reg->TiempoPrep;
    espacios=TAM-contarCifrasInt(reg->TiempoPrep);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|       ID RESTAURANTE: " << reg->IDrestaurante;
    espacios=TAM-contarCifrasInt(reg->IDrestaurante);
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "| COMISION RESTAURANTE: " << reg->comision << "%";
    espacios=TAM-contarCifrasInt(reg->comision)-1;
    while(espacios>0){
        cout << " ";
        espacios--;
        }
    cout << "|" << endl;
    cout << "|         ID CATEGORIA: " << reg->categoria;
    espacios=TAM-contarCifrasInt(reg->categoria);
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
bool listarPlatoID(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*id==reg.IDplato){
            mostrarReg(&reg,TAMCELDAPLATO);
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
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(*restaurante==reg.IDrestaurante){
            mostrarReg(&reg,TAMCELDAPLATO);
            cout << endl;
        }
    }
    fclose(p);
    return true;
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
void listarTodosPlatos(){
    struct plato reg;
    bool saltoLinea=false;
    FILE*p=fopen(ARCHIVOPLATOS,"rb");
    if(p==NULL){
        errorArchivo();
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
void errorEncabezado(char const cadena[TAMCELDAMENSAJE]){
    system("cls");
    cout << endl << endl;
    system("color 4f");
    cout << " ====================================================== "<< endl;
    cout << "|";
    int margenIzq,margenDer;
    int longitud=strlen(cadena);
    margenIzq=(TAMCELDAMENSAJE-longitud)/2;
    margenDer=margenIzq;
    if ((TAMCELDAMENSAJE%2!=0 && longitud%2==0)||(TAMCELDAMENSAJE%2==0 && longitud%2!=0)){
        cout << " ";
    }
    while (margenIzq>0){
        cout <<" ";
        margenIzq--;
    }
    cout << cadena;
    while (margenDer>0){
        cout <<" ";
        margenDer--;
    }
    cout << "|"<< endl;
}
void errorPie(char const cadena[TAMCELDAMENSAJE]){
    system("color 4f");
    cout << " ------------------------------------------------------ "<< endl;
    cout << "|                                                      |" << endl;
    cout << "|";
    int margenIzq,margenDer;
    int longitud=strlen(cadena);
    margenIzq=(TAMCELDAMENSAJE-longitud)/2;
    margenDer=margenIzq;
    if ((TAMCELDAMENSAJE%2!=0 && longitud%2==0)||(TAMCELDAMENSAJE%2==0 && longitud%2!=0)){
        cout << " ";
    }
    while (margenIzq>0){
        cout <<" ";
        margenIzq--;
    }
    cout << cadena;
    while (margenDer>0){
        cout <<" ";
        margenDer--;
    }
    cout << "|"<< endl;
    cout << "|                                                      |" << endl;
    cout << " ====================================================== "<< endl;
}
void mensageExito(char const cadena[TAMCELDAMENSAJE]){
    system("cls");
    cout << endl << endl;
    system("color 2f");
    cout << " ====================================================== "<< endl;
    cout << "|";
    int margenIzq,margenDer;
    int longitud=strlen(cadena);
    margenIzq=(TAMCELDAMENSAJE-longitud)/2;
    margenDer=margenIzq;
    if ((TAMCELDAMENSAJE%2!=0 && longitud%2==0)||(TAMCELDAMENSAJE%2==0 && longitud%2!=0)){
        cout << " ";
    }
    while (margenIzq>0){
        cout <<" ";
        margenIzq--;
    }
    cout << cadena;
    while (margenDer>0){
        cout <<" ";
        margenDer--;
    }
    cout << "|"<< endl;
    cout << " ====================================================== "<< endl;
}

//funciones de validacion
bool validarImporte(struct plato*reg){
    if(reg->imp < reg->costo){
        errorEncabezado("EL IMPORTE DE VENTA NO PUEDE SER MENOR AL COSTO");
        return false;
    }
    else if(reg->imp < 0){
        errorEncabezado("EL IMPORTE DE VENTA NO PUEDE SER CERO");
        return false;
    }
    return true;
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
            errorArchivo();
            return -1;
        }
        while(fread(&reg,sizeof reg,1,p)==1){
            if (id==reg.IDplato){
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|        EL ID DEL PLATO YA FUE ASIGNADO A OTRO       |" << endl;
            cout << " ===================================================== "<< endl;
                fclose(p);
                return -1;
            }
        }
        fclose(p);
    }
    return 1;
}


//funciones de carga
bool cargarIDplato(struct plato*reg){
    cout << "                        ID: ";
    cin >> reg->IDplato;
    if (validarID(reg->IDplato)==-1){
        return false;
    }
    return true;
}
bool cargarNombrePlato(char*nombre,int cant){
    cout << "          NOMBRE DEL PLATO: ";
    cin.ignore();
    cin.getline(nombre,cant);
    if (nombre[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        TODOS LOS PLATOS DEBEN TENER UN NOMBRE       |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarCostoPlato(float*costo){
    cout << "      COSTO DE PREPARACION: $";
    cin >> *costo;
    if (*costo<0){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|    EL COSTO DE PREPARACION DEBE SER MAYOR A CERO    |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarImporteVenta(struct plato*reg){
    cout << "          IMPORTE DE VENTA: $";
    cin >> reg->imp;
    if (!validarImporte(reg)){
        return false;
    }
    return true;
}
bool cargarMinPrep(int*minutos){
    cout << "    MINUTOS DE PREPARACION: ";
    cin >> *minutos;
    if(*minutos<0){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|  EL TIEMPO DE PREPARACION NO DEBE SER MENOR A CERO  |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarIDRestaurant(int*id){
    cout << "        ID DEL RESTAURANTE: ";
    cin >> *id;
    if (*id<1){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|     EL ID DEL RESTAURANTE DEBE SER MAYOR A CERO     |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarComision(int*comision){
    cout << "  COMISION DEL RESTAURANTE: %";
    cin >> *comision;
    if (*comision<0 || *comision>100){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "| EL VALOR DE LA COMISION DEBE SER ENTRE 0% y 100%    |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarIDCategoria(int*id){
    cout << "        ID DE LA CATEGORIA: ";
    cin >> *id;
    if (*id<1){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      EL ID DE LA TEGORIA DEBE SER MAYOR A CERO      |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool bajaPlato(int*id){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"rb+");
    if(p==NULL){
        errorArchivo();
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
bool cargarPlatos(){
    struct plato reg;
    FILE*p=fopen(ARCHIVOPLATOS,"ab");
    if(p==NULL){
        errorArchivo();
        return false;
    }
    system("cls");
    cout << " ===================================================== "<< endl;
    cout << "|            INGRESO DE NUEVO PLATO                   |"<< endl;
    cout << " ===================================================== "<< endl;

    if(!cargarIDplato(&reg)){
        fclose(p);
        return false;
    }
    if(!cargarNombrePlato(reg.nombre,49)){
        fclose(p);
        return false;
    }
    if(!cargarCostoPlato(&reg.costo)){
        fclose(p);
        return false;
    }
    if(!cargarImporteVenta(&reg)){
        fclose(p);
        return false;
    }
    if(!cargarMinPrep(&reg.TiempoPrep)){
        fclose(p);
        return false;
    }
    if(!cargarIDRestaurant(&reg.IDrestaurante)){
        fclose(p);
        return false;
    }
    if(!cargarComision(&reg.comision)){
        fclose(p);
        return false;
    }
    if(!cargarIDCategoria(&reg.categoria)){
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
        errorArchivo();
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


#endif // FUNCIONES_H_INCLUDED
