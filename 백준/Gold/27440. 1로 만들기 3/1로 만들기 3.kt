import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val X = br.readLine().toLong()

    val queue = LinkedList<Long>()
    val visited = HashMap<Long, Int>()
    visited[X] = 0
    queue.offer(X)

    while(queue.isNotEmpty()) {
        val now = queue.poll()

        if(now == 1L) {
            println("${visited[now]}")
            break;
        }

        // 3으로 나누어 떨어지면, 3으로 나눈다.
        if(now%3 == 0L && visited[now/3] == null) {
            visited[now/3] = visited[now]!! + 1
            queue.offer(now/3)
        }

        // 2로 나누어 떨어지면, 2로 나눈다.
        if(now%2 == 0L && visited[now/2] == null) {
            visited[now/2] = visited[now]!! + 1
            queue.offer(now/2)
        }

        // 1을 뺀다
        if(visited[now-1] == null) {
            visited[now-1] = visited[now]!! + 1
            queue.offer(now-1)
        }
    }

    br.close()
    bw.close()
}