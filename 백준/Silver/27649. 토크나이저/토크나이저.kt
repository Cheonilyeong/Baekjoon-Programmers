import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var arr = readLine()!!;
    val sep = listOf("<", ">", "&&", "||", "(", ")");

    for(i in sep) {
        arr = arr.replace(i, " $i ");
    }

    arr.forEachIndexed { index, c ->
        if(c==' ' && (index==0 || arr[index-1]==c)) return@forEachIndexed;
        bw.write(c.toString());
    }

    br.close();
    bw.flush();
    bw.close();
}
