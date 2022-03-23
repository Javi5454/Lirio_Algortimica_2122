#!/bin/bash
# Compile first seleccion_mejor.cpp at folder Code with 
# g++ seleccion_mejor.cpp -o seleccion_mejor -std=gnu++0x


i="10000"

while [ $i -le 200000 ]
do
../Code/seleccion_mejor $i >> salida_seleccion_mejor.dat
i=$[$i+7600]
done
