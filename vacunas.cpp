#include "vacunas.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string VACUNAS_PATH = "vacunas.dat";

class Vacuna
{
private:
  int ID;
  char nombre[50];
  char fabricante[50];
  char fechaVencimiento[20];
  int stock;

public:
  Vacuna(int _ID = 0, const char *_nombre = "", const char *_fabricante = "", const char *_fechaVencimiento = "", int _stock = 0)
  {
    ID = _ID;
    strncpy(nombre, _nombre, 50);
    strncpy(fabricante, _fabricante, 50);
    strncpy(fechaVencimiento, _fechaVencimiento, 20);
    stock = _stock;
  }

  friend ostream &operator<<(ostream &os, const Vacuna &vac)
  {
    os.write(reinterpret_cast<const char *>(&vac.ID), sizeof(int));
    os.write(vac.nombre, 50);
    os.write(vac.fabricante, 50);
    os.write(vac.fechaVencimiento, 20);
    os.write(reinterpret_cast<const char *>(&vac.stock), sizeof(int));
    return os;
  }

  friend istream &operator>>(istream &is, Vacuna &vac)
  {
    is.read(reinterpret_cast<char *>(&vac.ID), sizeof(int));
    is.read(vac.nombre, 50);
    is.read(vac.fabricante, 50);
    is.read(vac.fechaVencimiento, 20);
    is.read(reinterpret_cast<char *>(&vac.stock), sizeof(int));
    return is;
  }

  void imprimir() const
  {
    cout << "ID: " << ID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Fabricante: " << fabricante << endl;
    cout << "Fecha de vencimiento: " << fechaVencimiento << endl;
    cout << "Stock: " << stock << endl;
  }

  int getID() const
  {
    return ID;
  }

  const char *getNombre() const
  {
    return nombre;
  }
};

void crearVacuna()
{
  system("cls");

  int ID;
  char nombre[50];
  char fabricante[50];
  char fechaVencimiento[20];
  int stock;

  cout << "Ingrese el ID de la Vacuna: ";
  cin >> ID;

  cin.ignore();
  cout << "Ingrese el nombre: ";
  cin.getline(nombre, 50);

  cout << "Ingrese el fabricante: ";
  cin.getline(fabricante, 50);

  cout << "Ingrese la fecha de vencimiento: ";
  cin.getline(fechaVencimiento, 20);

  cout << "Ingrese el stock: ";
  cin >> stock;

  Vacuna vac(ID, nombre, fabricante, fechaVencimiento, stock);

  ofstream archivo(VACUNAS_PATH.c_str(), ios::binary | ios::app);
  archivo << vac;
  archivo.close();

  cout << "Vacuna creada exitosamente." << endl;
}

void leerVacuna()
{
  system("cls");

  ifstream archivo(VACUNAS_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  Vacuna vac;
  while (archivo >> vac)
  {
    vac.imprimir();
    cout << endl;
  }

  archivo.close();
  getch();
}

void actualizarVacuna()
{
  system("cls");

  int ID;
  char nombre[50];
  char fabricante[50];
  char fechaVencimiento[20];
  int stock;

  cout << "Ingrese el ID de la vacuna a actualizar: ";
  cin >> ID;

  cin.ignore();
  cout << "Ingrese el nuevo nombre: ";
  cin.getline(nombre, 50);

  cout << "Ingrese el nuevo fabricante: ";
  cin.getline(fabricante, 50);

  cout << "Ingrese la nueva fecha de vencimiento: ";
  cin.getline(fechaVencimiento, 20);

  cout << "Ingrese el nuevo stock: ";
  cin >> stock;

  ifstream archivoLectura(VACUNAS_PATH.c_str(), ios::binary);
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

  Vacuna vac;
  bool encontrado = false;

  while (archivoLectura >> vac)
  {
    if (vac.getID() == ID)
    {
      encontrado = true;
      vac.imprimir();
      vac = Vacuna(ID, nombre, fabricante, fechaVencimiento, stock);
      cout << "Vacuna actualizada." << endl;
    }
    archivoEscritura << vac;
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró la vacuna con el ID especificado." << endl;
    return;
  }

  remove(VACUNAS_PATH.c_str());
  rename("temp.dat", VACUNAS_PATH.c_str());
}

void eliminarVacuna()
{
  system("cls");

  int ID;

  cout << "Ingrese el ID de la vacuna a eliminar: ";
  cin >> ID;

  ifstream archivoLectura(VACUNAS_PATH.c_str(), ios::binary);
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

  Vacuna vac;
  bool encontrado = false;

  while (archivoLectura >> vac)
  {
    if (vac.getID() == ID)
    {
      encontrado = true;
      vac.imprimir();
      cout << "Vacuna eliminada." << endl;
    }
    else
    {
      archivoEscritura << vac;
    }
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró la vacuna con el ID especificado." << endl;
    return;
  }

  remove(VACUNAS_PATH.c_str());
  rename("temp.dat", VACUNAS_PATH.c_str());
}

void crearArchivo()
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

void borrarArchivo()
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

void vacunasMenu()
{
  int opcion;

  while (true)
  {
    system("cls");
    cout << "MENU" << endl;
    cout << "1. Crear vacuna" << endl;
    cout << "2. Leer vacunas" << endl;
    cout << "3. Actualizar vacuna" << endl;
    cout << "4. Eliminar vacuna" << endl;
    cout << "0. Salir" << endl;

    cout << endl;
    cout << "DEV MENU" << endl;
    cout << "11. Crear Archivo vacunas.dat" << endl;
    cout << "12. Borrar Archivo vacunas.dat" << endl;

    cout << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      crearVacuna();
      break;
    case 2:
      leerVacuna();
      break;
    case 3:
      actualizarVacuna();
      break;
    case 4:
      eliminarVacuna();
      break;
    case 11:
      crearArchivo();
      break;
    case 12:
      borrarArchivo();
      break;
    case 0:
      return;
    default:
      cout << "Opción inválida. Intente nuevamente." << endl;
      break;
    }
  }
}
