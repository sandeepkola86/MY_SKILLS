#!/bin/bash

echo -n "Enter string1: "
read Str1

echo -n "Enter String2: "
read Str2

if [ ${Str1} = ${Str2} ] then
	echo "Both Strings are same"
else
	echo "Both Strings are not same"
fi
