ocamlopt -output-obj -o bigmod.o mod.ml
g++ -c modwrap.cc
g++ -o myprog -I $(ocamlopt -where) \
    main.cc modwrap.o bigmod.o $(ocamlopt -where)/libasmrun.a -ldl