package engine;

public class PostInexistenteException extends Exception {
    public PostInexistenteException(){super();}

    public PostInexistenteException(String cod){
        super(cod);
    }
}
