#!/bin/bash


echo -n "Enter the path : "
read path

echo "Last modification of file :"
stat $path
