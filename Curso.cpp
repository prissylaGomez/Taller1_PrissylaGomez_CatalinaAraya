#include "Curso.h"

using namespace std;

Curso::Curso(string c, string n, int maxi, string carrera, string profe)
    : codigo(c), nombre(n), estudiantes_max(maxi), carrera(carrera), profesor(profe) {}

string Curso::getCodigo(){return codigo;}
string Curso::getNombre(){return nombre;}
int Curso::getEstudiantesMax(){return estudiantes_max;}
string Curso::getCarrera(){return carrera;}
string Curso:: getProfesor(){return profesor;}

Curso::~Curso() {}

ListCursos::ListCursos(){
    inicio = nullptr;
}
ListCursos::~ListCursos(){
    NodoCursos* actual = inicio;
    while (actual != nullptr){
        NodoCursos* temp = actual;
        actual = actual->next;
        delete temp;
    }
}
void ListCursos::agregarCurso(string codigo, string nombre, int max, string carrera, string profe){
    NodoCursos* nuevo = new NodoCursos;
    nuevo->data = Curso(codigo, nombre, max, carrera, profe);
    
    nuevo->next = inicio;
    inicio = nuevo;
    
    cout << "Curso creado correctamente\n";
}
void ListCursos::mostrarCurso(string codigo){
    NodoCursos* actual = inicio;
    if (!actual){
        cout << "No hay cursos creados";
        return;
    }
    
    while(actual != nullptr){
        if (codigo == actual->data.getCodigo() || codigo == actual->data.getNombre()){
            cout << "Estos son los datos del curso\n";
            cout << "Codigo: " << actual->data.getCodigo() << ", Nombre: " << actual->data.getNombre()
            << ", Cantidad maxima de estudiantes: " << actual->data.getEstudiantesMax()
            << ", Carrera: " << actual->data.getCarrera() << ", Profesor: " << actual->data.getProfesor() << "\n";
            return;
        }
        actual = actual-> next;
    }
    cout << "Curso no encontrado\n";
}
void ListCursos::eliminarCurso(string codigo){
    NodoCursos* actual = inicio;
    NodoCursos* anterior = nullptr;
    
    while (actual != nullptr){
        
        if (actual->data.getCodigo() == codigo){
            if (anterior == nullptr){
                inicio = actual->next;
            }else{
                anterior->next = actual->next;
            }
            delete actual;
            cout << "Curso eliminado con exito\n";
            return;
        }
        anterior = actual;
        actual = actual->next;
    }
    cout << "Curso no encontrado\n";
}

