
#!/bin/bash


i="1000000"

while [ $i -le 20000000 ]
do
../Code/genera-posicion $i >> ../Code/test_files/prueba$i.txt
i=$[$i+760000]
done
