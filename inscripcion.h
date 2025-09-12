#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
#include <iostream>
#include "estudiante.h"
#include "curso.h"
using namespace std;

// Nodo para notas 
struct NodoNota{
    float nota;
    NodoNota* next;
};

// Nodo de inscripcion: relaciona idAlumno  con codigoCurso y la lista de notas
struct NodoInscripcion{
    string idAlumno;
    string codigoCurso;
    NodoNota* notasHead; 
    NodoInscripcion* next;
};

class ListInscripciones{
private:
    NodoInscripcion* head;
public:
    ListInscripciones();
    ~ListInscripciones();

    void inscribir(string idAlumno, string codigoCurso);
    void eliminarInscripcion(string idAlumno, string codigoCurso);
    void eliminarInscripcionesPorAlumno(string idAlumno);
    void eliminarInscripcionesPorCurso(string codigoCurso);

    int contarInscritosCurso(string codigoCurso);
    void estaInscrito(string idAlumno, string codigoCurso);

    void agregarNota(string idAlumno, string codigoCurso, float nota);
    void mostrarNotas(string idAlumno, string codigoCurso);

    void mostrarCursosDeAlumno(string idAlumno);
    void mostrarAlumnosDeCurso(string codigoCurso, ListEstudiantes* estudiantes);

    void mostrarPromedioAlumnoCurso(string idAlumno, string codigoCurso);
    void mostrarPromedioGeneralAlumno(string idAlumno);
};

#endif
