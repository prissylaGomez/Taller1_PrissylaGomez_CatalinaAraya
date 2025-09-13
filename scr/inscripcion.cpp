/*
inscripcion.cpp
implementacion de la clase inscripcion.h
adelante lo explico con más detalle.
*/
#include "inscripcion.h"
//el contructor y destructor a
ListInscripciones::ListInscripciones(){ head = nullptr; }

ListInscripciones::~ListInscripciones(){
    NodoInscripcion* actual = head;
    while(actual){
        NodoInscripcion* tmp = actual;
        NodoNota* n = tmp->notasHead;
        while(n){ NodoNota* nt = n;
        n = n->next;
        delete nt;
        }
        actual = actual->next;
        delete tmp;
    }
}
//funciones
// Inscribe al alumno en el curso 
void ListInscripciones::inscribir(string idAlumno, string codigoCurso){
    NodoInscripcion* eso = head;
    while(eso){
        if (eso->idAlumno == idAlumno && eso->codigoCurso == codigoCurso){
            cout << "El alumno ya está inscrito en el curso " << codigoCurso << ". ";
            return;
        }
        eso = eso->next;
    }

    NodoInscripcion* nuevo = new NodoInscripcion;
    nuevo->idAlumno = idAlumno;
    nuevo->codigoCurso = codigoCurso;
    nuevo->notasHead = nullptr;
    nuevo->next = head;
    head = nuevo;
    cout << "Inscripcion realizada con exito: " << idAlumno << " -> " << codigoCurso << "
";
}

// Elimina una inscripcion específica 
void ListInscripciones::eliminarInscripcion(string idAlumno, string codigoCurso){
    NodoInscripcion* actual = head; NodoInscripcion* prev = nullptr;
    while(actual){
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso){
            if (!prev) head = actual->next; else prev->next = actual ->next;
            NodoNota* n = actual->notasHead;
            while(n){ NodoNota* nt = n; n = n->next; delete nt; }
            delete actual;
            cout << "Inscripcion eliminada: " << idAlumno << " -/-> " << codigoCurso << "
";
            return;
        }
        prev = actual; 
        actual= actual->next;
    }
    cout << "Inscripcion no encontrada para " << idAlumno << " en " << codigoCurso << ".
";
}

