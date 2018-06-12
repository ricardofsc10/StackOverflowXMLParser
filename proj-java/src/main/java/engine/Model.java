package engine;

/**
 * Classe Model que define a camada computacional que contém os dados e os algoritmos para o seu processamento.
 *
 * @author Grupo21
 * @version 20180610
 */

import common.*;
import li3.TADCommunity;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.time.LocalDate;
import java.util.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.Comparator;
import java.lang.String;

public class Model implements TADCommunity {

    private TCD_community com;

    /**
     * Função que faz a primeira inicialização da estrutura.
     *
     *
     * @returns Estrutura TAD_community inicializada.
     */
    public void init(){
        this.com = new TCD_community();
    }

    /**
     * Função que inicializa a estrutura TCD_community e invoca a função load da classe Load.
     */
    public void load(String dumpPath) throws IOException, SAXException, ParserConfigurationException { // temos que ter em atenção a tratar os erros
        init();
        this.com = Load.load(this.com, dumpPath);
    }

    // Query 1

    /**
     * Função que dado o identificador de um post, retorna o título do post e o nome de utilizador do autor.
     * Se o post for uma resposta, a função retorna informações (título e utilizador) da pergunta correspondente.
     *
     * @param id Parâmetro de comparação.
     *
     * @returns Par com informação do post.
     */
    public Pair<String,String> infoFromPost(long id) throws PostInexistenteException{
        Map<Long,Posts> todos_posts = this.com.get_posts();
        if(todos_posts.containsKey(id)){
            Posts post = todos_posts.get(id);
            Map<Long,Utilizador> utilizadores = this.com.get_utilizador();
            if(post instanceof Post_pergunta){
                Post_pergunta pergunta = (Post_pergunta) post;
                Long owner = pergunta.get_owner_user_id();
                return new Pair(pergunta.get_title(), utilizadores.get(owner).get_nome());
            }
            else{
                Post_resposta resposta = (Post_resposta) post;
                Post_pergunta pergunta = (Post_pergunta) todos_posts.get(resposta.get_parent_id());
                Long owner = pergunta.get_owner_user_id();
                return new Pair(pergunta.get_title(), utilizadores.get(owner).get_nome());
            }
        }
        else throw new PostInexistenteException();
    }

    // Query 2
    /**
     * Classe que implementa um Comparator que compara o posts_u de cada utilizador.
     */
    public class ComparatorPosts implements Comparator<Utilizador>{
        public int compare(Utilizador u1, Utilizador u2) {
            if(u1.get_posts_u() > u2.get_posts_u()) return -1;
            else return 1;
        }
    }

    /**
     * Função que devolve o top N utilizadores com maior número de posts de sempre.
     * São considerados tanto perguntas quanto respostas dadas pelo respectivo utilizador.
     *
     * @param N Tamanho do top.
     *
     * @returns Lista com o top correspondente.
     */
    public List<Long> topMostActive(int N) {
        Set<Utilizador> ativos = new TreeSet<>(new ComparatorPosts());

        for (Utilizador u : this.com.get_utilizador().values())
            ativos.add(u.clone());

        List<Long> res = new ArrayList<>();
        Iterator it = ativos.iterator();
        int i=0;
        while(it.hasNext() && i<N) {
            Utilizador u = (Utilizador) it.next();
            res.add(u.get_key_id());
            i++;
        }
        return res;
    }

    // Query 3

