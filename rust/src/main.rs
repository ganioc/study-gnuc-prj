use std::mem;

fn as_bytes<T>(o: &T) -> &[u8] {
    unsafe{
        std::slice::from_raw_parts(
            o as *const _ as *const u8,
            mem::size_of::<T>()) // ')' 换行就不行了
    }
}

fn main(){
    let a = 123;
    print!("hello main\n");
    print!("{}\n",a);
    print!("{} ", std::mem::size_of::<i32>());
    print!("{} ", std::mem::size_of_val(&12));

    print!("{} \n", mem::size_of::<i32>());
    print!("{} {} {} {}\n",
        mem::size_of::<isize>(),
        mem::size_of::<usize>(),
        mem::size_of::<&i8>(),
        mem::size_of::<&u32>());

    println!("{:?}", as_bytes(&1i8));
    println!("{:?}", as_bytes(&2i16));
    println!("{:?}", as_bytes(&3i32));
    println!("{:?}", as_bytes(&(4i64 + 5*256 + 6*256*256)));
    println!("{:?}", as_bytes(&'A'));
    println!("{:?}", as_bytes(&true));
    println!("{:?}", as_bytes(&&1i8));
    
    println!("");
}