/*
estudiante.h
el header tiene:
el constructor de la clase Estudiante
la estructura del NodoEstudiante
y los metodos para manejar estudiantes en memoria
*/
#ifndef estudiante_h
#define estudiante_h

#include <string>
#include <iostream>
#include "Curso.h"
using namespace std;
//constructor 
class Estudiante{
    private:
        string id;
        string nombre;
        string apellido;
        string carrera;
        string ingreso;

    public:
        Estudiante(){}//constructor vacio
        Estudiante(string id, string nombre, string apellido, string carrera, string ingreso);
        ~Estudiante();
        //getters
        string getId();
        string getNombre();
        string getApellido();
        string getCarrera();
        string getIngreso();
};
//nodo de la lista enlazada de estudiantes
struct NodoEstudiante {
    Estudiante data; //aqui se esta almacenando el estudiante 
    NodoEstudiante* next;
};
//lista enlazada admin estudiantes
class ListEstudiantes {
    private: 
    NodoEstudiante* head;
    
    public:
    ListEstudiantes(); //constructor 
    ~ListEstudiantes();//destructor
    //opciones de la lista
    void agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso);
    void buscarEstudiante(string id);
    void eliminarEstudiante(string id);
    EStudiante* buscarPorId(String id);
    void mostarPorCarrera(string carrera);
};
#endif

