#include "pacientes.h"
#include "vacunas.h"
#include "historialVacunacion.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <string>

using namespace std;

string PACIENTES_PATH = "pacientes.dat";
string TMP_PATH = "temp.dat";

class Paciente
{
private:
  char ID[10];
  char nombre[50];
  char apellidoPaterno[50];
  char apellidoMaterno[50];
  char fechaNacimiento[20];
  char genero[20];
  char correo[100];
  char distrito[50];
  char provincia[50];
  char departamento[50];
  char telefono[20];

public:
  Paciente(const char *_ID = "", const char *_nombre = "", const char *_apellidoPaterno = "", const char *_apellidoMaterno = "", const char *_fechaNacimiento = "", const char *_genero = "", const char *_correo = "", const char *_distrito = "", const char *_provincia = "", const char *_departamento = "", const char *_telefono = "")
  {
    strncpy(ID, _ID, 10);
    strncpy(nombre, _nombre, 50);
    strncpy(apellidoPaterno, _apellidoPaterno, 50);
    strncpy(apellidoMaterno, _apellidoMaterno, 50);
    strncpy(fechaNacimiento, _fechaNacimiento, 20);
    strncpy(genero, _genero, 20);
    strncpy(correo, _correo, 100);
    strncpy(distrito, _distrito, 50);
    strncpy(provincia, _provincia, 50);
    strncpy(departamento, _departamento, 50);
    strncpy(telefono, _telefono, 20);
  }

  friend ostream &operator<<(ostream &os, const Paciente &pac)
  {
    os.write(pac.ID, 10);
    os.write(pac.nombre, 50);
    os.write(pac.apellidoPaterno, 50);
    os.write(pac.apellidoMaterno, 50);
    os.write(pac.fechaNacimiento, 20);
    os.write(pac.genero, 20);
    os.write(pac.correo, 100);
    os.write(pac.distrito, 50);
    os.write(pac.provincia, 50);
    os.write(pac.departamento, 50);
    os.write(pac.telefono, 20);
    return os;
  }

  friend istream &operator>>(istream &is, Paciente &pac)
  {
    is.read(pac.ID, 10);
    is.read(pac.nombre, 50);
    is.read(pac.apellidoPaterno, 50);
    is.read(pac.apellidoMaterno, 50);
    is.read(pac.fechaNacimiento, 20);
    is.read(pac.genero, 20);
    is.read(pac.correo, 100);
    is.read(pac.distrito, 50);
    is.read(pac.provincia, 50);
    is.read(pac.departamento, 50);
    is.read(pac.telefono, 20);
    return is;
  }

  void setID(const char *_ID)
  {
    strncpy(ID, _ID, 10);
  }

  const char *getID() const
  {
    return ID;
  }

  void setNombre(const char *_nombre)
  {
    strncpy(nombre, _nombre, 50);
  }

  const char *getNombre() const
  {
    return nombre;
  }

  void setApellidoPaterno(const char *_apellidoPaterno)
  {
    strncpy(apellidoPaterno, _apellidoPaterno, 50);
  }

  const char *getApellidoPaterno() const
  {
    return apellidoPaterno;
  }

  void setApellidoMaterno(const char *_apellidoMaterno)
  {
    strncpy(apellidoMaterno, _apellidoMaterno, 50);
  }

  const char *getApellidoMaterno() const
  {
    return apellidoMaterno;
  }

  void setFechaNacimiento(const char *_fechaNacimiento)
  {
    strncpy(fechaNacimiento, _fechaNacimiento, 20);
  }

  const char *getFechaNacimiento() const
  {
    return fechaNacimiento;
  }

  void setGenero(const char *_genero)
  {
    strncpy(genero, _genero, 20);
  }

  const char *getGenero() const
  {
    return genero;
  }

  void setCorreo(const char *_correo)
  {
    strncpy(correo, _correo, 100);
  }

  const char *getCorreo() const
  {
    return correo;
  }

  void setDistrito(const char *_distrito)
  {
    strncpy(distrito, _distrito, 50);
  }

  const char *getDistrito() const
  {
    return distrito;
  }

  void setProvincia(const char *_provincia)
  {
    strncpy(provincia, _provincia, 50);
  }

  const char *getProvincia() const
  {
    return provincia;
  }

  void setDepartamento(const char *_departamento)
  {
    strncpy(departamento, _departamento, 50);
  }

