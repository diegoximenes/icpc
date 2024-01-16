package main

import (
	"fmt"
)

func main() {
	var TC int
	fmt.Scanf("%d\n", &TC)
	for tc := 0; tc < TC; tc += 1 {
		var k, b, s uint64
		var n int
		fmt.Scanf("%d %d %d %d\n", &n, &k, &b, &s)

		curr_s := s
		out := make([]uint64, n)
		for i := 0; i < n; i += 1 {
			out[i] = 0
		}

		can := true
		for i := 0; i < n; i += 1 {
			if curr_s/k > b {
				if k-1 <= curr_s {
					out[i] = k - 1
					curr_s -= k - 1
				} else {
					can = false
					break
				}
			} else if curr_s/k < b {
				can = false
				break
			} else {
				out[i] = curr_s
				curr_s = 0
				break
			}
		}

		if curr_s > 0 {
			can = false
		}

		if !can {
			fmt.Printf("-1\n")
		} else {
			fmt.Printf("%v", out[0])
			for i := 1; i < n; i += 1 {
				fmt.Printf(" %v", out[i])
			}
			fmt.Printf("\n")
		}
	}
}
