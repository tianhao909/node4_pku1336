#!/bin/bash

if test $# -ne 1
then 
    echo "error"
fi

filename=$1

echo "#include<stdio.h>">$filename
echo " ">>$filename
echo "int main(int argc, char **argv){">>$filename
echo "    printf(\"helloworld\");">>$filename
echo "    return 0;">>$filename
echo "}">>$filename
gedit $filename