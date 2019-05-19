#include "login.hpp"

using namespace std;


Datos::Datos(){

    string nombr;
    string pass;
    string info;
    int prof;
    ifstream archivo;
    archivo.open("bdl.txt", ios::in);
    if(archivo.fail()){
            cout<<"No se pudo abrir base de datos";
            exit(1);
    }
    //Rellena el vector de usuarios con todos los usuarios que se encuentran en la base de datos
    while(!archivo.eof()){

        getline(archivo,info);
        istringstream ss(info);

        ss>>nombr;
        ss>>pass;
        ss>>prof;
        vec.push_back(User(nombr,pass,prof));

    }
    //Borra el ultimo porque se repeti el ultimo siempre
    vec.erase(vec.end()-1);
}


void Datos::show_datos(){

    for(auto it : vec)
        cout<<it.getNombre()<<" ";
    cout<<endl;
}


bool Datos::login(User*& user){

    string name;
    bool cont=true;
    int intentos=3;
    User* xd;
    Otra:
    do{
        cout<<"\nIntroduce el nombre de usuario: ";
        getline(cin, name);
        //Bucle que confirma que el nombre de usuario esta en la base de datos
        for(auto it : vec){
            if(it.getNombre()==name){
                xd=new User(it.getNombre(),it.getPassw(),it.getProf());
                cont=false;
                break;
            }
        }
        if(!cont) break;
        cout<<"\nEse usuario no existe."<<endl;
    }while(cont);
    do{
        cout<<"\nIntroduce la contraseña: ";
        getline(cin,name);
        if(name=="quit") goto Otra;
        if(xd->getPassw()==name) break;
        cout<<"\nContraseña incorrecta."<<endl;
        intentos--;
        if(intentos==0) return false;
    }while(1);
    cout<<"\nLogin correcto"<<endl;
    cout<<"Bienvenido "<<xd->getNombre()<<endl;
    //Asigna el usuario logueado para obtener sus datos mas adelante
    user=new User(xd->getNombre(),xd->getPassw(),xd->getProf());
    return true;
}


void Datos::getA(string name){

    name+=".txt";
    int codigo=0;
    string info;
    ifstream archivo;
    archivo.open(name, ios::in);
    if(archivo.fail()){
            cout<<"No se pudo abrir asignaturas";
            exit(1);
    }
    //Bucle para obtener las asignaturas del usuario logueado
    //en el fichero que se llama como el nombre de usuario + .txt
    while(!archivo.eof()){

        archivo>>codigo;
        getline(archivo,info);
        vecA.push_back(Asig(info, codigo));

    }
    vecA.erase(vecA.end()-1);
}


void Datos::show_Asig(){

    int i=1;
    cout<<"\nAsignaturas matriculadas: "<<endl;
    for(auto it : vecA)
        cout<<i++<<"."<<it.getNombre()<<endl;

}


void Datos::exportarUsers(){

    ofstream archivo;
    archivo.open("bdl.txt", ios::out);
    if(archivo.fail()){
            cout<<"No se pudo abrir";
            exit(1);
    }
    //Al cambiar una contrasenya se actualiza la base de datos
    for(auto it : vec){
        archivo<<it.getNombre()<<" "<<it.getPassw()<<" "<<it.getProf()<<endl;
    }
}


void Datos::chPass(User* user){

    string pass;
    bool v=user->setPassw(pass);



    if(v){
        //Si el usuario ha cambiado la contrasenya se actualiza el vector
        //de usuarios para mas tarde actualizar la base de datos
        for (auto it = vec.begin(); it != vec.end(); /* NOTHING */)
        {
            //Se borra el anterior perfil del usuario
            if(user->getNombre()==it->getNombre())
                it = vec.erase(it);

          else
            ++it;
    }
        //Se introduce en el vector el usuario con la nueva contrasenya
    User xd(user->getNombre(),pass, user->getProf());
    vec.push_back(xd);
    exportarUsers();}
}
