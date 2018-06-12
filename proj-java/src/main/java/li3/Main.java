package li3;

import common.MyLog;
import common.Pair;
import engine.*;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.time.LocalDate;
import java.time.Month;
import java.util.List;

public class Main {


    public static void main(String[] args){

        Model model = new Model();
        View view = new View();
        Controller controller = new Controller();

        controller.setView(view);
        controller.setModel(model);
        controller.control_fluxo(args);

    }

}


