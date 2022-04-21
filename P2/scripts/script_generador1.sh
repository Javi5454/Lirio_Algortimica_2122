
#!/bin/bash


i="10"

while [ $i -le 10000 ]
do
../Code/genera-posicion $i >> ../Code/test_files/prueba$i.txt
i=$[$i+400]
done
