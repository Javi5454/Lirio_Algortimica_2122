#!/bin/bash


i="1"

while [ $i -le 24 ]
do
python ../cercania.py ../Datasets/$i.tsp >> cercania.dat 
i=$[$i+1]
done
