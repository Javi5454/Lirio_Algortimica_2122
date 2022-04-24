
#!/bin/bash


i="1000000"

while [ $i -le 20000000 ]
do
../Code/secuencial $i ../Code/test_files/prueba$i.txt >> secuencial_ejej1.dat
i=$[$i+760000]
done
