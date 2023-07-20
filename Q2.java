class Fibonacci {
	static int fibonacci(int n) {

		// Edge case: n is not a real number
		// Print error and return -1

		if (n < 0) {
			System.out.println("Error, invalid number");
			return -1;
		}
		if (n == 0 || n == 1) {
			return n;
		} else {
			return fibonacci(n - 1) + fibonacci(n - 2);
		}
	}

	public static void main(String[] args) {
        //Test program
        
        //Inputs
        int[] inputVal = {0,1,10,-6};
        
        //Expected results
        int[] expectedVal = {0,1,55,-1};
        
        
        for (int i = 0; i < inputVal.length; i++){
            int res = fibonacci(inputVal[i]);
			
			System.out.println("Input: " + inputVal[i] + " Expected: " + expectedVal[i] + " Result: " + res);

			if (res == expectedVal[i]){
				System.out.println("test " + i + " passed\n");
			}
			else{
				System.out.println("test " + i +" failed\n");
			}
        
    }

		}
}