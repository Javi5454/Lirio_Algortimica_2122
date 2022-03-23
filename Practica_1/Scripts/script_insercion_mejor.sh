
#!/bin/bash
# Compile first insercion_mejor.cpp at folder Code with 
# g++ insercion_mejor.cpp -o insercion_mejor -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/insercion_mejor $i >> salida_insercion_mejor.dat
i=$[$i+7600]
done