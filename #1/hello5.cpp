#include "pzhelp"

PROC hello(){

  WRITELN("hello world");

}

PROGRAM {

  int i, n;
  n = READ_INT();
  if (n<=0)  WRITELN("nothing today");
  else {

    FOR(i, 1 TO n)  hello();

  }

}  
