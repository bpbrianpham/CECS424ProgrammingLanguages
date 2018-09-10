import java.io.File;

/*
Code doesnt work. but Regex is used to string adjust
*/
public class RegExBasic{
    public static void main (String [] args){
        File dir = new File("To_determine_which_file_you_want");

        //modify this to fit whatever file format you are listing to
        String regex = "\\d{5,6}-\\d{6}\\s-\\s" +
            "([a-zA-Z\\s]+)" + "\\s-\\s" +
            "[a-zA-Z\\d\\s,]+" + "\\s-\\s" +
            "(.+)";
        
        //replaces string to new string
        for (File f : dir.listFiles()){
            String oldName = f.getName();
            //$1 -> from first parenthesis in the regex
            //$2 -> to the next parenthesis in the regex
            String newName = oldName.replaceAll(regex, "$1 : $2");
            System.out.println(newName);
        }
    }
}