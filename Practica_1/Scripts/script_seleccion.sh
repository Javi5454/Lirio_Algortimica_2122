
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ seleccion.cpp -o seleccion-std=gnu++0x


i="1000"

while [ $i -le 50000 ]
do
../Code/seleccion $i >> salida_seleccion.dat
i=$[$i+1000]
done