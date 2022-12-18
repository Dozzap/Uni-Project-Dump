/*
 * CS 1027 Computer Science Fundamentals II
 * Tile class
 * 
 */

 //import java.util.Random for future use
import java.util.Random;


public class Tile {
    

    private char value;
    

    //intializes a default value
    public Tile(){
        value = ' ';
    }


    //intializes value to the given argument
    //@param letter
    public Tile(char letter){
        this.value = letter;
    }


    //Uses java.util.Random to pick up a random Letter from variable alphabet;
    public void pickup(){
        String alphabet = "ABCDHIJKLMNIOPQRSTUVWXYZ";
 
        Random r = new Random();
        value = alphabet.charAt(r.nextInt(alphabet.length()));
    }

    
    // returns value 
    //@return char
    public char getValue(){
        return value;
    }
}
