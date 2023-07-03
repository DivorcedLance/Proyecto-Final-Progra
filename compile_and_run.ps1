$command = "g++ -c main.cpp vacunas.cpp pacientes.cpp ; g++ main.o vacunas.o pacientes.o -o programa ; .\programa.exe"
Invoke-Expression -Command $command
