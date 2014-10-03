FLAGS=-std=c99 -Wall -ggdb

db2: db2.c node.h node.c list.c list.h nodestruct.h readline.h readline.c
	gcc -o db2 $(FLAGS) db2.c node.c list.c readline.c node.h list.h nodestruct.h readline.h

db2bin: db2.c binary.h binary.c binarystruct.h readline.h readline.c
	gcc -o db2bin $(FLAGS) db2.c binary.c readline.c binary.h binarystruct.h readline.h
