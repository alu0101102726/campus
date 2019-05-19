#include "login.hpp"

using namespace std;

void menu(Datos &datt){
    datt.show_Asig();
    cout<<endl<<datt.vecA.size()+1<<". Cambiar contraseña."<<endl;
    cout<<datt.vecA.size()+2<<". Salir."<<endl;
}


int main(){

    int opc;
    Datos dat;
    User* user;
    bool log=false;
    //dat.show_datos();
    log=dat.login(user);
    if(!log){
        cout<<"\nLogin fallido."<<endl;
        return 0;
    }
    dat.getA(user->getNombre());
    do{
    menu(dat);
    cout<<"\nIntroduce una opcion:>> ";
    cin>>opc;
    switch(opc){
    case 5:
        dat.exportarUsers();
        break;
        case dat.vecA.size()+1:
                cin.ignore();
                dat.chPass(user);
        break;
    default:
        break;
    }
    }while(opc!=dat.vecA.size()+2);
    return 0;
}
