package common;

/**
 * Classe Posts que define as propriedades do Post.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.time.LocalDate;

public class Posts{
    private long key_id_post;
    private LocalDate data;
    private String data_string;
    private long score;
    private long owner_user_id;
    private String body;
    private long post_type_id; // 1-pergunta 2-resposta
    private long comment_count;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de Posts.
     */
    public Posts(){
        this.key_id_post = 0;
        this.data = LocalDate.now();
        this.data_string = "";
        this.score = 0;
        this.owner_user_id = 0;
        this.body = "";
        this.post_type_id = 0;
        this.comment_count = 0;
    }

    /**
     * Construtor parametrizado de Post.
     *
     * @param key Chave/Id do Post
     * @param data Data(LocalDate) do Post
     * @param data_string Data(String) do Post
     * @param score Score do Post
     * @param owner_user Utilizador que fez o Post
     * @param body Corpo do Post
     * @param post_type Tipo do Post
     * @param comment_count Contador de comentários do Post
     */
    public Posts(long key, LocalDate data, String data_string, long score, long owner_user, String body, long post_type,
                 long comment_count){
        this.key_id_post = key;
        this.data = data;
        this.data_string = data_string;
        this.score = score;
        this.owner_user_id = owner_user;
        this.body = body;
        this.post_type_id = post_type;
        this.comment_count = comment_count;
    }

    /**
     * Construtor de cópia de Posts.
     *
     * @param umpost Novo Post
     */
    public Posts(Posts umpost){
        this.key_id_post = umpost.get_key_id_post();
        this.data = umpost.get_data();
        this.data_string = umpost.get_data_string();
        this.score = umpost.get_score();
        this.owner_user_id = umpost.get_owner_user_id();
        this.body = umpost.get_body();
        this.post_type_id = umpost.get_post_type_id();
        this.comment_count = umpost.get_comment_count();
    }
    
    ////////////////////// Gets
    /**
     * Método que devolve o Key/Id do Post.
     *
     * @return Key/Id do Post.
     */
    public long get_key_id_post(){return this.key_id_post;}

    /**
     * Método que devolve a Data(LocalDate) do Post.
     *
     * @return Data(LocalDate) do Post.
     */
    public LocalDate get_data(){return this.data;}

    /**
     * Método que devolve o Data(String) do Post.
     *
     * @return Data(String) do Post.
     */
    public String get_data_string(){return this.data_string;}

    /**
     * Método que devolve o Score do Post.
     *
     * @return Score do Post.
     */
    public long get_score(){return this.score;}

    /**
     * Método que devolve o Id do Owner User do Post.
     *
     * @return Id do Owner User do Post.
     */
    public long get_owner_user_id(){return this.owner_user_id;}

    /**
     * Método que devolve o Corpo do Post.
     *
     * @return Corpo do Post.
     */
    public String get_body(){return this.body;}

    /**
     * Método que devolve o Tipo do Post.
     *
     * @return Tipo do Post.
     */
    public long get_post_type_id(){return this.post_type_id;}

    /**
     * Método que devolve o Contador de Comentários do Post.
     *
     * @return Contador de Comentários do Post.
     */
    public long get_comment_count(){return this.comment_count;}
    
    ////////////////////// Sets
    /**
     * Atualiza a Chave/Id do Post.
     *
     * @param id Nova Chave/Id do Post
     */
    public void set_key_id_post(long id){this.key_id_post = id;}

    /**
     * Atualiza a Data(LocalDate) do Post.
     *
     * @param d Nova Data(LocalDate) do Post
     */
    public void set_data(LocalDate d){this.data = d;}

    /**
     * Atualiza a Data(String) do Post.
     *
     * @param data Nova Data(String) do Post
     */
    public void set_data_string(String data){this.data_string = data;}

    /**
     * Atualiza a Score do Post.
     *
     * @param score Nova Score do Post.
     */
    public void set_score(long score){this.score = score;}

    /**
     * Atualiza o Utilizador que fez o Post.
     *
     * @param id Novo Utilizador que fez o Post
     */
    public void set_owner_user_id(long id){this.owner_user_id = id;}

    /**
     * Atualiza o Corpo do Post.
     *
     * @param body Novo Corpo do Post
     */
    public void set_body(String body){this.body = body;}

    /**
     * Atualiza o Tipo do Post.
     *
     * @param type Novo Tipo do Post
     */
    public void set_post_type_id(long type){this.post_type_id = type;}

    /**
     * Atualiza o Contador de comentários do Post.
     *
     * @param count Novo Contador de comentários do Post
     */
    public void set_comment_count(long count){this.comment_count = count;}
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de um Post.
     *
     * @return Objeto do tipo Posts.
     */
    public Posts clone(){return new Posts(this);}

    /**
     * Implementação do método de igualdade entre dois Posts.
     *
     * @param o Post que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Posts p = (Posts) o; 
        return (this.key_id_post == (p.get_key_id_post())
                && this.data.equals(p.get_data())
                && this.data_string.equals(p.get_data_string())
                && this.score == p.get_score()
                && this.owner_user_id == p.get_owner_user_id()
                && this.body.equals(p.get_body())
                && this.post_type_id == p.get_post_type_id()
                && this.comment_count == p.get_comment_count());
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Posts.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("ID: "); sb.append(this.key_id_post);
        sb.append(", Data: "); sb.append(this.data);
        sb.append(", Data em formato string: "); sb.append(this.data_string);
        sb.append(", Score: "); sb.append(this.score);
        sb.append(", Owner User: "); sb.append(this.owner_user_id);
        sb.append(", Body: "); sb.append(this.body);
        sb.append(", Tipo do post: "); sb.append(this.post_type_id);
        sb.append(", Nº de comentarios: "); sb.append(this.comment_count);
        return sb.toString();
    }
}
