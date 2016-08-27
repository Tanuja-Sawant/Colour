clear
gcc process.c 
par=0;

for ((i=0;i<10;i++))
do
	d=$(./a.out);

	if [ $d == 10 ]
		then
		par=$((par + 1 ))
	fi


done
echo "parent execcutes first: "
echo $par