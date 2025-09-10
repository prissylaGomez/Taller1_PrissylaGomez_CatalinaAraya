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
void ListEstudiantes::mostrarEstudiantes(){
    Nodo* actual = head;
    if (!actual){
        cout << "No hay estudiantes registrados\n";
        return;
    }
    cout << "Estos son los estudiantes registrados\n";
    while(actual != nullptr){
        cout << "ID:" << actual->data.id << " Nombre completo: " << actual-> data.nombre
        << actual-> data.apellido << " Carrera: " << actual-> data.carrera 
        << " Fecha de ingreso: " << actual-> data.ingreso << "\n";
        actual = actual->next;
    }
}
