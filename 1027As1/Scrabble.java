/*
 * 
 * CS 1027 Computer Science Fundamentals II
 * 
 * Scrabble Class
 * 
 */

//import java.io and java.util for future uses
import java.io.*;
import java.util.*;


public class Scrabble {
    

    //Initialize variables
    private Tile[] tiles;


    /*
     * Initialize a tile array
     * uses Tile class' pickup() method and assign to the index of tile array
     */
    public Scrabble(){
        tiles = new Tile[7];

        for (int i=0 ; i < tiles.length ; i++){
            tiles[i] = new Tile();
            tiles[i].pickup();

        }

    }


    /*
     * Sets the argument into the tile array
     * @param tileValues
     */
    public Scrabble(Tile[] tileValues){
        this.tiles = tileValues;
    }

        
    /*
     * Returns all the values of tiles object as string
     * @return String
     */
    public String getLetters(){
        return  ""+tiles[0].getValue() + tiles[1].getValue() +tiles[2].getValue() +tiles[3].getValue() +tiles[4].getValue() +tiles[5].getValue() +tiles[6].getValue();
    }


    /*
     * Reads through the given file, and find words that the current tile array values can make and then added to the ArrayList<String> variable
     * @return ArrayList<String>
     */
    public ArrayList<String> getWords() throws IOException{

        ArrayList<String> wordsList = new ArrayList<String>();
        try (BufferedReader wordFile = new BufferedReader(new FileReader("CollinsScrabbleWords2019.txt"))) {
            String currentFileLine;
            while ((currentFileLine = wordFile.readLine()) != null){
                //Uses getLetters method to return the tiles array into a string and then its turned into a char array
                //Since currentFileLine is already a string, it just needed to be turn into a char array
                char[] charArray = getLetters().toCharArray();
                char[] testCharArray = currentFileLine.toCharArray();
                //counter to keep track of matching letter
                int wordMatchcounter = 0;
                // Checks each char in both arrays and see if they are matching. If true, char will turn into different placeholder char
                //Since all the words in the wordFile and the Scrabble tiles are uppercased, I used lowercase letters as placeholder
                for (int i = 0; i < testCharArray.length; i++){
                    for (int j = 0; j < charArray.length; j++){
                        if (testCharArray[i] == charArray[j]) {
                            charArray[j] =  (char) 'a';
                            testCharArray[i] = (char) 'b';
                            wordMatchcounter++;
                        }
                    }
                }
                //checks if the matching letters equals the whole currentFileLine and if yes, it will be added into the Arraylist<String>
                if (wordMatchcounter == testCharArray.length){
                    wordsList.add(currentFileLine);
                }
            }
            //closes file
            wordFile.close();
        }
        return wordsList;
        
    }


    /*
     * It creates an array equal to the size of the words added at the wordList from getWords() method
     * Uses a private method (located the the bottom of the class)
     * private method returns an integer and then appended into the wordScoreList index of the word in wordList
     * It is later then sorted from least to greated using Arrays.sort() method
     * @return int[]
     */
    public int[] getScores() throws IOException{
        int[] wordScoreList = new int [getWords().size()];
        for (int i = 0; i < getWords().size(); i++){
            wordScoreList[i] = letterFrequencyCounter(getWords().get(i));
        }
        Arrays.sort(wordScoreList);
        return wordScoreList;
    }


    /*
     * This method checks if both Scrabble values are the same
     * My logic is that, if both Scrabble objects are the same, that means their scores should be equals aswell
     * This method sees if both scores are the same. Since both scores will be sorted, it just needs to see if both integers matches
     * @param otherScrabble
     * @return Boolean
     */
    public Boolean equals(Scrabble otherScrabble) throws IOException{
        return Arrays.equals(this.getScores(), otherScrabble.getScores());
        
    }


    /*
     * Private helper method
     * @parm givenWord
     * @return int
     */
    private int letterFrequencyCounter(String givenWord){
        //Keep tracks of the word values
        int scoreCounter = 0;
        //intialize a char array and the size == the lenght of the word
        char [] charArray = new char[givenWord.length()];
        //Turns each letter of the string into a char and then put into charArray
        for (int i = 0; i < givenWord.length(); i++){
            charArray[i] = givenWord.charAt(i);
        }
        //For each index in the charArray, each char will go through each statements and if they match a letter, counter goes up by that letter's value
        for (int i = 0; i < charArray.length ; i++){
            
            if (charArray[i] == 'A' || charArray[i] == 'E' || charArray[i] == 'I' || charArray[i] == 'L' || charArray[i] == 'N' ||  charArray[i] == 'R' || charArray[i] == 'U' || charArray[i] == 'O' || charArray[i] == 'S' || charArray[i] == 'T'){
                scoreCounter++;
            }
            else if (charArray[i] == 'D' || charArray[i] == 'G'){
                scoreCounter = scoreCounter +2;
            }
            else if (charArray[i] == 'B' || charArray[i] == 'C' || charArray[i] == 'M' || charArray[i] == 'P'){
                scoreCounter = scoreCounter +3;
            }
            else if (charArray[i] == 'F' || charArray[i] == 'H' || charArray[i] == 'V' || charArray[i] == 'Y' || charArray[i] == 'W'){
                scoreCounter = scoreCounter +4;
            }
            else if (charArray[i] == 'K'){
                scoreCounter = scoreCounter +5;
            }
            else if (charArray[i] == 'J' || charArray[i] == 'X' ){
                scoreCounter = scoreCounter +8;
            }
            else if (charArray[i] == 'Q' || charArray[i] == 'Z' ){
                scoreCounter = scoreCounter + 10;
            }
        }
        return scoreCounter;
    }
}

