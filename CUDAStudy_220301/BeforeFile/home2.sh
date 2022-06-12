#!/bin/bash

echo "input num1"
read str1
echo "input type"
read c
echo "input num2"
read str2

case $c in
+)
    echo "$str1 + $str2 = `expr $str1 + $str2`";;
-)
    echo "$str1 - $str2 = `expr $str1 - $str2`";;
\*)
    echo "$str1 * $str2 = `expr $str1 \* $str2`";;
/)
    echo "$str1 / $str2 = `expr $str1 / $str2`";;
esac