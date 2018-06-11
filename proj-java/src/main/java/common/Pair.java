package common;

/**
 * Classe Pair que define as propriedades do Pair.
 *
 * @author Grupo21
 * @version 20180610
 */

import java.util.Objects;

public class Pair<X,Y> {
    private X fst;
    private Y snd;

    /**
     * Construtor parametrizado de Pair.
     *
     * @param fst Primeira coordenada
     * @param snd Segunda coordenada
     */
    public Pair(X fst, Y snd) {
        this.fst = fst;
        this.snd = snd;
    }

    /**
     * Implementação do HashCode da classe Pair.
     *
     * @return Valor do HashCode.
     */
    public int hashCode() {
        int hashFst = fst != null ? fst.hashCode() : 0;
        int hashSnd = snd != null ? snd.hashCode() : 0;

        return (hashFst + hashSnd) * hashSnd + hashFst;
    }

    /**
     * Implementação do método de igualdade entre dois Pair's.
     *
     * @param o Pair que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair p = (Pair) o;
            return Objects.equals(this.fst, p.fst) && Objects.equals(snd, p.snd);
        }
        return false;
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Pair.
     */
    public String toString() {
        return "(" + fst + ", " + snd + ")";
    }

    /**
     * Método que devolve a Primeira coordenada do Pair.
     *
     * @return Primeira coordenada do Pair.
     */
    public X getFst() {
        return fst;
    }

    /**
     * Atualiza a Primeira coordenada do Pair.
     *
     * @param fst Nova Primeira coordenada do Pair
     */
    public void setFst(X fst) {
        this.fst = fst;
    }

    /**
     * Método que devolve a Segunda coordenada do Pair.
     *
     * @return Primeira coordenada do Pair.
     */
    public Y getSnd() {
        return snd;
    }

    /**
     * Atualiza a Segunda coordenada do Pair.
     *
     * @param snd Nova Segunda coordenada do Pair
     */
    public void setSecond(Y snd) {
        this.snd = snd;
    }
}