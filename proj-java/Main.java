
/**
 * Escreva a descrição da classe Main aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import org.xml.sax.SAXException;

public class Main{
    public static void main(){

        TCD_community com = new TCD_community();
        System.out.println("Estrutura inicializada ...");


        String path = "../../dumpexemplo/android";
        try{
            com = Load.load(com, path);
        }
        catch(ParserConfigurationException e){System.out.println("Parser " + e.getMessage());}
        catch(SAXException e){System.out.println("SAX " + e.getMessage());}
        catch(IOException e){System.out.println("IO " + e.getMessage());}
        catch(Exception e){System.out.println("Exception " + e.getMessage());}
        
        System.out.println("Terminado ...");
        
    }
}
