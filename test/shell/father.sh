#!/bin/bash
localVar="Define a lcoal variable"

echo "The script name is: ${0}"
echo "The arguments: $*"
echo "No of arguments: $#"

echo "Father process id is: $$"
echo "localvar=${localVar}"

${PWD}/child.sh

echo "In father process: $$"
echo "Any errors? $?"
echo "Exit"

exit 0
