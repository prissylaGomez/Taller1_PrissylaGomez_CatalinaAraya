/*
implementacion de clase Estudiante y de la lista enlazada
*/
#include "estudiante.h"
//aqui estan lo metodos de la lista (?
ListEstudiantes::ListEstudiantes(){
    head = nullptr;//lista vacia
}
ListEstudiantes::~ListEstudiantes(){
    //recorremos la lista y liberamos la memoria de los nodos
    NodoEstudiante* actual = head;
    while (actual != nullptr){
        NodoEstudiante* temp = actual;
        actual = actual->next;
        delete temp;
    }
}
//metodos de Estudiante
Estudiante::Estudiante(string i, string n, string a, string c, string ing)
    : id(i), nombre(n), apellido(a), carrera(c), ingreso(ing), cursos(nullptr) {}
    
string Estudiante::getId(){return id;}
string Estudiante::getNombre(){return nombre;}
string Estudiante::getApellido(){return apellido;}
string Estudiante::getCarrera(){return carrera;}
string Estudiante::getIngreso(){return ingreso;}

Estudiante::~Estudiante() {}
//funciones de la lista

//agregar un estudiante al comienzo  de la lista 
void ListEstudiantes::agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso){
    NodoEstudiante* nuevo = new NodoEstudiante;
    nuevo->data = Estudiante(id, nombre, apellido, carrera, ingreso);
    
    nuevo->next = head;
    head = nuevo;
    
    cout <<"Estudiante registrado correctamente\n";
    
}
//buscar estudiante por id o nombre
void ListEstudiantes::buscarEstudiante(string id){
    NodoEstudiante* actual = head;
    if (!actual){
        cout << "No hay estudiantes registrados\n";
        return;
    }
    
    while(actual != nullptr){
        if (id == actual->data.getId() || id == actual->data.getNombre()){
            cout << "Estos son los datos del estudiante:\n";
            cout << "ID:" << actual->data.getId() << ", Nombre completo: " << actual-> data.getNombre()
            << " " << actual-> data.getApellido() << ", Carrera: " << actual-> data.getCarrera() 
            << ", Fecha de ingreso: " << actual-> data.getIngreso() << "\n";
            return;
        }
        actual = actual->next;
    }
    cout << "Estudiante no encontrado\n";
}
//alimina estudiante de la lista
void ListEstudiantes::eliminarEstudiante(string id){
    NodoEstudiante* actual = head;
    NodoEstudiante* anterior = nullptr;
    
    while (actual != nullptr){
        
        if (actual->data.getId() == id){
            if (anterior == nullptr){
                head = actual->next;
            }else{
                anterior->next = actual->next;
            }
            delete actual;
            cout << "Estudiante eliminado con exito\n";
            return;
        }
        anterior = actual;
        actual = actual->next;
    }
    cout << "Estudiante no encontrado\n";
}
//buscar y devolver un puntero a un estudiante
Estudiante* ListEstudiantes::buscarPorId(String id){
    NodoEstudiante* actual = head;
    while(actual){
        if (actual->data.getId() == id) {
            return &(actual->data);
        }
        actual = actual->next;
    }
    return nullptr;
}
//mostrar estudiantes de una carrera especifica
void ListEstudiantes::mostrarPorCarrera(String carrera){
    NodoEstudiante* actual = head;
    bool found = false;
    while(actual){
        if (actual->data.getCarrera() == carrera){ 
            actual->data.mostrar(); found = true; 
        }
        actual = actual->next;
    }
    if (!found) cout << "No hay estudiantes en la carrera indicada\n";
}
//eso
