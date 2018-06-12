package li3;

/**
 * Classe Main que define o método principal do projeto.
 *
 * @author Grupo21
 * @version 20180610
 */

import engine.*;

public class Main {

    /**
     * Método principal que controla o fluxo de todas as queries, o Model e a View do projeto.
     *
     * @param args Argumentos passados na realização do executável
     */
    public static void main(String[] args){

        Model model = new Model();
        View view = new View();
        Controller controller = new Controller();

        controller.setView(view);
        controller.setModel(model);
        controller.control_fluxo(args);

    }

}

