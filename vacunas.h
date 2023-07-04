#ifndef VACUNAS_H
#define VACUNAS_H

// Declarar los prototipos de las funciones relacionadas con las vacunas

bool vacunaExiste(const char * vacunaID);

void crearVacuna();
const char* mostrarVacunas();


void crearArchivoVacunas();
void borrarArchivoVacunas();

#endif
