#!/bin/bash


i="1000000"

while [ $i -le 20000000 ]
do
../Code/binaria $i >> binaria.dat
i=$[$i+760000]
done
