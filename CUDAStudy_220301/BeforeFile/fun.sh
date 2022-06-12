#!/bin/bash
# from top to bottom
fun() 
{
    echo $*
    echo $#
    for a in $*
    do 
        echo $a
    done
    return 5
}

fun hello world apple
echo "return value=$?"
