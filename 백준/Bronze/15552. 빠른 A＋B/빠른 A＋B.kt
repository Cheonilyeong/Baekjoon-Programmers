import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var num = br.readLine().toInt();

    (1..num).forEach {
        val num = br.readLine().split(" ");
        val ret = num[0].toInt()+num[1].toInt();
        bw.write(ret.toString()+'\n');
    }

    br.close();
    bw.flush();
    bw.close();
}