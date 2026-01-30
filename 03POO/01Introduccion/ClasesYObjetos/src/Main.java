import java.util.Scanner;

import static java.sql.DriverManager.println;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Conejo conejo = null;
        Integer opcion = 0;
        Double dinero = 100.00;
        String letras = "";
        Zanahoria zanahoria = new Zanahoria(0);
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("Hola que quieres hacer?");
            System.out.println("1. Crear un conejo");
            System.out.println("2. Ir a la tienda");
            System.out.println("3. Interactuar con el conejo");
            opcion = sc.nextInt();
            letras = sc.nextLine();

            switch (opcion) {
                case 1:
                    conejo = new Conejo();
                    System.out.println("Has elegido crear un conejo ponle un nombre:");
                    letras = sc.nextLine();
                    conejo.nombre = letras;
                    System.out.println("De que color quieres que sea:");
                    letras = sc.nextLine();
                    conejo.color = letras;
                    System.out.println("De que raza quieres que sea:");
                    letras = sc.nextLine();
                    conejo.raza = letras;
                    conejo.edad = 0;
                    break;
                case 2:
                    Tienda tienda = new Tienda();
                    System.out.println("Has elegido entrar a la tienda cuentas con: $" + dinero + " y " + zanahoria.numZanahorias + " zanahorias");
                    System.out.println("Quieres comprar?");
                    System.out.println("1. Si");
                    System.out.println("2. No");
                    opcion = sc.nextInt();

                    if (opcion == 1) {
                        zanahoria = tienda.ComprarComida(dinero, zanahoria);
                        dinero = tienda.restarDinero(dinero);
                        System.out.println("Has comprado: " + zanahoria.numZanahorias + " zanahorias");
                        System.out.println("Dinero restante: $" + dinero);
                    }
                    break;
                case 3:
                    System.out.println("Has elegido jugar con el conejo");
                    System.out.println("Vamos a ver si tienes un conejo...");
                    if (conejo != null) {
                        System.out.println("Si tienes un conejo quieres que salte o que coma?");
                        System.out.println("1. Dar de comer");
                        System.out.println("2. Saltar");
                        opcion = sc.nextInt();

                        if (opcion == 1) {
                            conejo.Alimentar(conejo, zanahoria);
                        } else if (opcion == 2) {
                            conejo.Saltar(conejo.yaComio);
                        }

                    } else {
                        System.out.println("No cuentas con un conejo crea uno\n");
                    }
                    break;
            }
            ;

            System.out.println("Quieres salir del programa? \n1.Si \n2.No");
            opcion = sc.nextInt();

        } while (opcion != 1);
        sc.close();

    }

    public static class Conejo {
        String nombre;
        String color;
        String raza;
        Integer edad;
        Float peso;
        boolean estaSaltando = false;
        boolean yaComio = false;

        public Conejo(){

        }

        public Conejo(String nombre, String color, String raza, Integer edad, Float peso) {
            this.nombre = nombre;
            this.color = color;
            this.raza = raza;
            this.edad = edad;
            this.peso = peso;
        }

        public void Saltar (boolean yaComio){
            if(yaComio){
                this.estaSaltando = true;
                println("Conejo saltando...");
            } else {
                System.out.println("Alimenta al conejo para que tenga energia de saltar");
            }
        }
        public boolean Alimentar (Conejo conejo, Zanahoria zanahoria) {
            if(conejo != null && zanahoria.numZanahorias > 0){
                System.out.println("Alimentando a el conejo");
                return yaComio = true;
            } else if (conejo == null){
                System.out.println("No tienes conejos para alimentar");
            } else if (zanahoria.numZanahorias == 0) {
                System.out.println("No tienes zanahorias para darle al conejo, compralas en la tienda");
            }
            return yaComio = false;
        }
    }

    public static class Tienda {
         public Zanahoria ComprarComida(Double dinero, Zanahoria zanahoria){
             if(dinero > 0){
                 zanahoria.numZanahorias++;
                return zanahoria;
            }
            return null;
        }

        public Double restarDinero(Double dinero){
             dinero -= 10;
             return dinero;
        }
    }

    public static class Zanahoria {
        int numZanahorias;

        public Zanahoria(int numZanahorias) {
            this.numZanahorias += numZanahorias;
        }

    }
}