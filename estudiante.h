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
    void buscarEstudiantePorId(string id);
    void buscarEstudiantePorNombre(string nombre);
    void eliminarEstudiante(int id);
    Estudiante* obtenerEstudiante(string id);
    void mostrarEstudiante();
};

#endif



