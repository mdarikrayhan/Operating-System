echo "Enter a number:"
read n
if [ $n == 0 ]
then
    echo "$n is not even or odd."
elif [ $(($n % 2)) == 0 ]
then
    echo "$n is even."
else
    echo "$n is Odd."
fi