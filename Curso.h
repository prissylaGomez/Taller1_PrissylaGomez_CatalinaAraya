#ifndef curso_h
#define curso_h

#include <iostream>
#include <string>
using namespace std;

struct NodoInscritos;

class Curso {
private:
    string codigo;
    string nombre;
    int estudiantes_max;
    string carrera;
    string profesor;
    NodoInscritos* inicio;

public:
    Curso(){}
    Curso(string c, string n, int max, string car, string profe);
    ~Curso();

    string getCodigo();
    string getNombre();
    int getEstudiantesMax();
    string getCarrera();
    string getProfesor();
    
    void inscribirEstudiante(string idAlumno);
    void eliminarEstudiante(string idAlumno);
    void mostrarInfo();
};
struct NodoCursos {
    Curso data;
    NodoCursos* next;
};
class ListCursos{
    private:
        NodoCursos* inicio;
    public:
        ListCursos();
        ~ListCursos();
        
        void agregarCurso(string codigo, string nombre, int max, string carrera, string profesor);
        void eliminarCurso(string codigo);
        void mostrarCurso(string codigo);
        void mostrarInfoCursos();
};
#endif
