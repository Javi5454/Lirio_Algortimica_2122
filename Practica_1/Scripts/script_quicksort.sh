
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ quicksort.cpp -o quicksort -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/quicksort $i >> salida_quicksort.dat
i=$[$i+7600]
done
