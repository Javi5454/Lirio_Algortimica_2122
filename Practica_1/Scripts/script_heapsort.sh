
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ heapsort.cpp -o heapsort -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/heapsort $i >> salida_heapsort.dat
i=$[$i+7600]
done
