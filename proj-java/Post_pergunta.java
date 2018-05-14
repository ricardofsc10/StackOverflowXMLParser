/**
 * Escreva a descrição da classe Post_pergunta aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import java.time.LocalDate;
import java.util.ArrayList;

public class Post_pergunta extends Posts{
    private String title;
    private ArrayList<String> tags;
    private long answer_count;
    
    ////////////////////// Construtores
    // construtor vazio
    public Post_pergunta(){
        super();
        this.title = "";
        this.tags = new ArrayList<>();
        this.answer_count = 0;
    }
    
    // construtor parametrizado
    public Post_pergunta(long key, LocalDate data, String data_string, long score, long owner_user, String body, long post_type,
                         long comment_count, String title, ArrayList<String> tags, long answer_count){
        super(key,data,data_string,score,owner_user,body,post_type,comment_count);
        this.title = title;
        this.tags = tags;
        this.answer_count = answer_count;
    }
    
    // construtor de cópia
    public Post_pergunta(Post_pergunta pergunta){
        super(pergunta.get_key_id_post(), pergunta.get_data(), pergunta.get_data_string(), pergunta.get_score(),
              pergunta.get_owner_user_id(), pergunta.get_body(), pergunta.get_post_type_id(), pergunta.get_comment_count());
        this.title = pergunta.get_title();
        this.tags = pergunta.get_tags();
        this.answer_count = pergunta.get_answer_count();
    }
    
    ////////////////////// Gets
    public String get_title(){return this.title;}
    
    public ArrayList<String> get_tags(){ // acho que nao é preciso fazer isto tudo uma vez que sao strings
        ArrayList<String> res = new ArrayList<>();
        for(String t: this.tags) 
            res.add(t); // nao se pode fazer clone de long acho
        return res;
    }
    
    public long get_answer_count(){return this.answer_count;}
    
    ////////////////////// Sets
    public void set_title(String title){this.title = title;}
    
    public void set_tags(String tag){this.tags.add(tag);}
    
    public void set_answer_count(long count){this.answer_count = count;}
    
    ////////////////////// Métodos essenciais
    public Post_pergunta clone(){return new Post_pergunta(this);}
    
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Post_pergunta p = (Post_pergunta) o; 
        return (super.equals(p)
                && this.title.equals(p.get_title())
                && this.tags.equals(p.get_tags())
                && this.answer_count == p.get_answer_count());
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        super.toString();
        sb.append(", Titlo: "); sb.append(this.title);
        sb.append(", Tags: "); sb.append(this.tags);
        sb.append(", Nº de respostas: "); sb.append(this.answer_count);
        return sb.toString();
    }
}
