
#!/bin/bash
# Compile first insercion_peor.cpp at folder Code with 
# g++ insercion_peor.cpp -o insercion_peor -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/insercion_peor $i >> salida_insercion_peor.dat
i=$[$i+7600]
done