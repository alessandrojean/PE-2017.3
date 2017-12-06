#!/bin/bash
rm -f a.out 2> /dev/null
gcc -std=c99 lista01.c main01.c
if [ -f a.out ]; then
    echo "Compilou OK"
else
    echo "Não compilou!"
    echo "Certifique-se de que os arquivos main01.c, lista01.c e lista.h estejam neste diretório."
    exit
fi

N=$(./a.out | diff file01 - | grep "^<" | wc -l)
T=$(cat file01 | wc -l)
NOTA=$(echo "scale=2; 10 * ($T - $N) / $T" | bc)
echo "Nota da Q1: $NOTA de 10.00"


