#include "estudiante.h"

ListEstudiantes::ListEstudiantes(){
    head = nullptr;
}
ListEstudiantes::~ListEstudiantes(){
    Nodo* actual = head;
    while (actual != nullptr){
        Nodo* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

void ListEstudiantes::agregarEstudiante(string id, string nombre, string apellido, string carrera, string ingreso){
    Nodo* nuevo = new Nodo;
    nuevo->data.id = id;
    nuevo->data.nombre = nombre;
    nuevo->data.apellido = apellido;
    nuevo->data.carrera = carrera;
    nuevo->data.ingreso = ingreso;
    
    nuevo->next = head;
    head = nuevo;
    
    cout <<"Estudiante registrado correctamente\n";
    
}
void ListEstudiantes::buscarEstudiante(string id){
    Nodo* actual = head;
    if (!actual){
        cout << "No hay estudiantes registrados\n";
        return;
    }
    
    while(actual != nullptr){
        
        if (id == actual->data.id){
            cout << "Estos son los datos del estudiante:\n";
            cout << "ID:" << actual->data.id << ", Nombre completo: " << actual-> data.nombre
            << " " << actual-> data.apellido << ", Carrera: " << actual-> data.carrera 
            << ", Fecha de ingreso: " << actual-> data.ingreso << "\n";
            actual = actual->next;
        }else{
            cout << "Estudiante no encontrado\n";
        }
    }
}
void ListEstudiantes::eliminarEstudiante(String id){
    Nodo* actual = head;
    Nodo* anterior = nullptr;
    
    while (actual != nullptr){
        
        if (id == actual->data.id){
            
        } 
    }
}
