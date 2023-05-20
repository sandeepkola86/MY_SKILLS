#!/bin/bash
echo -n "Enter a String1: "
read str1

echo -n "Enter a String2: "
read str2

if [ -z "${str1}" ];then
	echo "string1 is Empty"
else
	echo "String1 is not Empty"
fi

echo ":$str:"

if [ -n "${str2}" ]
then
	echo "String2 is not Empty"
else
	echo "String2 is Empty"
fi
