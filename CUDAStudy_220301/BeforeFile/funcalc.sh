#!/bin/bash

add() {
    num1=$1
    num2=$2
    echo "$num1 + $num2 = `expr $num1 + $num2`"

}

sub(){
    num1=$1
    num2=$2
    echo "$num1 - $num2 = `expr $num1 - $num2`"
}

mul(){
    num1=$1
    num2=$2
    echo "$num1 * $num2 = `expr $num1 \* $num2`"
}

div(){
    num1=$1
    num2=$2
    echo "$num1 / $num2 = `expr $num1 / $num2`"
}




echo "input num1"
read str1
echo "input type"
read c
echo "input num2"
read str2

case $c in
+)
    add $str1 $str2;;
    #echo "$str1 + $str2 = `expr $str1 + $str2`";;
-)
    sub $str1 $str2;;
    #echo "$str1 - $str2 = `expr $str1 - $str2`";;
\*)
    mul $str1 $str2;;
    #echo "$str1 * $str2 = `expr $str1 \* $str2`";;
/)
    div $str1 $str2;;
    #echo "$str1 / $str2 = `expr $str1 / $str2`";;
esac