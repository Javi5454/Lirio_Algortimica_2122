
#!/bin/bash
# Compile first seleccion_peor.cpp at folder Code with 
# g++ seleccion_peor.cpp -o seleccion_peor -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/seleccion_peor $i >> salida_seleccion_peor.dat
i=$[$i+7600]
done
