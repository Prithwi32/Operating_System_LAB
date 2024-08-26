#QUESTION : a) Write a shell program to find largest of n numbers, storing numbers in an array.

#!/bin/bash
echo "Enter numbers of elements: "
read n
declare -A arr
echo "Enter array elements: "
for (( i=0; i<n; i++ ))
do
read arr["$i"]
done

max=${arr[$i]}

for (( i=1; i<n; i++ ))
do
if [[ $max < ${arr[$i]} ]]
then
max=${arr[$i]}
fi
done

echo "Largest number is: $max"