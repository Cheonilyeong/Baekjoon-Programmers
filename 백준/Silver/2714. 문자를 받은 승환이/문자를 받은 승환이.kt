import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()

    repeat(T) {
        val message = br.readLine().split(" ")

        val R = message[0].toInt()
        val C = message[1].toInt()
        val arr = Array<CharArray>(R) {CharArray(C)}
        message[2].forEachIndexed { index, c ->
            arr[index/C][index%C] = c
        }

        val dy = listOf(0, 1, 0, -1)
        val dx = listOf(1, 0, -1, 0)
        var y = 0
        var x = 0
        var mode = 0
        var cnt = 0
        val str = StringBuilder()
        val ret = StringBuilder()
        val visited = Array<BooleanArray>(R) {BooleanArray(C)}
        while(true) {
            cnt++
            if(visited[y][x] == false) {
                visited[y][x] = true
                str.append(arr[y][x])
            }

            if(str.length == 5) {
                val m = str.toString().toInt(2)
                when(m) {
                    0 -> ret.append(" ")
                    else -> ret.append("${('A'+m-1)}")
                }
                str.clear()
            }

            val ny = y + dy[mode]
            val nx = x + dx[mode]
            if(ny<0 || ny>=R || nx<0 || nx>=C || visited[ny][nx]) {
                mode = (mode+1) % 4
            }
            y += dy[mode]
            x += dx[mode]
            if(cnt == R * C) break;
        }
        bw.write("${ret.trim()}\n")
    }
    br.close()
    bw.flush()
    bw.close()
}