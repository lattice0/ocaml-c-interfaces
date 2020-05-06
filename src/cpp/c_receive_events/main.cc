#include <stdio.h>
#include <caml/callback.h>

extern "C" void register_function_callback();

int main(int argc, char **argv)
{
  caml_startup(argv);
  register_function_callback();
  while (true)
  {
  }
  return 0;
}