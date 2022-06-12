#!/bin/bash

for str in `ls`
do 
    if test -e $str && test -x $str
    then 
        echo $str
    elif test -e $str
    then
        echo "error"
    fi
done