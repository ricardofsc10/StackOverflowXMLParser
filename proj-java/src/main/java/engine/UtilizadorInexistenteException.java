package engine;

/**
 * Exceção UtilizadorInexistenteException que define a exceção da inexistência de um utilizador.
 *
 * @author Grupo21
 * @version 20180610
 */

public class UtilizadorInexistenteException extends Exception {
    /**
     * Construtor vazio de UtilizadorInexistenteException.
     */
    public UtilizadorInexistenteException(){super();}

    /**
     * Construtor parametrizado de UtilizadorInexistenteException.
     *
     * @param cod Código
     */
    public UtilizadorInexistenteException(String cod){
        super(cod);
    }
}