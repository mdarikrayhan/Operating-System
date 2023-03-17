echo "Enter nth number's value:"
read digit
t=1
total=0
while test $t -le $digit
do
        total=$(($total + $t))
        t=$(($t + 1))
done
echo "SUM of number from 1 to $digit: $total "