#!/bin/bash

# Check whether a number is between 10 and 20 (Using AND -a operator)
echo -n "Enter a Number: "
read Num

if [ $Num -ge 10 -a $Num -le 20 ];then
	echo "$Num is between 10 and 20"
else
	echo "$Num is not betwen 10 and 20"
fi

echo -n "Please enter a number: "
read num

if [ $num -lt 10 -o $num -gt 20 ];then
	echo "$num is not between 10 and 20"
else
	echo "$num is between 10 and 20"
fi	
