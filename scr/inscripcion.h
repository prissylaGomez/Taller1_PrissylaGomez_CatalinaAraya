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
   
};

#endif
