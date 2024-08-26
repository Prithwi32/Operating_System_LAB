#QUESTION : a) Write a shell program to Read two matrices , find addition and display the input matrices and resultant in matrix format
#!/bin/bash
declare -A x
declare -A y
declare -A z
echo "Enter order of matrix (m*n) :"
read m n
echo "Enter first $m*$n matrix elements: "
for(( i=0; i<$m; i++ ))
do
for(( j=0; j<$n; j++ ))
do
read x[$i,$j]
done
done
echo
echo "Enter second $m*$n matrix elements: "
for(( i=0; i<$m; i++ ))
do
for(( j=0; j<$n; j++ ))
do
read y[$i,$j]
done
done
echo
echo "Entered first $m*$n matrix: "
for(( i=0; i<$m; i++ ))
do
for(( j=0; j<$n; j++ ))
do
echo -ne "${x[$i,$j]} "
done
echo
done
echo "Entered second $m*$n matrix: "
for(( i=0; i<$m; i++ ))
do
for(( j=0; j<$n; j++ ))
do
echo -ne "${y[$i,$j]} "
done
echo
done
echo "Addition of $m*$n matrices: "
for(( i=0; i<$m; i++ ))
do
for(( j=0; j<$n; j++ ))
do
z[$i,$j]=$(( x[$i,$j]+y[$i,$j] ));
echo -ne "${z[$i,$j]} "
done
echo
done
