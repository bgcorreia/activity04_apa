# Activity 04 - APA - UFPB

## Description

This project intends to implement the ordering algorithm Counting and Radix Sort in C ++.

## Compilation/Linker

To compile/linker execute `make` in the clone directory.

Example:

```bash
user@host:~/activity04_apa$ make
g++     ordenacao4.cpp   -o ordenacao4
user@host:~/activity04_apa$
```

## Execution

Then, execute the generated binary:

```bash
user@host:~/activity04_apa$ ./ordenacao4 -h

Uso: ./ordenacao4 [OPÇÕES]

OPÇÕES:

 -t [cs|rs]     Tipo da Ordenação. P/ CountingSort -> CS , RadixSort -> RS.

                        Ex.: -t cs | -t rs

 -i [Arquivo]   Define o arquivo de entrada, com os valores a serem ordenados.

                        Ex.: -i ./couting.txt | -i ~/ordenar.txt
                        

 -h      Mostra esta tela de ajuda e sai
 -v      Mostra a versão do programa e sai
 
   
Exemplo completo de uso:

./ordenacao4 -t cs -i entrada.txt 
```
