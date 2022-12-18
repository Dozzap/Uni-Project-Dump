
/**
 * Describe word linked list
 * 
 */
public class WordLL {
    //Declares the variables mysteryWord and history
    private Word mysteryWord;
    private LinearNode<Word> history;
    /**
     * constructor for WordLl
     * @param mystery
     */
    public WordLL(Word mystery){
        history = new LinearNode<Word>();
        mysteryWord = mystery;
    }
    /**
     * checks if the letters of guess are in mysteryWord, returns a boolean
     * updates the history linked list
     * @param guess
     * @return true or false
     */
    public boolean tryWord(Word guess){
        guess.labelWord(mysteryWord);
        LinearNode<Word> guessWord = new LinearNode<Word>();
        guessWord.setElement(guess);

        LinearNode <Word> nextHistory = history.getNext();
        history.setNext(guessWord);
        guessWord.setNext(nextHistory);


        if (guess.labelWord(mysteryWord)){
            return true;
        }
        else{
            return false;
        }

    }
    /**
     * returns a string consists of the values of the history linkedlist
     * @return String
     */
    public String toString(){
        
        String words = "";
        LinearNode <Word> wordHistory = history.getNext();
        while (wordHistory  != null){
            words = words + (wordHistory.getElement()).toString() + '\n';
            wordHistory  = wordHistory.getNext();

        }
        
        return words;
    }
}