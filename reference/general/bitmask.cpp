// iterate all subsets
for (int mask1 = ((mask - 1) & mask); mask1; mask1 = ((mask1 - 1) & mask))

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(x, N) ((x) & (N - 1))   // returns x % N, where N is a power of 2
#define isPowerOfTwo(x) ((x & (x - 1)) == 0)
#define nearestPowerOfTwo(x) ((int)pow(2.0, (int)((log((double)x) / log(2.0)) + 0.5)))

