class Pessoa {
    private String nome, end, tel;
  
    public void setNome(String n) {
      nome = n;
    }
  
    public String getNome() {
      return nome;
    }
  
    public void setEnd(String end) {
      this.end = end; //this.end para se referir ao atributo da instância
    }
  
    public String getEnd() {
      return end;
    }
  
    public void setTel(String t) {
      tel = t;
    }
  
    public String getTel() {
      return tel;
    }
  
    public void imprimir() {
      System.out.printf("Nome: %s\n"+
                        "End.: %s\n"+
                        "Tel.: %s\n", nome, end, tel);
    }
  }

  class Aluno extends Pessoa{
    public String Ra;

    public void setRa(String Ra){
      this.Ra = Ra;
    }
    
    public String getRa(){
      return Ra;
    }

    public void imprimir(){
      super.imprimir();
      System.out.printf("RA: %s\n", Ra);
    }
  }
  
  public class ExercicioPessoa {
    public static void main(String s[]) {
      Pessoa p = new Pessoa();
      p.setNome("Pedro");
      p.setEnd("Rua Qualquer, 1-23");
      p.setTel("(14) 98765-4534");
      p.imprimir();
      System.out.println(p.getNome());

      Aluno a = new Aluno();
      a.setNome("Pedro");
      a.setEnd("Rua Qualquer, 1-23");
      a.setTel("(14) 98765-4534");
      a.setRa("242422442");
      a.imprimir();
      
      System.out.println(a.getRa());
    }
  }