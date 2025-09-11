#include <iostream>
#include "estudiante.h"
#include <list>
using namespace std;
// Nota n1("123", "INF-101"); asi se agregan notas
int main(){
    
    ListEstudiantes list;
    
    int opcion;
    int eleccion;
    
    do {
        cout << "\n Menu de gestion \n";
        cout << "1. Gestion de alumnos\n";
        cout << "2. Gestion de cursos\n";
        cout << "3. Inscripcion a cursos\n";
        cout << "4. Gestion de notas\n";
        cout << "5. Reportes\n";
        cout << "6. Terminar\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion){
            case 1:
                do{
                    cout << "Gestion de alumnos\n";
                    cout << "1. Registar alumno\n";
                    cout << "2. Buscar alumno\n";
                    cout << "3. Eliminar alumno\n";
                    cout << "4. Volver al menu anterior\n";
                    cout << "¿Que desea hacer?: ";
                    cin >> eleccion;
                    
                    switch (eleccion){
                        case 1:{
                            string id, nombre, apellido, carrera, ingreso;
                            cout << "Ingrese los datos del alumno a registrar:\n";
                            cin.ignore();
                            cout << "ID: ";
                            getline(cin, id);
                            cout << "Nombre: ";
                            getline(cin, nombre);
                            cout << "Apellido: ";
                            getline(cin, apellido);
                            cout << "Carrera: ";
                            getline(cin, carrera);
                            cout << "Fecha de ingreso (dd/mm/aaaa): ";
                            getline(cin, ingreso);
                                                    
                            list.agregarEstudiante(id, nombre, apellido, carrera, ingreso);
                            break;
                        }
                        case 2:{
                            string id;
                            cout << "Ingrese el id del alumno que desea buscar: ";
                            cin >> id;
                            list.buscarEstudiante(id);
                            break;
                        }
                        case 3:{
                            string id;
                            cout << "Ingrese el id del alumno que desea eliminar: ";
                            cin >> id;
                            list.eliminarEstudiante(id);
                            break;
                        }
                        default:
                            cout << "Opcion no valida";
                    }
                }while (eleccion != 4);
            break;
            case 2:
                do{
                    cout << "Gestion de cursos\n";
                    cout << "1. Crear curso\n";
                    cout << "2. Buscar curso\n";
                    cout << "3. Eliminar curso\n";
                    cout << "4. Volver al menu anterior\n";
                    cout << "¿Que desea hacer?: ";
                    cin >> eleccion;
                    
                    switch (eleccion){
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Opcion no valida";
                    }
                }while (eleccion != 4);
                break;
            case 3:
                do{
                    cout << "Inscripcion a cursos\n";
                    cout << "1. Incribir alumno\n";
                    cout << "2. Eliminar alumno\n";
                    cout << "3. Volver al menu anterior\n";
                    cout << "¿Que desea hacer?: ";
                    cin >> eleccion;
                    
                    switch (eleccion){
                        case 1:
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Opcion no valida";
                    }
                }while(eleccion != 3);
                break;
            case 4:
                break;
            case 5:
                
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    }while (opcion != 6);
}
