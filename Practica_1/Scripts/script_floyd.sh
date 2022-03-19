
#!/bin/bash
# Compile first floyd.cpp at folder Code with 
# g++ floyd.cpp -o floyd -std=gnu++0x


i="100"

while [ $i -le 2000 ]
do
../Code/floyd $i >> salida_floyd.dat
i=$[$i+76]
done
