package engine;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Funcoes {

    /**
     * Função que filtra as datas, transformando-as em formatos de LocalDate.
     *
     * @param data_string Data que vai ser transformada.
     *
     * @returns Data em formato LocalDate.
     */
    public static LocalDate stringToDias(String data_string){
        LocalDate data = LocalDate.parse(data_string, DateTimeFormatter.ISO_LOCAL_DATE_TIME);
        return data;
    }

    /**
     * Função que transforma uma string num array de tags, atraves da repartição
     * da string.
     *
     * @param tags String a transformar
     *
     * @returns Array de Strings que são as tags.
     */
    public static ArrayList<String> strToTag(String tags){
        ArrayList<String> res = new ArrayList<String>();
        String delim = "<>";
        StringTokenizer palavra = new StringTokenizer(tags,delim);
        while (palavra.hasMoreTokens()) {
            res.add(palavra.nextToken());
        }
        return res;
    }
}
