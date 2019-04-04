#!/bin/bash

# docker config
CONTAINER_NAME=forgnuc-1
IMAGE_NAME=forgnuc:0.2

# network config


echo -e '\nStart ${CONTAINER_NAME}'

if [ ! -d data  ]
then
    echo 'No data/ found'
    exit 1
fi

docker run -i -t -d --name ${CONTAINER_NAME} -v $(pwd)/data:/home/ruff/data   ${IMAGE_NAME}  /bin/bash 


echo -e '\nEnd\n'
