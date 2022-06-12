#!/bin/bash

if test $# -ne 1
then
    echo "input error"
fi

if test -e $1 && test -f $1 
then
    echo "hello" >> $1
    echo "success"
else
    echo "error"
fi