$command = "g++ -c main.cpp pacientes.cpp vacunas.cpp historialVacunacion.cpp; g++ main.o pacientes.o vacunas.o historialVacunacion.o -o programa ; .\programa.exe"
Invoke-Expression -Command $command
