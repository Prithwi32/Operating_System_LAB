#QUESTION : Write a shell program to generate prime numbers in a given range
#!/bin/bash
echo "Enter lower bound: "
read n1
echo "Enter upper bound: "
read n2
for (( i=n1; i<=n2; i++ ))
do
   for(( j=2; j<=$i/2; j++ ))
   do
   if [[ $((i%j)) == 0 ]]
   then
   flag=1
   break;
   fi
   done

   if [[ $flag == 0 && $i -gt 1 ]]
   then
   echo -ne "$i "
   fi

   flag=0;
done