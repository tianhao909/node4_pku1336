#!/bin/bash

fun()
{
    echo "hello"
}

#trap fun INT
trap fun 2
n=0
while test $n -eq 0
do 
    n=0
done