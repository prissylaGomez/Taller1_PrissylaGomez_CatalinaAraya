#ifndef estudiante_h
#define estudiante_h

#include <string>
#include <iostream>
#include "Curso.h"
using namespace std;

class Estudiante{
    private:
        string id;
        string nombre;
        string apellido;
        string carrera;
        string ingreso;

    public:
        Estudiante(){}
        Estudiante(string id, string nombre, string apellido, string carrera, string ingreso);
        ~Estudiante();
        
        string getId();
        string getNombre();
        string getApellido();
        string getCarrera();
        string getIngreso();
};
struct NodoEstudiante {
    Estudiante data;
    NodoEstudiante* next;
};

class ListEstudiantes {
    private: 
    NodoEstudiante* head;
    
    public:
    ListEstudiantes();
    ~ListEstudiantes();
    
    void agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso);
    void buscarEstudiante(string id);
    void eliminarEstudiante(string id);
    EStudiante* buscarPorId(String id);
    void mostarPorCarrera(string carrera);
};
#endif

