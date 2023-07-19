class Permutation {
	static int permutations(int n, int k) {

		// Edge case: where k is larger than n
		// Print err and return -1
		if (n < k) {
			System.out.println("Invalid Input");
			return -1;
		}
		// Base case: if k is 0, return 1
		if (k == 0) {
			return 1;

			// Recursive portion: n will be multiplied to the return value of
			// permutations(n-1,k-1)
			// Will be recursively called until base cased is reached
		} else {
			return n * permutations(n - 1, k - 1);
		}
	}

	public static void main(String[] args) {
		int[][] testCases = { { 0, 0 }, { 1, 0 }, { 3, 5 }, { 6, 5 } };
		int[] expectedRes = { 1, 1, -1, 720 };

		for (int i = 0; i < testCases.length; i++) {
			int n = testCases[i][0];
			int k = testCases[i][1];
			int res = permutations(n, k);

			System.out.println("Result for permutation of n = " + n + " and k = " + k + " is " + res);
			if (res == expectedRes[i]) {
				System.out.println("Test " + i + " passed\n");
			} else {
				System.out.println("Test " + i + " failed\n");

			}
		}
	}

}
