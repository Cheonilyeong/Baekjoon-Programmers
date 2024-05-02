import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();

    (0 until N).forEach {
        var str = br.readLine();
        print(str[0]);
        println(str[str.length-1]);
    }

    br.close();
    bw.flush();
    br.close();
}