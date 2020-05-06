#include <stdio.h>
#include <caml/callback.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/bigarray.h>
#include <caml/threads.h>

extern void register_function_callback();

void print_from_event(char* message) {
    printf("OCaml event: %s\n", message);
}

extern "C" value function_pointer_caller(value _pointer, value _message)
{
    //void (*f)(char *);
    //f = pointer;
}

void register_function_callback() {
    static const value *begin_event_closure = NULL;
    if (begin_event_closure == NULL)
    {
        begin_event_closure = caml_named_value("begin_event");
        if (begin_event_closure == NULL)
        {
            printf("couldn't find OCaml function\n");
            exit(1);
        }
    }
    //uint64_t pointer = (uint64_t) &function_pointer_caller;
    //caml_callback(*begin_event_closure, (int64_t) &pointer);
}

int main(int argc, char **argv)
{
  caml_startup(argv);
  register_function_callback();
  caml_release_runtime_system();
  
  while (true)
  {
  }
  return 0;
}
