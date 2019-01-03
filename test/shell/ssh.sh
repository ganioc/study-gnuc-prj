#!/usr/local/bin/expect -f
set timeout 10
spawn ssh nanchao@139.219.184.44
expect "*password:"
exec sleep 1
send "1Nanchao.org\r"
expect "*~$"
send "ls -l\r"
expect eof
exit 0
