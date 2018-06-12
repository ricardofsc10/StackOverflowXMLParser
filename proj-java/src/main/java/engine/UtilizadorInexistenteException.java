package engine;

public class UtilizadorInexistenteException extends Exception {
    public UtilizadorInexistenteException(){super();}

    public UtilizadorInexistenteException(String cod){
        super(cod);
    }
}
