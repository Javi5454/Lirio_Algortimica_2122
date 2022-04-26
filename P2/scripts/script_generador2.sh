#!/bin/bash


i="10"

while [ $i -le 4000 ]
do
../Code/genera-vectores $i 50 >> ../Code/test_files/prueba_vectores$i.txt
i=$[$i+160]
done
