
/**
 * Escreva a descrição da classe Load aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class Load{
    
    public static void getReferenceUser (Document doc, NodeList cur, TCD_community com){
        int i,j = 0;
        for (i = 0; i < cur.getLength(); i++) {
               Node node = cur.item(i);

               if (node.getNodeType() == Node.ELEMENT_NODE) {
                    //Element elem = (Element) node;

                    // faz o parse dos parametros necessários
                    Long id_l = Long.parseLong(node.getAttributes().getNamedItem("Id").getNodeValue());
                    String nome_l = node.getAttributes().getNamedItem("DisplayName").getNodeValue();
                    
                    String bio_l;
                    try{
                        bio_l = node.getAttributes().getNamedItem("AboutMe").getNodeValue();
                    }
                    catch(Exception e){ bio_l = "";}
                    
                    Long reputacao_l = Long.parseLong(node.getAttributes().getNamedItem("Reputation").getNodeValue());

                    // preenche os parametros do utilizador
                    Utilizador value_user = new Utilizador();
                    value_user.set_key_id(id_l);
                    value_user.set_nome(nome_l);
                    value_user.set_bio(bio_l);
                    value_user.set_reputacao(reputacao_l);

                    // insere na tabela de hash referente aos utilizadores
                    com.set_utilizador(id_l,value_user);
                    j++;
               }
        }
        System.out.println(j + " Users ...");
    }


    public static TCD_community load(TCD_community com, String dump_path)throws ParserConfigurationException,
        SAXException, IOException{

        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();

        // documento Users.xml
        Document doc_user = builder.parse(new File(dump_path + "/Users.xml"));

        NodeList node_user = doc_user.getDocumentElement().getChildNodes();
        
        getReferenceUser(doc_user, node_user, com);

        return com;
    }

}
