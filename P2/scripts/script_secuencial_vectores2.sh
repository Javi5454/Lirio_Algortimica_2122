#!/bin/bash


i="100"

while [ $i -le 2000 ]
do
../Code/secuencial_vectores2 30 $i >> secuencial_vectores2.dat
i=$[$i+76]
done
