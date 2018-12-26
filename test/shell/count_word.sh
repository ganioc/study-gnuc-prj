#!/bin/bash
ARGS=1
E_BADARGS=55
E_NOFILE=56

if [ $# -ne "$ARGS" ]
then
    echo "Usage 'basename $0' filename"
    exit $E_BADARGS
fi

if [ ! -f "$1" ]
then
    echo "File \"$1\"  does not exist."
    exit $E_NOFILE
fi

# sed -e 's/\.//g' -e 's/\,/ /g' -e 's/\;//g' -e 's/[ ][ ]*/\\\n/g' "$1" | sort | uniq -c | sort -nr
# The first part is quoted in '...' form.
# The second part is quoted in $'...' form.
#echo 'foo bar' | sed -e 's/ /\'$'\n/g'
#
#
# sed  -e 's/ /\
# /g'  "$1" | sort | uniq -c | sort -nr
#
# OS X uses the FreeBSD sed, which is strictly POSIX compliant; GNU, as usual, adds extra stuff and then Linux users all think that is some kind of "standard"
#
#

sed -e 's/\,/ /g'  -e 's/\:/ /g' -e 's/\;/ /g' -e 's/ /\'$'\n/g' "$1" | sort | uniq -c | sort -nr


exit 0
