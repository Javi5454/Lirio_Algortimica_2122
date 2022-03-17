
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ seleccion.cpp -o seleccion-std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/seleccion $i >> salida_seleccion.dat
i=$[$i+7600]
done