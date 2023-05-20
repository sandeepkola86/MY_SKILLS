#!bin/bash

# Element 0   1   2    3   4   5
echo ${array[0]}       #  zero
echo ${array:0}        #  zero, Parameter expansion of first element,+ starting at position # 0 (1st character).
echo ${array:1}        #  ero, Parameter expansion of first element, + starting at position # 1 (2nd character).
echo "--------------"
echo ${#array[0]}      #  4, Length of first element of array.
echo ${#array}         #  4, Length of first element of array. (Alternate notation)
echo ${#array[1]}      #  3, Length of second element of array. Arrays in Bash have zero-based indexing.
echo ${#array[*]}      #  6, Number of elements in array.
echo ${#array[@]}      #  6, Number of elements in array.
echo "--------------"

# Quoting permits embedding whitespace within individual array elements.
array2=([0]="first element" [1]="second element" [3]="fourth element")

echo "The ${array2[0]}"   # first element
echo "The ${array2[1]}"   # second element
echo "The ${array2[2]}"   # Skipped in initialization, and therefore null.
echo "The ${array2[3]}"   # fourth element
echo "The lenght of ${array2[0]} ${#array2[0]}" 	   # 13 (length of first element)
echo "The number of elements in the array ${#array2[*]}"  # 3  (number of elements in array)