  const char *getDepartamento() const
  {
    return departamento;
  }

  void setTelefono(const char *_telefono)
  {
    strncpy(telefono, _telefono, 20);
  }

  const char *getTelefono() const
  {
    return telefono;
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
};

bool pacienteExiste(const char *pacienteID)
{
  ifstream archivoLectura(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    crearArchivoPacientes();
  }

  Paciente pac;
  while (archivoLectura >> pac)
  {
    if (strcmp(pac.getID(), pacienteID) == 0)
    {
      archivoLectura.close();
      return true;
    }
  }

  archivoLectura.close();
  return false;
}

const char *crearPaciente()
{
  system("cls");

  char *ID = new char[10];
  ;
  cin.ignore();
  cout << "Ingrese el ID del Paciente: ";
  cin.getline(ID, 10);

  if (pacienteExiste(ID))
  {
    cout << "El paciente con el ID: " << ID << " ya existe." << endl;
    getch();
    delete[] ID;
    return nullptr;
  }

  char nombre[50];
  char apellidoPaterno[50];
  char apellidoMaterno[50];
  char fechaNacimiento[20];
  char genero[20];
  char correo[100];
  char distrito[50];
  char provincia[50];
  char departamento[50];
  char telefono[20];

  cout << "Ingrese el nombre: ";
  cin.getline(nombre, 50);

  cout << "Ingrese el apellido paterno: ";
  cin.getline(apellidoPaterno, 50);

  cout << "Ingrese el apellido materno: ";
  cin.getline(apellidoMaterno, 50);

  cout << "Ingrese la fecha de nacimiento: ";
  cin.getline(fechaNacimiento, 20);

  cout << "Ingrese el género: ";
  cin.getline(genero, 20);

  cout << "Ingrese el correo: ";
  cin.getline(correo, 100);

  cout << "Ingrese el distrito: ";
  cin.getline(distrito, 50);

  cout << "Ingrese la provincia: ";
  cin.getline(provincia, 50);

  cout << "Ingrese el departamento: ";
  cin.getline(departamento, 50);

  cout << "Ingrese el teléfono: ";
  cin.getline(telefono, 20);

  Paciente pac(ID, nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, genero, correo, distrito, provincia, departamento, telefono);

  ofstream archivo(PACIENTES_PATH.c_str(), ios::binary | ios::app);
  archivo << pac;
  archivo.close();

  cout << "Paciente creado exitosamente." << endl;

  return pac.getID();
}

const char *buscarPaciente()
{
  system("cls");

  char *ID = new char[10];
  ;
  cin.ignore();
  cout << "Ingrese el ID del Paciente: ";
  cin.getline(ID, 10);

  if (!pacienteExiste(ID))
  {
    cout << "No se encontró un paciente con el ID especificado." << endl;
    getch();
    delete[] ID;
    return nullptr;
  }
  else
  {
    return ID;
  }
}

void leerPaciente(const char *pacienteID)
{
  system("cls");

  ifstream archivo(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo de pacientes." << endl;
    return;
  }

  Paciente pac;
  bool encontrado = false;

  while (archivo >> pac)
  {
    if (strcmp(pac.getID(), pacienteID) == 0)
    {
      encontrado = true;
      pac.imprimir();
      cout << endl;
      getch();
    }
  }

  archivo.close();

  if (!encontrado)
  {
    cout << "No se encontró un paciente con el ID especificado." << endl;
    getch();
  }
}

void registrarVacunacion(const char *pacienteID)
{
  const char* tempID = nullptr;
  char vacunaID[10];

  tempID = mostrarVacunas();
  if (tempID != nullptr)
  {
    strcpy(vacunaID, tempID);
    delete[] tempID;
    crearHistorialVacunacion(pacienteID, vacunaID);
  }
  return;
}

void leerHistorialPaciente(const char *pacienteID)
{
  leerHistorialVacunacionPaciente(pacienteID);
  return;
}

void actualizarPaciente(const char *pacienteID)
{
  system("cls");

  ifstream archivoLectura(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    cout << "No se pudo abrir el archivo de pacientes." << endl;
    return;
  }

  ofstream archivoEscritura("temp.dat", ios::binary);
  if (!archivoEscritura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    archivoLectura.close();
    return;
  }

  Paciente pac;
  bool encontrado = false;

  while (archivoLectura >> pac)
  {
    if (strcmp(pac.getID(), pacienteID) == 0)
    {
      encontrado = true;
      pac.imprimir();

      cin.ignore();

      cout << endl;

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

      pac = Paciente(pacienteID, nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, genero, correo, distrito, provincia, departamento, telefono);
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

void eliminarPaciente(const char *pacienteID)
{
  system("cls");

  ifstream archivoLectura(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    cout << "No se pudo abrir el archivo de pacientes." << endl;
    return;
  }

  ofstream archivoEscritura("temp.dat", ios::binary);
  if (!archivoEscritura)
  {
    cout << "No se pudo abrir el archivo." << endl;
    archivoLectura.close();
    return;
  }

  Paciente pac;
  bool encontrado = false;

  while (archivoLectura >> pac)
  {
    if (strcmp(pac.getID(), pacienteID) == 0)
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

void leerPacientes()
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



void generarDatosPacientes() {
  ofstream archivo(PACIENTES_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo crear el archivo pacientes.dat." << endl;
    return;
  }
    const char* id[15] = {"001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011", "012", "013", "014", "015"};
  const char* nombres[15] = {"Juan", "María", "Carlos", "Ana", "Luis", "Carmen", "Jorge", "Rosa", "Pedro", "Laura", "José", "Silvia", "Marco", "Paola", "Ricardo"};
  const char* apellidosPaterno[15] = {"García", "Torres", "Vargas", "Paredes", "Ramos", "Huamán", "Castro", "Soto", "Mendoza", "Castro", "Aguilar", "Gutiérrez", "Vidal", "Ríos", "Medina"};
  const char* apellidosMaterno[15] = {"Rodríguez", "López", "Guzmán", "Díaz", "Chavez", "Sánchez", "Gómez", "Gonzales", "Alvarado", "Ruiz", "Valdez", "Torres", "Vargas", "Quispe", "Espinoza"};
  const char* fechasNacimiento[15] = {"15/05/1985", "10/12/1990", "20/07/1978", "05/03/1965", "18/09/1980", "25/06/1995", "12/11/1972", "30/04/1993", "07/08/1988", "14/02/1977", "03/09/1996", "25/07/1982", "02/06/1970", "17/11/1991", "12/03/1987"};
  const char* generos[15] = {"Masculino", "Femenino", "Masculino", "Femenino", "Masculino", "Femenino", "Masculino", "Femenino", "Masculino", "Femenino", "Masculino", "Femenino", "Masculino", "Femenino", "Masculino"};
  const char* correos[15] = {"juan.garcia@example.com", "maria.torres@example.com", "carlos.vargas@example.com", "ana.paredes@example.com", "luis.ramos@example.com", "carmen.huaman@example.com", "jorge.castro@example.com", "rosa.soto@example.com", "pedro.mendoza@example.com", "laura.castro@example.com", "jose.aguilar@example.com", "silvia.gutierrez@example.com", "marco.vidal@example.com", "paola.rios@example.com", "ricardo.medina@example.com"};
  const char* distritos[15] = {"Miraflores", "San Isidro", "La Victoria", "Surco", "Trujillo", "Cusco", "Los Olivos", "San Juan de Miraflores", "Callao", "San Borja", "Arequipa", "Piura", "Chiclayo", "Huancayo", "Iquitos"};
  const char* provincias[15] = {"Lima", "Lima", "Lima", "Lima", "Trujillo", "Cusco", "Lima", "Lima", "Callao", "Lima", "Arequipa", "Piura", "Chiclayo", "Huancayo", "Maynas"};
  const char* departamentos[15] = {"Lima", "Lima", "Lima", "Lima", "La Libertad", "Cusco", "Lima", "Lima", "Callao", "Lima", "Arequipa", "Piura", "Lambayeque", "Junín", "Loreto"};
  const char* telefonos[15] = {"987654321", "912345678", "934567890", "945678901", "956789012", "967890123", "978901234", "989012345", "990123456", "901234567", "912345678", "923456789", "934567890", "945678901", "956789012"};

  for (int i = 0; i < 15; i++) {
    Paciente pac(id[i], nombres[i], apellidosPaterno[i], apellidosMaterno[i], fechasNacimiento[i], generos[i], correos[i], distritos[i], provincias[i], departamentos[i] , telefonos[i]);
    ofstream archivo(PACIENTES_PATH.c_str(), ios::binary | ios::app);
    archivo << pac;
    archivo.close();
  }
}