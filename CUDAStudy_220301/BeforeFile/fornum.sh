#!/bin/bash

for i in `seq 1 100`
do 
sum=`expr $sum + $i`
done
echo $sum