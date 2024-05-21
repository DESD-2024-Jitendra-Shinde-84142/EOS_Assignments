#!/bin/bash

echo -n "Enter the number : "
read num

fact=1
i=1
#for i in `seq 1 $num`
while [ $i -lt `expr $num + 1` ]
do
	fact=`expr $fact \* $i`
	i=`expr $i + 1`
done
echo "$fact"
