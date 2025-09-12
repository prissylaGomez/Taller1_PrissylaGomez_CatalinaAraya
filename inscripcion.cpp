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

// Cuenta inscritos en un curso
int ListInscripciones::contarInscritosCurso(string codigoCurso){
    int c = 0; NodoInscripcion* curr = head;
    while(curr){ if (curr->codigoCurso == codigoCurso) c++; curr = curr->next; }
    return c;
}

// Imprime si inscrito o no en curso
void ListInscripciones::estaInscrito(string idAlumno, string codigoCurso){
    NodoInscripcion* curr = head;
    while(curr){ if (curr->idAlumno == idAlumno && curr->codigoCurso == codigoCurso){ cout << "El alumno " << idAlumno << " SI está inscrito en " << codigoCurso << "
"; return; } curr = curr->next; }
    cout << "El alumno " << idAlumno << " NO está inscrito en " << codigoCurso << "
";
}

// Agrega una nota a la inscripcion
void ListInscripciones::agregarNota(string idAlumno, string codigoCurso, float nota){
    NodoInscripcion* curr = head;
    while(curr){
        if (curr->idAlumno == idAlumno && curr->codigoCurso == codigoCurso){
            NodoNota* n = new NodoNota; n->nota = nota; n->next = curr->notasHead; curr->notasHead = n;
            cout << "Nota agregada: " << nota << " para " << idAlumno << " en " << codigoCourse << "
";
            return;
        }
        curr = curr->next;
    }
    cout << "Inscripcion no encontrada. No se pudo agregar la nota.
";
}

// Muestra las notas de una inscripcion
void ListInscripciones::mostrarNotas(string idAlumno, string codigoCurso){
    NodoInscripcion* curr = head;
    while(curr){
        if (curr->idAlumno == idAlumno && curr->codigoCurso == codigoCurso){
            NodoNota* n = curr->notasHead; if (!n){ cout << "No hay notas registradas para este alumno en dicho curso.
"; return; }
            cout << "Notas de " << idAlumno << " en " << codigoCurso << ":
";
            while(n){ cout << " - " << n->nota << "
"; n = n->next; }
            return;
        }
        curr = curr->next;
    }
    cout << "Inscripcion no encontrada.
";
}

// cursos donde esta inscrito alumno
void ListInscripciones::mostrarCursosDeAlumno(string idAlumno){
    NodoInscripcion* curr = head; bool found = false;
    cout << "Cursos de alumno " << idAlumno << ":
";
    while(curr){ if (curr->idAlumno == idAlumno){ cout << " - " << curr->codigoCurso << "
"; found = true; } curr = curr->next; }
    if (!found) cout << "El alumno no tiene inscripciones.
";
}

// alumnos inscritos en curso
void ListInscripciones::mostrarAlumnosDeCurso(string codigoCurso, ListEstudiantes* estudiantes){
    NodoInscripcion* curr = head; bool found = false;
    cout << "Alumnos en curso " << codigoCourse << ":
";
    while(curr){
        if (curr->codigoCurso == codigoCourse){
            Estudiante* e = estudiantes->buscarPorId(curr->idAlumno);
            if (e) e->mostrar(); else cout << "ID: " << curr->idAlumno << " (sin datos)
";
            found = true;
        }
        curr = curr->next;
    }
    if (!found) cout << "No hay alumnos inscritos en ese curso.
";
}

// promedio del alumno en un curso
void ListInscripciones::mostrarPromedioAlumnoCurso(string idAlumno, string codigoCurso){
    NodoInscripcion* curr = head;
    while(curr){
        if (curr->idAlumno == idAlumno && curr->codigoCurso == codigoCurso){
            NodoNota* n = curr->notasHead; if (!n){ cout << "No hay notas para calcular promedio.
"; return; }
            float sum = 0; int cnt = 0;
            while(n){ sum += n->nota; cnt++; n = n->next; }
            cout << "Promedio en curso " << codigoCourse << ": " << (sum / cnt) << "
";
            return;
        }
        curr = curr->next;
    }
    cout << "Inscripcion no encontrada.
";
}

// promedio general del alumno 
void ListInscripciones::mostrarPromedioGeneralAlumno(string idAlumno){
    NodoInscripcion* curr = head; float sumProm = 0; int cursos = 0;
    while(curr){
        if (curr->idAlumno == idAlumno){
            NodoNota* n = curr->notasHead; if (!n){ curr = curr->next; continue; }
            float sum = 0; int cnt = 0;
            while(n){ sum += n->nota; cnt++; n = n->next; }
            if (cnt > 0){ sumProm += (sum / cnt); cursos++; }
        }
        curr = curr->next;
    }
    if (cursos == 0) { cout << "No hay promedios para calcular.
"; return; }
    cout << "Promedio general del alumno: " << (sumProm / cursos) << "
";
}
