#include <iostream>
#include "estudiante.h"
#include <list>
#include<vector>
#include <algorithm> 
using namespace std;

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
                        if (eleccion != 4){
                            cout << "Opcion no valida";   
                        }
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
                        case 1:{
                            string codigo, nombre, carrera, profesor;
                            int max_est;
                            cout << "Ingrese los datos del curso a crear:\n";
                            cin.ignore();
                            cout << "Codigo: ";
                            getline(cin, codigo);
                            cout << "Nombre: ";
                            getline(cin, nombre);
                            cout << "Maximo de estdiantes: ";
                            cin >> max_est;
                            cout << "Carrera: ";
                            getline(cin, carrera);
                            cout << "Profesor: ";
                            getline(cin, profesor);
                            
                            break;
                        }
                        case 2:{
                            string curso;
                            cout << "Ingrese el nombre o codigo del curso: ";
                            getline(cin, curso);
                        
                            break;
                        }
                        case 3:{
                            string codigo;
                            cout << "Ingrese el codigo del curso a eliminar: ";
                            getline(cin, codigo);
                            break;
                        }
                        default:
                            if (eleccion != 4){
                                cout << "Opcion no valida";   
                            }
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
                        case 1:{
                            string curso, estudiante;
                            cout << "Ingrese el id del alumno que desea inscribir: ";
                            getline(cin, estudiante);
                            cout << "Ingrese el codigo del curso al que se va a inscribir: ";
                            getline(cin, curso);
                            break;
                        }
                        case 2:{
                            string curso, estudiante;
                            cout << "Ingrese el id del alumno que desea eliminar: ";
                            getline(cin, estudiante);
                            cout << "Ingrese el codigo del curso del cual lo va a eliminar: ";
                            getline(cin, curso);
                            break;
                        }
                        default:
                            if (eleccion != 3){
                                cout << "Opcion no valida";   
                            }
                    }
                }while(eleccion != 3);
                break;
            case 4:{
                string estudiante;
                float nota;
                string conti;
                vector<float> notas;
                bool continuar = true;
                
                cin.ignore();
                cout << "Ingrese el id del alumno que desea registrar notas: ";
                getline(cin, estudiante);
                do{
                    cout << "Ingrese la nota: ";
                    cin >> nota;
                    if(nota < 1 || nota > 7){
                        cout << "Nota no valida\n";
                    }else{
                        cout << "Nota ingresada con exito\n";
                    }
                    cin.ignore();
                    cout << "Para agregar otra nota ingrese (s): ";
                    getline(cin, conti);
                    transform(conti.begin(), conti.end(), conti.begin(), ::tolower);
                    if (conti != "s"){
                        cout << "Volviendo al menu anterior\n";
                        continuar = false;
                    }
                }while(continuar);
                break;
            }
            case 5:{
                int accion;
                do{
                    cout << "Elija el tipo de reporte que desea: \n";
                    cout << "1. Obtener todos los alumnos de una carrera\n";
                    cout << "2. Obtener todos los cursos en los que un alumno está inscrito\n";
                    cout << "3. Calcular el promedio de notas de un alumno en un curso\n";
                    cout << "4. Calcular el promedio general de un alumno\n";
                    cout << "5. Volver al menu anterior\n";
                    cin >> accion;
                    
                    switch(accion){
                        case 1:{
                            string carrera;
                            cout << "Ingrese la carrera: ";
                            getline(cin, carrera);
                            
                            break;
                        }
                        case 2:{
                            string estudiante;
                            cout << "Ingrese el id del alumno: ";
                            getline(cin, estudiante);
                            
                            break;
                        }
                        case 3:{
                            string estudiante, curso;
                            cout << "Ingrese el id del alumno: ";
                            getline(cin, estudiante);
                            cout << "Ingrese el curso: ";
                            getline(cin, curso);
                            break;
                        }
                        case 4:{
                            string estudiante;
                            cout << "Ingrese el id del alumno: ";
                            getline(cin, estudiante);
                            break;
                        }
                        default:
                            if (accion != 5){
                                cout << "Opcion no valida";   
                            }
                    }
                }while(accion != 5);
                break;
            }
            default:
                cout << "Opcion no valida.\n";
        }
    }while (opcion != 6);
}