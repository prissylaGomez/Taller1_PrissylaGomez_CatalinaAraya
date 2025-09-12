#include "estudiante.h"

ListEstudiantes::ListEstudiantes(){
    head = nullptr;
}
ListEstudiantes::~ListEstudiantes(){
    NodoEstudiante* actual = head;
    while (actual != nullptr){
        NodoEstudiante* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

Estudiante::Estudiante(string i, string n, string a, string c, string ing)
    : id(i), nombre(n), apellido(a), carrera(c), ingreso(ing), cursos(nullptr) {}
    
string Estudiante::getId(){return id;}
string Estudiante::getNombre(){return nombre;}
string Estudiante::getApellido(){return apellido;}
string Estudiante::getCarrera(){return carrera;}
string Estudiante::getIngreso(){return ingreso;}

Estudiante::~Estudiante() {}

void ListEstudiantes::agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso){
    NodoEstudiante* nuevo = new NodoEstudiante;
    nuevo->data = Estudiante(id, nombre, apellido, carrera, ingreso);
    
    nuevo->next = head;
    head = nuevo;
    
    cout <<"Estudiante registrado correctamente\n";
    
}
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
