#include "pacientes.h"
#include "vacunas.h"
#include "historialVacunacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

// Función para mostrar el menú de paciente
void mostrarMenuPaciente(const char *pacienteID)
{
  int opcionPaciente;

  while (true)
  {
    system("cls");

    cout << "----- MENÚ DE PACIENTE -----" << endl;
    cout << "ID: " << pacienteID << endl;
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
      leerPaciente(pacienteID);
      break;

    case 2:
      registrarVacunacion(pacienteID);
      break;

    case 3:
      leerHistorialPaciente(pacienteID);
      break;

    case 4:
      actualizarPaciente(pacienteID);
      break;

    case 5:
      eliminarPaciente(pacienteID);
      return; // Salir de la función
      break;

    case 0:
      return; // Salir de la función
      break;

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
    system("cls");
    cout << "----- CENTRO DE VACUNACIÓN -----" << endl;
    cout << "1. Registrar nuevo paciente" << endl;
    cout << "2. Buscar paciente" << endl;
    cout << "3. Imprimir pacientes" << endl;
    cout << "4. Registrar nuevo vacuna" << endl;
    cout << "0. Salir" << endl;
    cout << endl;
    cout << "DEV MENU" << endl;
    cout << "11. Crear archivo pacientes.bat" << endl;
    cout << "12. Crear archivo vacuna.bat" << endl;
    cout << "13. Crear archivo historialVacunacion.bat" << endl;
    cout << "14. Borrar archivo pacientes.bat" << endl;
    cout << "15. Borrar archivo vacuna.bat" << endl;
    cout << "16. Borrar archivo historialVacunacion.bat" << endl;

    cout << "Ingrese una opción: ";
    cin >> opcionPrincipal;
    const char* tempID = nullptr;
    char pacienteID[10];
    switch (opcionPrincipal)
    {
    case 1:
      tempID = crearPaciente();
      if (tempID != nullptr)
      {
        strcpy(pacienteID, tempID);
        delete[] tempID;
        mostrarMenuPaciente(pacienteID);
      }
      break;

    case 2:
      tempID = buscarPaciente();
      if (tempID != nullptr)
      {
        strcpy(pacienteID, tempID);
        delete[] tempID;
        mostrarMenuPaciente(pacienteID);
      }
      break;

    case 3:
      leerPacientes();
      break;

    case 4:
      crearVacuna();
      break;

    case 11:
      crearArchivoPacientes();
      break;

    case 12:
      crearArchivoVacunas();
      break;

    case 13:
      crearArchivoHistorialVacunacion();
      break;

    case 14:
      borrarArchivoPacientes();
      break;

    case 15:
      borrarArchivoVacunas();
      break;

    case 16:
      borrarArchivoHistorialVacunacion();
      break;

    case 0:
      cout << "Saliendo del programa..." << endl;
      break;

    default:
      cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
      break;
    }
  } while (opcionPrincipal != 0);
}

int main()
{
  mostrarMenuPrincipal();
  return 0;
}