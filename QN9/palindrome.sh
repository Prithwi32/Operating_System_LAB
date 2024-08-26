#!/bin/bash
echo "Enter a number to check Palindrome"
read num1

length=${#num1}

for (( i=$length-1; i>=0; i-- ))
do
num2="$num2${num1:i:1}"
done

if [ $num1 -eq $num2 ]
then
echo "$num1, Given Number is Palindrome"
else
echo "Number is not a Palindrome"
fi

