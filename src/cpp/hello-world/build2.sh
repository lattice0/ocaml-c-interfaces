ocamlc -custom -output-obj -o say_something.o say_something.ml
ocamlc -c say_something.cc
cp `ocamlc -where`/libcamlrun.a mod.a && chmod +w mod.a
ar r mod.a modcaml.o modwrap.o