#!/bin/bash


i="10"

while [ $i -le 110 ]
do
../Code/genera-vectores 2000 $i >> ../Code/test_files/prueba_vectores_nfijo_$i.txt
i=$[$i+4]
done
