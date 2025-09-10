#include "Curso.h"
#include <iostream>
#include <algorithm>

using namespace std;

Curso::Curso(string c,string n,int maxi,string carrera,
string profe){
    codigo = c;
    nombre=n;
    estudiantes_max=maxi;
    carrera=carrera;
    profesor=profe;
}
string  Curso::getCodigo(){
    return codigo;
}
string Curso::getNombre(){
    return nombre;
}
int Curso::getEstudiantesMax(){
    return estudiantes_max:
}
string Curso::getCarrera(){
    return carrera;
}
string Curso:: getProfesor(){
    return profesor;
}
vector<string> Curso::getInscritos(){
    return Inscritos;
}

void Curso::setNombre(string n){
    nombre=n;
}
void Curso:: setEstudiantesMax(int max){
    estudiantes_max=max;
}
void Curso:: setProfesor(strin p){
    profesor=p;
}

bool Curso::inscribirAlumno(string idAlumno){
    if(Inscritos.size()>= estudiantes_max){
        cout <<"Curso lleno , no hay espacio para la inscripcion "<<endl;
    return false;
        
    }
    if(find(Inscritos.begin(),Inscritos.end(),idAlumno)!=
    Inscritos.end()){
        cout<<"alumno ya inscrito una vez "<<endl;
        return false;
    }
    Inscritos.push_back(idAlumno);
    return true;
    }
    bool Curso::eliminarAlumno(string idAlumno){
        for(int i=0;i< Inscritos.size();i++){
            if(Inscritos[i]==idAlumno){
                Inscritos.erase(Inscritos.begin()+i);
                return true;
            }
        }
        return false;
    }
    
    
    
    
    
    
}