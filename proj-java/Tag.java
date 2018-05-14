/**
 * Escreva a descrição da classe Tag aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

public class Tag{
    private String key_tag_name;
    private long id_tag;
    
    ////////////////////// Construtores
    // construtor vazio
    public Tag(){
        this.key_tag_name = "";
        this.id_tag = 0;
    }
    
    // construtor parametrizado
    public Tag(String key, long id){
        this.key_tag_name = key;
        this.id_tag = id;
    }
    
    // construtor de cópia
    public Tag(Tag umatag){
        this.key_tag_name = umatag.get_key_tag_name();
        this.id_tag = umatag.get_id_tag();
    }
    
    ////////////////////// Gets
    public String get_key_tag_name(){return this.key_tag_name;}
    
    public long get_id_tag(){return this.id_tag;}
    
    ////////////////////// Sets
    public void set_key_tag_name(String name){this.key_tag_name = name;}
    
    public void setid_tag(long id){this.id_tag = id;}
    
    ////////////////////// Métodos essenciais
    public Tag clone(){return new Tag(this);}
    
    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        Tag t = (Tag) o; 
        return (this.key_tag_name.equals(t.get_key_tag_name())
                && this.id_tag == t.get_id_tag());
    }
    
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Tag: "); sb.append(this.key_tag_name);
        sb.append(", ID: "); sb.append(this.id_tag);
        return sb.toString();
    }
}
