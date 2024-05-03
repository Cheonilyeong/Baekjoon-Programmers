import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue

val INF = 987654321;

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val VE = br.readLine().split(" ").map {it.toInt()};
    val K = br.readLine().toInt();

    var adj = Array<MutableList<Pair<Int,Int>>>(VE[0]+1) { mutableListOf() };
    (0 until VE[1]).forEach {
        val uvw = br.readLine().split(" ").map {it.toInt()};
        adj[uvw[0]].add(Pair(uvw[2],uvw[1]));
    }

    val pq = PriorityQueue<Pair<Int,Int>>(compareBy {it.first});
    val dist = IntArray(VE[0]+1) {it -> INF};

    pq.add(Pair(0,K));
    dist[K] = 0;

    while(pq.isNotEmpty()) {
        val here = pq.peek().second;
        val here_dist = pq.poll().first;

        if(dist[here] != here_dist) continue;

        adj[here].forEach() {
            val there = it.second;
            val there_dist = it.first;
            if(dist[there] > dist[here]+there_dist) {
                dist[there] = dist[here]+there_dist;
                pq.add(Pair(dist[there],there));
            }
        }
    }

    (1..VE[0]).forEach() {
        if(dist[it]==INF) println("INF");
        else println(dist[it]);
    }

    br.close();
    bw.flush();
    bw.close();
}