package engine;

import common.MyLog;
import common.Pair;
import li3.TADCommunity;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.time.LocalDate;
import java.time.Month;
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

    public void escreve_ficheiros(String[] args){
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

        /*
           Query 1
        */
        before = System.currentTimeMillis();
        Pair<String,String> q1 = m.infoFromPost(796430);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 1: -> "+(after-before)+" ms");
        log.writeLog("Query1 -> " + q1);

        /*
           Query 2
        */
        before = System.currentTimeMillis();
        List<Long> q2 = m.topMostActive(10);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 2 -> "+(after-before)+" ms");
        log.writeLog("Query 2 -> "+q2);

        /*
           Query 3
        */
        before = System.currentTimeMillis();
        Pair<Long,Long> q3 = m.totalPosts(LocalDate.of(2016, Month.JULY,1),
                LocalDate.of(2016,Month.JULY,31));
        after = System.currentTimeMillis();
        logtime.writeLog("Query 3 -> "+(after-before)+" ms");
        log.writeLog("Query 3 -> "+q3);

        /*
           Query 4
        */
        before = System.currentTimeMillis();
        List<Long> query4 = m.questionsWithTag("package-management", LocalDate.of(2013, Month.MARCH, 1),
                LocalDate.of(2013, Month.MARCH,31));
        after = System.currentTimeMillis();
        logtime.writeLog("Query 4 -> " + (after - before) + " ms");
        log.writeLog("Query 4 -> " + query4);

        /*
           Query 5
        */
        before = System.currentTimeMillis();
        Pair<String, List<Long>> q5 = m.getUserInfo(15811);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 5 -> "+(after-before)+" ms");
        log.writeLog("Query 5 -> "+q5);

        /*
           Query 6
        */
        before = System.currentTimeMillis();
        List<Long> q6 = m.mostVotedAnswers(5, LocalDate.of(2015, Month.NOVEMBER, 1),
                LocalDate.of(2015, Month.NOVEMBER,30));
        after = System.currentTimeMillis();
        logtime.writeLog("Query6 -> " + (after - before) + " ms");
        log.writeLog("Query6 -> " + q6);

        /*
           Query 7
        */
        before = System.currentTimeMillis();
        List<Long> q7 = m.mostAnsweredQuestions(10, LocalDate.of(2012,Month.JANUARY,1),
                LocalDate.of(2012,Month.DECEMBER,31));
        after = System.currentTimeMillis();
        logtime.writeLog("Query 7 -> "+(after-before)+" ms");
        log.writeLog("Query 7 -> "+q7);

        /*
           Query 8
        */
        before = System.currentTimeMillis();
        List<Long> q8 = m.containsWord(10, "kde");
        after = System.currentTimeMillis();
        logtime.writeLog("Query 8 -> " + (after - before) + " ms");
        log.writeLog("Query 8 -> " + q8);

        /*
           Query 9
        */
        before = System.currentTimeMillis();
        List<Long> q9 = m.bothParticipated(10, 15811, 449);
        after = System.currentTimeMillis();
        logtime.writeLog("Query9 -> " + (after - before) + " ms");
        log.writeLog("Query 9 -> " + q9);

        /*
           Query 10
        */
        before = System.currentTimeMillis();
        long q10 = m.betterAnswer(30334);
        after = System.currentTimeMillis();
        logtime.writeLog("Query 10 -> "+(after-before)+" ms");
        log.writeLog("Query 10 -> "+q10);

        /*
            Query 11
        */
        before = System.currentTimeMillis();
        List<Long> q11 = m.mostUsedBestRep(10, LocalDate.of(2014,Month.JANUARY,1),
                LocalDate.of(2014,Month.DECEMBER,31));
        after = System.currentTimeMillis();
        logtime.writeLog("Query 11 -> "+(after-before)+" ms");
        log.writeLog("Query 11 -> "+q11);

        /*
            CLEAN PHASE
         */
        before = System.currentTimeMillis();
        m.clear();
        after = System.currentTimeMillis();
        logtime.writeLog("CLEAN -> "+(after-before)+" ms");

    }


    public void control_fluxo(String[] args){

        escreve_ficheiros(args);

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
                        par = m.infoFromPost(id);
                        v.imprime_pair(par,1);
                        break;

                case 2: tamanho = v.insere_tamanho(2);
                        list = m.topMostActive(tamanho);
                        v.imprime_list(list,2);
                        break;

                case 3: inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        par = m.totalPosts(inicio,fim);
                        v.imprime_pair(par,3);
                        break;

                case 4: tag = v.insere_string(4);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        list = m.questionsWithTag(tag,inicio,fim);
                        v.imprime_list(list,4);
                        break;

                case 5: id = v.insere_ID(5);
                        par = m.getUserInfo(id);
                        v.imprime_pair(par,5);
                        break;

                case 6: tamanho = v.insere_tamanho(6);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        list = m.mostVotedAnswers(tamanho,inicio,fim);
                        v.imprime_list(list,6);
                        break;

                case 7: tamanho = v.insere_tamanho(7);
                        inicio = v.insere_data(0);
                        fim = v.insere_data(1);
                        list = m.mostAnsweredQuestions(tamanho,inicio,fim);
                        v.imprime_list(list,7);
                        break;

                case 8: tamanho = v.insere_tamanho(8);
                        palavra = v.insere_string(8);
                        list = m.containsWord(tamanho,palavra);
                        v.imprime_list(list,8);
                        break;

                case 9: tamanho = v.insere_tamanho(9);
                        id1 = v.insere_ID(9);
                        id2 = v.insere_ID(9);
                        list = m.bothParticipated(tamanho,id1,id2);
                        v.imprime_list(list,9);
                        break;

                case 10: id = v.insere_ID(10);
                         res = m.betterAnswer(id);
                         v.imprime_long(10);
                         break;

                case 11: tamanho = v.insere_tamanho(11);
                         inicio = v.insere_data(0);
                         fim = v.insere_data(1);
                         list = m.mostUsedBestRep(tamanho,inicio,fim);
                         v.imprime_list(list,11);
                         break;
            }

        } while(true);
    }

}
