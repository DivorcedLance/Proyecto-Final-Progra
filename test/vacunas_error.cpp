#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// *: ---------------PATHS DE ARCHIVOS---------------
string VACUNAS_PATH = "vacunas.dat";

// *: ---------------CLASES---------------

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

  int getID() const
  {
    return ID;
  }

  string getNombre() const
  {
    return nombre;
  }

  string getFabricante() const
  {
    return fabricante;
  }

  string getFechaVencimiento() const
  {
    return fechaVencimiento;
  }

  int getStock() const
  {
    return stock;
  }

  void setStock(int s)
  {
    stock = s;
  }
};

// *: ---------------PROTOTIPOS DE FUNCIONES---------------

// *: FUNCIONES CRUD DE PACIENTES
// Función para agregar una vacuna al archivo
void crearVacuna(const Vacuna &vacuna);

// Función para leer todas las vacunas del archivo
void leerVacunas();

// Función para actualizar una vacuna en el archivo
void actualizarVacuna(const Vacuna &vacunaActualizada);

// Función para eliminar una vacuna del archivo
void eliminarVacuna(int id);

void mostrarMenu();
void limpiarBuffer();

void agregarVacuna();

int test()
{

  Vacuna vacuna1(1, "Vacuna1", "Fabricante1", "2023-12-31", 100);
  crearVacuna(vacuna1);

  Vacuna vacuna2(2, "Vacuna2", "Fabricante2", "2024-06-30", 50);
  crearVacuna(vacuna2);

  leerVacunas();

  Vacuna vacunaActualizada(2, "Vacuna2", "Fabricante2", "2024-06-30", 75);
  actualizarVacuna(vacunaActualizada);

  leerVacunas();

  eliminarVacuna(1);

  leerVacunas();

  return 0;
}

int main()
{
  int opcion = 0;
  Vacuna vacuna1(1, "Vacuna1", "Fabricante1", "2023-12-31", 100);
  crearVacuna(vacuna1);
  while (opcion != 4)
  {
    mostrarMenu();

    // Obtener la opción del usuario
    cout << "Ingrese una opción: ";
    cin >> opcion;

    // Limpiar el buffer de entrada
    limpiarBuffer();

    // Ejecutar la opción seleccionada
    switch (opcion)
    {
    case 1:
      agregarVacuna();
      break;
    case 2:
      leerVacunas();
      break;
    case 3:
      // Lógica para actualizar una vacuna
      break;
    case 4:
      // Lógica para eliminar una vacuna
      break;
    case 5:
      // Salir del programa
      cout << "¡Hasta luego!" << endl;
      break;
    default:
      cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
      break;
    }
  }

  return 0;
}

void mostrarMenu()
{
  cout << "----- MENÚ -----" << endl;
  cout << "1. Agregar una vacuna" << endl;
  cout << "2. Mostrar todas las vacunas" << endl;
  cout << "3. Actualizar una vacuna" << endl;
  cout << "4. Eliminar una vacuna" << endl;
  cout << "5. Salir" << endl;
}

void limpiarBuffer()
{
  cin.ignore(999999, '\n');
}

// Función para agregar una vacuna al archivo
void crearVacuna(const Vacuna& vacuna)
{
  cout << "-----TEST-----" << endl; 
  cout << vacuna.getID() << endl;
  ofstream archivo(VACUNAS_PATH.c_str(), ios::binary | ios::app);
  if (archivo)
  {
    archivo.write(reinterpret_cast<const char*>(&vacuna), sizeof(Vacuna));
  }
  archivo.close();
}

// Función para leer todas las vacunas del archivo
void leerVacunas()
{
  ifstream archivo(VACUNAS_PATH.c_str(), ios::binary);
  if (archivo)
  {
    Vacuna vacuna(0, "", "", "", 0);
    while (archivo.read(reinterpret_cast<char*>(&vacuna), sizeof(Vacuna)))
    {
      cout << "ID: " << vacuna.getID() << endl;
      cout << "Nombre: " << vacuna.getNombre() << endl;
      cout << "Fabricante: " << vacuna.getFabricante() << endl;
      cout << "Fecha de vencimiento: " << vacuna.getFechaVencimiento() << endl;
      cout << "Stock: " << vacuna.getStock() << endl;
      cout << endl;
    }
  }
  archivo.close();
}

// Función para actualizar una vacuna en el archivo
void actualizarVacuna(const Vacuna &vacunaActualizada)
{
  fstream archivo(VACUNAS_PATH.c_str(), ios::binary | ios::in | ios::out);
  Vacuna vacuna(0, "", "", "", 0);
  while (archivo.read(reinterpret_cast<char *>(&vacuna), sizeof(Vacuna)))
  {
    if (vacuna.getID() == vacunaActualizada.getID())
    {
      archivo.seekp(-static_cast<int>(sizeof(Vacuna)), ios::cur);
      archivo.write(reinterpret_cast<const char *>(&vacunaActualizada), sizeof(Vacuna));
      break;
    }
  }
  archivo.close();
}

// Función para eliminar una vacuna del archivo
void eliminarVacuna(int id)
{
  ifstream archivoIn(VACUNAS_PATH.c_str(), ios::binary);
  ofstream archivoOut("temp.dat", ios::binary | ios::trunc);
  Vacuna vacuna(0, "", "", "", 0);
  while (archivoIn.read(reinterpret_cast<char *>(&vacuna), sizeof(Vacuna)))
  {
    if (vacuna.getID() != id)
    {
      archivoOut.write(reinterpret_cast<const char *>(&vacuna), sizeof(Vacuna));
    }
  }
  archivoIn.close();
  archivoOut.close();

  // Eliminar el archivo original y renombrar el archivo temporal
  remove(VACUNAS_PATH.c_str());
  rename("temp.dat", VACUNAS_PATH.c_str());
}

void agregarVacuna()
{
    // int id, stock;
    // string nombre, fabricante, fechaVencimiento;

    // // Solicitar datos al usuario
    // cout << "Ingrese el ID de la vacuna: ";
    // cin >> id;
    // cout << "Ingrese el nombre de la vacuna: ";
    // cin.ignore(); // Limpiar el búfer de entrada antes de getline()
    // getline(cin, nombre);
    // cout << "Ingrese el fabricante de la vacuna: ";
    // getline(cin, fabricante);
    // cout << "Ingrese la fecha de vencimiento de la vacuna (YYYY-MM-DD): ";
    // getline(cin, fechaVencimiento);
    // cout << "Ingrese el stock de la vacuna: ";
    // cin >> stock;

    // // Crear una instancia de la clase Vacuna con los datos ingresados
    // Vacuna nuevaVacuna(id, nombre, fabricante, fechaVencimiento, stock);
    Vacuna nuevaVacuna(2, "Vacuna2", "Fabricante2", "2022-02-02", 200);

    // Agregar la nueva vacuna a la base de datos
    crearVacuna(nuevaVacuna);

    cout << "La vacuna se ha agregado correctamente." << endl;
}