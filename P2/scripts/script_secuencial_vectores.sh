#!/bin/bash


i="10"

while [ $i -le 4000 ]
do
../Code/secuencial_vectores $i 50 ../Code/test_files/prueba_vectores$i.txt >> ../Code/test_files/tiempo_vectores_secuencial$i.txt
i=$[$i+160]
done
