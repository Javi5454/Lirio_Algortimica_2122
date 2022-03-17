
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ insercion.cpp -o insercion -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/insercion $i >> salida_insercion.dat
i=$[$i+7600]
done