import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var num = br.readLine();

    for(i in 1..9) {
        bw.write(num + " * " + i + " = " + num.toInt()*i + "\n");
        bw.flush();
    }
}