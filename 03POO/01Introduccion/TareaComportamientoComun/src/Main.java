//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Moto moto = new Moto(2, 2);
        Coche coche = new Coche(4, 4);
        Bici bici = new Bici(2, 2);

        System.out.println("Moto:");
        System.out.println(moto.Acelerar());
        System.out.println(moto.Frenar());
        System.out.println(moto.FiltrarTrafico());
        System.out.println("");

        System.out.println("Coche:");
        System.out.println(coche.Acelerar());
        System.out.println(coche.Frenar());
        System.out.println(coche.CerrarVentanas());
        System.out.println("");

        System.out.println("Bici:");
        System.out.println(bici.Acelerar());
        System.out.println(bici.Frenar());
        System.out.println(bici.AndarZonaBici());
        System.out.println("");

    }

    public static class Moto {
        private int ruedas;
        private int frenos;

        public Moto(int ruedas, int frenos) {
            this.ruedas = ruedas;
            this.frenos = frenos;
        }

        private String Frenar() {
            return "La moto esta frenando";
        }

        private String Acelerar() {
            return "La moto esta acelerando";
        }

        private String FiltrarTrafico() {
            return "Avanza sobre el trafico";
        }
    }

    public static class Coche {
        private int ruedas;
        private int frenos;

        public Coche(int frenos, int ruedas) {
            this.frenos = frenos;
            this.ruedas = ruedas;
        }

        private String Frenar() {
            return "El coche esta frenando";
        }

        private String Acelerar() {
            return "El coche esta acelerando";
        }

        private String CerrarVentanas() {
            return "Cierra las ventanas del coche";
        }
    }

    public static class Bici {
        private int ruedas;
        private int frenos;

        public Bici(int ruedas, int frenos) {
            this.ruedas = ruedas;
            this.frenos = frenos;
        }

        private String Frenar() {
            return "La bici esta frenando";
        }

        private String Acelerar() {
            return "La bici esta acelerando";
        }

        private String AndarZonaBici() {
            return "Anda en zonas exclusivas para bici";
        }
    }
}

/*
    --Reflexion escrita--
1. Se repiten los atributos de las ruedas y los frenos
2. Acelerar y frenar
3. Los metodos de acelerar, frenar y sus atributos
4. Copiar y pegar las cosas y estarlas cambiando

*/