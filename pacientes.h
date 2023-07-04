#ifndef PACIENTES_H
#define PACIENTES_H

using namespace std;

// Declarar los prototipos de las funciones relacionadas con los pacientes

bool pacienteExiste(const char * pacienteID);
const char * crearPaciente();
const char * buscarPaciente();

void leerPaciente(const char * pacienteID);
void registrarVacunacion(const char * pacienteID);
void leerHistorialPaciente(const char * pacienteID);
void actualizarPaciente(const char * pacienteID);
void eliminarPaciente(const char * pacienteID);

void leerPacientes();

void crearArchivoPacientes();
void borrarArchivoPacientes();

void generarDatosPacientes();

#endif