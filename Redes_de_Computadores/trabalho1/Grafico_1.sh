#! /bin/bash

PROG=$1;

for((R=1; R<=100; R++)) do
	echo -n $R
	./$PROG 30000 2 1 3000 0.000001 $R 300000000 2 $R 300000000 1
	echo
done
