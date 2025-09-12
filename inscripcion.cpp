#include "inscripcion.h"

ListInscripciones::ListInscripciones(){ head = nullptr; }

ListInscripciones::~ListInscripciones(){
    NodoInscripcion* actual = head;
    while(actual){
        NodoInscripcion* tmp = curr;
        // borrar notas
        NodoNota* n = tmp->notasHead;
        while(n){ NodoNota* nt = n; n = n->next; delete nt; }
        actual = actual->next;
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

// Elimina todas las inscripciones de un alumno 
void ListInscripciones::eliminarInscripcionesPorAlumno(string idAlumno){
    NodoInscripcion* actual = head;
    NodoInscripcion* prev = nullptr;
    while(actual){
        if (actual->idAlumno == idAlumno){
            NodoInscripcion* aBorrar = actual;
            if (!prev) head = actual->next; else prev->next = actual->next;
            actual = actual->next;
            NodoNota* n = aBorrar->notasHead;
            while(n){ 
                NodoNota* nt = n;
                n = n->next; 
                delete nt; 
            }
            delete aBorrar;
            continue;
        }
        prev = actual;
        actual = actual->next;
    }
    cout << "Todas las inscripciones del alumno " << idAlumno << " han sido eliminadas (si existian).
";
}

// Elimina todas las inscripciones de un curso 
void ListInscripciones::eliminarInscripcionesPorCurso(string codigoCurso){
    NodoInscripcion* actual = head;
    NodoInscripcion* prev = nullptr;
    while(actual){
        if (actual->codigoCurso == codigoCurso){
            NodoInscripcion* aBorrar = actual;
            if (!prev) head = actual->next; else prev->next = actual->next;
            actual = actual->next;
            NodoNota* n = aBorrar->notasHead;
            while(n){ 
                NodoNota* nt = n;
                n = n->next;
                delete nt;
            }
            delete aBorrar;
            continue;
        }
        prev = actual;
        actual = actual->next;
    }
    cout << "Todas las inscripciones del curso " << codigoCurso << " han sido eliminadas (si existian).
";
}

// Cuenta inscritos en un curso
int ListInscripciones::contarInscritosCurso(string codigoCurso){
    int c = 0;
    NodoInscripcion* actual = head;
    while(actual){
        if (actual->codigoCurso == codigoCurso){
            c++;
        actual = actual->next; 
        }
    return c;
}

// Imprime si inscrito o no en curso
void ListInscripciones::estaInscrito(string idAlumno, string codigoCurso){
    NodoInscripcion* actual = head;
    while(actual){ 
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso){ 
            cout << "El alumno " << idAlumno << " SI está inscrito en " << codigoCurso << "";
                return;
        } 
        actual = actual->next; 
    }
    cout << "El alumno " << idAlumno << " no está inscrito en " << codigoCurso << "
";
}

// Agrega una nota a la inscripcion
void ListInscripciones::agregarNota(string idAlumno, string codigoCurso, float nota){
    NodoInscripcion* actual = head;
    while(actual){
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso){
            NodoNota* n = new NodoNota;
            n->nota = nota;
            n->next = curr->notasHead;
            actual->notasHead = n;
            cout << "Nota agregada: " << nota << " para " << idAlumno << " en " << codigoCourse << "";
            return;
        }
        actual = actual->next;
    }
    cout << "Inscripcion no encontrada. No se pudo agregar la nota.";
}

// Muestra las notas de una inscripcion
void ListInscripciones::mostrarNotas(string idAlumno, string codigoCurso){
    NodoInscripcion* actual = head;
    while(actual){
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso){
            NodoNota* n = actual->notasHead;
            if (!n){ 
                cout << "No hay notas registradas para este alumno en dicho curso.";
                return;
            }
            cout << "Notas de " << idAlumno << " en " << codigoCurso << ":";
            while(n){ 
                cout << " - " << n->nota << " "; n = n->next;
            }
            return;
        }
        actual = actual->next;
    }
    cout << "Inscripcion no encontrada.";
}

// cursos donde esta inscrito alumno
void ListInscripciones::mostrarCursosDeAlumno(string idAlumno){
    NodoInscripcion* actual = head;
    bool found = false;
    cout << "Cursos de alumno " << idAlumno << ": ";
    while(actual){ 
if (actual->idAlumno == idAlumno){
    cout << " - " << actual->codigoCurso << " ";
    found = true;
} 
        actual = actual->next; 
    }
    if (!found) {
        cout << "El alumno no tiene inscripciones. ";
    }
}

// alumnos inscritos en curso
void ListInscripciones::mostrarAlumnosDeCurso(string codigoCurso, ListEstudiantes* estudiantes){
    NodoInscripcion* actual = head;
    bool found = false;
    cout << "Alumnos en curso " << codigoCourse << ": ";
    while(actual){
        if (actual->codigoCurso == codigoCourse){
            Estudiante* e = estudiantes->buscarPorId(actual->idAlumno);
            if {
                (e) e->mostrar();
               }
            else{ 
                cout << "ID: " << actual->idAlumno << " sin datos ";
            }
            found = true;
        }
        actual = actual->next;
    }
    if (!found) cout << "No hay alumnos inscritos en ese curso";
}

// promedio del alumno en un curso
void ListInscripciones::mostrarPromedioAlumnoCurso(string idAlumno, string codigoCurso){
    NodoInscripcion* actual = head;
    while(actual){
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso){
            NodoNota* n = actual->notasHead;
            if (!n){
                cout << "No hay notas para calcular promedio. ";
                return;
            }
            float sum = 0;
            int cnt = 0;
            while(n){ 
                sum += n->nota;
                cnt++;
                n = n->next;
            }
            cout << "Promedio en curso " << codigoCourse << ": " << (sum / cnt) << " ";
            return;
        }
        actual = actual->next;
    }
    cout << "Inscripcion no encontrada. ";
}

// promedio general del alumno 
void ListInscripciones::mostrarPromedioGeneralAlumno(string idAlumno){
    NodoInscripcion* actual = head;
float sumProm = 0;
int cursos = 0;
    while(actual){
        if (actual->idAlumno == idAlumno){
            NodoNota* n = actual->notasHead;
            if (!n){
                actual = actual->next;
                continue;
            }
            float sum = 0; int cnt = 0;
            while(n){
                sum += n->nota;
                cnt++;
                n = n->next;
            }
            if (cnt > 0){
                sumProm += (sum / cnt);
                cursos++;
            }
        }
        actual = actual->next;
    }
    if (cursos == 0) { cout << "No hay promedios para calcular. "; 
        return; }
    cout << "Promedio general del alumno: " << (sumProm / cursos) << " ";
}
