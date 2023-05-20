#!/bin/bash

echo -n "Enter a Character: "
read char

case $char in
	a|A) echo "You entered $char which is vowel";;

	e|E) echo "You entered $char which is vowel";;

	i|I) echo "You entered $char which is vowel";;

	o|O) echo "You entered $char which is vowel";;

	u|U) echo "You entered $char which is vowel";;

	*) echo "You entered $char which is not vowel";;

esac




