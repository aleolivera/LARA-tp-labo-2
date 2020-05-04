#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

//funciones varias
int buscarCaracter(struct cliente*reg,char caracter){
    int i=0;
    int con=0;
    while(reg->mail[i]!='\0'){
        if(reg->mail[i]==caracter){
            con++;
        }
        i++;
    }
    return con;
}
bool ultimoCaracteresArroba (struct cliente*reg){
    int i=strlen(reg->mail);
    if(reg->mail[i-1]=='@')
    {
        return true;
    }
    return false;
}
bool buscarRepContiguos(struct cliente*reg,char caracter){
    int i=0;
    while (reg->mail[i]!='\0'){
        if(reg->mail[i]==caracter && reg->mail[i+1]==caracter){
//            cout << "elemento " << i << ": " << reg->mail[i] << " el siguiente es: " << reg->mail[i+1] << endl;
//            cin.ignore();
//            cin.get();
            return true;
        }
        i++;
    }
    return false;
}
char buscarUltCaracter(struct cliente*reg){
    int i=strlen(reg->mail);
    return reg->mail[i-1];
}
int contarSimbolos(struct cliente*reg){
    int con=0;
    int i=0;
    while(reg->mail[i]!='\0'){
        if(reg->mail[i]<'.' || (reg->mail[i]>'.' && reg->mail[i]<'0') || (reg->mail[i]>'9' && reg->mail[i]<'@') || (reg->mail[i]>'Z' && reg->mail[i]<'_') || (reg->mail[i]>'_' && reg->mail[i]<'a') || reg->mail[i]> 'z'){
            con++;
        }
        i++;
    }
    return con;
}

//funciones de impresion de pantalla
void presentacionSubmenuCL(){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|              M E N U     C L I E N T E              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|             1) NUEVO CLIENTE                        |"<< endl;
cout << "|             2) MODIFICAR CLIENTE                    |"<< endl;
cout << "|             3) LISTAR CLIENTE POR ID                |"<< endl;
cout << "|             4) LISTAR TODOS LOS CLIENTES            |"<< endl;
cout << "|             5) ELIMINAR CLIENTE                     |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|             0) VOLVER AL MENU PRINCIPAL             |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
}
void listarTodosClientes(){
    struct cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
        return;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        cout << reg.IDcliente<< endl;
        cout << reg.nombres<< endl;
        cout << reg.apellidos<< endl;
        cout << reg.mail<< endl;
        cout << reg.domicilio<< endl;
        cout << reg.CP << endl;
        cout << reg.nacimiento.dia<< endl;
        cout << reg.nacimiento.mes<< endl;
        cout << reg.nacimiento.anio<< endl<< endl;
    }
    fclose(p);
}

//funciones de validacion
bool validarFebrero(int*dia,int*anio){
        if ((*anio%400==0) || (!*anio%100==0 && *anio%4==0)){
        if(*dia>0&&*dia<30){
            return true;
        }
        else if (*dia>0 && *dia<29){
                return true;
            }
    }
    return false;
}
bool validarNacimiento(int dia,int mes,int anio){
    if (mes==2 && !validarFebrero(&dia,&anio)){
        return false;
    }
    if (mes<8 && mes%2!=0){
            if (dia<0&&dia>31){
                return false;
            }
    }
            else if(mes<8 && dia<0&&dia>30){
                return false;
            }
    if(mes%2!=0){
        if(dia<0&&dia>30){
            return false;
        }
        else if(dia<0&&dia>31){
            return false;
        }
    }
    return true;
}
int validarMail(struct cliente*reg){
    int espacios;
    if(contarSimbolos(reg)>0){
        return 5;
    }
    espacios=buscarCaracter(reg,' ');
    if (espacios>0){
        return 4;
    }
    if(reg->mail[0]=='.'||reg->mail[0]=='@')
    {
        return 1;
    }
    if(buscarCaracter(reg,'@')!=1||ultimoCaracteresArroba(reg)){
        return 2;
    }
    if(buscarCaracter(reg,'.')<1||buscarRepContiguos(reg,'.')||buscarUltCaracter(reg)=='.'){
        return 3;
    }
    return 0;
}

