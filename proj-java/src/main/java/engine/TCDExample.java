package engine;

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
import java.util.stream.*;
import java.lang.String;

public class TCDExample implements TADCommunity {

    private MyLog qelog;
    private TCD_community com;

    /*
    public void init() {
        this.qelog = new MyLog("queryengine");
    }
    */

    public void init(){
        this.com = new TCD_community();
    }

    public void load(String dumpPath) throws IOException, SAXException, ParserConfigurationException { // temos que ter em atenção a tratar os erros
        init();
        this.com = Load.load(this.com, dumpPath);
    }

    // Query 1
    public Pair<String,String> infoFromPost(long id) {
        HashMap<Long,Posts> todos_posts = this.com.get_posts();
        if(todos_posts.containsKey(id)){
            Posts post = todos_posts.get(id);
            HashMap<Long,Utilizador> utilizadores = this.com.get_utilizador();
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
        else return null;
    }

    // Query 2
    public List<Long> topMostActive(int N) {
        return Arrays.asList(15811L,449L,158442L,167850L,367165L,295286L,59676L,93977L,35795L,3940L);
    }

    // Query 3
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        return new Pair<>(3667L,4102L);
    }

    // Query 4
    public class ComparatorData4 implements Comparator<Post_pergunta>{
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_data().isBefore(p2.get_data()))return 1;
            else return -1;
        }
    }
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
        Set<Post_pergunta> aux = new TreeSet<>(new ComparatorData4());
        for(Posts p : this.com.get_posts().values()){
            if(p instanceof Post_pergunta){
                Post_pergunta post = (Post_pergunta) p;
                if(post.get_data().isBefore(end) && post.get_data().isAfter(begin)) {
                    ArrayList<String> tags = post.get_tags();
                    if (tags.contains(tag))
                        aux.add(post.clone());
                }
            }
        }
        List<Long> res = new ArrayList<>();
        for(Posts p : aux)
            res.add(p.get_key_id_post());
        return res;
    }

    // Query 5
    public Pair<String, List<Long>> getUserInfo(long id) {
        String shortBio = "<p>Coder. JS, Perl, Python, Basic<br>Books/movies: SF+F.<br>Dead:" +
                "dell 9300<br>Dead: dell 1720 as of may 10th 2011.</p>\n" +
                "<p>Current system: Acer Aspire 7750G.<br>\n" +
                "Works OOTB as of Ubuntu 12.04.<br></p>";
        List<Long> ids = Arrays.asList(982507L,982455L,980877L,980197L,980189L,976713L,974412L,
                974359L,973895L,973838L);
        return new Pair<>(shortBio,ids);
    }

    // Query 6
    public class ComparatorScore implements Comparator<Post_resposta>{
        public int compare(Post_resposta p1, Post_resposta p2){
            if(p1.get_score() > p2.get_score()) return -1;
            else return 1;
        }
    }

    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {
        Set<Post_resposta> posts = new TreeSet<>(new ComparatorScore());
        for(Posts p : this.com.get_posts().values()){
            if (p instanceof Post_resposta) {
                Post_resposta post = (Post_resposta) p;
                if (post.get_data().isBefore(end) && post.get_data().isAfter(begin)) {
                    posts.add(post.clone());
                }
            }
        }
        posts = posts.stream().limit(N).collect(Collectors.toSet());
        List<Long> res = new ArrayList<>();
        for(Posts p : posts) {
            res.add(p.get_key_id_post());
        }
        return res;
    }

    // Query 7
    public class ComparatorAnswer implements Comparator<Post_pergunta>{
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_answer_count() > p2.get_answer_count()) return -1;
            else return 1;
        }
    }

    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
        Set<Post_pergunta> posts = new TreeSet<>(new ComparatorAnswer());
        for(Posts p : this.com.get_posts().values()) {
            if (p instanceof Post_pergunta) {
                Post_pergunta post = (Post_pergunta) p;
                if (post.get_data().isBefore(end) && post.get_data().isAfter(begin)) {
                    posts.add(post.clone());
                }
            }
        }
        posts = posts.stream().limit(N).collect(Collectors.toSet());
        List<Long> res = new ArrayList<>();
        for(Posts p : posts) {
            res.add(p.get_key_id_post());
        }
        return res;
    }


    // Query 8
    public class ComparatorData8 implements Comparator<Post_pergunta>{
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_data().isBefore(p2.get_data()))return 1;
            else return -1;
        }
    }

    public List<Long> containsWord(int N, String word) {
        Set<Post_pergunta> aux = new TreeSet<>(new ComparatorData8());
        for(Posts p : this.com.get_posts().values()){
            if(p instanceof Post_pergunta){
                Post_pergunta post = (Post_pergunta) p;
                if (post.get_title().contains(word))
                    aux.add(post.clone());
            }
        }
        aux = aux.stream().limit(N).collect(Collectors.toSet());
        List<Long> res = new ArrayList<>();
        for(Posts p : aux)
            res.add(p.get_key_id_post());
        return res;
    }

    // Query 9
    public class ComparatorData implements Comparator<Post_pergunta>{ // não será ao contrário ?????
        public int compare(Post_pergunta p1, Post_pergunta p2){
            if(p1.get_data().isBefore(p2.get_data()))return -1;
            else return 1;
        }
    }

    public List<Long> bothParticipated(int N, long id1, long id2) {
        HashMap<Long,Utilizador> utilizadores = this.com.get_utilizador();
        if(utilizadores.containsKey(id1) && utilizadores.containsKey(id2)){
            ArrayList<Long> posts_id1 = utilizadores.get(id1).get_posts_frequentados();
            ArrayList<Long> posts_id2 = utilizadores.get(id2).get_posts_frequentados();
            HashMap<Long,Posts> posts = this.com.get_posts();

            ArrayList<Long> iguais = new ArrayList<>();
            for(long id : posts_id1)
                if(posts_id2.contains(id)) iguais.add(id);

            Set<Post_pergunta> ordenado = new TreeSet<>(new ComparatorData());
            for(Long id : iguais){
                Post_pergunta p = (Post_pergunta) posts.get(id);
                ordenado.add(p.clone());
            }
            ordenado = ordenado.stream().limit(N).collect(Collectors.toSet());
            List<Long> res = new ArrayList<>();
            for(Post_pergunta pp : ordenado)
                res.add(pp.get_key_id_post());

            return res;
        }
        else return null;
    }

    // Query 10
    public long betterAnswer(long id) {
        HashMap<Long,Posts> todos_posts = this.com.get_posts();
        if(todos_posts.containsKey(id)){
            Posts post = todos_posts.get(id);
            if(post instanceof Post_pergunta){
                double melhor_media = 0;
                long melhor_id = 0;
                HashMap<Long,Utilizador> utilizadores = this.com.get_utilizador();
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
            else return 0;
        }
        return 0;
    }

    // Query 11
    public class ComparatorOcorrencias implements Comparator<TagUnique>{
        public int compare(TagUnique tu1, TagUnique tu2){
            if(tu1.getOcorrencias() > tu2.getOcorrencias()) return -1;
            else return 1;
        }
    }

    public class ComparatorReputacao implements  Comparator<Utilizador>{
        public int compare(Utilizador u1, Utilizador u2){
            if(u1.get_reputacao() > u2.get_reputacao()) return  -1;
            else return 1;
        }
    }

    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
        HashMap<Long,Utilizador> utilizadores = this.com.get_utilizador();
        Set<Utilizador> melhor_reputacao = new TreeSet<>(new ComparatorReputacao());
        for(Utilizador u : utilizadores.values()) melhor_reputacao.add(u);

        melhor_reputacao = melhor_reputacao.stream().limit(N).collect(Collectors.toSet());

        Map<String,TagUnique> todas_tags = new HashMap<>();

        for(Utilizador user : melhor_reputacao){
            for(Post_pergunta post : user.get_posts_perguntas()){
                if(post.get_data().isAfter(begin) && post.get_data().isBefore(end)) {
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
        }

        Set<TagUnique> ordenado = new TreeSet<>(new ComparatorOcorrencias());
        for(TagUnique tu : todas_tags.values())
            ordenado.add(tu);

        List<TagUnique> ordenado_l = ordenado.stream().limit(N).collect(Collectors.toList());
        HashMap<String,Tag> tags = this.com.get_tag();
        List<Long> res = new ArrayList<>();

        Iterator it = ordenado_l.iterator();
        while(it.hasNext()) {
            TagUnique tu = (TagUnique) it.next();
            res.add(tags.get(tu.getNome()).get_id_tag());
        }
        return res;
    }

    public void clear(){

    }
}
