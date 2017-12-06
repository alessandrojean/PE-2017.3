#!/bin/bash
rm -f a.out 2> /dev/null
gcc -std=c99 lista02.c main02.c
if [ -f a.out ]; then
    echo "Compilou OK"
else
    echo "Não compilou!"
    echo "Certifique-se de que os arquivos main02.c, lista02.c e lista.h estejam neste diretório."
    exit
fi

N=$(./a.out | diff file02 - | grep "^<" | wc -l)
T=$(cat file02 | wc -l)
NOTA=$(echo "scale=2; 10 * ($T - $N) / $T" | bc)
echo "Nota da Q2: $NOTA de 10.00"


