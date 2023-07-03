#include <iostream>
using namespace std;

struct Paciente
{
  char primer_Nombre_Pa[20];
  char segundo_Nombre_Pa[20];
  char primer_Apellido_Pa[20];
  char segundo_Apellido_Pa[20];
  char documento_Paciente[15];
  int dia_Fnac_Paciente;
  int mes_Fnac_Paciente;
  int anio_Fnac_Paciente;
  char genero_Paciente;
  char correo_Paciente[20];
  char direccion_Paciente[20];
  char distrito_Paciente[20];
  char provincia_Paciente[20];
  char departamento_Paciente[20];
  char celular_Paciente[9];
  int dia_Atencion_Paciente;
  int mes_Atencion_Paciente;
  int anio_Atencion_Paciente;
};

struct Apoderado
{
  char parentesco_Apoderado[20];
  char primer_Nombre_Ap[20];
  char segundo_Nombre_Ap[20];
  char primer_Apellido_Ap[20];
  char segundo_Apellido_Ap[20];
  char documento_Ap[15];
  int dia_Fnac_Ap;
  int mes_Fnac_Ap;
  int anio_Fnac_Ap;
  char genero_Ap;
  char correo_Ap[20];
  char direccion_Ap[20];
  char distrito_Ap[20];
  char provincia_Ap[20];
  char departamento_Ap[20];
  char celular_Ap[9];
  char doc_Paciente[15];
};

void RedirigirMenuPacientes();

void MostrarMenuPacientes();

void RegistrarDatosPaciente(Paciente & pac);
void MostrarPaciente (Paciente & pac);

// * Funciones que no se van a usar pero estan en la definicion de modulos:

// ! void BuscarPaciente (Paciente pac, Apoderado apo);
// ? No se usa el apoderado en la busqueda, solo el documento asi que se usara BuscarPacientePorDocumento
// void BuscarPaciente(Paciente pac);

// void MostrarListaDeCamposPaciente();
// void ModificarPaciente(FILE * PACFILE, Paciente pac);

// int CalcularEdadPaciente(Paciente pacientes);

// void MostrarMenuApoderado();
// void RegistrarDatosApoderado(Apoderado apoderados);
// void MostrarIndiceDeCamposApoderado();
// void ModificarDatosApoderado(Apoderado apoderados);
// void MostrarApoderado(Apoderado apo);

// * Funciones necesarias que no estan en la definicion de modulos:
void crearArchivoPaciente();
void crearArchivoApoderado();
void crearRegistroPaciente();
void MostrarPacientes();
void BuscarPacientePorDocumento();

bool areArraysEqual(const char* array1, const char* array2, int size);

// VARIABLES GLOBALES
string PACFILEPATH = "paciente.txt";
string APOFILEPATH = "apoderado.txt";

// PROGRAMA PRINCIPAL
int main()
{
  RedirigirMenuPacientes();
  return 0;
}

// DEFINICION DE FUNCIONES

void MostrarMenuPacientes()
{
  cout << "Menu Paciente" << endl;
  cout << "1. Crear Archivo Paciente (también se crea el archivo Apoderado)" << endl;
  cout << "2. Registrar Paciente" << endl;
  cout << "3. Mostrar Pacientes" << endl;
  cout << "4. Buscar Paciente" << endl;
  cout << "5. Volver" << endl;
}

void crearArchivoPaciente()
{
  FILE *PACFILE = fopen(PACFILEPATH.c_str(), "w");

  if (PACFILE == NULL)
    cout << "No se puede abrir el archivo Paciente \n";
  else
  {
    cout << "Creacion exitosa del archivo Paciente \n";
    fclose(PACFILE);
  }
}

void crearArchivoApoderado()
{
  FILE *APOFILE = fopen(APOFILEPATH.c_str(), "w");
  if (APOFILE == NULL)
    cout << "No se puede abrir el archivo Apoderado \n";
  else
  {
    cout << "Creacion exitosa del archivo Apoderado\n";
    fclose(APOFILE);
  }
}

void RedirigirMenuPacientes()
{
  int opcion;
  Paciente pac;
  Apoderado apo;
  do
  {
    MostrarMenuPacientes();
    cout << "Ingrese la opcion deseada: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      crearArchivoPaciente();
      crearArchivoApoderado();
      break;
    case 2:
      crearRegistroPaciente();
      break;
    case 3:
      MostrarPacientes();
      break;
    case 4:
      BuscarPacientePorDocumento();
      break;
    case 5:
      cout << "Saliendo del menu Paciente..." << endl;
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  } while (opcion != 5);
}

