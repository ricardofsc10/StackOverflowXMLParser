package engine;

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

    public void setModel(Model model){
        this.m = model;
    }

    public void setView(View view){
        this.v = view;
    }


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
                        before = System.currentTimeMillis();
                        par = m.infoFromPost(id);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 1: -> "+(after-before)+" ms");
                        log.writeLog("Query1 -> " + par);
                        v.imprime_pair(par,1);
                        break;

                case 2: tamanho = v.insere_tamanho(2);
                        before = System.currentTimeMillis();
                        list = m.topMostActive(tamanho);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 2 -> "+(after-before)+" ms");
                        log.writeLog("Query 2 -> "+list);
                        v.imprime_list(list,2);
                        break;

                case 3: inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        before = System.currentTimeMillis();
                        par = m.totalPosts(inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 3 -> "+(after-before)+" ms");
                        log.writeLog("Query 3 -> "+par);
                        v.imprime_pair(par,3);
                        break;

                case 4: tag = v.insere_string(4);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        before = System.currentTimeMillis();
                        list = m.questionsWithTag(tag,inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 4 -> " + (after - before) + " ms");
                        log.writeLog("Query 4 -> " + list);
                        v.imprime_list(list,4);
                        break;

                case 5: id = v.insere_ID(5);
                        before = System.currentTimeMillis();
                        par = m.getUserInfo(id);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 5 -> "+(after-before)+" ms");
                        log.writeLog("Query 5 -> "+par);
                        v.imprime_pair(par,5);
                        break;

                case 6: tamanho = v.insere_tamanho(6);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        before = System.currentTimeMillis();
                        list = m.mostVotedAnswers(tamanho, inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query6 -> " + (after - before) + " ms");
                        log.writeLog("Query6 -> " + list);
                        v.imprime_list(list,6);
                        break;

                case 7: tamanho = v.insere_tamanho(7);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        before = System.currentTimeMillis();
                        list = m.mostAnsweredQuestions(tamanho,inicio,fim);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 7 -> "+(after-before)+" ms");
                        log.writeLog("Query 7 -> "+list);
                        v.imprime_list(list,7);
                        break;

                case 8: tamanho = v.insere_tamanho(8);
                        palavra = v.insere_string(8);
                        before = System.currentTimeMillis();
                        list = m.containsWord(tamanho,palavra);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query 8 -> " + (after - before) + " ms");
                        log.writeLog("Query 8 -> " + list);
                        v.imprime_list(list,8);
                        break;

                case 9: tamanho = v.insere_tamanho(9);
                        id1 = v.insere_ID(9);
                        id2 = v.insere_ID(9);
                        before = System.currentTimeMillis();
                        list = m.bothParticipated(tamanho,id1,id2);
                        after = System.currentTimeMillis();
                        logtime.writeLog("Query9 -> " + (after - before) + " ms");
                        log.writeLog("Query 9 -> " + list);
                        v.imprime_list(list,9);
                        break;

                case 10: id = v.insere_ID(10);
                         before = System.currentTimeMillis();
                         res= m.betterAnswer(id);
                         after = System.currentTimeMillis();
                         logtime.writeLog("Query 10 -> "+(after-before)+" ms");
                         log.writeLog("Query 10 -> "+res);
                         v.imprime_long(res);
                         break;

                case 11: tamanho = v.insere_tamanho(11);
                         inicio = v.insere_data(0);
                         fim = v.insere_data(1);
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
