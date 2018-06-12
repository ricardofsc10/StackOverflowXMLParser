package engine;

import common.Pair;

import java.time.LocalDate;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class View {

    public int escolhe_query(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Que query deseja resolver (-1 para abandonar o programa): ");
        int query = sc.nextInt();
        if(query == -1) return -1;
        if(query > 11 || query < 1){
            System.out.println("Query inexistente.");
            return 0;
        }
        return query;
    }

    public LocalDate insere_data(int inicio_fim){

        if(inicio_fim == 0) System.out.println("Data de ínicio:");
        else System.out.println("Data de fim:");

        Scanner sc = new Scanner(System.in);
        System.out.print("Dia: ");
        int dia = sc.nextInt();
        System.out.print("Mês: ");
        int mes = sc.nextInt();
        System.out.print("Ano: ");
        int ano = sc.nextInt();
        LocalDate data = LocalDate.of(ano,mes,dia);
        return data;
    }

    public int insere_tamanho(int query){

        switch(query){
            case 2: System.out.print("Tamanho da lista de Utilizadores: ");
            case 6: System.out.print("Tamanho da lista de Respostas: ");
            case 7: System.out.print("Tamanho da lista de Perguntas: ");
            case 8: System.out.print("Tamanho da lista de Perguntas: ");
            case 9: System.out.print("Tamanho da lista de Perguntas: ");
            case 11: System.out.print("Tamanho da lista de Tags/Utilizadores: ");
        }
        Scanner sc = new Scanner(System.in);
        int tamanho = sc.nextInt();
        return tamanho;
    }

    public long insere_ID(int query){
        switch(query){
            case 1: System.out.print("ID do post: ");
            case 5: System.out.print("ID do utilizador: ");
            case 9: System.out.print("ID do utilizador: ");
            case 10: System.out.print("ID pergunta: ");
        }
        Scanner sc = new Scanner(System.in);
        long id = sc.nextInt();
        return id;
    }

    public String insere_string(int query){
        switch(query){
            case 4: System.out.print("Tag a procurar: ");
            case 8: System.out.print("Palavra a comparar: ");
        }
        Scanner sc = new Scanner(System.in);
        String palavra = sc.next();
        return palavra;
    }

    public void imprime_long(long resultado){
        System.out.println("ID da melhor resposta: " + resultado);
    }

    public void imprime_pair(Pair par, int query){
        switch(query){
            case 1: System.out.println("Título do post: " + par.getFst());
                    System.out.println("Nome do autor: " + par.getSnd());

            case 3: System.out.println("Número de perguntas: " + par.getFst());
                    System.out.println("Número de respostas: " + par.getSnd());

            case 5: System.out.println("Biografia do autor: " + par.getFst());
                    System.out.println("Últimos 10 posts: " + par.getSnd());
        }
    }

    public void imprime_list(List<Long> lista, int query){
        switch(query){
            case 2: System.out.println("Lista com top correspondente: ");
            case 4: System.out.println("Lista com ID´s das perguntas: ");
            case 6: System.out.print("Lista com ID´s das respostas: ");
            case 7: System.out.print("Lista com ID´s das perguntas: ");
            case 8: System.out.print("Lista com ID´s das perguntas: ");
            case 9: System.out.print("Lista com ID´s das perguntas: ");
            case 11: System.out.print("Lista com ID´s das tags: ");
        }
        Iterator it = lista.iterator();
        int i = 1;
        while(it.hasNext()){
            long id = (long) it.next();
            System.out.println(i + "º ID: " + id);
            i++;
        }
    }

}
