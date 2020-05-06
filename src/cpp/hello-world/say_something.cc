#include <stdio.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/callback.h>
#include <caml/alloc.h>


char *say_something(const char *s)
{
  static const value *say_something_closure = NULL;
  if (say_something_closure == NULL) {
    say_something_closure = caml_named_value("say_something");
    if (say_something_closure == NULL) {
      std::exit(1);
    }
  }
  
  value str = caml_alloc_initialized_string(strlen(s), s);
  /* We copy the C string returned by String_val to the C heap
     so that it remains valid after garbage collection. */
  return strdup(String_val(caml_callback(*say_something_closure, str)));
}