#include <stdio.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/callback.h>
#include <caml/alloc.h>
#include <caml/bigarray.h>

extern void register_function_callback();

void print_from_event(char* message) {
    printf("OCaml event: %s\n", message);
}

void function_pointer_caller(uint64_t pointer, char* message)
{
    void (*f)(char *);
    f = pointer;
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
    uint64_t pointer = (uint64_t) &function_pointer_caller;
    caml_callback(*begin_event_closure, (int64_t) &pointer);
}