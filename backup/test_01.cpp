#include "vacunas.h" // Incluir el archivo de encabezado de las funciones relacionadas con vacunas
#include "pacientes.h" // Incluir el archivo de encabezado de las funciones relacionadas con pacientes
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

int main()
{
  int opcion;

  while (true)
  {
    system("cls");

    cout << "MENU" << endl;
    cout << "1. Vacunas" << endl;
    cout << "2. Pacientes" << endl;
    cout << "3. Salir" << endl;

    cout << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
        vacunasMenu(); // Llamar a la función que contiene el menú de vacunas
        break;
      case 2:
        pacientesMenu(); // Llamar a la función que contiene el menú de pacientes
        break;
      case 3:
        return 0;
      default:
        cout << "Opción inválida. Intente nuevamente." << endl;
        break;
    }
  }

  return 0;
}
