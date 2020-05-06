let say_something string = String.concat "" ["OCaml says: "; string]

let () = Callback.register "say_something" say_something