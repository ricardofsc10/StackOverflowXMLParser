package common;

/**
 * Classe TCD_community que define as propriedades do TCD_community.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class TCD_community{
    private HashMap<Long,Utilizador> utilizador;
    private HashMap<Long,Posts> posts;
    private ArrayList<Posts> date_posts;
    private HashMap<String,Tag> tag;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de TCD_community.
     */
    public TCD_community(){
        this.utilizador = new HashMap<>();
        this.posts = new HashMap<>();
        this.date_posts = new ArrayList<>();
        this.tag = new HashMap<>();
    }

    /**
     * Construtor parametrizado de TCD_community.
     *
     * @param utilizador Estrutura Utilizador
     * @param posts Estrutura Posts
     * @param date_posts Estrutura Date_posts
     * @param tag Estrutura Tag
     */
    public TCD_community(HashMap<Long,Utilizador> utilizador, HashMap<Long,Posts> posts, ArrayList<Posts> date_posts,
                         HashMap<String,Tag> tag){
        // para o hashmap de utilizador
        this.utilizador = new HashMap<>();
        for(Long l : utilizador.keySet()){
            Utilizador u = utilizador.get(l);
            this.utilizador.put(l,u.clone());
        }
        
        // para o hashmap de posts
        this.posts = new HashMap<>();
        for(Long l : posts.keySet()){
            Posts p = posts.get(l);
            this.posts.put(l,p.clone());
        }
        
        // pata o ArrayList date_posts
        this.date_posts = new ArrayList<>();
        for(Posts p : date_posts){
            this.date_posts.add(p.clone());
        }
        
        // para o hashmap de tags
        this.tag = new HashMap<>();
        for(String s : tag.keySet()){
            Tag t = tag.get(s);
            this.tag.put(s,t.clone());
        }
    }

    /**
     * Construtor de cópia de TCDCommunity.
     *
     * @param umatcd Nova TCDCommunity
     */
    public TCD_community(TCD_community umatcd){
        this.utilizador = umatcd.get_utilizador();
        this.posts = umatcd.get_posts();
        this.date_posts = umatcd.get_date_posts();
        this.tag = umatcd.get_tag();
    }
    
    ////////////////////// Gets
    /**
     * Método que devolve a estrutura Utilizador.
     *
     * @return Estrutura Utilizador.
     */
    public HashMap<Long,Utilizador> get_utilizador(){
        HashMap<Long,Utilizador> res = new HashMap<>();
        for(Long l : this.utilizador.keySet()){
            Utilizador u = this.utilizador.get(l);
            res.put(l,u.clone());
        }
        return res;
    }

    /**
     * Método que devolve a estrutura Posts.
     *
     * @return Estrutura Posts.
     */
    public HashMap<Long,Posts> get_posts(){
        HashMap<Long,Posts> res = new HashMap<>();
        for(Long l : this.posts.keySet()){
            Posts p = this.posts.get(l);
            res.put(l,p.clone());
        }
        return res;
    }

    /**
     * Método que devolve a estrutura Posts(ordenado por datas).
     *
     * @return Estrutura Posts(ordenado por datas).
     */
    public ArrayList<Posts> get_date_posts(){
        ArrayList<Posts> res = new ArrayList<>();
        for(Posts p : this.date_posts){
            res.add(p.clone());
        }
        return res;
    }

    /**
     * Método que devolve a estrutura Tags.
     *
     * @return Estrutura Tags.
     */
    public HashMap<String,Tag> get_tag(){
        HashMap<String,Tag> res = new HashMap<>();
        for(String s : this.tag.keySet()){
            Tag t = this.tag.get(s);
            res.put(s,t.clone());
        }
        return res;
    }
    
    ////////////////////// Sets
    /**
     * Atualiza a Estrutura Utilizador.
     *
     * @param key Nova chave da Estrutura Utilizador
     * @param value Novo valor da Estrutura Utilizador
     */
    public void set_utilizador(long key, Utilizador value){ this.utilizador.put(key,value.clone()); }

    /**
     * Atualiza a Estrutura Posts.
     *
     * @param key Nova chave da Estrutura Posts
     * @param value Novo valor da Estrutura Posts
     */
    public void set_posts(long key, Posts value){
	this.posts.put(key,value.clone());
    }

    /**
     * Atualiza a Estrutura Posts(organizados por data).
     *
     * @param key Nova chave da Estrutura Posts(organizados por data)
     * @param value Novo valor da Estrutura Posts(organizados por data)
     */
    public void set_date_posts(Posts value){
        this.date_posts.add(value.clone());
    }

    /**
     * Atualiza a Estrutura Tag.
     *
     * @param key Nova chave da Estrutura Tag
     * @param value Novo valor da Estrutura Tag
     */
    public void set_tag(String key, Tag value){
	this.tag.put(key,value.clone());
    }

    /**
     * Atualiza o Número de Posts e Posts_pergunta em que o Utilizador interage, tendo em conta o Post passado como parâmetro.
     *
     * @param post Post relacionado
     */
    public void set_posts_toUser(Posts post){
        if(post instanceof Post_pergunta) {
            Post_pergunta pergunta = (Post_pergunta) post;
            Utilizador user = this.utilizador.get(post.get_owner_user_id());
            user.set_posts_frequentados(pergunta.get_key_id_post());
            user.set_posts_perguntas(pergunta);
        }
        else{
            Post_resposta resposta = (Post_resposta) post;
            Utilizador user = this.utilizador.get(post.get_owner_user_id());
            user.set_posts_frequentados(resposta.get_parent_id());
        }
    }

    /**
     * Atualiza o Número de posts do Utilizador, tendo em conta o Post passado como parâmetro.
     *
     * @param p Post relacionado
     */
    public void set_posts_total(Posts p){
        Utilizador user = this.utilizador.get(p.get_owner_user_id());
        user.set_posts_u(user.get_posts_u() + 1);
    }
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem da TCD_community.
     *
     * @return Objeto do tipo TCD_community.
     */
    public TCD_community clone(){return new TCD_community(this);}

    /**
     * Implementação do método de igualdade entre dois TCD's_community.
     *
     * @param o TCD_community que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if(this == o) return true;
        if ((o == null) || (this.getClass() != o.getClass())) return false;
        TCD_community tcd = (TCD_community) o;
        return (this.utilizador.equals(tcd.get_utilizador())
                && this.posts.equals(tcd.get_posts())
                && this.date_posts.equals(tcd.get_date_posts())
                && this.tag.equals(tcd.get_tag()));
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto TCD_community.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Utilizadores: "); sb.append(this.utilizador);
        sb.append(", Posts: "); sb.append(this.posts);
        sb.append(", Posts ordenados: "); sb.append(this.date_posts);
        sb.append(", Tags: "); sb.append(this.tag);
        return sb.toString();
    }
}
