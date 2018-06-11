package common;

/**
 * Classe Post_pergunta que define as propriedades do Post_pergunta.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.time.LocalDate;
import java.util.ArrayList;

public class Post_pergunta extends Posts{
    private String title;
    private ArrayList<String> tags;
    private long answer_count;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de Post_pergunta.
     */
    public Post_pergunta(){
        super();
        this.title = "";
        this.tags = new ArrayList<>();
        this.answer_count = 0;
    }

    /**
     * Construtor parametrizado de Post_pergunta.
     *
     * @param key Chave/Id do Post_pergunta
     * @param data Data(LocalDate) do Post_pergunta
     * @param score Score do Post_pergunta
     * @param owner_user Utilizador que fez o Post_pergunta
     * @param body Respetivo Post_pergunta
     * @param post_type Tipo do Post_pergunta
     * @param comment_count Contador de comentários do Post_pergunta
     * @param title Título do Post_pergunta
     * @param tags Tags do Post_pergunta
     * @param answer_count Contador de respostas do Post_pergunta
     */
    public Post_pergunta(long key, LocalDate data, long score, long owner_user, String body, long post_type,
                         long comment_count, String title, ArrayList<String> tags, long answer_count){
        super(key,data,score,owner_user,body,post_type,comment_count);
        this.title = title;
        this.tags = tags;
        this.answer_count = answer_count;
    }

    /**
     * Construtor de cópia de Post_pergunta.
     *
     * @param pergunta Novo Post_pergunta
     */
    public Post_pergunta(Post_pergunta pergunta){
        super(pergunta.get_key_id_post(), pergunta.get_data(), pergunta.get_score(),
              pergunta.get_owner_user_id(), pergunta.get_body(), pergunta.get_post_type_id(), pergunta.get_comment_count());
        this.title = pergunta.get_title();
        this.tags = pergunta.get_tags();
        this.answer_count = pergunta.get_answer_count();
    }
    
    ////////////////////// Gets
    /**
     * Método que devolve o Título do Post.
     *
     * @return Título do Post.
     */
    public String get_title(){return this.title;}

    /**
     * Método que devolve as Tags do Post.
     *
     * @return Tags do Post.
     */
    public ArrayList<String> get_tags(){ // acho que nao é preciso fazer isto tudo uma vez que sao strings
        ArrayList<String> res = new ArrayList<>();
        for(String t: this.tags) 
            res.add(t); // nao se pode fazer clone de long acho
        return res;
    }

    /**
     * Método que devolve o Contador de respostas do Post.
     *
     * @return Contador de respostas do Post.
     */
    public long get_answer_count(){return this.answer_count;}
    
    ////////////////////// Sets
    /**
     * Atualiza o Título do Post_pergunta.
     *
     * @param title Novo Título do Post_pergunta
     */
    public void set_title(String title){this.title = title;}

    /**
     * Atualiza as Tags do Post_pergunta.
     *
     * @param tag Nova Tag do Post_pergunta
     */
    public void set_tags(String tag){this.tags.add(tag);}

    /**
     * Atualiza o Contador de respostas do Post_pergunta.
     *
     * @param count Novo Contador de respostas do Post_pergunta
     */
    public void set_answer_count(long count){this.answer_count = count;}
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de um Post_pergunta.
     *
     * @return Objeto do tipo Post_pergunta.
     */
    public Post_pergunta clone(){return new Post_pergunta(this);}

    /**
     * Implementação do método de igualdade entre dois Post's_pergunta.
     *
     * @param o Post_pergunta que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Post_pergunta p = (Post_pergunta) o; 
        return (super.equals(p)
                && this.title.equals(p.get_title())
                && this.tags.equals(p.get_tags())
                && this.answer_count == p.get_answer_count());
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Post_pergunta.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        super.toString();
        sb.append(", Titlo: "); sb.append(this.title);
        sb.append(", Tags: "); sb.append(this.tags);
        sb.append(", Nº de respostas: "); sb.append(this.answer_count);
        return sb.toString();
    }
}
