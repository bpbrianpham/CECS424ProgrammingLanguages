import java.io.File;
import java.util.*;

public class assn2{
    public static void main(String [] args){
        try{
            String value = "";
            String regex = "^\\$(\\*)*(\\d{0,2}(,\\d{3})*|0).\\d\\d";
            System.out.println("Starting Java Program Type to Check RegEx\n");
            //File file = new File("C:\\Users\\Brian Pham\\Desktop\\CSULB\\CECS 424 - Programming Languages\\Assignments\\A2\\a2_input.txt");
            File file = new File(args[0]);
            Scanner sc = new Scanner(file);
            while(sc.hasNext()){
                value = sc.next();
                if(value.matches(regex)){
                    System.out.println(value + " is a valid money format.");
                }
                else {
                    System.out.println(value + " is an invalid money format.");
                }
                //ToDo: start verifying printing is only temporary
            }

            sc.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}