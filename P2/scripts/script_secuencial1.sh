#!/bin/bash


i="1000000"

while [ $i -le 20000000 ]
do
../Code/secuencial $i 100 >> secuencial_ejej1.dat
i=$[$i+760000]
done
