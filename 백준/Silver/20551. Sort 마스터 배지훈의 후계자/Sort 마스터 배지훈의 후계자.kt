import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var num = br.readLine().split(" ");
    val N = num[0].toInt();
    val M = num[1].toInt();

    val arr = IntArray(N);
    val firstIdx = HashMap<Int,Int>();
    for(i in 0 until N) {
        val a = br.readLine().toInt();
        arr[i] = a;
    }
    arr.sort();

    arr.forEachIndexed { index, i ->
        if(!firstIdx.containsKey(i)) firstIdx.put(i, index);
    }

    for(i in 0 until M) {
        val a = br.readLine().toInt();

        if(firstIdx.containsKey(a)) {
            bw.write("${firstIdx[a]}\n");
        }
        else bw.write("-1\n");
    }

    br.close();
    bw.flush();
    bw.close();
}