    /**
     * Função que dado um intervalo de tempo arbitrário, obtem o número total de posts
     * (identificando perguntas e respostas separadamente) neste período.
     *
     * @param begin Data do ínicio da comparação.
     * @param end Data do fim da comparação.
     *
     * @returns Lista com o total de posts no período correspondente.
     */
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        long perguntas=0,respostas=0;
        for (Posts p : this.com.get_posts().values()){
            if ((p.get_data().isAfter(begin) || p.get_data().isEqual(begin)) && (p.get_data().isBefore(end) || p.get_data().isEqual(end))) {
                if (p instanceof Post_pergunta)
                    perguntas++;
                else if(p instanceof  Post_resposta)
                    respostas++;
             }
        }
        return new Pair(perguntas,respostas);
    }

    // Query 4
    /**
     * Classe que implementa um Comparator que compara a data de cada Post_pergunta.
     */
    public class ComparatorData implements Comparator<Post_pergunta>{
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_data().isBefore(p2.get_data()))return 1;
            else return -1;
        }
    }

    /**
     * Função que dado um intervalo de tempo arbitrário, devolve todas as perguntas que contêm
     * uma determinada tag.
     *
     * @param tag Tag a procurar.
     * @param begin Início do intervalo de tempo.
     * @param end Fim do intervalo de tempo.
     *
     * @returns Retorna uma lista com os IDs das perguntas ordenadas em cronologia inversa.
     */
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
        Set<Post_pergunta> aux = new TreeSet<>(new ComparatorData());
        for(Posts p : this.com.get_posts().values()){
            if(p instanceof Post_pergunta){
                Post_pergunta post = (Post_pergunta) p;
                if((post.get_data().isAfter(begin) || post.get_data().isEqual(begin)) && (post.get_data().isBefore(end) || post.get_data().isEqual(end))) {
                    List<String> tags = post.get_tags();
                    if (tags.contains(tag))
                        aux.add(post.clone());
                }
            }
        }
        List<Long> res = new ArrayList<>();
        Iterator it = aux.iterator();
        while(it.hasNext()) {
            Post_pergunta p = (Post_pergunta) it.next();
            res.add(p.get_key_id_post());
        }
        return res;
    }

    // Query 5
    /**
     * Classe que implementa um Comparator que compara o get_posts_u de cada utilizador.
     */
    public class ComparatorData5 implements Comparator<Posts>{
        public int compare(Posts p1, Posts p2){
            if(p1.get_data().isBefore(p2.get_data()))return 1;
            else return -1;
        }
    }

    /**
     * Função que dado um ID de utilizador, devolver a informação do seu perfil (short bio)
     * e os IDs dos seus 10 últimos posts (perguntas ou respostas), ordenados por cronologia inversa.
     *
     * @param id Parâmetro de comparação.
     *
     * @returns Utilizador com informação pedida.
     */
    public Pair<String, List<Long>> getUserInfo(long id) throws UtilizadorInexistenteException{

        Set<Posts> ids = new TreeSet<>(new ComparatorData5());

        for(Posts p : this.com.get_posts().values()){
            if(p.get_owner_user_id() == id)
                ids.add(p.clone());
        }

        List<Long> res = new ArrayList<>();
        Iterator it = ids.iterator();
        int i=0;
        while(it.hasNext() && i<10) {
            Posts p = (Posts) it.next();
            res.add(p.get_key_id_post());
            i++;
        }

        Utilizador user = this.com.get_utilizador().get(id);
        if(user == null) throw new UtilizadorInexistenteException();
        return new Pair(user.get_bio(),res);
    }

    // Query 6
    /**
     * Classe que implementa um Comparator que compara o score de cada Post_resposta.
     */
    public class ComparatorScore implements Comparator<Post_resposta>{
        public int compare(Post_resposta p1, Post_resposta p2){
            if(p1.get_score() > p2.get_score()) return -1;
            else return 1;
        }
    }

    /**
     * Função que dado um intervalo de tempo arbitrário, devolve os IDs das N respostas com mais votos,
     * em ordem decrescente do número de votos.
     *
     * @param N Número de respostas pedidas.
     * @param begin Data do ínicio da comparação.
     * @param end Data do fim da comparação.
     *
     * @returns Lista com os IDs.
     */
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {
        Set<Post_resposta> posts = new TreeSet<>(new ComparatorScore());
        for(Posts p : this.com.get_posts().values()){
            if (p instanceof Post_resposta) {
                Post_resposta post = (Post_resposta) p;
                if ((post.get_data().isAfter(begin) || post.get_data().isEqual(begin)) && (post.get_data().isBefore(end) || post.get_data().isEqual(end))) {
                    posts.add(post.clone());
                }
            }
        }
        List<Long> res = new ArrayList<>();
        Iterator it = posts.iterator();
        int i=0;
        while(it.hasNext() && i<N) {
            Post_resposta p = (Post_resposta) it.next();
            res.add(p.get_key_id_post());
            i++;
        }
        return res;
    }

    // Query 7
    /**
     * Classe que implementa um Comparator que compara o answer_count de cada Post_pergunta.
     */
    public class ComparatorAnswer implements Comparator<Post_pergunta>{
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_answer_count() > p2.get_answer_count()) return -1;
            else return 1;
        }
    }

    /**
     * Função que dado um intervalo de tempo arbitrário, devolve as IDs das N perguntas com mais respostas,
     * em ordem decrescente do número de respostas.
     *
     * @param N Número de respostas pedidas.
     * @param begin Data do ínicio da comparação.
     * @param end Data do fim da comparação.
     *
     * @returns Lista com os IDs.
     */
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
        Set<Post_pergunta> posts = new TreeSet<>(new ComparatorAnswer());
        for(Posts p : this.com.get_posts().values()) {
            if (p instanceof Post_pergunta) {
                Post_pergunta post = (Post_pergunta) p;
                if ((post.get_data().isAfter(begin) || post.get_data().isEqual(begin)) && (post.get_data().isBefore(end) || post.get_data().isEqual(end))) {
                    posts.add(post.clone());
                }
            }
        }
        List<Long> res = new ArrayList<>();
        Iterator it = posts.iterator();
        int i=0;
        while(it.hasNext() && i<N) {
            Post_pergunta p = (Post_pergunta) it.next();
            res.add(p.get_key_id_post());
            i++;
        }
        return res;
    }


    // Query 8
    /**
     * Função que dado uma palavra devolve uma lista com os IDs de N perguntas cujos títulos a contenham,
     * ordenados por cronologia inversa.
     *
     * @param word Parâmetro de comparação.
     * @param N Número de perguntas pedidas.
     *
     * @returns Lista com os IDs.
     */
    public List<Long> containsWord(int N, String word) {
        Set<Post_pergunta> aux = new TreeSet<>(new ComparatorData());
        for(Posts p : this.com.get_posts().values()){
            if(p instanceof Post_pergunta){
                Post_pergunta post = (Post_pergunta) p;
                if (post.get_title().contains(word))
                    aux.add(post.clone());
            }
        }
        List<Long> res = new ArrayList<>();
        Iterator it = aux.iterator();
        int i=0;
        while(it.hasNext() && i<N) {
            Post_pergunta p = (Post_pergunta) it.next();
            res.add(p.get_key_id_post());
            i++;
        }
        return res;
    }

    // Query 9
    /**
     * Função que dados os IDs de dois utilizadores, devolve as últimas
     * N perguntas, em cronologia inversa, em que participaram os dois utilizadores específicos
     *
     * @param id1 Parâmetro de comparação.
     * @param id2 Parâmetro de comparação.
     * @param N Número de perguntas pedidas.
     *
     * @returns Lista com os IDs das perguntas em que ambos participam.
     */
    public List<Long> bothParticipated(int N, long id1, long id2) throws UtilizadorInexistenteException{
        Map<Long,Utilizador> utilizadores = this.com.get_utilizador();
        if(utilizadores.containsKey(id1) && utilizadores.containsKey(id2)){
            Utilizador user_id1 = utilizadores.get(id1);
            List<Long> posts_id1 = user_id1.get_posts_frequentados();
            Utilizador user_id2 = utilizadores.get(id2);
            List<Long> posts_id2 = user_id2.get_posts_frequentados();

            Map<Long,Posts> posts = this.com.get_posts();

            List<Long> iguais = new ArrayList<>();
            for(long id : posts_id1)
                if(posts_id2.contains(id)) iguais.add(id);

            Set<Post_pergunta> ordenado = new TreeSet<>(new ComparatorData());
            for(Long id : iguais){
                Post_pergunta p = (Post_pergunta) posts.get(id);
                ordenado.add(p.clone());
            }

            List<Long> res = new ArrayList<>();
            Iterator it = ordenado.iterator();
            int i=0;
            while(it.hasNext() && i<N) {
                Post_pergunta p = (Post_pergunta) it.next();
                res.add(p.get_key_id_post());
                i++;
            }
            return res;
        }
        else throw new UtilizadorInexistenteException();
    }

    // Query 10

    /**
     * Função que dado o ID de uma pergunta, obtém a melhor resposta segundo uma média dada por:
     * (Scr × 0.45) + (Rep × 0.25) + (Vot × 0.2) + (Comt × 0.1) .
     *
     * @param id Parâmetro de comparação.
     *
     * @returns Id da melhor resposta.
     */
    public long betterAnswer(long id) throws PostInexistenteException{
        Map<Long,Posts> todos_posts = this.com.get_posts();
        if(todos_posts.containsKey(id)){
            Posts post = todos_posts.get(id);
            if(post instanceof Post_pergunta){
                double melhor_media = 0;
                long melhor_id = 0;
                Map<Long,Utilizador> utilizadores = this.com.get_utilizador();
                for(Posts posts : todos_posts.values()){
                    if(posts instanceof Post_resposta){
                        Post_resposta resposta = (Post_resposta) posts;
                        Utilizador user = utilizadores.get(resposta.get_owner_user_id());
                        if(resposta.get_parent_id() == id){
                            double media = (0.65 * resposta.get_score()) + (0.25 * user.get_reputacao()) + (0.1 * resposta.get_comment_count());
                            if(media > melhor_media){
                                melhor_media = media;
                                melhor_id = resposta.get_key_id_post();
                            }
                        }
                    }
                }
                return melhor_id;
            }
            else return -1;
        }
        else throw new PostInexistenteException();
    }

    // Query 11
    /**
     * Classe que implementa um Comparator que compara as ocorrencias de cada tag em TagUnique.
     */
    public class ComparatorOcorrencias implements Comparator<TagUnique>{
        public int compare(TagUnique tu1, TagUnique tu2){
            if(tu1.getOcorrencias() > tu2.getOcorrencias()) return -1;
            else return 1;
        }
    }

    /**
     * Classe que implementa um Comparator que compara o reputação de cada utilizador.
     */
    public class ComparatorReputacao implements  Comparator<Utilizador>{
        public int compare(Utilizador u1, Utilizador u2){
            if(u1.get_reputacao() > u2.get_reputacao()) return  -1;
            else return 1;
        }
    }

    /**
     * Função que dado um inteiro N e um intervalo de tempo arbitrário devolve uma lista com
     * as N tags mais usadas pelos N utilizadores com melhor reputação.
     *
     * @param N Número de tags e utilizadores.
     * @param begin Data inicial.
     * @param end Data final.
     *
     * @returns Lista com as N tags mais usadas.
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
        Map<Long,Utilizador> utilizadores = this.com.get_utilizador();
        Set<Utilizador> melhor_reputacao = new TreeSet<>(new ComparatorReputacao());
        for(Utilizador u : utilizadores.values()) melhor_reputacao.add(u);

        Map<String,TagUnique> todas_tags = new HashMap<>();

        Iterator it1 = melhor_reputacao.iterator();
        int i=0;
        while(it1.hasNext() && i<N) {
            Utilizador user = (Utilizador) it1.next();
            for(Post_pergunta post : user.get_posts_perguntas()){
                if((post.get_data().isAfter(begin) || post.get_data().isEqual(begin)) && (post.get_data().isBefore(end) || post.get_data().isEqual(end))) {
                    for (String tag : post.get_tags()){
                        if (todas_tags.containsKey(tag)) {
                            TagUnique tu = todas_tags.get(tag);
                            tu.setOcorrencias((tu.getOcorrencias()) + 1);
                        } else {
                            TagUnique tu = new TagUnique(tag, 1);
                            todas_tags.put(tag, tu);
                        }
                    }
                }
            }
            i++;
        }

        Set<TagUnique> ordenado = new TreeSet<>(new ComparatorOcorrencias());
        for(TagUnique tu : todas_tags.values())
            ordenado.add(tu);

        Map<String,Tag> tags = this.com.get_tag();
        List<Long> res = new ArrayList<>();

        Iterator it = ordenado.iterator();
        i=0;
        while(it.hasNext() && i < N) {
            TagUnique tu = (TagUnique) it.next();
            res.add(tags.get(tu.getNome()).get_id_tag());
            i++;
        }
        return res;
    }

    /**
     * Função que limpa a estrutura toda com auxílio do GarbageCollection.
     *
     */
    public void clear(){
        this.com.clearTCD();
        this.com = null;
        System.gc();
    }
}
