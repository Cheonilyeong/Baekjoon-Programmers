import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue

val INF : Int = 987654321;

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    var num = br.readLine().split(" ");
    val N = num[0].toInt();
    val M = num[1].toInt();
    val X = num[2].toInt();

    val adj = MutableList(N+2) { mutableListOf<Pair<Int,Int>>() };
    val retDist = IntArray(N+2) {init -> 0};

    (1..M).forEach() {
        num = br.readLine()!!.split(" ");
        adj[num[0].toInt()].add(Pair(num[2].toInt(),num[1].toInt()));
    }

    // it마을에서 X마을 까지의 최단거리 구하기
    (1..N).forEach() {
        val pq = PriorityQueue<Pair<Int,Int>>(compareBy { it.first });
        val dist = IntArray(N+1) {init -> INF};

        pq.add(Pair(0,it));
        dist[it] = 0;

        while(pq.isNotEmpty()) {
            val here = pq.peek().second;
            val here_dist = pq.poll().first;

            if(dist[here] != here_dist) continue;

            for(i in 0..adj[here].lastIndex) {
                val _there = adj[here][i].second;
                val _there_dist = adj[here][i].first;
                if(dist[_there] > dist[here] + _there_dist) {
                    dist[_there] = dist[here] + _there_dist;
                    pq.add(Pair(dist[_there],_there));
                }
            }
        }

        // 최단거리
        if(it==X) {
            for(i in 1..N) {
                retDist[i] += dist[i];
            }
        }
        else {
            retDist[it] += dist[X];
        }

    }

    var ret = 0;
    var mx = 0;
    (1..N).forEach() {
        //bw.write(retDist[it].toString() + " ");
        if(it != X && mx < retDist[it]) {
            ret = it;
            mx = retDist[it];
        }
    }

    println(mx);

    br.close();
    bw.flush();
    bw.close();

}