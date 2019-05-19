#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <set>
#include <vector>
#include <string>

using namespace std;

//Clase de usuarios del sitema
/**
 * @class User
 * @brief Clase donde se guardan los datos de los ususarios
 * @var nombre Nombre del usuario
 * @var passwd Contraseña del ususario
 * @var profesor Rol que va a desempeñar
 */
class User{
public:
  /**
    * @brief Crea un usuario
    * @param nombre_ Corresponde al nombre del usuario
    * @param passw_ Corresponde a la contraseña del usuario
    * @param profesor_ Corresponde al profesor
 */
    User(string nombre_, string passw_,int profesor_){
        nombre=nombre_;
        passw=passw_;
        profesor=profesor_;
    }

  /**
    * @brief Devuelve el nombre del alumno
    * @return Nombre del alumno
  */
    string getNombre(){
        return nombre;
    }

  /**
    * @brief Devuelve la contraseña del alumno
    * @return Contraseña del alumno
 */
    string getPassw(){
        return passw;
    }

  /**
    * @brief Devuelve el valor del profesor
    * @return Profesor (rol)
 */
    int getProf(){
        return profesor;
    }

    /**
      * @brief Cambiar la contraseña del alumno
      * @param passwd Contraseña nueva
      * @return Correcto cambio de contraseña o no
 */
    bool setPassw(string &passwd){
        string pass,pass1;
        do{
          cout<<"\nIntroducir nueva contraseña: ";
          getline(cin,pass);
          if(pass=="quit") return false;
            cout<<"\nVuelve a introducirla: ";
            getline(cin,pass1);
          if(pass1=="quit") return false;
          if(pass.compare(pass1)==0) break;
            cout<<"\nContraseña incorrecta."<<endl;
        }while(1);
        passwd=pass;
        return true;
    }
private:
    string nombre;
    string passw;
    int profesor;
};

/**
 * @class Asig
 * @brief Clase donde se guardan los datos de las asignaturas
 * @var nombre Nombre de la asignatura
 * @var cod Codigo de la asignatura para diferenciarlas
 */
class Asig{
  public:
    /**
      * @brief Crear una asignatura
      * @param name Nombre de la asignatura
      * @param codigo Codigo de la asignatura
    */
    Asig(string name, int codigo){
        nombre=name;
        cod=codigo;
    }

    /**
     * @brief Devuelve el nombre de la asignatura
     * @return Nombre de la asignatura
    */
    string getNombre(){
        return nombre;
    }

    /**
      * @brief Devuelve el código de la asignatura
      * @return Codigo de la asignatura
    */
    int getCod(){
        return cod;
    }
private:

   string nombre;
   int cod;

};

/**
 * @class Datos
 * @brief Clase donde se guardan los datos de todos los usuarios y al identificarse uno se rellenan los datos de sus asignaturas cursadas.
 * @var Vector de Usuarios obtenido de la base de datos bdl.txt
 * @var Vector de asignaturas del usuario logueado
 */
class Datos{
public:
    vector<User> vec;
    vector<Asig> vecA;

public:
    /**
      * @brief Constructor que coge los ususarios de la base de datos
   */
    Datos();

    /**
     * @brief Muestra los datos por pantalla
    */
    void show_datos();

    /**
     * @brief Comprueba si el usuario se puede logear o no
     * @param user Corresponde a un objeto de tipo usuario
     * @return Devuelve si fue o no existoso el login
    */
    bool login(User *&user);

    /**
     * @brief Se encarga de recoger las asignaturas del usuario que se ha identificado
     * @param name Corresponde al nombre de la asignatura
    */
    void getA(string name);

    /**
     * @brief Muestra las asignaturas matriculadas
    */
    void show_Asig();

    /**
     * @brief Permite cambiar la contraseña en caso de ser requerido
     * @param user Representa a un usuario
    */
    void chPass(User *user);

    /**
     * @brief Actualiza los usuarios en la base de datos
    */
    void exportarUsers();
};
