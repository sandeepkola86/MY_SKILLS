#!/bin/bash

echo "Is divya good girl(Yes/No): "
read option

case $option in
	YES |Yes |yes) echo "Yes you are Right";;

	NO |No |no) echo "No you are Wrong";;

	*) echo "Please enter either Yes or No";;

esac
