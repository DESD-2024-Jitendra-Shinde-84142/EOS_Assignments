#!/bin/bash

echo "Enter the file path : "
read path

if [ -e $path ]
then
	if [ -f $path ]
	then
		echo "The path is of regular type"
		cat $path
	elif [ -d $path ]
	then
		echo "This path is of Directory"
	    ls $path
	else
		echo "The path is of something else"
	fi
else
	echo "Entered path is not valid!!"
fi

