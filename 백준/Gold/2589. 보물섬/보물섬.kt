import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val dy = listOf(-1, 0, 1, 0)
val dx = listOf(0, 1, 0, -1)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (R, C) = br.readLine().split(" ").map { it.toInt() }

    val map = Array<CharArray>(R) { CharArray(C) }
    // map 받기
    for(i in 0 until R) {
        val arr = br.readLine()
        for(j in 0 until C) {
            map[i][j] = arr[j]
        }
    }
    // 브루트포스
    var ret = 0
    for(i in 0 until R) {
        for(j in 0 until C) {
            if(map[i][j] == 'L') {
                // bfs
                val queue = LinkedList<Pair<Int,Int>>()
                val visited = Array<IntArray>(R) { IntArray(C) }
                visited[i][j] = 1
                queue.offer(Pair(i,j))

                while(queue.isNotEmpty()) {
                    val (y,x) = queue.poll()

                    ret = maxOf(ret, visited[y][x] - 1)

                    for(k in 0 until 4) {
                        val ny = y + dy[k]
                        val nx = x + dx[k]
                        if(ny<0 || ny>=R || nx<0 || nx>=C) continue
                        if(visited[ny][nx] > 0) continue
                        if(map[ny][nx] == 'W') continue
                        visited[ny][nx] = visited[y][x] + 1
                        queue.offer(Pair(ny,nx))
                    }
                }

            }
        }
    }
    println("${ret}")

    br.close()
    bw.close()
}