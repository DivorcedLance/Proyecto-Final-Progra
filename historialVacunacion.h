#ifndef HISTORIALVACUNACION_H
#define HISTORIALVACUNACION_H

// Declarar los prototipos de las funciones relacionadas con el historial de vacunación

void leerHistorialesVacunaciones();

void crearHistorialVacunacion(const char * pacienteID, const char * vacunaID);
void leerHistorialVacunacionPaciente(const char * pacienteID);

void crearArchivoHistorialVacunacion();
void borrarArchivoHistorialVacunacion();

#endif
