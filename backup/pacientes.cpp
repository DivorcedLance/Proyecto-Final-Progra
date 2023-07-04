#include "pacientes.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string PACIENTES_PATH = "pacientes.dat";

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
  Paciente(const char *_ID = "", const char *_nombre = "", const char *_apellidoPaterno = "", const char *_apellidoMaterno = "", const char *_fechaNacimiento = "", const char *_genero = "", const char *_correo = "", const char *_distrito = "", const char *_provincia = "", const char *_departamento = "", const char *_telefono = "")
  {
    strncpy(ID, _ID, 10);
    strncpy(nombre, _nombre, 50);
    strncpy(apellidoPaterno, _apellidoPaterno, 50);
    strncpy(apellidoMaterno, _apellidoMaterno, 50);
    strncpy(fechaNacimiento, _fechaNacimiento, 20);
    strncpy(genero, _genero, 10);
    strncpy(correo, _correo, 50);
    strncpy(distrito, _distrito, 50);
    strncpy(provincia, _provincia, 50);
    strncpy(departamento, _departamento, 50);
    strncpy(telefono, _telefono, 15);
  }

  friend ostream &operator<<(ostream &os, const Paciente &pac)
  {
    os.write(pac.ID, 10);
    os.write(pac.nombre, 50);
    os.write(pac.apellidoPaterno, 50);
    os.write(pac.apellidoMaterno, 50);
    os.write(pac.fechaNacimiento, 20);
    os.write(pac.genero, 10);
    os.write(pac.correo, 50);
    os.write(pac.distrito, 50);
    os.write(pac.provincia, 50);
    os.write(pac.departamento, 50);
    os.write(pac.telefono, 15);
    return os;
  }

  friend istream &operator>>(istream &is, Paciente &pac)
  {
    is.read(pac.ID, 10);
    is.read(pac.nombre, 50);
    is.read(pac.apellidoPaterno, 50);
    is.read(pac.apellidoMaterno, 50);
    is.read(pac.fechaNacimiento, 20);
    is.read(pac.genero, 10);
    is.read(pac.correo, 50);
    is.read(pac.distrito, 50);
    is.read(pac.provincia, 50);
    is.read(pac.departamento, 50);
    is.read(pac.telefono, 15);
    return is;
  }

  void imprimir() const
  {
    cout << "ID: " << ID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido Paterno: " << apellidoPaterno << endl;
    cout << "Apellido Materno: " << apellidoMaterno << endl;
    cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
    cout << "Género: " << genero << endl;
    cout << "Correo: " << correo << endl;
    cout << "Distrito: " << distrito << endl;
    cout << "Provincia: " << provincia << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Teléfono: " << telefono << endl;
  }

  const char *getID() const
  {
    return ID;
  }

  const char *getNombre() const
  {
    return nombre;
  }
};

void crearPaciente()
{
  system("cls");

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

  cout << "Ingrese el ID del Paciente: ";
  cin >> ID;

  cin.ignore();
  cout << "Ingrese el nombre: ";
  cin.getline(nombre, 50);

  cout << "Ingrese el apellido paterno: ";
  cin.getline(apellidoPaterno, 50);

  cout << "Ingrese el apellido materno: ";
  cin.getline(apellidoMaterno, 50);

  cout << "Ingrese la fecha de nacimiento: ";
  cin.getline(fechaNacimiento, 20);

  cout << "Ingrese el género: ";
  cin.getline(genero, 10);

  cout << "Ingrese el correo: ";
  cin.getline(correo, 50);

  cout << "Ingrese el distrito: ";
  cin.getline(distrito, 50);

  cout << "Ingrese la provincia: ";
  cin.getline(provincia, 50);

  cout << "Ingrese el departamento: ";
  cin.getline(departamento, 50);

  cout << "Ingrese el teléfono: ";
  cin.getline(telefono, 15);

  Paciente pac(ID, nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, genero, correo, distrito, provincia, departamento, telefono);

  ofstream archivo(PACIENTES_PATH.c_str(), ios::binary | ios::app);
  archivo << pac;
  archivo.close();

  cout << "Paciente creado exitosamente." << endl;
}

