set -e
eval `opam env`
ocamlopt -output-obj -o s.o bigarray.ml
g++ -o bigarray -I $(ocamlopt -where) \
    main.cc interface.cc s.o $(ocamlopt -where)/libasmrun.a -ldl