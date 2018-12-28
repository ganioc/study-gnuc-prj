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

pushd

popd








