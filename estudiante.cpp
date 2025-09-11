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

void ListEstudiantes::agregarEstudiante(int id, string nombre, string apellido, string carrera, string ingreso){
    Nodo* nuevo = new Nodo{{id,nombre,apellido,carrera,ongreso},nullptr};
    if(!head){
        head = nuevo;
    }else{
        Nodo* actual = head;
        while(actual-> next != nullptr){
            actual = actual->next;
        }
        actual->next= nuevo;
    }
    
}
void ListEstudiantes::buscarEstudiante(string id){
    Nodo* actual = head;
    if (!actual){
        cout << "No hay estudiantes registrados"<< endl;
        return;
    }
    cout << "Lista de estudiantes registrados" << endl;
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
void ListEstudiantes::eliminarEstudiante(int id){
    if(!head){
        return false;
    }
    
    if(head->data.id == id){
        Nodo* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
      Nodo* actual = head;
    while(actual->next && actual->next->data.id != id){
        actual = actual->next;
    }
    if(actual->next){
        Nodo* temp = actual->next;
        actual->next= actual->next->next;
        delete temp;
        return true;
    }
    return false;
    }
Estudiante* ListaEstudiante::buscarEstudiante(int id){
    Nodo* actual = head;
    while(actual){
        if(actual->data.id == id){
            return &actual->data;
        }
        actual = actual->next;
    }
    return nullptr;
}
