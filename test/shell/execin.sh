#!/bin/bash

exec 8<&0

exec < hfile
read a
read b
echo "-----------------"
echo $a
echo $b
exec 0<&8 8<&-

exec 8>&1

exec > logg

echo "output of date command"
date

exec 1>&8 8>&-
echo "------------------"
date

i=0
while :
do
    if (( i >= 10 ))
    then
        break
    fi
    echo $((++i))
done

( grep -r "root" ./* | sort > part1 ) &
( grep -r "root" ../awk/ | sort > part2 ) &

wait

echo -e "Finished\n"

trap "echo 'You hit the Ctrl-C'" INT

# sleep 10

echo "End of shell script"

hello(){
    echo "Hello World!"
}

hello

output1(){
    for(( num = 1; num <= 6; num ++ ))
    do
        echo "output1-->${num}"
    done
}

output1

let "num2=1"

while [ ${num2}  -le 6 ]
do
    output1
    echo ""
    let "num2=num2+1"
done

filenum=0
dirnum=0

for file in $( ls )
do
    if [ -d ${file} ]
    then
        let "dirnum=dirnum+1"
    else
        let "filenum=filenum+1"
    fi


done

echo "Current file nums: ${filenum}"
echo "Current dir nums: ${dirnum}"

echo -e "\n\nFactorial"

fact(){
    local num=$1

    if [ ${num} -le 0 ]
    then
        factorial=1
    else    
        let "decnum=num-1"
        fact ${decnum}

        let "factorial=${num} * $?"
    fi
    return ${factorial}

}

fact 6
echo "Factorial 6 is : ${factorial}"

fact 5
echo "Factorial 5 is : ${factorial}"

array[0]=1
array[1]=2
array[2]=3

echo "${array[*]}"

echo "${array[@]}"

for i in ${array[*]}
do
    echo ${i} '-'
done

City=(Nanjing Atlanta Massachusetts Marseilles)

echo "City:" ${City[*]}
