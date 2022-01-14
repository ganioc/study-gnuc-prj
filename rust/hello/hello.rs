fn main(){
    print!("Hello, world!\n");
    print!("{}, {}!", "Hello", "world");
    println!("Let's go.");

    let  number=12;
    // number = 0;
    let other_number = 53;
    print!("{}\n", number + other_number);

    print!("{} {}\n", str::len("abc"),
        "abcdefg".len());
    
    let n = 4;
    if n > 0 { print!("positive\n"); }

    for i in 1..11 {
        print!("{} ", i*i);
    }
    println!("");
    let mut a1 = vec![4,56];
    let a2 = vec![7,81,100];
    print!("{:?}", a1);
    print!("{:?}\n", a2);
    a1 = a2;
    print!("a1: {:?}\n", a1);
    // print!("a2: {:?}\n", a2);

    let _number = 12;
    print!("{}\n", _number);

    let truth = true;
    let falsity = false;
    print!("{} {}\n", truth, falsity);

    let hexadecimal = 0x10;
    let decimal = 10;
    let octal = 0o10;
    let binary = 0b10;
    print!("{} {} {} {}\n", hexadecimal, decimal, octal, binary);

    let a:i8 = 5;
    let b:i16 = 5;
    let c:i32 = 5;
    let d:i64 = 5;
    print!("{} {} {} {}\n", a, b,c,d);

    enum Continent{
        Europe,
        Asia,
        Africa,
        America,
        Oceania,
    }
    let mut contin = Continent::Asia;

    match contin{
        Continent::Europe => {
            contin = Continent::Asia;
            print!("E");
        },
        Continent::Asia => {let a = 7;
            print!("a is {}\n", a)},
        Continent::Africa => print!("Af"),
        Continent::America => print!("Am"),
        Continent::Oceania => print!("0"),
    }

    for n in -2..5 {
        println!("{} is {}.", n, match n {
            0 => "zero",
            1 => "one",
            _ if n< 0 => "negative",
            _ => "plural",
        });
    }

    fn f2() { print!("2"); }
    f2();

    fn double_negatives(mut a: [i32; 10]) -> [i32;10] {
        for i in 0..10{
            if a[i] < 0 {
                a[i] *= 2;
            }
        }
        a
    }
    let mut arr = [ 5, -4, 9, 0, -7, -1, 3, 5,3,1];
    arr = double_negatives(arr);
    print!("{:?}", arr);
    
    println!("");
}