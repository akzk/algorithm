/*
	利用Golang的语言特性，使用sync.Once以只执行一次实例创建
*/

package main

import (
	"fmt"
	"sync"
)

var instance *Singleton
var once sync.Once

// Singleton 单例模式测试结构体
type Singleton struct {
	n int
}

// NewSingleton 创建单例
func NewSingleton() *Singleton {
	once.Do(func() {
		instance = &Singleton{}
	})
	return instance
}

func main() {
	a := NewSingleton()
	fmt.Println(a)

	a.n = 123

	b := NewSingleton()
	fmt.Println(b)
}
