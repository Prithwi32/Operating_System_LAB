# a) Write a shell program to find the largest of three numbers

# #!/bin/bash
# echo "Enter three Numbers:"
# read n1 n2 n3
# echo "Entered numbers are: $n1 $n2 $n3"
# if [[ $n1 -gt $n2 ]]
# then
# if [[ $n1 -gt $n3 ]]
# then
# echo "$n1 is greatest among 3 numbers"
# fi
# fi
# if [[ $n2 -gt $n3 ]]
# then
# if [[ $n2 -gt $n1 ]]
# then
# echo "$n2 is greatest among 3 numbers"
# fi
# fi
# if [[ $n3 -gt $n1 ]]
# then
# if [[ $n3 -gt $n2 ]]
# then
# echo "$n3 is greatest among 3 numbers"
# fi
# fi

#!/bin/bash
echo "Enter 3 numbers: "
read n1
read n2
read n3

if [[ $n1 > $n2 ]]
then
largest=$n1
else
largest=$n2
fi

if [[ $n3 > $largest ]]
then
largest=$n3
fi

echo "Largest number is: $largest"
