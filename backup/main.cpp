#include "vacunas.h"
#include "pacientes.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

// Función para mostrar el menú de paciente
void mostrarMenuPaciente(int pacienteID)
{
  int opcionPaciente;

  while (true)
  {
    system("cls");

    cout << "----- MENÚ DE PACIENTE -----" << endl;
    cout << "1. Ver información del paciente" << endl;
    cout << "2. Registrar vacunación" << endl;
    cout << "3. Ver historial de vacunación" << endl;
    cout << "4. Actualizar información del paciente" << endl;
    cout << "5. Eliminar paciente" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Ingrese una opción: ";

    cin >> opcionPaciente;

    switch (opcionPaciente)
    {
    case 1:
      // Lógica para ver información del paciente
      break;

    case 2:
      // Lógica para registrar una vacunación
      break;

    case 3:
      // Lógica para ver historial de vacunación
      break;

    case 4:
      // Lógica para actualizar información del paciente
      break;

    case 5:
      // Lógica para eliminar un paciente
      break;

    case 0:
      return; // Salir de la función

    default:
      cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
      break;
    }
  }
}

void mostrarMenuPrincipal()
{
  int opcionPrincipal;

  do
  {
    cout << "----- CENTRO DE VACUNACIÓN -----" << endl;
    cout << "1. Registrar nuevo paciente" << endl;
    cout << "2. Buscar paciente" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcionPrincipal;

    switch (opcionPrincipal)
    {
    int pacienteID;
    case 1:
      pacienteID;
      mostrarMenuPaciente(pacienteID); // Pasar Paciente como parámetro
      break;

    case 2:
      // Lógica para buscar un paciente
      mostrarMenuPaciente(pacienteID); // Pasar Paciente como parámetro
      break;

    case 3:
      cout << "Saliendo del programa..." << endl;
      break;

    default:
      cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
      break;
    }
  } while (opcionPrincipal != 3);
}
