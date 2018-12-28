var1=10
var2=33

echo "${var1}"
echo "${var2?}"

a=2009
let a+=1
echo "a=${a}"

b=2009
echo "b=$b"
declare -i b
echo "b=$b"

let b+=1
echo "b=${b}"

# export will make it a Environment Variable




exit 0
