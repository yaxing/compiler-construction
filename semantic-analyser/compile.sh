flex lex.l;
bison -d translate.y;
gcc lex.yy.c translate.tab.c -ll -o SA.out;
