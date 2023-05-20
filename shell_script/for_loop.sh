#!/bin/bash

cnt=0

for i in 1 2 3 4 5 6
do
	echo "loop count is $cnt"
	cnt=$((cnt + 1))
done
