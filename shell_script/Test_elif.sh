#!/bin/bash

echo -n "Enter a Number: "
read Num

if [ $Num -gt 0 ]
then
	echo "The +ve value is $Num"
elif [ $Num -lt 0 ]
then
	echo "The -ve value is $Num"
else
	echo "The value $Num"
fi 

