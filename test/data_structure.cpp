#include <iostream>
#include <string>

using namespace std;

// Clase Vacuna
class Vacuna
{
private:
  int ID;
  string nombre;
  string fabricante;
  string fechaVencimiento;
  int stock;

public:
  Vacuna(int id, const string &n, const string &f, const string &fv, int s)
      : ID(id), nombre(n), fabricante(f), fechaVencimiento(fv), stock(s) {}

  // Métodos getter y setter para acceder a los atributos de la clase
};

// Clase Paciente
class Paciente {
private:
    int ID;
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string fechaNacimiento;
    char genero;
    string correo;
    string distrito;
    string provincia;
    string departamento;
    string telefono;

public:
    Paciente(int id, const string& n, const string& ap, const string& am, const string& fn, char g, const string& c,
        const string& d, const string& p, const string& dep, const string& t)
        : ID(id), nombre(n), apellidoPaterno(ap), apellidoMaterno(am), fechaNacimiento(fn), genero(g),
          correo(c), distrito(d), provincia(p), departamento(dep), telefono(t) {}

    // Métodos getter y setter para acceder a los atributos de la clase
};


// Clase HistorialVacunacion
class HistorialVacunacion
{
private:
  int ID;
  int IDVacuna;
  int IDPaciente;
  string fechaVacunacion;
  int dosis;
  string fechaSiguienteVacuna;

public:
  HistorialVacunacion(int id, int idVacuna, int idPaciente, const string &fv, int d, const string &fsv)
      : ID(id), IDVacuna(idVacuna), IDPaciente(idPaciente), fechaVacunacion(fv), dosis(d), fechaSiguienteVacuna(fsv) {}

  // Métodos getter y setter para acceder a los atributos de la clase
};

