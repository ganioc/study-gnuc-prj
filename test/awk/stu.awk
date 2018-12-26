#!/usr/bin/awk -f
BEGIN {FS=","}
{
    total = $4
    print $1,total

}
