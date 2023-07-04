#include "vacunas.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string VACUNAS_PATH = "vacunas.dat";

class Vacuna {
private:
  char ID[10];
  char nombre[50];
  char fabricante[50];

public:
  Vacuna(const char* _ID = "", const char* _nombre = "", const char* _fabricante = "") {
    strncpy(ID, _ID, 10);
    strncpy(nombre, _nombre, 50);
    strncpy(fabricante, _fabricante, 50);
  }

  friend ostream& operator<<(ostream& os, const Vacuna& vac) {
    os.write(vac.ID, 10);
    os.write(vac.nombre, 50);
    os.write(vac.fabricante, 50);
    return os;
  }

  friend istream& operator>>(istream& is, Vacuna& vac) {
    is.read(vac.ID, 10);
    is.read(vac.nombre, 50);
    is.read(vac.fabricante, 50);
    return is;
  }

  void setID(const char* _ID) {
    strncpy(ID, _ID, 10);
  }

  const char* getID() const {
    return ID;
  }

  void setNombre(const char* _nombre) {
    strncpy(nombre, _nombre, 50);
  }

  const char* getNombre() const {
    return nombre;
  }

  void setFabricante(const char* _fabricante) {
    strncpy(fabricante, _fabricante, 50);
  }

  const char* getFabricante() const {
    return fabricante;
  }

  void imprimir() const {
    cout << "ID: " << ID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Fabricante: " << fabricante << endl;
  }
};

bool vacunaExiste(const char* vacunaID)
{
  ifstream archivoLectura(VACUNAS_PATH.c_str(), ios::binary);
  if (!archivoLectura)
  {
    crearArchivoVacunas();
  }

  Vacuna vac;
  while (archivoLectura >> vac)
  {
    if (strcmp(vac.getID(), vacunaID) == 0)
    {
      archivoLectura.close();
      return true;
    }
  }

  archivoLectura.close();
  return false;
}

void crearVacuna()
{
  system("cls");

  char ID[10];
  cin.ignore();
  cout << "Ingrese el ID de la Vacuna: ";
  cin.getline(ID, 10);

  if (vacunaExiste(ID))
  {
    cout << "La vacuna con el ID " << ID << " ya existe." << endl;
    getch();
    return;
  }

  char nombre[50];
  char fabricante[50];

  cout << "Ingrese el nombre de la vacuna: ";
  cin.getline(nombre, 50);

  cout << "Ingrese la fabricante de la vacuna: ";
  cin.getline(fabricante, 50);

  Vacuna vac(ID, nombre, fabricante);

  ofstream archivo(VACUNAS_PATH.c_str(), ios::binary | ios::app);
  archivo << vac;
  archivo.close();

  cout << "Vacuna creada exitosamente." << endl;
  vac.imprimir();
  getch();
}

const char* mostrarVacunas()
{
  system("cls");

  ifstream archivo(VACUNAS_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    crearArchivoVacunas();
  }

  cout << "Vacunas disponibles:" << endl;
  cout << "--------------------" << endl;

  const int MAX_VACUNAS = 200;
  Vacuna* vacunas[MAX_VACUNAS] = {nullptr};

  Vacuna vac;
  int contador = 1;
  int totalVacunas = 0;

  while (archivo >> vac)
  {
    vacunas[totalVacunas] = new Vacuna(vac);
    totalVacunas++;

    cout << "Opción " << contador << ":" << endl;
    cout << "ID: " << vac.getID() << endl;
    cout << "Nombre: " << vac.getNombre() << endl;
    cout << "Fabricante: " << vac.getFabricante() << endl;
    cout << "--------------------" << endl;

    contador++;
  }

  archivo.close();

  if (totalVacunas == 0)
  {
    cout << "No hay vacunas disponibles." << endl;
    getch();
    return nullptr;
  }

  cout << "Seleccione una opción: ";
  int opcion;
  cin >> opcion;

  if (opcion < 1 || opcion > totalVacunas)
  {
    cout << "Opción inválida." << endl;
    return nullptr;
  }

  const char* seleccionado = vacunas[opcion - 1]->getID();

  // Liberar la memoria asignada para las instancias de vacuna
  for (int i = 0; i < totalVacunas; i++)
  {
    delete vacunas[i];
  }

  return seleccionado;
}

void crearArchivoVacunas()
{
  ofstream archivo(VACUNAS_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo crear el archivo vacunas.dat." << endl;
    return;
  }

  archivo.close();

  cout << "Archivo vacunas.dat creado exitosamente." << endl;
}

void borrarArchivoVacunas()
{
  if (remove(VACUNAS_PATH.c_str()) == 0)
  {
    cout << "Archivo vacunas.dat borrado exitosamente." << endl;
  }
  else
  {
    cout << "No se pudo borrar el archivo vacunas.dat." << endl;
  }
}


void generarDatosVacunas() {
  ofstream archivo(VACUNAS_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo crear el archivo vacunas.dat." << endl;
    return;
  }
  
  for (int i = 0; i < 8; i++) {
    const char* ids[8] = {"001", "002", "003", "004", "005", "006", "007", "008"};
    const char* nombres[8] = {"Pfizer-BioNTech", "Sinovac", "AstraZeneca", "Moderna", "Johnson & Johnson", "Covishield", "Sputnik V", "CanSino"};
    const char* fabricantes[8] = {"Pfizer-BioNTech", "Sinovac Life Sciences", "AstraZeneca", "Moderna, Inc.", "Johnson & Johnson", "Serum Institute of India", "Gamaleya Research Institute", "CanSino Biologics"};

    Vacuna pac(ids[i], nombres[i], fabricantes[i]);
    ofstream archivo(VACUNAS_PATH.c_str(), ios::binary | ios::app);
    archivo << pac;
    archivo.close();
  }
}