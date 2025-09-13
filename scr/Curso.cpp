/*
El curso.cpp
aqui esta la implementacion de la clase y el uso de la lista enlazada yeii 
*/
#include "Curso.h"
#include "estudiante.h"

using namespace std;
//constructor
Curso::Curso(string c, string n, int maxi, string carrera, string profe)
    : codigo(c), nombre(n), estudiantes_max(maxi), carrera(carrera), profesor(profe) {
        inicioInscritos = nullptr;
    }
//getters
string Curso::getCodigo(){return codigo;}
string Curso::getNombre(){return nombre;}
int Curso::getEstudiantesMax(){return estudiantes_max;}
string Curso::getCarrera(){return carrera;}
string Curso:: getProfesor(){return profesor;}

Curso::~Curso() {}
//metodos de la lista
ListCursos::ListCursos(){
    inicio = nullptr;
}
ListCursos::~ListCursos(){
    //liberamos memoria d elos nodos aqui
    NodoCursos* actual = inicio;
    while (actual != nullptr){
        NodoCursos* temp = actual;
        actual = actual->next;
        delete temp;
    }
}//aqui estan los usos de la lista enlazada
//agregamos un curso al comienzo de la lista
void ListCursos::agregarCurso(string codigo, string nombre, int max, string carrera, string profe){
    NodoCursos* nuevo = new NodoCursos;
    nuevo->data = Curso(codigo, nombre, max, carrera, profe);
    
    nuevo->next = inicio;
     = nuevo;
    
    cout << "Curso creado correctamente\n";
}//buscamos curso por su codigo y lo mostramos 
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
}//eliminamos el curso por codigo
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
}//inscribimos estudiante 
void Curso::incribirEstudiante(ListEstudiante listE, string id){
    EStudiante* e = ListEstudiante.
}
Curso* ListCursos::buscarPorCodigo(string codigo){
    NodoCursos* actual = inicio;
    while(actual){ 
        if (actual->data.getCodigo() == codigo) {
            return &(actual->data); 
        }
        actual = actual->next; 
    }
    return nullptr;
}

