#ifndef estudiante_h
#define estudiante_h

#include <string>
#include <iostream>
using namespace std;

struct Estudiante{
    string id;
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
    
    void agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso);
    void buscarEstudiante(string id);
    void eliminarEstudiante(int id);
};

#endif



