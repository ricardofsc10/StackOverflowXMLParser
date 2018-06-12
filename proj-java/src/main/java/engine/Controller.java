package engine;

/**
 * Classe Controller que define a camada fundamental de controlo do fluxo de execução
 * da aplicação, é o mediador entre o model e a view.
 *
 * @author Grupo21
 * @version 20180610
 */

import common.MyLog;
import common.Pair;
import li3.TADCommunity;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.time.LocalDate;
import java.util.List;

public class Controller {
    private TADCommunity m;
    private View v;

    /**
     * Atualiza a Model do Controller.
     *
     * @param model Nova Model do Controller
     */
    public void setModel(Model model){
        this.m = model;
    }

    /**
     * Atualiza a View do Controller.
     *
     * @param view Nova View do Controller
     */
    public void setView(View view){
        this.v = view;
    }

    /**
     * Método que controla o fluxo de todas as queries entre o Model e a View do projeto.
     *
     * @param args Argumentos passados na realização do executável
     */
    public void control_fluxo(String[] args){

        /*
            LOG CONFIGURATION
        */
        MyLog log = new MyLog("results");
        MyLog logtime = new MyLog("times");
        /* -------------------------------------------------------------------------------------------*/

        long before, after;

        /*
            LOAD PHASE
         */
        try {
            before = System.currentTimeMillis();
            m.load(args[0]);
            after = System.currentTimeMillis();
            logtime.writeLog("LOAD -> "+(after-before)+" ms");
        }
        catch(IndexOutOfBoundsException e){
            System.out.println("Deve passar o caminho do dump como argumento.");
        }
        catch(ParserConfigurationException e){
            System.out.println(e.getMessage());
        }
        catch(SAXException e){
            System.out.println(e.getMessage());
        }
        catch(IOException e){
            System.out.println(e.getMessage());
        }

        do{
            int query = v.escolhe_query();
            if(query == -1) break;

            long id,id1,id2,res;
            Pair par = null;
            LocalDate inicio=null,fim=null;
            int tamanho;
            List<Long> list = null;
            String tag,palavra;

            switch(query){
                case 1: id = v.insere_ID(1);
                        if(id == -2) break;
                        before = System.currentTimeMillis();
                        try {
                            par = m.infoFromPost(id);
                        }
                        catch(PostInexistenteException e){
                            v.imprime_erro_post(e);
                            break;
                        }
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 1: -> "+(after-before)+" ms");
                        log.writeLog("Query1 -> " + par);
                        v.imprime_pair(par,1);
                        break;

                case 2: tamanho = v.insere_tamanho(2);
                        if(tamanho == -1) break;
                        before = System.currentTimeMillis();
                        list = m.topMostActive(tamanho);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 2 -> "+(after-before)+" ms");
                        log.writeLog("Query 2 -> "+list);
                        v.imprime_list(list,2);
                        break;

                case 3: inicio = v.insere_data(0);
                        if(inicio == null) break;
                        fim = v.insere_data(1);
                        if(fim == null) break;
                        before = System.currentTimeMillis();
                        par = m.totalPosts(inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 3 -> "+(after-before)+" ms");
                        log.writeLog("Query 3 -> "+par);
                        v.imprime_pair(par,3);
                        break;

                case 4: tag = v.insere_string(4);
                        if(tag == null) break;
                        inicio = v.insere_data(0);
                        if(inicio == null) break;
                        fim = v.insere_data(1);
                        if(fim == null) break;
                        before = System.currentTimeMillis();
                        list = m.questionsWithTag(tag,inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 4 -> " + (after - before) + " ms");
                        log.writeLog("Query 4 -> " + list);
                        v.imprime_list(list,4);
                        break;

                case 5: id = v.insere_ID(5);
                        if(id == -2) break;
                        before = System.currentTimeMillis();
                        try {
                            par = m.getUserInfo(id);
                        }
                        catch(UtilizadorInexistenteException e){
                            v.imprime_erro_user(e);
                            break;
                        }
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 5 -> "+(after-before)+" ms");
                        log.writeLog("Query 5 -> "+par);
                        v.imprime_pair(par,5);
                        break;

                case 6: tamanho = v.insere_tamanho(6);
                        if(tamanho == -1) break;
                        inicio = v.insere_data(0);
                        if(inicio == null) break;
                        fim = v.insere_data(1);
                        if(fim == null) break;
                        before = System.currentTimeMillis();
                        list = m.mostVotedAnswers(tamanho, inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query6 -> " + (after - before) + " ms");
                        log.writeLog("Query6 -> " + list);
                        v.imprime_list(list,6);
                        break;

                case 7: tamanho = v.insere_tamanho(7);
                        if(tamanho == -1) break;
                        inicio = v.insere_data(0);
                        if(inicio == null) break;
                        fim = v.insere_data(1);
                        if(fim == null) break;
                        before = System.currentTimeMillis();
                        list = m.mostAnsweredQuestions(tamanho,inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 7 -> "+(after-before)+" ms");
                        log.writeLog("Query 7 -> "+list);
                        v.imprime_list(list,7);
                        break;

                case 8: tamanho = v.insere_tamanho(8);
                        if(tamanho == -1) break;
                        palavra = v.insere_string(8);
                        if(palavra == null) break;
                        before = System.currentTimeMillis();
                        list = m.containsWord(tamanho,palavra);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 8 -> " + (after - before) + " ms");
                        log.writeLog("Query 8 -> " + list);
                        v.imprime_list(list,8);
                        break;

                case 9: tamanho = v.insere_tamanho(9);
                        if(tamanho == -1) break;
                        id1 = v.insere_ID(9);
                        if(id1 == -2) break;
                        id2 = v.insere_ID(9);
                        if(id2 == -2) break;
                        before = System.currentTimeMillis();
                        try {
                            list = m.bothParticipated(tamanho, id1, id2);
                        }
                        catch (UtilizadorInexistenteException e){
                            v.imprime_erro_user(e);
                            break;
                        }
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query9 -> " + (after - before) + " ms");
                        log.writeLog("Query 9 -> " + list);
                        v.imprime_list(list,9);
                        break;

                case 10: id = v.insere_ID(10);
                         if(id == -2) break;
                         before = System.currentTimeMillis();
                         try {
                             res = m.betterAnswer(id);
                         }
                         catch(PostInexistenteException e){
                            v.imprime_erro_post(e);
                            break;
                         }
                         after = System.currentTimeMillis();
                         logtime.writeLog("Query 10 -> "+(after-before)+" ms");
                         log.writeLog("Query 10 -> "+res);
                         v.imprime_long(res);
                         break;

                case 11: tamanho = v.insere_tamanho(11);
                         if(tamanho == -1) break;
                         inicio = v.insere_data(0);
                         if(inicio == null) break;
                         fim = v.insere_data(1);
                         if(fim == null) break;
                         before = System.currentTimeMillis();
                         list = m.mostUsedBestRep(tamanho,inicio,fim);
                         after = System.currentTimeMillis();
                         logtime.writeLog("Query 11 -> "+(after-before)+" ms");
                         log.writeLog("Query 11 -> "+list);
                         v.imprime_list(list,11);
                         break;
            }

        } while(true);

        before = System.currentTimeMillis();
        m.clear();
        after = System.currentTimeMillis();
        logtime.writeLog("CLEAN -> "+(after-before)+" ms");
    }

}
