public class DecoratorTags{
    private MetodoSimples texto;

    public DecoratorTags(){
        this.texto = new MetodoSimples();
    }

    public String getTexto(){
        return "<b>" + texto.getTexto() + "</b>";
    }
}
