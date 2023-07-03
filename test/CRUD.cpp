#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string DATOS_PATH = "datos.dat";

class Objeto
{
private:
  char nombre[50];
  int edad;

public:
  Objeto(const char *_nombre = "", int _edad = 0)
  {
    strncpy(nombre, _nombre, 50);
    edad = _edad;
  }

  friend ostream &operator<<(ostream &os, const Objeto &obj)
  {
    os.write(obj.nombre, 50);
    os.write(reinterpret_cast<const char *>(&obj.edad), sizeof(int));
    return os;
  }

  friend istream &operator>>(istream &is, Objeto &obj)
  {
    is.read(obj.nombre, 50);
    is.read(reinterpret_cast<char *>(&obj.edad), sizeof(int));
    return is;
  }

  void imprimir() const
  {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
  }

  const char *getNombre() const
  {
    return nombre;
  }
};

void crearObjeto()
{
  system("cls");

  char nombre[50];
  int edad;

  cout << "Ingrese el nombre: ";
  cin.ignore();
  cin.getline(nombre, 50);

  cout << "Ingrese la edad: ";
  cin >> edad;

  Objeto obj(nombre, edad);

  ofstream archivo(DATOS_PATH.c_str(), ios::binary | ios::app);
  archivo << obj;
  archivo.close();

  cout << "Objeto creado exitosamente." << endl;
}

void leerObjeto()
{
  system("cls");
  
  ifstream archivo(DATOS_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  Objeto obj;
  while (archivo >> obj)
  {
    obj.imprimir();
    cout << endl;
  }

  archivo.close();
  getch();
}

void actualizarObjeto()
{
  system("cls");

  char nombre[50];
  int edad;

  cout << "Ingrese el nombre del objeto a actualizar: ";
  cin.ignore();
  cin.getline(nombre, 50);

  cout << "Ingrese la nueva edad: ";
  cin >> edad;

  ifstream archivoLectura(DATOS_PATH.c_str(), ios::binary);
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

  Objeto obj;
  bool encontrado = false;

  while (archivoLectura >> obj)
  {
    if (strcmp(obj.getNombre(), nombre) == 0)
    {
      encontrado = true;
      obj.imprimir();
      obj = Objeto(nombre, edad);
      cout << "Objeto actualizado." << endl;
    }
    archivoEscritura << obj;
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró el objeto con el nombre especificado." << endl;
    return;
  }

  remove(DATOS_PATH.c_str());
  rename("temp.dat", DATOS_PATH.c_str());
}

void eliminarObjeto()
{
  system("cls");

  char nombre[50];

  cout << "Ingrese el nombre del objeto a eliminar: ";
  cin.ignore();
  cin.getline(nombre, 50);

  ifstream archivoLectura(DATOS_PATH.c_str(), ios::binary);
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

  Objeto obj;
  bool encontrado = false;

  while (archivoLectura >> obj)
  {
    if (strcmp(obj.getNombre(), nombre) == 0)
    {
      encontrado = true;
      obj.imprimir();
      cout << "Objeto eliminado." << endl;
    }
    else
    {
      archivoEscritura << obj;
    }
  }

  archivoLectura.close();
  archivoEscritura.close();

  if (!encontrado)
  {
    cout << "No se encontró el objeto con el nombre especificado." << endl;
    return;
  }

  remove(DATOS_PATH.c_str());
  rename("temp.dat", DATOS_PATH.c_str());
}

int mostrarMenu()
{
  system("cls");

  int opcion;
  cout << "====== Menú ======" << endl;
  cout << "1. Crear objeto" << endl;
  cout << "2. Leer objetos" << endl;
  cout << "3. Actualizar objeto" << endl;
  cout << "4. Eliminar objeto" << endl;
  cout << "5. Salir" << endl;
  cout << "===================" << endl;
  cout << "Ingrese una opción: ";
  cin >> opcion;

  return opcion;
}

int main()
{
  int opcion;

  do
  {
    opcion = mostrarMenu();

    switch (opcion)
    {
    case 1:
      crearObjeto();
      break;
    case 2:
      leerObjeto();
      break;
    case 3:
      actualizarObjeto();
      break;
    case 4:
      eliminarObjeto();
      break;
    case 5:
      cout << "Saliendo del programa..." << endl;
      break;
    default:
      cout << "Opción inválida. Intente nuevamente." << endl;
      break;
    }

    cout << endl;

  } while (opcion != 5);

  return 0;
}
