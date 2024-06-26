#!/bin/bash
# Compilar el archivo main.cpp
echo "Compilando..."
g++ -g main.cpp ./functions/**.cpp -o main
if [ $? -ne 0 ]; then
    echo "Error en la compilación."
    exit 1
fi
# Ejecutar el archivo compilado
./main
