
#!/bin/bash
# Compile first floyd.cpp at folder Code with 
# g++ floyd.cpp -o floyd -std=gnu++0x


i="6000"

while [ $i -le 150000 ]
do
../Code/floyd $i >> salida_floyd.dat
i=$[$i+6000]
done
