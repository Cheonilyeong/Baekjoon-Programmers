import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine()!!;
    val str = br.readLine()!!;
    var ret = 0;
    str.forEachIndexed { index, c ->
        ret += c.digitToInt();
    }

    bw.write("$ret");

    br.close();
    bw.flush();
    br.close();
}