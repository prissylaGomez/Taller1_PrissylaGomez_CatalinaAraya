
#include <string>
#include<vector>
using namespace std;

class Curso{
    private:
        string codigo;
        string nombre;
        int estudiantes_max;
        string carrera;
        string profesor;
        vector<string> Inscritos;
    public:
    Curso(string c , string n , int max, string carrera, 
    profe);
    
    string getCodigo();
    string getNombre();
    int getEstudiantesMax();
    string getCarrera();
    string getProfesor();
    vector<string>getInscritos();
    
    void setNombre(string n);
    void setEstudiantesMax(int max);
    void setProfesor(string profe);
    
    bool inscribirestudiante(string idAlumno);
    bool eliminaEstudiante(string idAlumno);
    
    void mostrarInfo();
};

