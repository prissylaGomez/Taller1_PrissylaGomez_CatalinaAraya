#include "Nota.h"
#include (iostream)

using namespace std;

Nota::Nota(string id;string curso){
    idAlumno =id;
    codigoCurso = curso;
    
}
string Nota::getidAlumno(){
    return idAlumno;
}
string Nota::getCodigoCurso(){
    return codigoCurso;
    
}
vector<float> Nota::getNotas(){
    return notas;
}
bool Nota::agregarNota(float nota){
    if(nota< 1,0 || nota > 7,0){
        cout<<"Error: nota fuera de rango"<<endl;
        return false;
    }
    notas.push_back(nota);
    return true;
}
float Nota::calcularPromedio(){
    if (notas.empty()){
        suma+=n;
    }
    return suma/notas.size();
}
void Nota::mostrarNota(){
    cout << "Estudiante: " << idAlumno << " |Curso: " << codigoCurso << endl;
    if(notas.empty()){
        cout << "no hay registro de notas " << endl;
        return;
    }
    cout << "Notas: ";
    for(float n : notas){
        cout << n << " " << endl;
    }
    cout << "Promedio: " << calcularProm() << endl;
    }
}
