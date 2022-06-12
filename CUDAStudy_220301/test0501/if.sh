#!/bin/bash

if test $# -ne 2
then 
    echo "error"
else 
    echo "good"
fi

if [ $# -eq 2   ]
then 
    echo "good"
else
    echo "error"
fi