#!/bin/bash


echo -n "Enter the number : "
read num
temp=0
te=`expr $num \/ 2`
for i in `seq 2 $te`
do
	temp=`expr $num \% $i`
	if [ $temp -eq 0 ]
	then
		echo "This is not a prime number"
		exit 0
	fi
	i=`expr $i + 1`
done
echo " This is a prime number $num"
