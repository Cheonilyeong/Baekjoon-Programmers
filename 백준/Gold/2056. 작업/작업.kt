import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var N = br.readLine().toInt();

    val t = IntArray(size=N+1);
    val cnt = IntArray(size=N+1);
    val adj = Array<MutableList<Int>>(N+1) {mutableListOf()};
    val pq = PriorityQueue<Pair<Int,Int>> (compareBy {it.first});

    (1.. N).forEach {
        val num = br.readLine().split(" ").map { it.toInt() };

        t[it] = num[0];
        cnt[it] = num[1];
        if(cnt[it]==0) pq.add(Pair(t[it],it));
        for(i in 2 until num[1]+2) {
            adj[num[i]].add(it);
        }
    }

    var time = 0;
    while(true) {

        while(pq.size>0 && pq.peek().first == time) {
            var n = pq.poll().second;
            N--;

            adj[n].forEachIndexed { index, i ->
                if(--cnt[i]==0) pq.add(Pair(time+t[i],i));
            }
        }
        if(N==0) break;
        time++;
    }

    println(time);
    
    br.close();
    bw.flush();
    bw.close();
}