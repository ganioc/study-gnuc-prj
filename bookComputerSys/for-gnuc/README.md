# Description

Use it for gnuc compiling, cross compilation.

1. vim
2. make
3. cmake


docker build -t forgnuc:0.2 . 




发布为: docker pull forgnuc:0.1

// docker tag 2ac6ba3ccdca forgnuc:0.1

docker push forgnuc:0.1
docker pull forgnuc:0.1

## HowTo

In your .vimrc, add set encoding=utf-8 and restart Vim


```
// Run the container
$ ./rungnuc.sh

// Recommended way to connect to the container
$ docker exec -i -t forgnuc-1 /bin/bash

$ docker attach forgnuc-1


```

## Modification



## problems

   




