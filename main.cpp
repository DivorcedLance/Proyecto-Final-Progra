#include "pacientes.h" // Funciones relacionadas con pacientes
#include "vacunas.h" // Funciones relacionadas con vacunas
#include "historialVacunacion.h" // Funciones relacionadas con el historial de vacunación
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

// Muestra el menú de paciente
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
      leerPaciente(pacienteID); // Muestra información del paciente
      break;

    case 2:
      registrarVacunacion(pacienteID); // Registra una vacunación para el paciente
      break;

    case 3:
      leerHistorialPaciente(pacienteID); // Muestra el historial de vacunación del paciente
      break;

    case 4:
      actualizarPaciente(pacienteID); // Actualiza la información del paciente
      break;

    case 5:
      eliminarPaciente(pacienteID); // Elimina al paciente
      return; // Sale de la función y vuelve al menú principal
      break;

    case 0:
      return; // Sale de la función y vuelve al menú principal
      break;

    default:
      cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
      break;
    }
  }
}

// Muestra el menú principal
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
    cout << "4. Registrar nueva vacuna" << endl;
    cout << "0. Salir" << endl;
    cout << endl;
    cout << "DEV MENU" << endl;
    cout << "11. Crear archivos" << endl;
    cout << "12. Borrar archivos" << endl;

    cout << "Ingrese una opción: ";
    cin >> opcionPrincipal;
    const char* tempID = nullptr;
    char pacienteID[10];
    switch (opcionPrincipal)
    {
    case 1:
      tempID = crearPaciente(); // Registra un nuevo paciente y devuelve el ID del paciente
      if (tempID != nullptr)
      {
        strcpy(pacienteID, tempID); // Copia el ID del paciente a la variable pacienteID
        delete[] tempID; // Libera la memoria asignada a tempID
        mostrarMenuPaciente(pacienteID); // Muestra el menú de paciente con el ID del paciente como argumento
      }
      break;

    case 2:
      tempID = buscarPaciente(); // Busca un paciente existente y devuelve el ID del paciente
      if (tempID != nullptr)
      {
        strcpy(pacienteID, tempID); // Copia el ID del paciente a la variable pacienteID
        delete[] tempID; // Libera la memoria asignada a tempID
        mostrarMenuPaciente(pacienteID); // Muestra el menú de paciente con el ID del paciente como argumento
      }
      break;

    case 3:
      leerPacientes(); // Imprime la lista de pacientes
      break;

    case 4:
      crearVacuna(); // Registra una nueva vacuna
      break;

    case 11:
      crearArchivoPacientes(); // Crea el archivo de pacientes
      crearArchivoVacunas(); // Crea el archivo de vacunas
      crearArchivoHistorialVacunacion(); // Crea el archivo de historial de vacunación
      break;

    case 12:
      borrarArchivoPacientes(); // Borra el archivo de pacientes
      borrarArchivoVacunas(); // Borra el archivo de vacunas
      borrarArchivoHistorialVacunacion(); // Borra el archivo de historial de vacunación
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
  mostrarMenuPrincipal(); // Inicia el programa mostrando el menú principal
  return 0;
}
