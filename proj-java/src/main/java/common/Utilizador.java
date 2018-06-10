package common;

import java.util.List;
import java.util.ArrayList;

public class Utilizador{
    private long key_id;
    private String nome;
    private String bio;
    private ArrayList<Long> posts_frequentados; // so contem o id das perguntas em que ele interage
    private ArrayList<Posts> posts_perguntas; // contem os todas as perguntas que colocou em forma de POSTS
    private long posts_u;
    private long reputacao;
    
    ////////////////////// Construtores
    // construtor vazio
    public Utilizador(){
        this.key_id = 0;
        this.nome = "";
        this.bio = "";
        this.posts_frequentados = new ArrayList<>();
        this.posts_perguntas = new ArrayList<>();
        this.posts_u = 0;
        this.reputacao = 0;
    }
    
    // construtor parametrizado
    public Utilizador(long key, String nome, String bio, ArrayList<Long> posts_freq, ArrayList<Posts> posts_per, long posts, long reputacao){
        this.key_id = key;
        this.nome = nome;
        this.bio = bio;
        this.posts_frequentados = posts_freq; // nao sei se é assim
        
        this.posts_perguntas = new ArrayList<>();
        for(Posts p : posts_per){
            this.posts_perguntas.add(p.clone());
        }
        
        this.posts_u = posts;
        this.reputacao = reputacao;
    }
    
    // construtor de cópia
    public Utilizador(Utilizador umutilizador){
        this.key_id = umutilizador.get_key_id();
        this.nome = umutilizador.get_nome();
        this.bio = umutilizador.get_bio();
        this.posts_frequentados = umutilizador.get_posts_frequentados();
        this.posts_perguntas = umutilizador.get_posts_perguntas();
        this.posts_u = umutilizador.get_posts_u();
        this.reputacao = umutilizador.get_reputacao();
    }
    
    ////////////////////// Gets
    public long get_key_id(){return this.key_id;}
    
    public String get_nome(){return this.nome;}
    
    public String get_bio(){return this.bio;}
    
    public ArrayList<Long> get_posts_frequentados(){
        ArrayList<Long> res = new ArrayList<>();
        for(Long l: this.posts_frequentados) 
            res.add(l); // nao se pode fazer clone de long acho
        return res;
    }
    
    public ArrayList<Posts> get_posts_perguntas(){
        ArrayList<Posts> res = new ArrayList<>();
        for(Posts p: this.posts_perguntas) 
            res.add(p.clone());
        return res;
    }
    
    public long get_posts_u(){return this.posts_u;}
    
    public long get_reputacao(){return this.reputacao;}
    
    ////////////////////// Sets
    public void set_key_id(long id){this.key_id = id;}
    
    public void set_nome(String nome){this.nome = nome;}
    
    public void set_bio(String bio){this.bio = bio;}
    
    public void set_posts_frequentados(long id_post){
        if(!this.posts_frequentados.contains(id_post))
            this.posts_frequentados.add(id_post);
    }
    
    public void set_posts_perguntas(Posts p){this.posts_perguntas.add(p.clone());}
    
    public void set_posts_u(long posts){this.posts_u = posts;}
    
    public void set_reputacao(long reputacao){this.reputacao = reputacao;}
    
    ////////////////////// Métodos essenciais
    public Utilizador clone(){return new Utilizador(this);}
    
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Utilizador u = (Utilizador) o; 
        return (this.key_id == u.get_key_id()
                && this.nome.equals(u.get_nome()) 
                && this.bio.equals(u.get_bio())
                && this.posts_frequentados.equals(u.get_posts_frequentados()) 
                && this.posts_perguntas.equals(u.get_posts_perguntas()) 
                && this.posts_u == u.get_posts_u()
                && this.reputacao == u.get_reputacao());
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("ID: "); sb.append(this.key_id);
        sb.append(", Nome: "); sb.append(this.nome);
        sb.append(", Biografia: "); sb.append(this.bio);
        sb.append(", ID de posts frequentados: "); sb.append(this.posts_frequentados); // já nao sei se se faz assim para arraylist
        sb.append(", Posts das perguntas colocadas: "); sb.append(this.posts_perguntas); // já nao sei se se faz assim para arraylist
        sb.append(", Número de posts: "); sb.append(this.posts_u);
        sb.append(", Reputação: "); sb.append(this.reputacao);
        return sb.toString();
    }
}
