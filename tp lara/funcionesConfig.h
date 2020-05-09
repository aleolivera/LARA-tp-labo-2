#ifndef FUNCIONESCONFIG_H_INCLUDED
#define FUNCIONESCONFIG_H_INCLUDED

void PresentacionSubmenuConfig(){
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|        M E N U     C O N F I G U R A C I O N        |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|          1) REALIZAR COPIA DE SEGURIDAD             |"<< endl;
cout << "|          2) RESTAURAR COPIA DE SEGURIDAD            |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|          0) VOLVER AL MENU PRINCIPAL                |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                       L A R A                       |"<< endl;
cout << " ===================================================== "<< endl;
}

//Validaciones
bool siOno(char*cadena){
    if((cadena[0]=='s' || cadena[0]=='S')&&(cadena[1]=='i' || cadena[1]=='I')){
        return true;
    }
    return false;
}
bool validarDecision(){
    char op [3];
    cout << " ===================================================== "<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|     ESTA SEGURO QUE DESEA REALIZAR ESTA ACCION?     |"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|                    INGRESE:                         |"<< endl;
    cout << "|              'SI' - PARA CONFIRMAR                  |"<< endl;
    cout << "|                      ";
    cin >> op;
    if(siOno(op)){
        return true;
    }
    return false;
}

//Generar  backup
bool backupPlatos(){
    struct plato reg;
    FILE*pArchivo=fopen(ARCHIVOPLATOS,"rb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPPLATOS,"wb");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    return true;
}
bool backupClientes(){
    struct cliente reg;
    FILE*pArchivo=fopen(ARCHIVOCLIENTES,"rb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPCLIENTES,"wd");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    return true;
}
bool backupPedidos(){
    struct pedido reg;
    FILE*pArchivo=fopen(ARCHIVOPEDIDOS,"rb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPPEDIDOS,"wb");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    return true;
}

//Restaurar backup
bool restaurarPlatos(){
    struct plato reg;
    FILE*pArchivo=fopen(ARCHIVOPLATOS,"wb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPPLATOS,"rb");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pBackup)==1){
        fwrite(&reg,sizeof reg,1,pArchivo);
    }
    return true;
}
bool restaurarClientes(){
    struct cliente reg;
    FILE*pArchivo=fopen(ARCHIVOCLIENTES,"wb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPCLIENTES,"rb");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pBackup)==1){
        fwrite(&reg,sizeof reg,1,pArchivo);
    }
    return true;
}
bool restaurarPedidos(){
    struct pedido reg;
    FILE*pArchivo=fopen(ARCHIVOPEDIDOS,"wb");
    if(pArchivo==NULL){
        errorArchivo();
        return false;
    }
    FILE*pBackup=fopen(BKPPEDIDOS,"rb");
    if(pBackup==NULL){
        errorArchivo();
        return false;
    }
    while(fread(&reg,sizeof reg,1,pBackup)==1){
        fwrite(&reg,sizeof reg,1,pArchivo);
    }
    return true;
}

//Menu
bool realizarBackup(){
    if(!validarDecision()){
        return false;
    }
    if(!backupPlatos()){
        return false;
    }
    if(!backupClientes()){
        return false;
    }
    if(!backupPedidos()){
        return false;
    }
    return true;
}
bool restaurarBackup(){
    if(!validarDecision()){
        return false;
    }
    if(!restaurarPlatos()){
        return false;
    }
    if(!restaurarClientes()){
        return false;
    }
    if(!restaurarPedidos()){
        return false;
    }
    return true;
}

#endif // FUNCIONESCONFIG_H_INCLUDED
