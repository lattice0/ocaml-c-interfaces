set -e
eval `opam env`
ocamlopt -output-obj -o s.o say_something.ml
g++ -o hello_world -I $(ocamlopt -where) \
    main.cc say_something.cc s.o $(ocamlopt -where)/libasmrun.a -ldl