#!/bin/bash

variable1=2010
variable2="a  b  c"


echo ${variable1}
echo "${variable1}"

echo ${variable2}
echo "${variable2}"
echo '${variable2}'

path=$(pwd)
echo "The path is: ${path}"
data=$(date)
timeData=$( echo ${data} | awk '{ print $5 }')
echo "date is: ${data}"
echo "time is: ${timeData}"

dirlist=$(ls -l)
echo "${dirlist}"

echo "\&"

variable3=$'\044'
echo ${variable3}

num1=15
num2=45

echo "Test num1 -eq num2 "
[ ${num1} -eq ${num2} ]

echo $?

str1=hi
str2=hi1


echo "Test str1 == str2 "
[ ${str1} = ${str2} ]

echo "${str1} == ${str2}" $?

echo -e "\n\nTo test 'hi' string"

if [ ${str1} = "hi" ]
then
    echo " It is equal"
else
    echo " It is not equal"
fi

# echo "Please input a string:"
# read strInput

# if [ ${strInput} = "go" ]
# then
#     echo "Welcome"
# else    
#     echo "Not you"
# fi

casestr=21
case1=1
case21=21
case23=23
echo -e "\n\nTest case: ${casestr} "
case ${casestr} in
1)
    echo "${casestr} is 1";;
21)
    echo "${casestr} is 21";;
23)
    echo "${casestr} is 23";;
*)
    echo "Not included";;
esac

let "num0=16#F"
echo "${num0}"

echo -e "\n\nTest for"
for vari in  1 2 3 4
do
    let "temp=${vari}**2"
    echo ${temp}

done

echo -e "\n another example:"
for vari in {1..5}
do
    echo ${vari}
done

temp=0
echo -e "\nCompute 1 to 100"
for vari in {1..100}
do
    let "temp+=${vari}"
done
echo ${temp}

temp=0
echo -e "\nCompute 1 to 100, another way"
for vari in $( seq 1 1 100)
do
    let "temp+=vari"
done
echo "sum:${temp}"

for file in $(ls)
do
    echo "file: ${file}"
done


echo -e "\n\nTest arguments loop"
for argument
do
    echo ${argument}
done

echo -e "\n\nC style for loop"
for (( integer=1; integer<=5; integer++))
do
    echo ${integer}
done

for (( integer=1; integer<=3; integer++))
do  
    echo "hello world"
done

echo -e "\n\nTest while loop"
mark=4
while [ ${mark} -ge 0 ]
do  
    echo ${mark}
    let "mark-=1"
done

mark=1
while (( ${mark}  <= 5 ))
do
    echo ${mark}
    let "mark++"
done

echo -e "\nfactorial computation"
factoria=1
num=5
while [ ${num}  -gt 0 ]
do
    let "factoria=factoria*num"
    let "num--"
done

echo "factoria 5!" ${factoria}

echo "\n\nTest steps"
for (( i=1; i<=9; i++))
do
    for (( j=1; j<=i ; j++))
    do
        let "temp=${i}*${j}"
        echo -n "${i}*${j}=${temp}  "
    done
    echo -e "\n"
done

echo "\n\nprint a chess"
# for (( i=1; i<=8; i++))
# do
#     for (( j=1; j<=8; j++))
#     do
#         total=$((${i}+ ${j}))
#         tmp=$((${total}%2))

#         if [ ${tmp} -eq 0 ];
#         then
#             echo -e -n "\033[47m "
#         else
#             echo -e -n "\033[40m "
#         fi
#     done
#     echo ""
# done

echo -e "\nWhich is your favourite color?"
# select color in "red" "blue" "yellow" "white" "green"
# do  
#     break
# done

echo "You have chosed ${color}"

echo -e "\n\nRead"
# read
echo "${REPLY}"

str2=abcd
echo "${str2} length is: ${#str2}"
# expr length ${str2}
echo "${str2:2:2}"
echo "${str2:(-2)}"
exp1=$(expr ${str2} : '\([ab]*\)')
echo "exp1:" ${exp1}
echo "delete:" ${str2#ab}
echo "delete:" ${str2##ab}
echo "delete from tail:" ${str2%cd}
echo "replace:" ${str2/ab/xy}

declare -i variaInt varia3
variaInt=90
varia3=${variaInt}+1
echo "varia3 is:" "${varia3}"

(( a = 2009))
echo ${a}
(( a++ ))
echo ${a}
#declare -f

echo -e "\n\nTest indirect reference"
variable1=variable2
variable2=Hadoop

echo ${variable1}
echo ${variable2}
eval tempvar=\$$variable1
echo "variable1 is:" ${tempvar}
echo ${!variable1}


echo -e "\nTest bc"
var1=20
var3=`echo "${var1} ^ 2 " | bc`
echo "var3:${var3}"

str4="Speeding up small jobs in Hadoop"
echo ${str4} | awk '{print length($0)}'
echo ${str4} | awk '{print substr($0,1,9)}'
echo ${str4} | awk '{print substr($1, 2)}'

echo -e "\nTest pipe"
awk 'BEGIN{ while (("ls /usr" | getline d)>0) print d}'
df -k | awk '$4>100000'

