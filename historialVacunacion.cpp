#include "historialVacunacion.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string HISTORIAL_VACUNACION_PATH = "historialVacunacion.dat";

class HistorialVacunacion
{
private:
  char ID[10];
  char IDVacuna[10];
  char IDPaciente[10];
  char FechaVacunacion[20];
  int Dosis;
  char FechaSiguienteVacuna[20];

public:
  HistorialVacunacion(const char *_ID = "", const char *_IDVacuna = "", const char *_IDPaciente = "", const char *_FechaVacunacion = "", int _Dosis = 0, const char *_FechaSiguienteVacuna = "")
  {
    strncpy(ID, _ID, 10);
    strncpy(IDVacuna, _IDVacuna, 10);
    strncpy(IDPaciente, _IDPaciente, 10);
    strncpy(FechaVacunacion, _FechaVacunacion, 20);
    Dosis = _Dosis;
    strncpy(FechaSiguienteVacuna, _FechaSiguienteVacuna, 20);
  }

  // Sobrecarga del operador de inserción (<<) para imprimir objetos de la clase
  friend ostream &operator<<(ostream &os, const HistorialVacunacion &historial)
  {
    os.write(historial.ID, 10);
    os.write(historial.IDVacuna, 10);
    os.write(historial.IDPaciente, 10);
    os.write(historial.FechaVacunacion, 20);
    os.write(reinterpret_cast<const char *>(&historial.Dosis), sizeof(int));
    os.write(historial.FechaSiguienteVacuna, 20);
    return os;
  }

  // Sobrecarga del operador de extracción (>>) para leer objetos de la clase desde el flujo de entrada
  friend istream &operator>>(istream &is, HistorialVacunacion &historial)
  {
    is.read(historial.ID, 10);
    is.read(historial.IDVacuna, 10);
    is.read(historial.IDPaciente, 10);
    is.read(historial.FechaVacunacion, 20);
    is.read(reinterpret_cast<char *>(&historial.Dosis), sizeof(int));
    is.read(historial.FechaSiguienteVacuna, 20);
    return is;
  }

  // Getters y Setters de la clase
  void setID(const char *_ID)
  {
    strncpy(ID, _ID, 10);
  }

  const char *getID() const
  {
    return ID;
  }

  void setIDVacuna(const char *_IDVacuna)
  {
    strncpy(IDVacuna, _IDVacuna, 10);
  }

  const char *getIDVacuna() const
  {
    return IDVacuna;
  }

  void setIDPaciente(const char *_IDPaciente)
  {
    strncpy(IDPaciente, _IDPaciente, 10);
  }

  const char *getIDPaciente() const
  {
    return IDPaciente;
  }

  void setFechaVacunacion(const char *_FechaVacunacion)
  {
    strncpy(FechaVacunacion, _FechaVacunacion, 20);
  }

  const char *getFechaVacunacion() const
  {
    return FechaVacunacion;
  }

  void setDosis(int _Dosis)
  {
    Dosis = _Dosis;
  }

  int getDosis() const
  {
    return Dosis;
  }

  void setFechaSiguienteVacuna(const char *_FechaSiguienteVacuna)
  {
    strncpy(FechaSiguienteVacuna, _FechaSiguienteVacuna, 20);
  }

  const char *getFechaSiguienteVacuna() const
  {
    return FechaSiguienteVacuna;
  }

  void imprimir() const
  {
    cout << "ID: " << ID << endl;
    cout << "ID Vacuna: " << IDVacuna << endl;
    cout << "ID Paciente: " << IDPaciente << endl;
    cout << "Fecha de Vacunación: " << FechaVacunacion << endl;
    cout << "Dosis: " << Dosis << endl;
    cout << "Fecha de Siguiente Vacuna: " << FechaSiguienteVacuna << endl;
  }
};

// Lee los historiales de vacunaciones desde un archivo
void leerHistorialesVacunaciones()
{
  system("cls");

  ifstream archivo(HISTORIAL_VACUNACION_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo." << endl;
    return;
  }

  HistorialVacunacion historial;
  while (archivo >> historial)
  {
    historial.imprimir();
    cout << endl;
  }

  archivo.close();
  getch();
}

