echo "Enter Number :"
read n
if [ $n == 0 ]
then
    echo "$n is not prime or composite"
    exit 0
fi
if [ $n == 1 ]
then
    echo "$n is not prime or composite"
    exit 0
fi
for((i=2; i<=$n/2; i++))
do
  ans=$(( n%i ))
  if [ $ans == 0 ]
  then
    echo "$n is not a prime number."
    exit 0
  fi
done
echo "$n is a prime number."