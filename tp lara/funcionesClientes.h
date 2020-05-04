#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

void presentacionSubmenuCL(){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|              M E N U     C L I E N T E              |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|             1) NUEVO CLIENTE                        |"<< endl;
cout << "|             2) MODIFICAR CLIENTE                    |"<< endl;
cout << "|             3) LISTAR CLIENTE POR ID                |"<< endl;
cout << "|             5) LISTAR TODOS LOS CLIENTES            |"<< endl;
cout << "|             6) ELIMINAR CLIENTE                     |"<< endl;
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
        fclose(p);
        return reg.IDcliente+1;
    }
}
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

    cout << "                 NOMBRE/S: ";
    cin.ignore();
    cin.getline(reg.nombres,49);
    if (reg.nombres[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|       TODOS LOS CLIENTES DEBEN TENER UN NOMBRE      |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }

    cout << "               APELLIDO/S: ";
    cin.getline(reg.apellidos,49);
    if (reg.apellidos[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|       TODOS LOS CLIENTES DEBEN TENER APELLIDO       |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }

    cout << "                    @MAIL: ";
    cin.getline(reg.mail,49);
    switch (validarMail(&reg)){
        case 1:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|        EL @MAIL NO DEBE EMPEZAR CON '@' NI '.'      |" << endl;
            cout << " ===================================================== "<< endl;
            fclose(p);
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
            fclose(p);
            return false;
            break;
        case 3:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "| EL @MAIL NO DEBE TERMINAR EN '.' O TENER 2 SEGUIDOS |" << endl;
            cout << " ===================================================== "<< endl;
            fclose(p);
            return false;
            break;
        case 4:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|       EL @MAIL NO DEBE TENER ESPACIOS VACIOS        |" << endl;
            cout << " ===================================================== "<< endl;
            fclose(p);
            return false;
            break;
        case 5:
            system("cls");
            cout << endl << endl;
            system("color 4f");
            cout << " ===================================================== "<< endl;
            cout << "|      EL @MAIL CONTIENE CARACTERES NO PERMITIDOS     |" << endl;
            cout << " ===================================================== "<< endl;
            fclose(p);
            return false;
            break;
        case 0:
            break;
    }

    cout << "                DOMICILIO: ";
    cin.getline(reg.domicilio,49);
    if (reg.domicilio[0]=='\0'){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|     TODOS LOS CLIENTES DEBEN TENER UN DOMICILIO     |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }

    cout << "            CODIGO POSTAL: ";
    cin >> reg.CP;
    cin.ignore();
    if(reg.CP<1000||reg.CP>9999){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "| EL VALOR DEL CODIGO POSTAL DEBE SER DE 1000 A 9999  |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }

    cout << "       FECHA DE NACIMIENTO " << endl;
    cout << "                      DIA: ";
    cin >> reg.nacimiento.dia;
    cout << "                      MES: ";
    cin >> reg.nacimiento.mes;
    cout << "                     ANIO: ";
    cin >> reg.nacimiento.anio;
    if(!validarNacimiento(reg.nacimiento.dia,reg.nacimiento.mes,reg.nacimiento.anio)){
        system("cls");
        cout << endl << endl;
        system("color 4f");
        cout << " ===================================================== "<< endl;
        cout << "|      LA FECHA ";
        cout << reg.nacimiento.dia << "/" << reg.nacimiento.mes << "/" << reg.nacimiento.anio;
        cout << " NO ES UNA FECHA VALIDA       |" << endl;
        cout << " ===================================================== "<< endl;
        fclose(p);
        return false;
    }

    reg.estado=true;
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return true;
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
