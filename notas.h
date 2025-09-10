#include <string>
#include <vector>
using namespace std;

class Nota{
private:
    string idAlumno;
    string codigoCurso;
    vector<float>notas;
    
public:
    Nota(string id,string curso);
    
    string getidAlumno();
    string getCodigoCurso();
    vector<float>getNotas();
    
    bool agregarNota(float nota);
    float calcularProm();
    void mostrarNota();
    

};

