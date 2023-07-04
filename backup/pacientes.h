#ifndef PACIENTES_H
#define PACIENTES_H

string PACIENTES_PATH;

class Paciente
{
private:
  char ID[10];
  char nombre[50];
  char apellidoPaterno[50];
  char apellidoMaterno[50];
  char fechaNacimiento[20];
  char genero[10];
  char correo[50];
  char distrito[50];
  char provincia[50];
  char departamento[50];
  char telefono[15];

public:
  Paciente(const char *_ID = "", const char *_nombre = "", const char *_apellidoPaterno = "", const char *_apellidoMaterno = "", const char *_fechaNacimiento = "", const char *_genero = "", const char *_correo = "", const char *_distrito = "", const char *_provincia = "", const char *_departamento = "", const char *_telefono = "");

  friend ostream &operator<<(ostream &os, const Paciente &pac);

  friend istream &operator>>(istream &is, Paciente &pac);

  void imprimir();

  const char *getID();

  const char *getNombre();
};

// Declarar los prototipos de las funciones relacionadas con los pacientes
void crearPaciente();
void leerPaciente();
void actualizarPaciente();
void eliminarPaciente();
void crearArchivoPacientes();
void borrarArchivoPacientes();
void pacientesMenu();

#endif
