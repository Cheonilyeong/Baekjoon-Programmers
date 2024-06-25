import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    val list = ArrayList<Int>()
    val pq = PriorityQueue<Int>(compareByDescending { it })
    for(i in 0 until N) {
        val num = br.readLine().split(" ").map{ it.toInt() }
        for(j in 0 until N) {
            pq.offer(num[j])
        }
    }
//    list.sort()
//    list.sortBy { it }
//    list.sortWith(compareBy{it})


    for(i in 0 until N-1) {
        pq.poll()
    }
    println("${pq.poll()}")

    br.close()
    bw.close()
}