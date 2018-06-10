package common;

public class TagUnique {
    private String nome;
    private int ocorrencias;

    public TagUnique(){
        this.nome = "";
        this.ocorrencias = 0;
    }

    public TagUnique(String nome, int ocorr){
        this.nome = nome;
        this.ocorrencias = ocorr;
    }

    public TagUnique(TagUnique umatag){
        this.nome = umatag.getNome();
        this.ocorrencias = umatag.getOcorrencias();
    }

    public String getNome(){return this.nome;}

    public int getOcorrencias(){return this.ocorrencias;}

    public void setNome(String nome){this.nome = nome;}

    public void setOcorrencias(int ocorre){this.ocorrencias = ocorre;}

    public TagUnique clone(){return new TagUnique(this);}

    public boolean equals (Object o){
        if (this == o) return true;
        if ((o == null) || (this.getClass()!=o.getClass())) return false;
        TagUnique tu = (TagUnique) o;
        return (this.nome.equals(tu.getNome()) &&
                this.ocorrencias == tu.getOcorrencias());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Nome da Tag: "); sb.append(this.nome);
        sb.append("Número de ocorrências: "); sb.append(this.ocorrencias);
        return sb.toString();
    }
}
