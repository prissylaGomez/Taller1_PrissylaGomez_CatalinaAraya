#include "inscripcion.h"

ListInscripciones::ListInscripciones(){ head = nullptr; }

ListInscripciones::~ListInscripciones(){
    NodoInscripcion* curr = head;
    while(curr){
        NodoInscripcion* tmp = curr;
        // borrar notas
        NodoNota* n = tmp->notasHead;
        while(n){ NodoNota* nt = n; n = n->next; delete nt; }
        curr = curr->next;
        delete tmp;
    }
}

// Inscribe al alumno en el curso 
void ListInscripciones::inscribir(string idAlumno, string codigoCurso){
    NodoInscripcion* it = head;
    while(it){
        if (it->idAlumno == idAlumno && it->codigoCurso == codigoCurso){
            cout << "El alumno ya está inscrito en el curso " << codigoCurso << ".
";
            return;
        }
        it = it->next;
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
    NodoInscripcion* curr = head; NodoInscripcion* prev = nullptr;
    while(curr){
        if (curr->idAlumno == idAlumno && curr->codigoCurso == codigoCurso){
            if (!prev) head = curr->next; else prev->next = curr->next;
            NodoNota* n = curr->notasHead;
            while(n){ NodoNota* nt = n; n = n->next; delete nt; }
            delete curr;
            cout << "Inscripcion eliminada: " << idAlumno << " -/-> " << codigoCurso << "
";
            return;
        }
        prev = curr; curr = curr->next;
    }
    cout << "Inscripcion no encontrada para " << idAlumno << " en " << codigoCurso << ".
";
}

// Elimina todas las inscripciones de un alumno 
void ListInscripciones::eliminarInscripcionesPorAlumno(string idAlumno){
    NodoInscripcion* curr = head; NodoInscripcion* prev = nullptr;
    while(curr){
        if (curr->idAlumno == idAlumno){
            NodoInscripcion* aBorrar = curr;
            if (!prev) head = curr->next; else prev->next = curr->next;
            curr = curr->next;
            NodoNota* n = aBorrar->notasHead;
            while(n){ NodoNota* nt = n; n = n->next; delete nt; }
            delete aBorrar;
            continue;
        }
        prev = curr; curr = curr->next;
    }
    cout << "Todas las inscripciones del alumno " << idAlumno << " han sido eliminadas (si existian).
";
}

// Elimina todas las inscripciones de un curso 
void ListInscripciones::eliminarInscripcionesPorCurso(string codigoCurso){
    NodoInscripcion* curr = head; NodoInscripcion* prev = nullptr;
    while(curr){
        if (curr->codigoCurso == codigoCurso){
            NodoInscripcion* aBorrar = curr;
            if (!prev) head = curr->next; else prev->next = curr->next;
            curr = curr->next;
            NodoNota* n = aBorrar->notasHead;
            while(n){ NodoNota* nt = n; n = n->next; delete nt; }
            delete aBorrar;
            continue;
        }
        prev = curr; curr = curr->next;
    }
    cout << "Todas las inscripciones del curso " << codigoCurso << " han sido eliminadas (si existian).
";
}

