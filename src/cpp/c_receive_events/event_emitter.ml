open Lwt.Infix

external call: int -> string -> unit = "function_pointer_caller"

let begin_event pointer = 
    Lwt_unix.sleep 1.0 >>= fun () ->
        (Lwt.return @@ call pointer "message")

let () = Callback.register "begin_event" begin_event


let create_threads () =
  print_endline "starting plain non-lwt threads";
  let (_: Thread.t) =
    let counter = ref 0 in
    let rec f () =
      let _ = Thread.delay 1.0 in
      incr counter;
      Printf.printf "ticked %d times\n%!" !counter;
      f ()
    in
    Thread.create f ()
  in
  ()

let () = create_threads()

