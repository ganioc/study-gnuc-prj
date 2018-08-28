package maths

import (
	"fmt"
	"time"
)

func pinger(c chan string) {
	for i := 0; i < 10; i++ {
		c <- "ping"
	}
}
func printer(c chan string) {
	for {
		msg := <-c
		fmt.Println(msg)
		time.Sleep(time.Second * 1)
	}
}

// Run function
func Run() {
	var c = make(chan string)

	go pinger(c)
	go printer(c)

	var input string
	fmt.Scanln(&input)
}
