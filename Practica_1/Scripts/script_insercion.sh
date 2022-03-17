
#!/bin/bash

echo "" > salida_insercion.dat

i="1000"

while [ $i -le 5000 ]
do
../insercion $i > salida_insercion.dat
i=$[$i+4000]
done