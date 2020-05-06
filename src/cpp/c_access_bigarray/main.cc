#include <stdio.h>
#include <caml/callback.h>

extern uint8_t* return_big_array();

int main(int argc, char ** argv)
{

  /* Initialize OCaml code */
  caml_startup(argv);
  /* Do some computation */
  uint8_t* p = return_big_array();
  //Should print 5
  printf("first element: %d \n", p[0]);
  return 0;
}