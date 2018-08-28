package main

import (
	"fmt"
	"strings"
	"time"

	"math/rand"

	m "./maths"
)

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
	// fmt.Scanf("%f", &fNum2)
	fmt.Printf("Input %f\n", fNum2)

	var i int16 = 1
	for i < 10 {
		fmt.Printf("%d ", i)
		i++
	}
	var xArr [5]int
	xArr[1] = 123
	fmt.Println(xArr)

	for i := 0; i < 5; i++ {
		xArr[i] = i + 2
		fmt.Printf("%d ", xArr[i])
	}
	fmt.Println(" ")

	var total int = 0
	for _, value := range xArr {
		// fmt.Println(i, " ", value)
		total += value
	}
	fmt.Println("total:", total)

	var yArr = [5]float64{98, 94, 22, 45, 22}
	fmt.Println(yArr)

	var zArr []float32
	var aArr = make([]float32, 6, 10)
	fmt.Println("zArr:", zArr)
	fmt.Println("aArr:", aArr)

	var xMap = make(map[string]int)
	xMap["key"] = 1
	xMap["goal"] = 40
	xMap["goal"] = 402
	fmt.Println(xMap)
	xK, xV := xMap["key"]
	fmt.Println(xK, xV)

	var elements = map[string]map[string]string{
		"h": map[string]string{
			"name":    "John",
			"surname": "Smith",
		},
	}
	fmt.Println(elements)

	if el, ok := elements["h"]; ok {
		fmt.Println(el["name"], el["surname"])
	}

	var c1, d1 = f()
	fmt.Println(c1, d1)

	fmt.Println(factorial(10))

	defer second()

	first()

	testPanic()

	fmt.Println(strings.Contains("test", "te"))

	fmt.Println(m.Average([]float64{1, 2, 3, 4}))

	for i := 0; i < 10; i++ {
		go fTask(i)
	}

	m.Run()

	var input string
	fmt.Scanln(&input)
}
func init() {
	fmt.Println("============= init() ==============")
}
func f() (int, int) {
	return 1, 2
}
func factorial(x uint) uint {
	if x == 0 {
		return 1
	}
	return x * factorial(x-1)
}
func first() {
	fmt.Println("I'm first")
}
func second() {
	fmt.Println("I'm second")
}
func testPanic() {
	defer func() {
		str := recover()
		fmt.Println("recover:", str)
	}()
	panic("I am Panic")
}
func zero(nPtr *int) {
	*nPtr = 0
}
func fTask(n int) {
	for i := 0; i < 10; i++ {
		fmt.Println(n, ":", i)
		amt := time.Duration(rand.Intn(250))
		time.Sleep(time.Millisecond * amt)
	}
}
