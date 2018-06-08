package engine;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Funcoes {
    public LocalDate stringToDias(String data_string){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        LocalDate data = LocalDate.parse(data_string, formatter);
        return data;
    }

    public ArrayList<String> strToTag(String tags){
        ArrayList<String> res = new ArrayList<String>();
        String delim = "<>";
        StringTokenizer palavra = new StringTokenizer(tags,delim);
        while (palavra.hasMoreTokens())
            res.add(palavra.nextToken());
        return res;
    }
}
