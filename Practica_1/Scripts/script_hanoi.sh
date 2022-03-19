
#!/bin/bash
# Compile first hanoi.cpp at folder Code with 
# g++ hanoi.cpp -o hanoi -std=gnu++0x


i="7"

while [ $i -le 31 ]
do
../Code/hanoi $i >> salida_hanoi.dat
i=$[$i+1]
done
