#ifndef estudiante_h
#define estudiante_h

#include <string>
#include <iostream>
using namespace std;

struct Estudiante{
    int id;
    string nombre;
    string apellido;
    string carrera;
    string ingreso;
};

struct Nodo {
    Estudiante data;
    Nodo* next;
};

class ListEstudiantes {
    private: 
    Nodo* head;
    public:
    ListEstudiantes();
    ~ListEstudiantes();
    
    void agregarEstudiante(int id, string nombre, string apellido, string carrera, string ingreso);
    void mostrarEstudiantes();
    bool eliminarEstudiante(int id);
    Estudiante* buscarEstudiante(int id);
    
};

#endif



