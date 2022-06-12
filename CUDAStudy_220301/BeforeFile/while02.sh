#!/bin/bash
declare -i n=1
declare -i multiply=1
#while test $n -le 11
while test $n -le 10
do
#$multiply=$multiply\*n
multiply=$multiply\*n
n=$n+1
done
echo "$n"
echo "$multiply"