#QUESTION:  Write a shell program to check whether a given number is palindrome or not
#!/bin/bash
echo "Enter string/number to check palindrome: "
read str
len=${#str}

for(( i=$len-1; i>=0; i-- ))
do
reverse="$reverse${str:i:1}"
done

if [ "$reverse" -eq "$str" ]
then
echo "It is a palindrome"
else
echo "It is not a palindrome"
fi