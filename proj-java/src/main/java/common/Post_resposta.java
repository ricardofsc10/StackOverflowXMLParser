
/**
 * Escreva a descrição da classe Post_resposta aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import java.time.LocalDate;
import java.util.ArrayList;

public class Post_resposta extends Posts{
    private long parent_id;
    
    ////////////////////// Construtores
    // construtor vazio
    public Post_resposta(){
        super();
        this.parent_id = 0;
    }
    
    //construtor parametrizado
    public Post_resposta(long key, LocalDate data, String data_string, long score, long owner_user, String body, long post_type,
                         long comment_count, long parent){
        super(key,data,data_string,score,owner_user,body,post_type,comment_count);
        this.parent_id = parent;
    }
    
    // construtor de cópia
    public Post_resposta(Post_resposta resposta){
        super(resposta.get_key_id_post(), resposta.get_data(), resposta.get_data_string(), resposta.get_score(),
              resposta.get_owner_user_id(), resposta.get_body(), resposta.get_post_type_id(), resposta.get_comment_count());
        this.parent_id = resposta.get_parent_id();
    }
    
    ////////////////////// Gets
    public long get_parent_id(){return this.parent_id;}
    
    ////////////////////// Sets
    public void set_parent_id(long id){this.parent_id = id;}
    
    ////////////////////// Métodos essenciais
    public Post_resposta clone(){return new Post_resposta(this);}
    
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Post_resposta p = (Post_resposta) o; 
        return (super.equals(p)
                && this.parent_id == p.get_parent_id());
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        super.toString();
        sb.append(", ID da pergunta a que se responde: "); sb.append(this.parent_id);;
        return sb.toString();
    }
}