// Crea un nuevo historial de vacunación con el paciente y vacuna dados. Establece las fechas y dosis automáticamente. 
void crearHistorialVacunacion(const char *pacienteID, const char *vacunaID)
{
  system("cls");

  char ID[10];
  snprintf(ID, sizeof(ID), "%ld", time(nullptr));  // Generar un ID único basado en la hora actual

  // Obtener la fecha actual (puedes adaptar esta lógica según tus necesidades)
  time_t now = time(nullptr);
  tm *fechaActual = localtime(&now);
  char fechaVacunacion[20];
  strftime(fechaVacunacion, 20, "%d/%m/%Y", fechaActual);

  // Verificar si el paciente ya tiene un historial con la misma vacuna
  ifstream archivo(HISTORIAL_VACUNACION_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo abrir el archivo de historiales." << endl;
    return;
  }

  HistorialVacunacion historial;
  bool encontrado = false;
  while (archivo >> historial)
  {
    if (strcmp(historial.getIDPaciente(), pacienteID) == 0 && strcmp(historial.getIDVacuna(), vacunaID) == 0)
    {
      encontrado = true;
      break;
    }
  }

  archivo.close();

  // Asignar la dosis según corresponda
  int dosis;
  if (encontrado)
  {
    dosis = historial.getDosis() + 1;
  }
  else
  {
    dosis = 1;
  }

  // Calcular la fecha de siguiente vacuna (fecha actual + 21 días)
  time_t fechaSiguienteVacunaTimestamp = now + 21 * 24 * 60 * 60; // 21 días en segundos
  tm *fechaSiguienteVacunaStruct = localtime(&fechaSiguienteVacunaTimestamp);
  char fechaSiguienteVacuna[20];
  strftime(fechaSiguienteVacuna, 20, "%d/%m/%Y", fechaSiguienteVacunaStruct);

  // Crear el objeto HistorialVacunacion
  HistorialVacunacion nuevoHistorial;
  char historialIDStr[10];
  snprintf(historialIDStr, 10, "%d", ID);
  nuevoHistorial.setID(historialIDStr);
  nuevoHistorial.setIDVacuna(vacunaID);
  nuevoHistorial.setIDPaciente(pacienteID);
  nuevoHistorial.setFechaVacunacion(fechaVacunacion);
  nuevoHistorial.setDosis(dosis);
  nuevoHistorial.setFechaSiguienteVacuna(fechaSiguienteVacuna); // Puedes asignar la fecha siguiente según tus necesidades

  // Guardar el nuevo historial en el archivo
  ofstream archivoHistorial(HISTORIAL_VACUNACION_PATH.c_str(), ios::binary | ios::app);
  if (!archivoHistorial)
  {
    cout << "No se pudo abrir el archivo de historiales." << endl;
    return;
  }

  archivoHistorial << nuevoHistorial;
  archivoHistorial.close();

  cout << "Historial de vacunación creado exitosamente." << endl;
}

// Función para leer el historial de vacunación de un paciente específico
void leerHistorialVacunacionPaciente(const char *pacienteID)
{
  system("cls");

  ifstream archivo(HISTORIAL_VACUNACION_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    crearArchivoHistorialVacunacion();
  }

  HistorialVacunacion historial;
  bool encontrado = false;

  while (archivo >> historial)
  {
    if (strcmp(historial.getIDPaciente(), pacienteID) == 0)
    {
      historial.imprimir();
      cout << endl;
      encontrado = true;
    }
  }

  archivo.close();

  if (!encontrado)
  {
    cout << "El paciente con ID " << pacienteID << " no tiene historial de vacunación" << endl;
  }

  getch();
}

void crearArchivoHistorialVacunacion()
{
  ofstream archivo(HISTORIAL_VACUNACION_PATH.c_str(), ios::binary);
  if (!archivo)
  {
    cout << "No se pudo crear el archivo historialVacunacion.dat." << endl;
    return;
  }

  archivo.close();

  cout << "Archivo historialVacunacion.dat creado exitosamente." << endl;
}

void borrarArchivoHistorialVacunacion()
{
  if (remove(HISTORIAL_VACUNACION_PATH.c_str()) == 0)
  {
    cout << "Archivo historialVacunacion.dat eliminado exitosamente." << endl;
  }
  else
  {
    cout << "No se pudo eliminar el archivo historialVacunacion.dat." << endl;
  }
}