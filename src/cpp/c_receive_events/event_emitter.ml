open Lwt.Infix

external call: int64 -> string -> _ = "function_pointer_caller"

let begin_event pointer = 
    Lwt_unix.sleep 5.0 >>= fun () ->
        call pointer "message"

let () = Callback.register "begin_event" begin_event