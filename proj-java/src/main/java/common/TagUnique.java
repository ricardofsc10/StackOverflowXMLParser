package common;

/**
 * Classe TagUnique que define as propriedades da TagUnique.
 *
 * @author Grupo21
 * @version 20180610
 */

public class TagUnique {
    private String nome;
    private int ocorrencias;

    ////////////////////// Construtores
    /**
     * Construtor vazio de TagUnique.
     */
    public TagUnique(){
        this.nome = "";
        this.ocorrencias = 0;
    }

    /**
     * Construtor parametrizado de TagUnique.
     *
     * @param nome Nome da TagUnique
     * @param ocorr Ocorrencias da TagUnique
     */
    public TagUnique(String nome, int ocorr){
        this.nome = nome;
        this.ocorrencias = ocorr;
    }

    /**
     * Construtor de cópia de TagUnique.
     *
     * @param umatag Nova TagUnique
     */
    public TagUnique(TagUnique umatag){
        this.nome = umatag.getNome();
        this.ocorrencias = umatag.getOcorrencias();
    }

    ////////////////////// Gets
    /**
     * Método que devolve a Chave/Nome da TagUnique.
     *
     * @return Chave/Nome da TagUnique.
     */
    public String getNome(){return this.nome;}

    /**
     * Método que devolve as Ocorrencias da TagUnique.
     *
     * @return Ocorrencias da TagUnique.
     */
    public int getOcorrencias(){return this.ocorrencias;}

    ////////////////////// Sets
    /**
     * Atualiza o Nome da TagUnique.
     *
     * @param nome Novo Nome da TagUnique
     */
    public void setNome(String nome){this.nome = nome;}

    /**
     * Atualiza as Ocorrencias da TagUnique.
     *
     * @param name Novas Ocorrencias da TagUnique
     */
    public void setOcorrencias(int ocorre){this.ocorrencias = ocorre;}

    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de uma TagUnique.
     *
     * @return Objeto do tipo TagUnique.
     */
    public TagUnique clone(){return new TagUnique(this);}

    /**
     * Implementação do método de igualdade entre duas Tag'sUnique.
     *
     * @param a TagUnique que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        TagUnique tu = (TagUnique) o;
        return (this.nome.equals(tu.getNome()) &&
                this.ocorrencias == tu.getOcorrencias());
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Tag_Unique.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Nome da Tag: "); sb.append(this.nome);
        sb.append("Número de ocorrências: "); sb.append(this.ocorrencias);
        return sb.toString();
    }
}
