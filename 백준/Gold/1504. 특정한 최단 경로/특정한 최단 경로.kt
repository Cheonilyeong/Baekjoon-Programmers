import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue

val INF = 987654321;

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var num = br.readLine().split(" ")
    val N = num[0].toInt()
    val E = num[1].toInt()

    val adj = Array<MutableList<Pair<Int,Int>>>(N+2) { mutableListOf() }

    (1..E).forEach() {
        num = br.readLine().split(" ")
        val u = num[0].toInt();
        val v = num[1].toInt();
        val w = num[2].toInt();
        adj[u].add(Pair(w,v));
        adj[v].add(Pair(w,u));
    }

    num = br.readLine().split(" ")
    val V1 = num[0].toInt();
    val V2 = num[1].toInt();
    var V1Dist = Triple(0,0,0);
    var V2Dist = Triple(0,0,0);

    for(i in 0 until 2) {
        var startV : Int = 0;
        if(i==0) startV = V1;
        else startV = V2;

        val dist = IntArray (size=N+2) {init -> INF};
        val pq = PriorityQueue<Pair<Int,Int>>(compareBy {it.first});
        pq.add(Pair(0,startV));
        dist[startV] = 0;

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

        if(i==0) V1Dist = Triple(dist[1],dist[V2],dist[N]);
        else V2Dist = Triple(dist[1],dist[V1],dist[N]);
    }

    if(V1Dist.first==INF && V2Dist.first==INF) println(-1);
    else if (V1Dist.second==INF && V2Dist.second==INF) println(-1);
    else if (V1Dist.third==INF && V2Dist.third==INF) println(-1);
    else {
        val d1 = V1Dist.first + V1Dist.second + V2Dist.third;
        val d2 = V2Dist.first + V2Dist.second + V1Dist.third;
        println(Math.min(d1,d2));
    }

    br.close();
    bw.flush();
    bw.close();
}