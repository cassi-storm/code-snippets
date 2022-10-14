package main

import (
	"fmt"
)

func getAllPossiabilities(n int, x int, a []int) int {
	mod_, m := 1_000_000_007, 1024
	for i := 0; i < n; i++ {
		a[i] &= x
	}
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m)
	}
	dp[0][0] = 1
	for i, v := range a {
		for j := 0; j < m; j++ {
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod_
			dp[i+1][v^j] = (dp[i+1][v^j] + dp[i][j]) % mod_
		}
	}
	return dp[n][0]
}

func main() {
	var n, x int
	fmt.Scanf("%d\n", &n)
	fmt.Scanf("%d\n", &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	result := getAllPossiabilities(n, x, a)
	fmt.Println(result)
}
