#!/bin/bash

echo -n "Enter a Number: "
read Num

let Sum=0;

for I in `seq $Num`
do
	Sum=`expr $Sum + $I`
	I=$((${I} + 1))
done

echo "Sum of first $Num numbers is $Sum"

