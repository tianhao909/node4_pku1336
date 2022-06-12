#!/bin/bash

touch 3.txt
echo "hello">3.txt
echo "`ls -l`">>3.txt
cat 3.txt

str=asdfkahsdfkljhaskldfhjas
echo "${#str}"