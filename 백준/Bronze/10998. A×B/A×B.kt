import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));

    var numbers = br.readLine().split(" ");
    var a = numbers[0].toInt();
    var b = numbers[1].toInt();

    println("${a*b}");
}