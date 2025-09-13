/*
Inscripcion.h
lista enlazada de notas de por estudiante en un curso, la relacion entre estudiante y curso atravez de NodoInscripcion
y una lista enlazada de inscripciones.
*/
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

//  relaciona idAlumno  con codigoCurso y la lista de notas
struct NodoInscripcion{
    string idAlumno;
    string codigoCurso;
    NodoNota* notasHead; 
    NodoInscripcion* next;
};
//la lista enlazada de inscripciones
class ListInscripciones{
private:
    NodoInscripcion* head;
public:
    ListInscripciones();
    ~ListInscripciones();
//funciones de la clase
    void inscribir(string idAlumno, string codigoCurso);
    void eliminarInscripcion(string idAlumno, string codigoCurso);
   
};

#endif