void leerPaciente()
{
  system("cls");

  ifstream archivo(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  Paciente pac;
  while (archivo >> pac)
  {
    pac.imprimir();
    cout << endl;
  }

  archivo.close();
  getch();
}

void actualizarPaciente()
{
  system("cls");

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

  ifstream archivoLectura(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  ofstream archivoEscritura("temp.dat", ios::binary);
  if (!archivoEscritura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  cout << "Ingrese el ID del paciente a actualizar: ";
  cin >> ID;

  Paciente pac;
  bool encontrado = false;

  while (archivoLectura >> pac)
  {
    if (strcmp(pac.getID(), ID) == 0)
    {
      encontrado = true;
      pac.imprimir();

      cin.ignore();

      cout << endl;

      cout << "Ingrese el nuevo nombre: ";
      cin.getline(nombre, 50);

      cout << "Ingrese el nuevo apellido paterno: ";
      cin.getline(apellidoPaterno, 50);

      cout << "Ingrese el nuevo apellido materno: ";
      cin.getline(apellidoMaterno, 50);

      cout << "Ingrese la nueva fecha de nacimiento: ";
      cin.getline(fechaNacimiento, 20);

      cout << "Ingrese el nuevo género: ";
      cin.getline(genero, 10);

      cout << "Ingrese el nuevo correo: ";
      cin.getline(correo, 50);

      cout << "Ingrese el nuevo distrito: ";
      cin.getline(distrito, 50);

      cout << "Ingrese la nueva provincia: ";
      cin.getline(provincia, 50);

      cout << "Ingrese el nuevo departamento: ";
      cin.getline(departamento, 50);

      cout << "Ingrese el nuevo teléfono: ";
      cin.getline(telefono, 15);

      pac = Paciente(ID, nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, genero, correo, distrito, provincia, departamento, telefono);
      cout << "Paciente actualizado." << endl;
    }
    archivoEscritura << pac;
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró el paciente con el ID especificado." << endl;
    getch();
    return;
  }

  remove(PACIENTES_PATH.c_str());
  rename("temp.dat", PACIENTES_PATH.c_str());
}

void eliminarPaciente()
{
  system("cls");

  char ID[10];

  cout << "Ingrese el ID del paciente a eliminar: ";
  cin >> ID;

  ifstream archivoLectura(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  ofstream archivoEscritura("temp.dat", ios::binary);
  if (!archivoEscritura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  Paciente pac;
  bool encontrado = false;

  while (archivoLectura >> pac)
  {
    if (strcmp(pac.getID(), ID) == 0)
    {
      encontrado = true;
      pac.imprimir();
      cout << "Paciente eliminado." << endl;
    }
    else
    {
      archivoEscritura << pac;
    }
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró el paciente con el ID especificado." << endl;
    getch();
    return;
  }

  remove(PACIENTES_PATH.c_str());
  rename("temp.dat", PACIENTES_PATH.c_str());
}

void crearArchivoPacientes()
{
  ofstream archivo(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo crear el archivo pacientes.dat." << endl;
    return;
  }

  archivo.close();

  cout << "Archivo pacientes.dat creado exitosamente." << endl;
}

void borrarArchivoPacientes()
{
  if (remove(PACIENTES_PATH.c_str()) == 0)
  {
    cout << "Archivo pacientes.dat eliminado exitosamente." << endl;
  }
  else
  {
    cout << "No se pudo eliminar el archivo pacientes.dat." << endl;
  }
}

void pacientesMenu()
{
  int opcion;

  while (true)
  {
    system("cls");

    cout << "MENU PACIENTE" << endl;
    cout << "1. Crear paciente" << endl;
    cout << "2. Leer pacientes" << endl;
    cout << "3. Actualizar paciente" << endl;
    cout << "4. Eliminar paciente" << endl;
    cout << "0. Volver" << endl;

    cout << endl;
    cout << "DEV MENU" << endl;
    cout << "11. Crear Archivo pacientes.dat" << endl;
    cout << "12. Borrar Archivo pacientes.dat" << endl;

    cout << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      crearPaciente();
      break;
    case 2:
      leerPaciente();
      break;
    case 3:
      actualizarPaciente();
      break;
    case 4:
      eliminarPaciente();
      break;
    case 11:
      crearArchivoPacientes();
      break;
    case 12:
      borrarArchivoPacientes();
      break;
    case 0:
      return;
    default:
      cout << "Opción inválida. Intente nuevamente." << endl;
      break;
    }
  }
}
