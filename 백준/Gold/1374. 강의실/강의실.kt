import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(/* in = */ System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var ret = 0
    val N = br.readLine().toInt()
    val pq = PriorityQueue<Int>()
    val adj = ArrayList<Pair<Int,Int>>()

    for(i in 0 until N) {
        val num = br.readLine().split(" ").map { it.toInt() }
        adj.add(Pair(num[1], num[2]))
    }
    adj.sortWith(compareBy<Pair<Int, Int>> { it.first }.thenBy { it.second })
    
    for(i in 0 until N) {

        if (pq.isEmpty()) {
            pq.add(adj[i].second)
        }
        else {
            if(adj[i].first >= pq.peek()) {
                pq.poll()
                pq.add(adj[i].second)
            }
            else {
                pq.add(adj[i].second)
            }
        }
        ret = Math.max(ret, pq.size)
    }

    println(ret)

    br.close()
    bw.close()
}