#!/bin/bash

cnt=1

echo -n "Please Enter a Number: "
read num

for((i = 1; i <= $num; i++))
do
	echo "Loop count is $cnt"
	cnt=$((cnt + 1))
done
