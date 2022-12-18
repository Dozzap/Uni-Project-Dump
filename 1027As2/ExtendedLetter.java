/**
 * Decribes the ExtendedLetter, the subclass of Letter
 */
public class ExtendedLetter extends Letter{
    /**
     * sets up variable
     */
    private String content;
    private int family;
    private boolean related;
    private int SINGLETON = -1;
    
    /**
     * sets up the defailt value of for fam if there is no value of fam provided
     * @param s
     */
    public ExtendedLetter(String s){
        super('c');
        content = s;
        related = false;
        family = SINGLETON;
    }
    /**
     * sets up both s and fam
     * @param s
     * @param fam
     */
    public ExtendedLetter(String s, int fam){
        super('c');
        content = s;
        related = false;
        family = fam;
    }
    /**
     * This method determines if two ExtendedLetters are the same and also changes the related variable accordingly
     * @return true or false
     */
    public boolean equals(Object other){
        if (other instanceof ExtendedLetter){
            if (this.family == ((ExtendedLetter)other).family){
                related = true;
            }
            return (this.content == ((ExtendedLetter)other).content);
        }
        return false;
    }
    /***
     * This method declares the string print for ExtendedLetter instances
     * @return String
     */
    public String toString(){
        if (isUnused() == true && this.related == true){
            return "." + this.content + ".";
        }
        else{
            return decorator() + this.content + decorator();
        }
    }
    /**
     * Creates an array of letter object of the same size
     * @param content
     * @param codes
     * @return arrLetter an array of letter instances
     */
    public static Letter[] fromStrings(String[] content,int[] codes){
        Letter [] arrayLetter = new Letter[content.length];
        for (int i = 0; i <arrayLetter.length; i++){
            if (codes == null){
                arrayLetter[i] = new ExtendedLetter(content[i]);
            }
            else{
                arrayLetter[i] = new ExtendedLetter(content[i], codes[i]);
            }
        }
        return arrayLetter;
    }

}