//funciones de carga
int asignarID(){
    struct cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
        cout << " ===================================================== "<< endl;
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
bool cargarNombre(char*nombres,int cant){
    cout << "                 NOMBRE/S: ";
    cin.ignore();
    cin.getline(nombres,cant);
    if (nombres[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|       TODOS LOS CLIENTES DEBEN TENER UN NOMBRE      |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarApellido(char*apellido,int cant){
    cout << "               APELLIDO/S: ";
    cin.getline(apellido,cant);
    if (apellido[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|       TODOS LOS CLIENTES DEBEN TENER APELLIDO       |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarEmail(struct cliente*reg,int cant){
    cout << "                    @MAIL: ";
    cin.getline(reg->mail,cant);
    switch (validarMail(reg)){
        case 1:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|        EL @MAIL NO DEBE EMPEZAR CON '@' NI '.'      |" << endl;
            cout << " ===================================================== "<< endl;
            return false;
            break;
        case 2:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|EL @MAIL NO DEBE TERMINAR EN @ NI ESTE DEBE REPETIRSE|" << endl;
            cout << "|          DEBE CONTENER POR LO MENOS UN @            |" << endl;
            cout << " ===================================================== "<< endl;
            return false;
            break;
        case 3:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "| EL @MAIL NO DEBE TERMINAR EN '.' O TENER 2 SEGUIDOS |" << endl;
            cout << " ===================================================== "<< endl;
            return false;
            break;
        case 4:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|       EL @MAIL NO DEBE TENER ESPACIOS VACIOS        |" << endl;
            cout << " ===================================================== "<< endl;
            return false;
            break;
        case 5:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|      EL @MAIL CONTIENE CARACTERES NO PERMITIDOS     |" << endl;
            cout << " ===================================================== "<< endl;
            return false;
            break;
        case 0:
            break;
    }
    return true;
}
bool cargarDomicilio(struct cliente*reg,int cant){
    cout << "                DOMICILIO: ";
    cin.getline(reg->domicilio,cant);
    if (reg->domicilio[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|     TODOS LOS CLIENTES DEBEN TENER UN DOMICILIO     |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarCP(int*CP){
    cout << "            CODIGO POSTAL: ";
    cin >>*CP;
    cin.ignore();
    if(*CP<1000||*CP>9999){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "| EL VALOR DEL CODIGO POSTAL DEBE SER DE 1000 A 9999  |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
bool cargarFecha(struct cliente*reg){
    cout << "       FECHA DE NACIMIENTO " << endl;
    cout << "                      DIA: ";
    cin >> reg->nacimiento.dia;
    cout << "                      MES: ";
    cin >> reg->nacimiento.mes;
    cout << "                     ANIO: ";
    cin >> reg->nacimiento.anio;
    if(!validarNacimiento(reg->nacimiento.dia,reg->nacimiento.mes,reg->nacimiento.anio)){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      LA FECHA ";
        cout << reg->nacimiento.dia << "/" << reg->nacimiento.mes << "/" << reg->nacimiento.anio;
        cout << " NO ES UNA FECHA VALIDA       |" << endl;
        cout << " ===================================================== "<< endl;
        return false;
    }
    return true;
}
//bool modificarCliente(int*id){
//    struct cliente reg;
//    FILE*p=fopen(ARCHIVOCLIENTES,"rb+");
//    if(p==NULL){
//        cout << endl << endl;
//        system("color 4f");
//        cout << " ===================================================== "<< endl;
//        cout << "|        EL ARCHIVO NO SE PUDO ABRIR                  |" << endl;
//        cout << " ===================================================== "<< endl;
//        return false;
//    }
//    while(fread(&reg,sizeof reg,1,p)==1){
//        if(*id==reg.IDcliente){
//            cout << "                 DOMICILIO: ";
//            cin >> reg.domicilio;
//            if (!validarImporte(&reg)){
//            fclose(p);
//            return false;
//        }
//            cout << "    MINUTOS DE PREPARACION: ";
//            cin >> reg.TiempoPrep;
//            if(reg.TiempoPrep<0){
//                system("cls");
//                cout << endl << endl;
//                system("color 4f");
//                cout << " ===================================================== "<< endl;
//                cout << "|  EL TIEMPO DE PREPARACION NO DEBE SER MENOR A CERO  |" << endl;
//                cout << " ===================================================== "<< endl;
//                fclose(p);
//                return false;
//            }
//            fseek(p,(ftell(p)-sizeof reg),0);
//            fwrite(&reg,sizeof reg,1,p);
//            fclose(p);
//            return true;
//        }
//    }
//    fclose(p);
//    return false;
//}
bool cargarCliente(){
    struct cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"ab");
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
    cout << "|            INGRESO DE NUEVO CLIENTE                 |"<< endl;
    cout << " ===================================================== "<< endl;

    cout << "                        ID: ";
    reg.IDcliente=asignarID();
    cout << reg.IDcliente << endl;

    if(!cargarNombre(reg.nombres,49)){
        fclose(p);
        return false;
    }
    if(!cargarApellido(reg.apellidos,49)){
        fclose(p);
        return false;
    }
    if(!cargarEmail(&reg,49)){
        fclose(p);
        return false;
    }
    if(!cargarDomicilio(&reg,99)){
        fclose(p);
        return false;
    }
    if(!cargarCP(&reg.CP)){
        fclose(p);
        return false;
    }
    if(!cargarFecha(&reg)){
        fclose(p);
        return false;
    }
    reg.estado=true;
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return true;
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
