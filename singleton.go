package main

// 利用Golang的语言特性，使用sync.Once以只执行一次实例创建

import (
	"fmt"
	"sync"
)

var instance *Singleton
var once sync.Once

type Singleton struct {
	n int
}

func GetInstance() *Singleton {
	once.Do(func() {
		instance = &Singleton{}
	})
	return instance
}

func main() {
	a := GetInstance()
	fmt.Println(a)

	a.n = 123

	b := GetInstance()
	fmt.Println(b)
}
