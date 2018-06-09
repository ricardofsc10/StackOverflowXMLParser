package engine;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Funcoes {
    public static LocalDate stringToDias(String data_string){
        LocalDate data = LocalDate.parse(data_string, DateTimeFormatter.ISO_LOCAL_DATE_TIME);
        return data;
    }

    public static ArrayList<String> strToTag(String tags){
        ArrayList<String> res = new ArrayList<String>();
        String delim = "<>";
        StringTokenizer palavra = new StringTokenizer(tags,delim);
        while (palavra.hasMoreTokens())
            res.add(palavra.nextToken());
        return res;
    }
}
