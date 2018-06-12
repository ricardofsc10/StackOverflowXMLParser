package engine;

/**
 * Exceção PostInexistenteException que define a exceção da inexistência de um post.
 *
 * @author Grupo21
 * @version 20180610
 */

public class PostInexistenteException extends Exception {
    /**
     * Construtor vazio de PostInexistenteException.
     */
    public PostInexistenteException(){super();}

    /**
     * Construtor parametrizado de PostInexistenteException.
     *
     * @param cod Código
     */
    public PostInexistenteException(String cod){
        super(cod);
    }
}