void RegistrarDatosPaciente(Paciente & pac)
{
  cout << "Primer Nombre: ";
  cin >> pac.primer_Nombre_Pa;
  cout << "Segundo Nombre: ";
  cin >> pac.segundo_Nombre_Pa;
  cout << "Primer Apellido: ";
  cin >> pac.primer_Apellido_Pa;
  cout << "Segundo Apellido: ";
  cin >> pac.segundo_Apellido_Pa;
  cout << "Documento: ";
  cin >> pac.documento_Paciente;
  cout << "Dia de Nacimiento: ";
  cin >> pac.dia_Fnac_Paciente;
  cout << "Mes de Nacimiento: ";
  cin >> pac.mes_Fnac_Paciente;
  cout << "Anio de Nacimiento: ";
  cin >> pac.anio_Fnac_Paciente;
  cout << "Genero: ";
  cin >> pac.genero_Paciente;
  cout << "Correo: ";
  cin >> pac.correo_Paciente;
  cout << "Direccion: ";
  cin >> pac.direccion_Paciente;
  cout << "Distrito: ";
  cin >> pac.distrito_Paciente;
  cout << "Provincia: ";
  cin >> pac.provincia_Paciente;
  cout << "Departamento: ";
  cin >> pac.departamento_Paciente;
  cout << "Celular: ";
  cin >> pac.celular_Paciente;
  cout << "Dia de Atencion: ";
  cin >> pac.dia_Atencion_Paciente;
  cout << "Mes de Atencion: ";
  cin >> pac.mes_Atencion_Paciente;
  cout << "Anio de Atencion: ";
  cin >> pac.anio_Atencion_Paciente;
}

void crearRegistroPaciente()
{
  FILE *PACFILE = fopen(PACFILEPATH.c_str(), "a");

  if (PACFILE != NULL)
  {
    cout << "Ingreso de nuevo paciente \n";
    cout << "Digite datos del nuevo paciente \n";

    Paciente pac;
    RegistrarDatosPaciente(pac);

    fwrite(&pac, sizeof(pac), 1, PACFILE);
    if (!ferror(PACFILE))
      fclose(PACFILE);
    else
      cout << "Error de escritura en archivo Autos \n";
    fclose(PACFILE);
    printf("Registro creado exitosamente.\n");
  }
  else
  {
    printf("No se pudo abrir el archivo.\n");
  }
}

void MostrarPaciente (Paciente & pac) {
  cout << "Primer Nombre: " << pac.primer_Nombre_Pa << endl;
  cout << "Segundo Nombre: " << pac.segundo_Nombre_Pa << endl;
  cout << "Primer Apellido: " << pac.primer_Apellido_Pa << endl;
  cout << "Segundo Apellido: " << pac.segundo_Apellido_Pa << endl;
  cout << "Documento: " << pac.documento_Paciente << endl;
  cout << "Dia de Nacimiento: " << pac.dia_Fnac_Paciente << endl;
  cout << "Mes de Nacimiento: " << pac.mes_Fnac_Paciente << endl;
  cout << "Anio de Nacimiento: " << pac.anio_Fnac_Paciente << endl;
  cout << "Genero: " << pac.genero_Paciente << endl;
  cout << "Correo: " << pac.correo_Paciente << endl;
  cout << "Direccion: " << pac.direccion_Paciente << endl;
  cout << "Distrito: " << pac.distrito_Paciente << endl;
  cout << "Provincia: " << pac.provincia_Paciente << endl;
  cout << "Departamento: " << pac.departamento_Paciente << endl;
  cout << "Celular: " << pac.celular_Paciente << endl;
  cout << "Dia de Atencion: " << pac.dia_Atencion_Paciente << endl;
  cout << "Mes de Atencion: " << pac.mes_Atencion_Paciente << endl;
  cout << "Anio de Atencion: " << pac.anio_Atencion_Paciente << endl;
}

void MostrarPacientes()
{
  Paciente pac;
  int i;
  cout << "Lista de Pacientes \n";
  FILE * PACFILE = fopen(PACFILEPATH.c_str(), "r");
  if (PACFILE == NULL)
  {
    cout << "No se puede abrir el archivo pacientes \n";
    system("pause");
    exit(1);
  }
  cout << "Datos del Paciente \n";
  while (!feof(PACFILE))
  {
    fread(&pac, sizeof(pac), 1, PACFILE);
    if (ferror(PACFILE))
    {
      cout << "Error de Lectura en archivo pacientes \n";
      system("pause");
      exit(1);
    }
    if (!feof(PACFILE))
    {
      cout << "RUNING IN MostrarPaciente" << endl;
      MostrarPaciente(pac);
    }
  }
  fclose(PACFILE);
}

bool areArraysEqual(const char* array1, const char* array2, int size) {
    for (int i = 0; i < size; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
        if (array1[i] == '\0' || array2[i] == '\0') {
            break;
        }
    }
    return true;
}

void BuscarPacientePorDocumento()
{
  char documentoBuscar[15];
  cout << "Ingrese el documento del paciente a buscar: ";
  cin >> documentoBuscar;

  FILE* PACFILE = fopen(PACFILEPATH.c_str(), "r");
  if (PACFILE != NULL)
  {
    bool encontrado = false;
    Paciente pac;
    while (fread(&pac, sizeof(pac), 1, PACFILE))
    {
      cout << "TEST\n";

      cout << pac.documento_Paciente << endl;
      cout << documentoBuscar << endl;
      cout << areArraysEqual(pac.documento_Paciente, documentoBuscar, 15);
      
      cout << "TEST\n";
      if (areArraysEqual(pac.documento_Paciente, documentoBuscar, 15))
      {
        MostrarPaciente(pac);
        encontrado = true;
        break;
      }
    }

    fclose(PACFILE);

    if (!encontrado)
    {
      cout << "Paciente no encontrado." << endl;
    }
  }
  else
  {
    cout << "No se pudo abrir el archivo." << endl;
  }
}