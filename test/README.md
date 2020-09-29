# About Shell

## ${USER}
${UID}

${PPID}

${PS1}, ${PS2}

${IFS}, 域分隔符


## 环境变量配置文件
.bash_profile, 

如果不存在将执行/etc/profile

.bashrc

.bash_login

.profile

.bash_logout


## 位置参数
${1}

${2}

$*==$@

$# number of arguments

## 引号
"" 引用除了 $, ` , \ 之外的字符

'' 应用所有的字符

`` 解释为系统命令

\  转义符，屏蔽下一个字符的意义

## 命令替换
`` 反印号

$()  运行命令

-e === $'' , 将转义符和后跟字符形成的特殊字符解释成特殊的含义

-n 输出文字后，不换行

## 判断
字符串

-n  是否不为空

-z  是否为空

=   相同

!=  不同

-b block file

-c character special file

-d directory

-e file exists

-f file, regular file


## 逻辑运算符
-a 同时为真

-o or逻辑或

## Bash的内部变量
BASH

SHELL

DIRSTACK

pushd

popd

GLOBIGNORE

```
GROUPS  HOSTNAME  HOSTTYPE  MACHTYPE OSTYPE  REPLY  
SECONDS SHELLOPTS   SHLVL  TMOUT
```

## character handling

```
${#str}  length of str

${string:positiong:length}

${string:-position}  // to extract from right

expr ${str} : '\([ab]\)'  // regular expression

${str#substr}  // delete longest string
${str##substr} // delete shortest string
${str%%substr}  // delete from tail
${string/substring/replacement}  // replace 1st time
${string//substring/replacement}  // replace all substrings
${string/#substring/replacement} // replace form head
${string/%substring/replacement} // replace from tail



```
## 类型

```
declare
-r 只读
-i 整型
-a 数组
-f 所有函数和内容
-F 所有函数名，定义过的
-x 环境变量

```

((...)) 双圆括号方法，进行数字运算


typeset

## 间接引用
eval tempvar=\$$variable
tempvar=${!variable}

## 浮点运算
expr 233 \*  3

bc 运算

## I/O重定向
wc -l

exec命令 0<&8  8<&-

```
exec 8<&0
exec 8>&1

exec > logg  // exec 1>logg

echo "output of date command"
date

exec 1>&8 8>&-
echo "------------------"
date

&>file 输出和错误输出都定向到文件
```

( xxxx ) & 作为子shell运行

wait // 等待sub-shell运行结束

## 限制模式
set -r


set+r

## trap
TERM  15

INT ctrl-c,  2

KILL , 9

QUIT ,3, 信号 // kill -3 %1

## 函数


```
case $2 in
+)

    ;;
-) 
    ;;
*)
    ;;
esac

local //局部变量



```

## alias
unalias

列表  && && &&

||  ||   ||   ||

## 数组
${array[x]}

array[0]=1

array[*]

array[@], 所有赋值的元素

declare -a  // array


## 编码风格

```
shift // 

getopts // mac os 不支持

// 命名规范
操作对象+操作
操作名

// 变量
英文名字
常量，用大写的

保持脚本的灵活性，无硬编码的变量
足够的提示


```

## go
if [ $UID -ne 0 ]

Shell 是一个交互式解释器

## 如何交互式输入密码呢？
Pseudo-terminal will not be allocated because stdin is not a terminal

```
-T      Disable pseudo-tty allocation.

-t      Force pseudo-tty allocation.  This can be used to execute arbitrary 
        screen-based programs on a remote machine, which can be very useful,
        e.g. when implementing menu services.  Multiple -t options force tty
        allocation, even if ssh has no local tty.

ssh user@host.com <<EOF
  nohup /path/to/run.sh &
EOF
echo 'done

ssh -t -t sssssss /bin/bash 
需要batch mode

ftp -i -n 192.168.21.46 <<EOF
user zjk zjk123
ls
EOF

## method 1
ssh-keygen -t rsa
在母机上，进入/root/.ssh目录，找到id_rsa.pub该文件
用scp命令，将母机产生的key拷一份到远程的linux服务器上，并命名成authorized_keys；scp ~/.ssh/id_rsa.pub  root@192.168.1.113:/root/.ssh/authorized_keys
会发现不在需要输入密码了


## method 2
expect
在运行脚本时候要expect  file，不能sh file了

首行指定用来执行该脚本的命令程序，这里是/usr/bin/expect

上面语句第一句是设定超时时间为30s，spawn是expect的语句，执行命令前都要加这句

expect "password："这句意思是交互获取是否返回password：关键字，因为在执行ssh时会返回输入password的提示：james@192.168.1.119's password:

send就是将密码123456发送过去

expect eof 子进程已经结束的eof字符，expect脚本也就退出结束

interact代表执行完留在远程控制台，不加这句执行完后返回本地控制台 

#!/usr/local/bin/expect -f
set timeout 30
spawn scp TcrController james@192.168.1.119:/home/james/ws
expect "*password:"
send "123456\r"
expect eof

# 取Arguments
set user [lindex $argv 1]
set ip [lindex $argv 0]
set password [lindex $argv 2]


## method 3
sshpass
sshpass -ptest1324 ssh user@192.168.1.200 ls -l /tmp


```

# 调试
EXIT . 退出

ERR,  命令执行不成功

DEBUG, 每一条命令执行前




















