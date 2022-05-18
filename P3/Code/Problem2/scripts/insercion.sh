#!/bin/bash


i="1"

while [ $i -le 25 ]
do
../insercion_tsp ../Datasets/Many_TSP/$i.tsp >> insercion.dat 
i=$[$i+1]
done
