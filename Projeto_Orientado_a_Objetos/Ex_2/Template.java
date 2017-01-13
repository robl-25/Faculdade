public abstract class Template{
    public String Leitura(String texto){
        return texto;
    }
    public abstract String transformar(String texto);

    public String templateMethod(){
        String msg = "Hello World";
        return transformar(msg);
    }
}
