#!/bin/bash

echo -n "Menu : "

echo -e "1.Date\n2.Cal\n3.list_Contents\n4.pwd\n5.Exit"

echo -n "Enter your choice : "
read choice
i=$choice
case $choice in
1)
	echo "Todays date : "
	date
	;;
2)
	echo "Calender : "
	cal
	;;
3)
	echo "List Contentets : "
	ls
	;;
4)
	echo "Present Working Directory : "
	pwd
	;;
5)
	echo "bye.."
	;;
*)
	echo "Invalid Operation!!"
	;;
esac
