#!/bin/bash


i="1000000"

while [ $i -le 20000000 ]
do
../Code/binaria_repes $i >> binaria_repes.dat
i=$[$i+760000]
done
