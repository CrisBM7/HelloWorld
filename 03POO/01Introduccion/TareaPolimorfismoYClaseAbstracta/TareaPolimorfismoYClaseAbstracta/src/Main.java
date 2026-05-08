import java.util.Scanner;
Scanner scanner = new Scanner(System.in);


void main() {
    Operacion suma = new Suma();
    suma.PedirDatosUsr();
    suma.operacion();
    suma.MostrarResultadoUsr();

    Operacion resta = new Resta();
    resta.PedirDatosUsr();
    resta.operacion();
    resta.MostrarResultadoUsr();

}

public abstract class Operacion {
    int val1;
    int val2;
    int res;

    public void PedirDatosUsr(){
        System.out.println("Introduce un numero: ");
        val1 = scanner.nextInt();
        System.out.println("Introduce el segundo numero: ");
        val2 = scanner.nextInt();
    }

    public void MostrarResultadoUsr(){
        System.out.println("El resultado fue: " + res);
    }

     abstract Integer operacion();
}

public class Suma extends Operacion{
    @Override
    Integer operacion(){
        res = val1 + val2;
        return res;
    }
}

public class Resta extends Operacion{
    @Override
    Integer operacion(){
        res = val1 - val2;
        return res;
    }
}