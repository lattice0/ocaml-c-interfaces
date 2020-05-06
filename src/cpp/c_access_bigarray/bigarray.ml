open Format

let make_byte_array len = 
    Bigarray.Array1.create Bigarray.int8_signed Bigarray.c_layout len 

let make_and_fill_array () =  
    let b = make_byte_array 10 in 
    let s = Bigarray.Array1.fill b 5 in
    b

let () = Callback.register "make_and_fill_array" make_and_fill_array

