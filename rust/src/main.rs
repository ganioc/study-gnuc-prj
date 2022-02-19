use std::mem;
use std::cmp::Ordering;
use std::io::Write;
// use std::num;
use std::num;
use std::time::Instant;

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
fn test_io(){
    let command_line:std::env::Args = std::env::args();
    // arguments in command line, 
    for argument in command_line {
        println!("[{}]", argument);
    }
    // for var in std::env::vars() {
    //     println!("[{}]=[{}]", var.0, var.1);
    // }
    std::env::set_var("abcd", "This is the value.");
    println!("[{:?}]",std::env::var("abcd"));

    println!("{}",
        if std::env::var("abcd").is_ok(){
            "Already defined"
        }else{
            "Undefined"
        });
    println!("{}.", match std::env::var("abcd"){
        Ok(value) => value,
        Err(err) => format!("Still undefined: {}",err),
    });

    // let mut line= String::new();
    // println!("{:?}", std::io::stdin().read_line(&mut line));
    // println!("[{}]", line);
/*
    let mut text = format!("First: ");
    let inp = std::io::stdin();
    inp.read_line(&mut text).unwrap();
    text.push_str("Second: ");
    inp.read_line(&mut text).unwrap();
    println!("{}: {} bytes", text, text.len());
*/

}
fn f1(x: i32) -> Result<i32, String>{
    if x == 1 {
        Err(format!("Err.1"))
    }else{
        Ok(x)
    }
}
fn f2(x: i32) -> Result<i32, String>{
    if x == 2 {
        Err(format!("Err.2"))
    }else{
        Ok(x)
    }
}
fn f3(x: i32) -> Result<i32, String>{
    if x == 3 {
        Err(format!("Err.3"))
    }else{
        Ok(x)
    }
}
fn test_error(x: i32) -> Result<i32, String>{
    let result = f1(x);
    if result.is_err() { return result; }
    f1(result.unwrap())
}
fn test_io_write(){
    std::io::stdout().write("Hi".as_bytes()).unwrap();

    //std::io::stdout().write("Hello ".as_bytes()).unwrap();
    std::io::stdout().write(String::from("world").as_bytes()).unwrap();

    let int_str: String = 45.to_string();
    let float_str: String = 4.5.to_string();
    let bool_str: String =  true.to_string();

    print!("{} {} {}\n", int_str, float_str, bool_str);
    
}
trait HasSquareRoot {
    fn sq_root(self) -> Self;
}
impl HasSquareRoot for f32{
    fn sq_root(self) -> Self { f32::sqrt(self) }
}
impl HasSquareRoot for f64{
    fn sq_root(self) -> Self{ f64::sqrt(self) }
}
fn quartic_root<Number> (x: Number) -> Number
where Number: HasSquareRoot{
    x.sq_root().sq_root()
}
fn test_traits(){
    println!("{} {}", quartic_root(100f64), quartic_root(100f32));
    println!("test traits.");
    println!("{}", f64::sqrt(100.0));

    println!("{},", "abcd".to_string());
    println!("{},", [1,2,3].len());
    let mut v1 = vec![0u8; 0];
    v1.push(7u8);
    print!("{:?};", v1);

}
fn _f1<T> (a:T) -> T {a}
fn _f2<T> (a: T) -> T {
    let b: T = a;
    let mut c = b;
    c = _f1(c);
    c
}
fn test_oo(){
    trait Tr{
        fn f1(a: u32)-> bool;
        fn f2(&self, b:u16) -> Self;

    }
    struct Stru{
        x: u16,
        y: u16,
    }
    impl Tr for Stru{
        fn f1(a: u32) -> bool{
            a == 0
        }
        fn f2(&self, b: u16) -> Self{
            if b == self.x || b == self.y {
                Stru {
                    x: self.x +1,
                    y: self.y + 1,
                }
            }else{
                Stru {
                    x: self.x -1,
                    y: self.y -1,
                }
            }
        }
    }
    let s = Stru{ x:23, y: 456};
    println!("{} {}", Stru::f1(500_000), s.f2(456).x);

    enum Continent{
        Afica,
        America,
        Asia,
        Europe,
        Oceania,
    }
    impl Continent{
        fn name(&self) -> &str {
            match *self {
                Continent::Afica => "Africa",
                Continent::America => "America",
                Continent::Asia => "Asia",
                Continent::Europe => "Europe",
                Continent::Oceania => "Oceania",
            }
        }
    }
    println!("{}", Continent::Asia.name());

}
fn elapsed_ms(t1:Instant, t2: Instant) -> f64{
    let t = t2 - t1;
    t.as_secs() as f64 * 1000.
        + t.subsec_nanos() as f64/1e6
}
fn test_collection_vec(){
    println!("vec");
    const SIZE:usize = 100_000_000;
    let t0 = Instant::now();
    let mut v = Vec::<usize>::with_capacity(SIZE);
    let t1 = Instant::now();
    for i in 0..SIZE {
        v.push(i);
    }
    let t2 = Instant::now();
    for _ in 0..SIZE {
        v.pop();
    }
    let t3 = Instant::now();
    print!("{} {} {}", elapsed_ms(t0,t1),
        elapsed_ms(t1,t2),
        elapsed_ms(t2,t3));
    println!("");
}
fn test_collection_vec2 (){
    println!("vec 2");
    const SIZE:usize = 100_000_000;
    let t0 = Instant::now();
    let mut v = Vec::<usize>::with_capacity(SIZE);
    let t1 = Instant::now();
    for i in 0..SIZE {
        v.insert(0,i);
    }
    let t2 = Instant::now();
    for _ in 0..SIZE {
        v.remove(0);
    }
    let t3 = Instant::now();
    print!("{} {} {}", elapsed_ms(t0,t1),
        elapsed_ms(t1,t2),
        elapsed_ms(t2,t3));
    println!("");
}
fn test_collection_que(){
    println!("que");
    const SIZE: usize = 40_000;
    let t0 = Instant::now();
    let mut v = Vec::<usize>::new();
    for i in 0..SIZE {
        v.push(i);
        v.push(SIZE + i);
        v.remove(0);
        v.push(SIZE*2 + i);
        v.remove(0);
    }
    let t1 = Instant::now();
    while v.len() > 0 {
        v.remove(0);
    }
    let t2 = Instant::now();
    println!("{} {}", elapsed_ms(t0,t1),elapsed_ms(t1,t2));

}
fn test_collection_que2(){
    println!("que2");
    const SIZE: usize = 40_000;
    let t0 = Instant::now();
    let mut v = std::collections::VecDeque::<usize>::new();
    for i in 0..SIZE {
        v.push_back(i);
        v.push_back(SIZE + i);
        v.pop_front();
        v.push_back(SIZE*2 + i);
        v.pop_front();
    }
    let t1 = Instant::now();
    while v.len() > 0 {
        v.pop_front();
    }
    let t2 = Instant::now();
    println!("{} {}", elapsed_ms(t0,t1),elapsed_ms(t1,t2));
    
}
fn add(v: &mut Vec<i32>, a: i32){
    v.push(a);
    v.sort();
}
fn extract(v: &mut Vec<i32>) -> Option<i32>{
    v.sort();
    v.pop()
}
fn test_collection_binaryheap(){

    println!("collection binaryheap");
    let a = [48,18,20,35,17,13,39,12,42,33,29,27,50,16];
    let mut v = Vec::<i32>::new();
    for i in 0..a.len()/2 {
        add(&mut v, a[i*2]);
        add(&mut v, a[i*2 + 1]);
        print!("{} ", v.pop().unwrap());
    }
    while !v.is_empty() {
        print!("{} ", v.pop().unwrap());
    }
    println!("");
}
fn test_collection_binaryheap2(){

    println!("collection binaryheap2");
    let a = [48,18,20,35,17,13,39,12,42,33,29,27,50,16];
    let mut v = Vec::<i32>::new();
    for i in 0..a.len()/2 {
        add(&mut v, a[i*2]);
        add(&mut v, a[i*2 + 1]);
        print!("{} ", extract(&mut v).unwrap());
    }
    while !v.is_empty() {
        print!("{} ", extract(&mut v).unwrap());
    }
    println!("");
}
fn test_collection(){
    println!("Spend on test collection {}", "TV");
    let time0 = Instant::now();
    for i in 0..10_000 {
        println!("{}", i);
    }

    let time1 = Instant::now();
    println!("{} ms",elapsed_ms(time0, time1));
    test_collection_vec();
    // test_collection_vec2();
    test_collection_que();
    test_collection_que2();
    test_collection_binaryheap();
    test_collection_binaryheap2();
}
fn test_assign(){
    let v1 = vec![11,22,33];
    let v2 = v1;
    // println!("{}", v1.len());
    println!("test assign");

    struct S{}
    impl Clone for S {
        fn clone(&self)-> Self{
            Self{}
        }
    }
    impl Copy for S{

    }
    let s = S{};
    let t = s.clone();
    let u = s;

    let mut a = 12;
    
    let _c = &mut a;
    // let _b = &mut a;
    *_c = 11;
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

    // test_io();
    let result = test_error(2);
    println!("{}", result.is_ok());

    test_io_write();

    test_traits();

    test_oo();

    test_collection();

    test_assign();

    println!("");
}