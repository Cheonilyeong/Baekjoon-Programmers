import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()

    for(i in 0 until T) {

        val l = br.readLine().toInt()
        val (startY,startX) = br.readLine().split(" ").map { it.toInt() }
        val (endY, endX) = br.readLine().split(" ").map { it.toInt() }

        val visited = Array<IntArray>(l) { IntArray(l) }
        val queue = LinkedList<Pair<Int,Int>>()
        val dy = listOf(-1, -1, 1, 1, -2, -2, 2, 2)
        val dx = listOf(2, -2, 2, -2, 1, -1, 1, -1)
        queue.offer(Pair(startY,startX))
        visited[startY][startX] = 1
        while(queue.isNotEmpty()) {
            val (y, x) = queue.poll()

            if(y == endY && x == endX) {
                bw.write("${visited[y][x]-1}\n")
                break
            }

            for(i in 0 until 8) {
                val ny = y + dy[i]
                val nx = x + dx[i]
                if(ny<0 || ny>=l || nx<0 || nx>=l) continue
                if(visited[ny][nx] != 0) continue
                visited[ny][nx] = visited[y][x] + 1
                queue.offer(Pair(ny,nx))
            }
        }
    }

    br.close()
    bw.flush()
    bw.close()
}