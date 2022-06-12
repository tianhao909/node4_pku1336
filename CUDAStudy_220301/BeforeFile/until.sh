#!/bin/bash

declare -i n=1

until test $n -gt 100
do
    echo "n=$n"
    
    sum=`expr $sum + $n`
    echo "sum=$sum"
    n=$n+1
done
echo $sum