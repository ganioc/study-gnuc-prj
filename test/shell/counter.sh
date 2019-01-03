#!/bin/bash

echo -e "Txt words counter script\n\n"

end=$1

cat $2 | \
tr -cs "[a-z][A-Z]" "[\012*]" | \
tr A-Z a-z | \
sort | \
uniq -c | \
sort -k1nr -k2 | \
head -n "${end}"

MAX=5
i=1

echo "${MAX} random numbers are generated"
while [ "${i}" -le ${MAX} ]
do
    number=$RANDOM 
    echo ${number}
    let "i=i+1"

done
