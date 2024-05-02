import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    while(true) {
        val str = br.readLine() ?: break;
        bw.write(str+"\n");
    }

    br.close();
    bw.flush();
    br.close();
}