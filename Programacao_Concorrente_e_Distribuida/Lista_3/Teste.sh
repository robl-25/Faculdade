#! /bin/bash

PROG=$1;

for((THREADS=1; THREADS<=4; THREADS*=2)) do
	./$PROG $THREADS
	echo
done
