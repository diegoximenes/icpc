package main

import (
	"fmt"
)

func main() {
	var TC int
	fmt.Scanf("%d\n", &TC)
	for tc := 0; tc < TC; tc += 1 {
		var n, m int
		fmt.Scanf("%d %d\n", &n, &m)

		out := n - 1 + m - 1
		if n < m {
			out += n - 1
			if m > 1 {
				out += 1
			}
		} else {
			out += m - 1
			if n > 1 {
				out += 1
			}
		}

		fmt.Printf("%v\n", out)
	}
}
