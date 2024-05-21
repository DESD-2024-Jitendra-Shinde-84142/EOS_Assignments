#!/bin/bash

echo -n "Enter the num1 : "
read num1

echo -n "Enter the num2 : "
read num2

echo -n "Enter the num3 : "
read num3

if [ $num1 -gt $num2 ]
then
	echo "The first number is greater $num1."
elif [ $num2 -lt $num3 ]
then
	echo "The Third number is greater $num3 ."
else
	echo "The second number is greater $num2 ."
fi
