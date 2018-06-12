package li3;

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


