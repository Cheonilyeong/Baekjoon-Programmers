import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    // N and M
    var a = br.readLine().split(" ").map { it.toInt() }
    val N = a[0]
    val M = a[1]

    // X and Y
    a = br.readLine().split(" ").map { it.toInt() }
    val X = a[0]-1
    val Y = a[1]-1

    // bfs
    val dy = arrayOf(-1, 1, -2, 2, -2, 2, -1, 1)
    val dx = arrayOf(-2, -2, -1, -1, 1, 1, 2, 2)

    val visited = Array<IntArray>(N) {IntArray(N) }

    val queue = LinkedList<Pair<Int,Int>>()
    visited[Y][X] = 1
    queue.addLast(Pair(Y,X))    // offer
    while(queue.isNotEmpty()) {
        val now = queue.pollFirst()

        for (i in 0 until 8) {
            val ny = now.first + dy[i]
            val nx = now.second + dx[i]
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue
            if(visited[ny][nx] > 0) continue
            visited[ny][nx] = visited[now.first][now.second] + 1
            queue.addLast(Pair(ny,nx))  // offer
        }
    }

    // Question
    (0 until M).forEach {
        a = br.readLine().split(" ").map { it.toInt() }
        bw.write("${visited[a[1]-1][a[0]-1]-1} ")
    }

    br.close();
    bw.flush();
    bw.close();
}
