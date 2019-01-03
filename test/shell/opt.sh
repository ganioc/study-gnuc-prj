#!/bin/bash

while getopts "fh:" optname
do
    case ${optnmae} in
    f)
        echo "Option ${optname} specified"
        ;;
    h)
        echo "Option ${optname} specified has value ${OPTARG}"
        ;;
    :)
        echo "Unknow option ${OPTARG}"
        ;;
    \?)
        echo "No parameter value for option ${OPTARG}"
        ;;
    *)
        echo "optname:" ${optname}
        echo "Unknow error"
        ;;
    esac

done

shift $(( $OPTIND - 1 ))

ipAddrArray=([0]="192.158.0.3" [1]="192.158.0.5" [2]="192.158.0.23" [3]="192.158.0.112")

echo "array num:" ${#ipAddrArray[*]}

echo -e "\nLogin server:"

expect --version

if [ $? -eq 0 ]
then
    echo "You must install expect"
    exit 1
fi

( expect ./ssh.sh )

wait

echo $?

echo -e "1Nanchao.org\n"

sleep 1


exit 0
