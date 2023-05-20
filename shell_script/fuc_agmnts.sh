#!/bin/bash

# Function definition
function find_sum()
{
    SUM=`expr $1 + $2`
    echo Sum is $SUM
}

# Pass arguments 10 and 20 to find_sum function
find_sum 10 20

# Save the output of function in a variable
RESULT=`find_sum 100 200`
echo $RESULT
