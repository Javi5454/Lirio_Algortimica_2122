#!/bin/bash


i="1"

while [ $i -le 25 ]
do
python ../cercania.py ../Datasets/Many_TSP/$i.tsp >> cercania.dat 
i=$[$i+1]
done
