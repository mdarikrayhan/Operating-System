echo "Enter first number : "
read a
echo "Enter second number : "
read b
echo "a before swapping is $a and b is $b"
a=$((a+b))
b=$((a - b))
a=$((a-b))
echo "a after swapping is  $a and b is $b"