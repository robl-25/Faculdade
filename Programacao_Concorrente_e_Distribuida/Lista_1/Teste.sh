#! /bin/bash

PROG=$1;
TAM_MIN=$2;
TAM_MAX=$3;

echo -n '# Threads '

for((i=$TAM_MIN; i<=$TAM_MAX; i++)) do
	echo -n '10^'$i' '
done

echo

for((THREADS=1; THREADS<=8; THREADS*=2)) do
	echo -n $THREADS' '

	for((TAM=$TAM_MIN; TAM<=$TAM_MAX; TAM++)) do
		./$PROG $TAM $THREADS
	done

	echo
done
