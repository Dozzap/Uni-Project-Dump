import java.util.Arrays;

//Dynamic Programming Solution
class ChangeDp{
    static int CoinChange(int[] coins, int amount) {
	//Intialize the combinations array
        int[] possibleCombinations = new int[amount + 1]; 

	//Fill in a default/placeholder value that is bigger than asked amount
	//This is important for the end part of this function 
        Arrays.fill(possibleCombinations, amount + 5);  
        
	//Set up a min for the array
        possibleCombinations[0] = 0;    

	//Iterate through all possible amount of the coint
        for (int i = 1; i < amount + 1; i++) {
	    //Iterate through all the possible coins 
            for (int j = 0; j < coins.length; j++) {
		//This checks if the current value of the coin is less than the value of amount
                if (coins[j] <= i) {
		    //This checks for which is the minimum between its current value and the value of amount subtracted by the current coin/change value 
		    //Lesser value will be assigned to the index of possibleCombinations array
                    possibleCombinations[i] = Math.min(possibleCombinations[i], 1 + possibleCombinations[i - coins[j]]);
                }
            }
        }
	//Returns the number of combinations at the value of amount if the value is less than the amount, else it will return -1 because there is no combination
        return possibleCombinations[amount] > amount ? -1 : possibleCombinations[amount];
    }

    public static void main(String[] args) {
        //Test program
        
        //Coins sample
        int[] coinValues = {25, 10, 5};
        
        //Amount to be turn into change
        int[] amountInt = {30, 100, 1};  // 3, Reasoning: 5 + 5 + 1
        
        //Expected Solution
        int[] expectedRes = new int[3];
        expectedRes[0] = 2;     //30 = 25 + 5
        expectedRes[1] = 4;     //100 = 25 + 25 + 25 + 25
        expectedRes[2] = -1;    //-1 because there is no possible combination

        for (int i = 0; i < amountInt.length; i++){
            int res = CoinChange(coinValues,amountInt[i]);
            if ( res == expectedRes[i]){
                System.out.println("Test " + i + " passed");
                System.out.println("Output: Minimum " + res + " coins required");
            }
            else{
                System.out.println("Test" + i + " failed");
            }
        }

    }
}
