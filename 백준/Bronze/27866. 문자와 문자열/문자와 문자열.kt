import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var str = br.readLine();
    var N = br.readLine().toInt();

    println(str[N-1]);

    br.close();
    bw.flush();
    br.close();
}