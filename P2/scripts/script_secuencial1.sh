
#!/bin/bash


i="10"

while [ $i -le 10000 ]
do
../Code/secuencial $i ../Code/test_files/prueba$i.txt >> secuencial$i.txt
i=$[$i+400]
done
