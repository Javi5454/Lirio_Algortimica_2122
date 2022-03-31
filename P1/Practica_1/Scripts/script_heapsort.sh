
#!/bin/bash
# Compile first insercion.cpp at folder Code with 
# g++ heapsort.cpp -o heapsort -std=gnu++0x


i="100000"

while [ $i -le 2000000 ]
do
../Code/heapsort $i >> salida_heapsort.dat
i=$[$i+76000]
done
