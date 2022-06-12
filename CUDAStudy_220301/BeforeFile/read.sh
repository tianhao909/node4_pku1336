#!/bin/bash

echo "please input a num"
read str
echo $str

read -p "please input a num" s
echo $s

sums=`expr $str + $s`
echo $sums

sums2=`$str + $s`
echo $sums2
