#!/bin/bash


i="10"

while [ $i -le 10000 ]
do
../Code/genera-vectores $i 50 >> ../Code/test_files/prueba_vectores$i.txt
i=$[$i+400]
done