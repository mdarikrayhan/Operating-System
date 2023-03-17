echo "Enter a number : "
read a
echo "Enter another number : "
read b
echo "What do you want to do : "
echo "1. Addition "
echo "2. Subtraction "
echo "3. Multiplication "
echo "4. Division "

read choice
if [ $choice == 1 ]
then
    echo "Addition of $a and $b is : " $(($a+$b))
    exit 0
fi

if [ $choice == 2 ]
then
    echo "Subtraction of $a and $b is : " $(($a-$b))
    exit 0
fi

if [ $choice == 3 ]
then
    echo "Multiplication of $a and $b is : " $(($a*$b))
    exit 0
fi
    
if [ $b == 0 ]
then
    echo "Division of $a and $b is : " "Infinite"
    exit 0
else
    echo "Division of $a and $b is : " 
    echo "scale=2 ; $a / $b" | bc
    exit 0
fi