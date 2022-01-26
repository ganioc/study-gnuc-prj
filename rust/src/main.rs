use std::mem;
use std::cmp::Ordering;



fn desc(a: &i32, b: &i32) -> Ordering {
    if a < b { Ordering::Greater }
    else if a > b { Ordering::Less}
    else { Ordering::Equal }
}

fn as_bytes<T>(o: &T) -> &[u8] {
    unsafe{
        std::slice::from_raw_parts(
            o as *const _ as *const u8,
            mem::size_of::<T>()) // ')' 换行就不行了
    }
}

fn chap13(){
    let factor = 2;
    let multiply = |a| a*factor;
    println!("{}", multiply(13));

    let multiply_ref: &( dyn Fn(i32)->i32) = &multiply;

    println!(
        "{} {} {} {} {}",
        (*multiply_ref)(13),
        multiply_ref(13),
        (|a| a*factor)(13),
        (|a: i32| a * factor) (13),
        |a| -> i32 { a* factor} (13)
    );
    println!(
        "{}",
        (|v: &Vec<i32>|{
            let mut sum =0;
            for i in 0..v.len() {
                sum+= v[i];
            }
            sum
        })(&vec![11,22,34])
    );
    let a: &str = "0123456789";
    println!("{}", mem::size_of_val(a));
    let s: &str = "S";
    println!("{}", mem::size_of::<&str>());

    let mut astring:String = "he".to_string();
    astring.push('1');
    astring.push('2');
    astring.push('3');
    println!("{} {}", s, astring);

    let mut s_string = "".to_string();
    for _ in 0..10{
        println!("{:?} {} {}",
            s_string.as_ptr(), 
            s_string.capacity(),
            s_string.len()
        );
        s_string.push('a');
    }
}
fn m_slice(){
    let arr = [55,22,33,44,66,7,8];
    let v = vec![55,22,33,4,55,77,88];
    let sr1 = &arr[2..5];
    let sr2 = &v[2..5];

    println!("{:?} {:?} {:?} {:?}",
        sr1,
        sr2,
        &sr1[1..2],
        &sr2[1]);
    
}
fn print_nth_char(s: &str, n: u32){
    let mut iter: std::str::Chars = s.chars();
    let mut times = n;
    println!("n is : {}", times);
    loop{
        let item: Option<char> = iter.next();
        match item {
            Some(c) => if times==1 {
                println!("{}", c);
                break;
            },
            None => { break;}
        }
        times = times - 1;
    }
}
fn print_codes(s:&str){
    let mut iter = s.chars();
    loop{
        match iter.next(){
            Some(c) => {
                println!("{}: {}",c, c as u32);
            },
            None => {break; },
        }
    }
}
fn m_iterator(){
    let s = "abc012";
    for i in 0..s.len(){
        println!("{}: {}", i, s.as_bytes()[i]);
    }
    print_nth_char("abcdefg",2);
    print_codes("啊呀");

    let string: &str = "aaλαψ";
    let string_it: std::str::Bytes = string.bytes();
    for byte in string_it {
        print!("{} ", byte);
    }
    println!("");
    for item_ref in (&[11u8,22,33]).iter(){
        print!("{} ", *item_ref);
    }
    println!("");
    for item_ref in vec!['a','b','c'].iter(){
        print!("{} ", *item_ref);
    }
    let slice: &[u8] = &[11u8,22,23];
    let slice_it: std::slice::Iter<u8> = slice.iter();
    for item_ref in slice_it{
        print!("{} ", *item_ref);
    }

    let slice = &mut[3,4,5,6];
    {
        let iterator = slice.iter_mut();
        for item_ref in iterator{
            *item_ref += 1;
        }
    }
    println!("{:?}", slice);

    let arr = [66, -90, -20, 223, 34 , 0, 32];
    for n in arr.iter().filter(|x| **x < 0){
        print!("{} ", n);
    }
    println!("");
    for n in arr.iter().map(|x| *x * 2){
        print!("{} ", n);
    }
    println!("");
    for (i,ch) in arr.iter().enumerate() {
        print!("{} {}, ", i, *ch);
    }
    println!("");
    match arr.iter().min(){
        Some(n) => println!("{}", n),
        _ => (),
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

    let b1 = true;
    println!("{}", &b1 as *const bool as usize);

    enum E1 {E1a, _E1b}
    enum E2 {E2a, _E2b(f64)}

    print!("{} {} {} {} {} {}",
        mem::size_of_val(&[0i16; 80]),
        mem::size_of_val(&(0i16, 0i64)),
        mem::size_of_val(&[(0i16, 0i64); 100]),
        mem::size_of_val(&E1::E1a),
        mem::size_of_val(&E2::E2a),
        mem::size_of_val(&vec![(0i16,0i64); 100])
    );

    let mut v = vec![0;0];
    println!("\n{} {}", v.len(), v.capacity());
    v.push(11);
    println!("\n{} {}", v.len(), v.capacity());
    v.push(22);
    println!("\n{} {}", v.len(), v.capacity());

    let mut arr = [4,23,34,1,34,34, 68, 12, 9,  5];
    arr.sort();
    println!("{:?}", arr);

    arr.sort_by(desc);
    println!("{:?}", arr);

    // let two = 2;
    const TWO: f64 = 2.;
    fn print_double(x: f64){
        println!("{}", x*TWO);
    }
    print_double(17.2);

    let desc2nd = |a: &i32, b:&i32| -> Ordering{
        if a< b { Ordering::Greater}
        else if a > b { Ordering::Less}
        else { Ordering::Equal }
    };
    arr.sort_by(desc2nd);
    println!("{:?}", arr);

    chap13();

    m_slice();

    m_iterator();
    
    println!("");
}