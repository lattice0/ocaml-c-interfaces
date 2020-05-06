#include <stdio.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/callback.h>
#include <caml/alloc.h>
#include <caml/bigarray.h>

uint8_t *return_big_array()
{
    static const value *make_and_fill_array_closure = NULL;
    if (make_and_fill_array_closure == NULL)
    {
        make_and_fill_array_closure = caml_named_value("make_and_fill_array");
        if (make_and_fill_array_closure == NULL)
        {
            printf("couldn't find OCaml function");
            std::exit(1);
        }
    }
    value bigArrayValue = caml_callback(*make_and_fill_array_closure, Val_unit);
    void *bigArrayPointer = Caml_ba_data_val(bigArrayValue);
    uint8_t *p = (uint8_t *)bigArrayPointer;
    return p;
}