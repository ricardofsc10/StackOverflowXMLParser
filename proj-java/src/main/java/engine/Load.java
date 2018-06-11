package engine;

import common.*;
import org.xml.sax.SAXException;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;
import java.time.LocalDate;
import java.io.FileInputStream;

import javax.xml.namespace.QName;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.EndElement;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;

public class Load{
    
    public static void getReferenceUser (XMLEventReader xmlEventReader, TCD_community com) throws XMLStreamException{ // por causa do nextEvent

            int j=0;

            while(xmlEventReader.hasNext()){
               XMLEvent xmlEvent = xmlEventReader.nextEvent();
               if (xmlEvent.isStartElement()){
                   StartElement startElement = xmlEvent.asStartElement();
                   if(startElement.getName().getLocalPart().equals("row")){
                       Utilizador user = new Utilizador();

                       //Get the 'id' attribute from Utilizador element
                       Attribute id_l = startElement.getAttributeByName(new QName("Id"));
                       if(id_l != null){
                         user.set_key_id(Long.parseLong(id_l.getValue()));
                       }

                       Attribute nome_l = startElement.getAttributeByName(new QName("DisplayName"));
                       if(nome_l != null){
                         user.set_nome(nome_l.getValue());
                       }

                       Attribute bio_l = startElement.getAttributeByName(new QName("AboutMe"));
                       if(bio_l != null){
                         user.set_bio(bio_l.getValue());
                       }

                       Attribute reputacao_l = startElement.getAttributeByName(new QName("Reputation"));
                       if(reputacao_l != null){
                         user.set_reputacao(Long.parseLong(reputacao_l.getValue()));
                       }

                       com.set_utilizador(user.get_key_id(), user);
                       j++;
                   }
               }
               //if Utilizador end element is reached, add utilizador object to list
               if(xmlEvent.isEndElement()){
                   EndElement endElement = xmlEvent.asEndElement();
               }
            }

        System.out.println(j + " Users ...");
    }

    public static void getReferencePosts (XMLEventReader xmlEventReader, TCD_community com) throws XMLStreamException{ // por causa do nextEvent

            Integer j=0;
            Long key_id_post = null, post_type_id = null, score = null, owner_user_id = null, comment_count = null, parent_id = null, answer_count = null;
            String data_string = "", body = "", title = "";
            LocalDate data = null;
            ArrayList<String> tags = null;
            Map<Long,Utilizador> utilizadores = com.get_utilizador();

            while(xmlEventReader.hasNext()){
               XMLEvent xmlEvent = xmlEventReader.nextEvent();
               if (xmlEvent.isStartElement()){
                   StartElement startElement = xmlEvent.asStartElement();
                   if(startElement.getName().getLocalPart().equals("row")){
                       Posts post = null;

                       //Get the 'id' attribute from Utilizador element
                       Attribute id_l = startElement.getAttributeByName(new QName("Id"));
                       if(id_l != null){
                        key_id_post = Long.parseLong(id_l.getValue());
                       }

                       Attribute post_type_id_l = startElement.getAttributeByName(new QName("PostTypeId"));
                       if(post_type_id_l != null){
                         post_type_id = Long.parseLong(post_type_id_l.getValue());
                       }

                       Attribute data_string_l = startElement.getAttributeByName(new QName("CreationDate"));
                       if(data_string_l != null){
                         data_string = data_string_l.getValue();
                       }

                       Attribute data_l = startElement.getAttributeByName(new QName("CreationDate"));
                       if(data_l != null){
                         data = Funcoes.stringToDias(data_l.getValue()); // LocalDate
                       }

                       Attribute score_l = startElement.getAttributeByName(new QName("Score"));
                       if(score_l != null){
                        score = Long.parseLong(score_l.getValue());
                       }

                       Attribute body_l = startElement.getAttributeByName(new QName("Body"));
                       if(body_l != null){
                         body = body_l.getValue();
                       }

                       Attribute owner_user_id_l = startElement.getAttributeByName(new QName("OwnerUserId"));
                       if(owner_user_id_l != null){
                         owner_user_id = Long.parseLong(owner_user_id_l.getValue());
                       }

                       Attribute comment_count_l = startElement.getAttributeByName(new QName("CommentCount"));
                       if(comment_count_l != null){
                         comment_count = Long.parseLong(comment_count_l.getValue());
                       }

                       Utilizador user = utilizadores.get(owner_user_id);
                       user.set_posts_u(user.get_posts_u()+1);

                       if(post_type_id == 1){

                           Attribute title_l = startElement.getAttributeByName(new QName("Title"));
                           if(title_l != null){
                             title = title_l.getValue();
                           }

                           Attribute tags_l = startElement.getAttributeByName(new QName("Tags"));
                           if(tags_l != null){
                             tags = Funcoes.strToTag(tags_l.getValue());
                           }

                           Attribute answer_count_l = startElement.getAttributeByName(new QName("AnswerCount"));
                           if(answer_count_l != null){
                             answer_count = Long.parseLong(answer_count_l.getValue());
                           }

                           post = new Post_pergunta(key_id_post,data,data_string,score,owner_user_id,body,post_type_id, comment_count,title,tags,answer_count);
                           com.set_posts_toUser(post);
                       }

                       if(post_type_id == 2){

                           Attribute parent_id_l = startElement.getAttributeByName(new QName("ParentId"));
                           if(parent_id_l != null){
                             parent_id = Long.parseLong(parent_id_l.getValue());
                           }

                           post = new Post_resposta(key_id_post,data,data_string,score,owner_user_id,body,post_type_id, comment_count,parent_id);
                           com.set_posts_toUser(post);
                       }
                       if(post!=null) {
                           com.set_posts(post.get_key_id_post(), post);
                           j++;
                       }
                   }
               }

               //if Posts end element is reached, add utilizador object to list
               if(xmlEvent.isEndElement()){
                   EndElement endElement = xmlEvent.asEndElement();
               }

        }
        System.out.println(j + " Posts ...");
    }



