#!/bin/bash

declare -i n=1
for data in $*
do 
echo "argv[$n]:$data"
n=$n+1
done