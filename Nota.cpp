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
//agh hay que poner lo de agregar nota y calcular promedio
//tambn hay q poner aqui lo de mostrar nota ;;
