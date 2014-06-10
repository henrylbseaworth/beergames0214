#!/bin/bash
if [ $# -eq 0 ]
then
  echo "Usage: $0 <biary> <key>"
  exit 2
fi

platform='unknown'
MYNAME=`uname`
if [[ "$MYNAME" == 'Linux' ]]; then
	for fs in *.txt
	do
		NAME=${fs%.txt}
		EXE=${1#*./}
		cp $fs $fs.tmp
		strace -c -o"BENCH_${NAME}_$EXE.d" -Ttt $1 $fs.tmp $2 
		rm $fs.tmp
	done
else
  echo "Platform not supported"
fi

