import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));

    var arr = br.readLine().split(" ");

    println(arr[0].toDouble()/arr[1].toDouble());
}