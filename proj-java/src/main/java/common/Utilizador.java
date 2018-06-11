package common;

/**
 * Classe Utilizador que define as propriedades do Utilizador.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.util.List;
import java.util.ArrayList;

public class Utilizador{
    private long key_id;
    private String nome;
    private String bio;
    private List<Long> posts_frequentados; // so contem o id das perguntas em que ele interage
    private List<Post_pergunta> posts_perguntas; // contem os todas as perguntas que colocou em forma de POSTS
    private long posts_u;
    private long reputacao;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de Utilizador.
     */
    public Utilizador(){
        this.key_id = 0;
        this.nome = "";
        this.bio = "";
        this.posts_frequentados = new ArrayList<>();
        this.posts_perguntas = new ArrayList<>();
        this.posts_u = 0;
        this.reputacao = 0;
    }

    /**
     * Construtor parametrizado de Utilizador.
     *
     * @param key Chave/Id do Utilizador
     * @param nome Nome do Utilizador
     * @param bio Biografia do Utilizador
     * @param posts_freq Posts em que o Utilizador interage
     * @param posts_per Posts_pergunta em que o Utilizador interage
     * @param posts Número de posts do Utilizador
     * @param reputacao Reputação do Utilizador
     */
    public Utilizador(long key, String nome, String bio, List<Long> posts_freq, List<Post_pergunta> posts_per, long posts, long reputacao){
        this.key_id = key;
        this.nome = nome;
        this.bio = bio;
        this.posts_frequentados = posts_freq; // nao sei se é assim
        
        this.posts_perguntas = new ArrayList<>();
        for(Post_pergunta p : posts_per){
            this.posts_perguntas.add(p.clone());
        }
        
        this.posts_u = posts;
        this.reputacao = reputacao;
    }

    /**
     * Construtor de cópia de Utilizador.
     *
     * @param umutilizador Novo Utilizador
     */
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
    /**
     * Método que devolve o Chave/Id do Utilizador.
     *
     * @return Chave/Id do Utilizador.
     */
    public long get_key_id(){return this.key_id;}

    /**
     * Método que devolve o Nome do Utilizador.
     *
     * @return Nome do Utilizador.
     */
    public String get_nome(){return this.nome;}

    /**
     * Método que devolve o Biografia do Utilizador.
     *
     * @return Biografia do Utilizador.
     */
    public String get_bio(){return this.bio;}

    /**
     * Método que devolve os Posts em que o Utilizador interage.
     *
     * @return Posts em que o Utilizador interage.
     */
    public List<Long> get_posts_frequentados(){
        List<Long> res = new ArrayList<>();
        for(Long l: this.posts_frequentados) 
            res.add(l); // nao se pode fazer clone de long acho
        return res;
    }

    /**
     * Método que devolve os Posts_pergunta em que o Utilizador interage.
     *
     * @return Posts_pergunta em que o Utilizador interage.
     */
    public List<Post_pergunta> get_posts_perguntas(){
        List<Post_pergunta> res = new ArrayList<>();
        for(Post_pergunta p: this.posts_perguntas)
            res.add(p.clone());
        return res;
    }

    /**
     * Método que devolve o Número de posts do Utilizador.
     *
     * @return Número de posts do Utilizador.
     */
    public long get_posts_u(){return this.posts_u;}

    /**
     * Método que devolve o Reputação do Utilizador.
     *
     * @return Reputação do Utilizador.
     */
    public long get_reputacao(){return this.reputacao;}
    
    ////////////////////// Sets
    /**
     * Atualiza a Chave/Id do Utilizador.
     *
     * @param id Nova Chave/Id do Utilizador
     */
    public void set_key_id(long id){this.key_id = id;}

    /**
     * Atualiza o Nome do Utilizador.
     *
     * @param nome Novo Nome do Utilizador
     */
    public void set_nome(String nome){this.nome = nome;}

    /**
     * Atualiza a Biografia do Utilizador.
     *
     * @param bio Nova Biografia do Utilizador
     */
    public void set_bio(String bio){this.bio = bio;}

    /**
     * Atualiza os Posts em que o Utilizador interage.
     *
     * @param id_post Novos Posts em que o Utilizador interage
     */
    public void set_posts_frequentados(long id_post){
        if(!this.posts_frequentados.contains(id_post))
            this.posts_frequentados.add(id_post);
    }

    /**
     * Atualiza os Posts_pergunta em que o Utilizador interage.
     *
     * @param p Novos Posts_pergunta em que o Utilizador interage
     */
    public void set_posts_perguntas(Post_pergunta p){this.posts_perguntas.add(p.clone());}

    /**
     * Atualiza o Número de posts do Utilizador.
     *
     * @param posts Número de posts do Utilizador
     */
    public void set_posts_u(long posts){this.posts_u = posts;}

    /**
     * Atualiza a Reputação do Utilizador.
     *
     * @param reputacao Nova Reputação do Utilizador
     */
    public void set_reputacao(long reputacao){this.reputacao = reputacao;}
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de um Utilizador.
     *
     * @return Objeto do tipo Utilizador.
     */
    public Utilizador clone(){return new Utilizador(this);}

    /**
     * Implementação do método de igualdade entre dois Utilizadores.
     *
     * @param o Utilizador que é comparado com o recetor
     * @return Booleano True ou False.
     */
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

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Utilizador.
     */
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
