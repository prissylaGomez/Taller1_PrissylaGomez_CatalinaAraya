/*
curso.h
este header tiene:
constructor, el nodo con la lista enlazada y el manejo de la lista de cursos.
*/
#ifndef curso_h
#define curso_h

#include <iostream>
#include <string>
using namespace std;
//constructor
class Curso {
private:
    string codigo;
    string nombre;
    int estudiantes_max;
    string carrera;
    string profesor;

public:
    Curso(){}//constructor vacio como en los otros header
    Curso(string c, string n, int max, string car, string profe);
    ~Curso();
//los getters
    string getCodigo();
    string getNombre();
    int getEstudiantesMax();
    string getCarrera();
    string getProfesor();
    
};//nodo lista enlazada de cursos
struct NodoCursos {
    Curso data;//aqui se guarda el cursito
    NodoCursos* next;
};
//lista enlazada para admin de curso
class ListCursos{
    private:
        NodoCursos* inicio;
    public:
        ListCursos();
        ~ListCursos();
        //funciones principales
        void agregarCurso(string codigo, string nombre, int max, string carrera, string profesor);
        void eliminarCurso(string codigo);
        void mostrarCurso(string codigo);
        Curso* buscarPorCodigo(string codigo);
};
#endif
//ya eso
