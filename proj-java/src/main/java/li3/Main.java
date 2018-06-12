package li3;

/**
 * Classe Main que define o método principal do projeto.
 *
 * @author Grupo21
 * @version 20180610
 */

import engine.*;

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


