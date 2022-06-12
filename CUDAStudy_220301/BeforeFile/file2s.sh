#!/bin/bash

if test $1 \< $2 
then
    echo "$1 < $2"
elif test $1 \> $2
then
    echo "$1 > $2"
else 
    echo "$1 = $2"
fi