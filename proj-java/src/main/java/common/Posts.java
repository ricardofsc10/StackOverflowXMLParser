package common;

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
    // construtor vazio
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
    
    // construtor parametrizado
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
    
    // contrutor de cópia
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
    public long get_key_id_post(){return this.key_id_post;}
    
    public LocalDate get_data(){return this.data;}
    
    public String get_data_string(){return this.data_string;}
    
    public long get_score(){return this.score;}
    
    public long get_owner_user_id(){return this.owner_user_id;}
    
    public String get_body(){return this.body;}
    
    public long get_post_type_id(){return this.post_type_id;}
    
    public long get_comment_count(){return this.comment_count;}
    
    ////////////////////// Sets
    public void set_key_id_post(long id){this.key_id_post = id;}
    
    public void set_data(LocalDate d){this.data = d;}
    
    public void set_data_string(String data){this.data_string = data;}
    
    public void set_score(long score){this.score = score;}
    
    public void set_owner_user_id(long id){this.owner_user_id = id;}
    
    public void set_body(String body){this.body = body;}
    
    public void set_post_type_id(long type){this.post_type_id = type;}
    
    public void set_comment_count(long count){this.comment_count = count;}
    
    ////////////////////// Métodos essenciais
    public Posts clone(){return new Posts(this);}
    
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
