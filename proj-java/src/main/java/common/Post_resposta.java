package common;

/**
 * Classe Post_resposta que define as propriedades do Post_resposta.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;

public class Post_resposta extends Posts{
    private long parent_id;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de Post_resposta.
     */
    public Post_resposta(){
        super();
        this.parent_id = 0;
    }

    /**
     * Construtor parametrizado de Post_resposta.
     *
     * @param key Chave/Id do Post_resposta
     * @param data Data(LocalDate) do Post_resposta
     * @param score Score do Post_resposta
     * @param owner_user Utilizador que fez o Post_resposta
     * @param body Respetivo Post_resposta
     * @param post_type Tipo do Post_resposta
     * @param comment_count Contador de comentários do Post_resposta
     * @param parent Pergunta a qual o Post_resposta responde
     */
    public Post_resposta(long key, LocalDate data, long score, long owner_user, String body, long post_type,
                         long comment_count, long parent){
        super(key,data,score,owner_user,body,post_type,comment_count);
        this.parent_id = parent;
    }

    /**
     * Construtor de cópia de Post_resposta.
     *
     * @param resposta Novo Post_resposta
     */
    public Post_resposta(Post_resposta resposta){
        super(resposta.get_key_id_post(), resposta.get_data(), resposta.get_score(),
              resposta.get_owner_user_id(), resposta.get_body(), resposta.get_post_type_id(), resposta.get_comment_count());
        this.parent_id = resposta.get_parent_id();
    }
    
    ////////////////////// Gets
    /**
     * Método que devolve o Pergunta a qual o Post responde.
     *
     * @return Pergunta a qual o Post responde.
     */
    public long get_parent_id(){return this.parent_id;}
    
    ////////////////////// Sets
    /**
     * Atualiza a Pergunta a qual o Post_resposta responde.
     *
     * @param id Nova Pergunta a qual o Post_resposta responde
     */
    public void set_parent_id(long id){this.parent_id = id;}
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de um Post_resposta.
     *
     * @return Objeto do tipo Post_resposta.
     */
    public Post_resposta clone(){return new Post_resposta(this);}

    /**
     * Implementação do método de igualdade entre dois Post's_resposta.
     *
     * @param o Post_resposta que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Post_resposta p = (Post_resposta) o; 
        return (super.equals(p)
                && this.parent_id == p.get_parent_id());
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Post_resposta.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        super.toString();
        sb.append(", ID da pergunta a que se responde: "); sb.append(this.parent_id);;
        return sb.toString();
    }
}