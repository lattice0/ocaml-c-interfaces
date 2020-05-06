set -e
set -x
eval `opam env`
#ocamlopt -output-obj -o s.o -package lwt.unix event_emitter.ml
#g++ -o event_emitter -I $(ocamlopt -where) main.cc -L . -ldl
ocamlfind ocamlopt -output-obj -o s.o -linkpkg -package lwt.unix -thread event_emitter.ml interface.c
#cp $(ocamlopt -where)/libasmrun.a libmyoc.a
#ar r libevent_emitter.a event_emitter.o s.o
#g++ -o s.o -I $(ocamlopt -where) main.cc -L . -levent_emitter -ldl
g++ -o event_emitter_program -I $(ocamlopt -where) \
    s.o interface.o main.cc -L$(ocamlc -where) -lunix -lasmrun -pthread /root/.opam/4.10.0/lib/lwt/unix/liblwt_unix_stubs.a /root/.opam/4.10.0/lib/stublibs/dlllwt_unix_stubs.so -ldl