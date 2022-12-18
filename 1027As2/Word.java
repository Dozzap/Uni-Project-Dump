public class Word {
    private LinearNode<Letter> firstLetter;

    public Word(Letter[] letters){
        LinearNode<Letter> temp;
         

        this.firstLetter = new LinearNode<Letter>(letters[0]);
        LinearNode<Letter> headObject = this.firstLetter;

        for (int i = 1; i <letters.length; i++){
            temp = new LinearNode<Letter>(letters[i]);

            headObject.setNext(temp);

            headObject = headObject.getNext();
        }

    }


    public String toString(){
        String returnString = "Word: ";

        LinearNode <Letter> tempIterator = this.firstLetter;

        while(tempIterator != null){

            returnString+= tempIterator.getElement().toString() + " ";

            tempIterator = tempIterator.getNext();


        }

        return returnString;

    }

    //Checks and labels each value of the guessWord
    //Has two statements, one where both words are them same, and the other where it checks for each
    public boolean labelWord(Word mystery){
        LinearNode<Letter> mysteryWord = mystery.firstLetter;
        LinearNode<Letter> guessWord = this.firstLetter;
        
        //if both words' toString are equal. for example mysteryWord = "Word: O B J E C T" and guessWord = "Word: O B J E C T" are both the same, this statement will be true.
        if (mysteryWord.toString().equals(guessWord.toString())){
            //Since both words are equal in both value and position, only 1 loop is needed, and each values will be set to correct.  will return true aswell
            while (mysteryWord != null){
                guessWord.getElement().setCorrect();
                guessWord = guessWord.getNext();
                mysteryWord= mysteryWord.getNext();
            }
            return true;
        }

        /* 2nd statement where the guessWord and mysteryWord are not the same, both in order and value. Will iterate from mysteryWord then guessWord, and see if some values of
        *guessWord are used in the mysteryWord
        *
        *this will return false
        */
        else{
            /* this nested loop will get the first letter of guessWord then set it to null and get the firstLetter of mysteryWord.
             * the letter from guessWord is then checked to a value of mysteryWord, if its used, the label will be changed to used. and will test for the next letter.
             * it will then go to the next letter
             * this loop will continue until there is no more letters in guessWord;
             */
            while (guessWord != null){
                guessWord.getElement().setUnused();
            mysteryWord = mystery.firstLetter;
            while (mysteryWord != null){
                
                if (guessWord.getElement().equals(mysteryWord.getElement())){
                guessWord.getElement().setUsed();
                mysteryWord = mysteryWord.getNext();
                    }
                else{mysteryWord = mysteryWord.getNext();}
            }
            guessWord = guessWord.getNext();
            }
        //this will check if the letter of the guessWord is in the right and in the same order as the letter from mysteryWord and sets the letters to correct
            guessWord= this.firstLetter;
            mysteryWord = mystery.firstLetter;

            while(mysteryWord != null && guessWord != null){
                if (guessWord.getElement().equals(mysteryWord.getElement())){
                    guessWord.getElement().setCorrect();
                }
                guessWord = guessWord.getNext();
                mysteryWord = mysteryWord.getNext();
            }
        }
        return false;
    }
}
