
#!/bin/bash
# Compile first quicksort.cpp at folder Code with 
# g++ quicksort.cpp -o quicksort -std=gnu++0x


i="100000"

while [ $i -le 2000000 ]
do
../Code/quicksort $i >> salida_quicksort.dat
i=$[$i+76000]
done
