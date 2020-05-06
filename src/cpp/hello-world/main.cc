#include <stdio.h>
#include <caml/callback.h>

extern char* say_something(const char* s);

int main(int argc, char ** argv)
{
  char* result;

  /* Initialize OCaml code */
  caml_startup(argv);
  /* Do some computation */
  result = say_something("hello world\n");
  printf("%s", result);
  return 0;
}