package common;

/**
 * Classe Tag que define as propriedades da Tag.
 *
 * @author Grupo21
 * @version 20180610
 */

public class Tag{
    private String key_tag_name;
    private long id_tag;
    
    ////////////////////// Construtores
    /**
     * Construtor vazio de Tag.
     */
    public Tag(){
        this.key_tag_name = "";
        this.id_tag = 0;
    }

    /**
     * Construtor parametrizado de Tag.
     *
     * @param key Chave/Nome da Tag
     * @param id Id da Tag
     */
    public Tag(String key, long id){
        this.key_tag_name = key;
        this.id_tag = id;
    }

    /**
     * Construtor de cópia de Tag.
     *
     * @param umatag Nova Tag
     */
    public Tag(Tag umatag){
        this.key_tag_name = umatag.get_key_tag_name();
        this.id_tag = umatag.get_id_tag();
    }
    
    ////////////////////// Gets
    /**
     * Método que devolve a Chave/Nome da Tag.
     *
     * @return Chave/Nome da Tag.
     */
    public String get_key_tag_name(){return this.key_tag_name;}

    /**
     * Método que devolve o Id da Tag.
     *
     * @return Id da Tag.
     */
    public long get_id_tag(){return this.id_tag;}
    
    ////////////////////// Sets
    /**
     * Atualiza a Chave/Nome da Tag.
     *
     * @param name Nova Chave/Nome da Tag
     */
    public void set_key_tag_name(String name){this.key_tag_name = name;}

    /**
     * Atualiza o Id da Tag.
     *
     * @param id Novo Id da Tag
     */
    public void setid_tag(long id){this.id_tag = id;}
    
    ////////////////////// Métodos essenciais
    /**
     * Método de clonagem de uma Tag.
     *
     * @return Objeto do tipo Tag.
     */
    public Tag clone(){return new Tag(this);}

    /**
     * Implementação do método de igualdade entre duas Tags.
     *
     * @param a Tag que é comparado com o recetor
     * @return Booleano True ou False.
     */
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Tag t = (Tag) o; 
        return (this.key_tag_name.equals(t.get_key_tag_name())
                && this.id_tag == t.get_id_tag());
    }

    /**
     * Implementação do método toString.
     *
     * @return Uma String com informação textual do objeto Tag.
     */
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Tag: "); sb.append(this.key_tag_name);
        sb.append(", ID: "); sb.append(this.id_tag);
        return sb.toString();
    }
}
