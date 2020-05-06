FROM ubuntu:bionic

WORKDIR /home/project

RUN export DEBIAN_FRONTEND=noninteractive && apt-get update && apt-get install -y curl unzip patch bubblewrap build-essential cmake autoconf git m4

#RUN curl -sL https://raw.githubusercontent.com/ocaml/opam/master/shell/install.sh -o get-ocaml.sh\
#    && sh get-ocaml.sh

COPY ./get-ocaml.sh /home/project/get-ocaml.sh

RUN sh /home/project/get-ocaml.sh --no-interaction --disable-sandboxing

RUN opam init -y \
    && eval `opam env`\
    && opam switch create 4.10.0\
    && eval `opam env`\
    && which ocaml\
    && ocaml -version\
    && opam install dune ocamlfind