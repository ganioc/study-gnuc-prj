package main

import "fmt"

func main() {
	fmt.Printf("hello, world\n")
	fmt.Println("hello again")
	fmt.Println("hello"[0], "hello"[1])

	var x = "Fu zi nan"

	fmt.Println(x)

	// main.myutil()

	var (
		a = 1
		b = 2
		c = 3
	)

	fmt.Println("Three numbers are:", a, b, c)

	var fNum1 float64
	var fNum2 float32
	fNum1 = 1.3

	fmt.Println(fNum1)
	fmt.Print("Please enter an float number: ")
	fmt.Scanf("%f", &fNum2)
	fmt.Printf("Input %f\n", fNum2)

	var i int16 = 1
	for i < 10 {
		fmt.Printf("%d ", i)
		i++
	}
}
