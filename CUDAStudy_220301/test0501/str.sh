#!/bin/bash

str=asb12345346345634524hello

echo $str
echo "${str#*asb}"
echo "${str#asb*}"
echo "${str%*asb}"
echo "${str%*bsa}"
echo "${str%%*bsa}"
echo "${str%%*asb}"

echo "${str##*4}"

echo "${str%h}"


str2=hello124sfasdf
echo "======"
echo "${str2%%o*}"
echo "${str2%*o}"
echo "${str2%%*o}"
echo "${str2%%*o}"
echo "${str2#*1}"
echo "${str2%1*}"