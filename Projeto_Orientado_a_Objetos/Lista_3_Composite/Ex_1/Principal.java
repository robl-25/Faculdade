public class Principal{
    public static void main(String[] args){
        Individuo ind1 = new Individuo("Maria");
        Individuo ind2 = new Individuo("Ana");
        Individuo ind3 = new Individuo("Pedro");
        Individuo ind4 = new Individuo("Paulo");
        Individuo ind5 = new Individuo("Carla");
        Congresso cong = new Congresso(4);
        Instituicao inst = new Instituicao();

        inst.addMembros(ind1);
        inst.addMembros(ind2);
        inst.addMembros(ind3);

        cong.addParticipantes(ind4);
        cong.addInstituicao(inst);

        System.out.println(cong.TotalParticipantes());
        cong.printParticipantes();

        cong.addParticipantes(ind5);
    }
}
