#!/bin/bash


i="100"

while [ $i -le 2000 ]
do
../Code/secuencial_vectores $i 25 >> secuencial_vectores.dat
i=$[$i+76]
done