    public static void getReferenceTags (XMLEventReader xmlEventReader, TCD_community com) throws XMLStreamException{ // por causa do nextEvent

            int j=0;

            while(xmlEventReader.hasNext()){
               XMLEvent xmlEvent = xmlEventReader.nextEvent();
               if (xmlEvent.isStartElement()){
                   StartElement startElement = xmlEvent.asStartElement();
                   if(startElement.getName().getLocalPart().equals("row")){
                       Tag tag = new Tag();

                       //Get the 'id' attribute from Utilizador element
                       Attribute tag_name_l = startElement.getAttributeByName(new QName("TagName"));
                       if(tag_name_l != null){
                         tag.set_key_tag_name(tag_name_l.getValue());
                       }

                       Attribute id_tag_l = startElement.getAttributeByName(new QName("Id"));
                       if(id_tag_l != null){
                         tag.setid_tag(Long.parseLong(id_tag_l.getValue()));
                       }
                       com.set_tag(tag.get_key_tag_name(), tag);
                       j++;
                   }
               }
               //if Utilizador end element is reached, add utilizador object to list
               if(xmlEvent.isEndElement()){
                   EndElement endElement = xmlEvent.asEndElement();
               }
            }

        System.out.println(j + " Tags ...");
    }

    public static TCD_community load(TCD_community com, String dump_path)throws ParserConfigurationException,
            SAXException, IOException {

        XMLInputFactory xmlInputFactory = XMLInputFactory.newInstance();
        
        try{
            XMLEventReader xmlEventReader_Users = xmlInputFactory.createXMLEventReader(new FileInputStream(dump_path + "/Users.xml"));
            getReferenceUser(xmlEventReader_Users, com);
        } catch (FileNotFoundException | XMLStreamException e) {
            e.getMessage();
        }

        try{
            XMLEventReader xmlEventReader_Posts = xmlInputFactory.createXMLEventReader(new FileInputStream(dump_path + "/Posts.xml"));
            getReferencePosts(xmlEventReader_Posts, com);
        } catch (FileNotFoundException | XMLStreamException e) {
            e.getMessage();
        }

        try{
            XMLEventReader xmlEventReader_Tags = xmlInputFactory.createXMLEventReader(new FileInputStream(dump_path + "/Tags.xml"));
            getReferenceTags(xmlEventReader_Tags, com);
        } catch (FileNotFoundException | XMLStreamException e) {
            e.getMessage();
        }

        return com;
    }

}
