#!/bin/bash

trap 'echo "before execute line:${LINENO}, a=${a}, b=${b}, c=${c} "' DEBUG

a=0
b=2
c=100

while :
do
    if (( a >= 10 ))
    then 
        break
    fi

    let "a=a+2"
    let "b=b*2"
    let "c=c-10"
done

