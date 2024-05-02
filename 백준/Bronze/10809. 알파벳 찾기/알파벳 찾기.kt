import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val str = br.readLine();
    var map = HashMap<Int,Int>();

    str.forEachIndexed { index, c ->
        if(!map.contains(c.toInt()-'a'.toInt())) {
            map[c.toInt()-'a'.toInt()] = index;
        }
    }

    (0 until 26).forEach {
        bw.write(map.getOrDefault(it,-1).toString() + " ");
    }

    br.close();
    bw.flush();
    br.close();
}