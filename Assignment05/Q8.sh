#!/bin/bash


echo -n "Enter the Number : "
read num
tt=0
#for i in `seq 1 10`
i=1
while [ $i -lt 11 ]
do
	echo `expr $i \* $num`
	i=`expr $i + 1`
done
