#!/bin/bash

echo -n "Enter the number : "
read num

if [ $num -lt 0 ]
then
	echo "The given number is Negative."
else
	echo "The given number is Positive."
fi

