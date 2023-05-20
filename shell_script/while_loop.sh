#!/bin/bash

Cnt=0

while [ $Cnt -lt 5 ]
do
	echo "Loop cont is $Cnt"
	Cnt=$((Cnt+1))
done

echo "Done"
