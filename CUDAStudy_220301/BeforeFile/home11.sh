#!/bin/bash

declare -i num
declare -i a

num=$(($RANDOM%100+0))
read -p "input num:" a
echo "num = $num"
while test $num -ne $a
do
    if test $num -gt $a
    then 
        echo "num > $a"
    elif test $num -lt $a
    then
        echo "num < $a"
    else 
        echo "num = $a"
    fi
    
    read -p "input num:" a
done