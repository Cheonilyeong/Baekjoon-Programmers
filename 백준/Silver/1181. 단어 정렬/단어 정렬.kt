import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();

    val arr = mutableListOf<String>();
    val set = HashSet<String>();

    (1..N).forEach() {
        val word = br.readLine();
        if(set.contains(word)) return@forEach;
        set.add(word);
        arr.add(word);
    }

    arr.sortWith(compareBy ({it.length}, {it}));

    arr.forEach() {
        bw.write(it+"\n")
    };

    br.close();
    bw.flush();
    bw.close();
}