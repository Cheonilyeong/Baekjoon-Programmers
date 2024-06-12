import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var a = br.readLine().split(" ").map{it.toInt()}
    val N = a[0]
    val M = a[1]

    val adj = Array<MutableList<Int>>(N) { mutableListOf<Int>() }

    for(i in 0 until M) {
        a = br.readLine().split(" ").map{it.toInt()}
        val A = a[0]-1
        val B = a[1]-1
        adj[A].add(B)
        adj[B].add(A)
    }

    var mn = Int.MAX_VALUE
    var ret1 = 0
    var ret2 = 0

    for(i in 0 until N) {
        for(j in i until N) {
            var sum = 0
            val visited = Array<Int>(N) {0}
            val queue = LinkedList<Int>()
            queue.offer(i)
            queue.offer(j)
            visited[i] = 1
            visited[j] = 1

            while(queue.isNotEmpty()) {
                val now = queue.pollFirst()

                for(next in adj[now]) {
                    if(visited[next] > 0) continue
                    visited[next] = visited[now] + 1
                    queue.offer(next)
                    sum += visited[now] * 2
                }
            }

            if(sum < mn) {
                mn = sum
                ret1 = i
                ret2 = j
            }
            else if(sum == mn) {
                if(i < ret1) {
                    ret1 = i
                    ret2 = j
                }
                else if(i == ret1 && j < ret2) {
                    ret1 = i
                    ret2 = j
                }
            }
        }
    }

    println("${ret1+1} ${ret2+1} $mn");

    br.close()
    bw.flush()
    bw.close()
}