#!/bin/bash

echo -n "Enter a Number: "
read Num

SUM=0;
I=1

while [ $I -le $Num ]
do
	SUM=`expr $SUM + $I`
	I=$((${I} + 1))
done

echo "The Sum of First $Num numbers is $SUM"
		
