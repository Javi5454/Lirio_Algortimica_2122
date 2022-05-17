#!/bin/bash


i="1"

while [ $i -le 24 ]
do
python ../perturbaciones.py ../Datasets/Many_TSP/$i.tsp 10 >> perturbaciones.dat 
i=$[$i+1]
done
