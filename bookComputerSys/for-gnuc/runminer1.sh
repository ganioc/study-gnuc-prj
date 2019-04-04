#!/bin/bash

# docker config
CONTAINER_NAME=ruffchain_Shepherd-1
IMAGE_NAME=registry.grootapp.com/rfc:1.73

# network config

SN_NAME=SN_RUFF_TEST
SN_IP=42.159.86.15
SN_TCPPORT=10000
SN_UDPPORT=10001
RPCPORT=18089
BDT_TCPPORT=13010
BDT_UDPPORT=13000
CONFIG_FILE=config.tar.gz
SECRET=054898c1a167977bc42790a3064821a2a35a8aa53455b9b3659fb2e9562010f7
ADDRESS=1Bbruv7E4nP62ZD4cJqxiGrUD43psK5E2J
FEELIMIT=50

echo -e '\nStart miner: ${CONTAINER_NAME}'

if [ ! -d data -o ! -d ruff ]
then
    echo 'Need data/ , ruff/ from config.tar.gz'
    tar xvfz ./${CONFIG_FILE}
fi

docker run -i -t -d --name ${CONTAINER_NAME} -v $(pwd)/data:/home/ruff/chainsdk/data   -v $(pwd)/ruff:/home/ruff/chainsdk/ruff  -p ${RPCPORT}:${RPCPORT} -p ${BDT_TCPPORT}:${BDT_TCPPORT}  -p  ${BDT_UDPPORT}:${BDT_UDPPORT}/udp  ${IMAGE_NAME}     /home/ruff/chainsdk/run.sh miner --genesis './data/dposbft/genesis' --dataDir './data/dposbft/miner1' --loggerConsole --loggerLevel debug --minerSecret ${SECRET}    --rpchost  0.0.0.0 --rpcport ${RPCPORT}  --minOutbound 0 --feelimit ${FEELIMIT} --net bdt --host 0.0.0.0 --port "${BDT_TCPPORT}|${BDT_UDPPORT}" --peerid  ${ADDRESS}  --sn ${SN_NAME}@${SN_IP}@${SN_TCPPORT}@${SN_UDPPORT}  --bdt_log_level info --ignoreBan --executor inprocess  --txServer --forceClean


echo -e '\nEnd\n'
