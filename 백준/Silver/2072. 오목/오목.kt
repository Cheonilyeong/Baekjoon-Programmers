import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val dy = listOf(-1, 1, 0, 0, -1, 1, -1, 1)
val dx = listOf(0, 0, -1, 1, -1, 1, 1, -1)
val arr = Array<IntArray>(19) { IntArray(19) }

fun check(y: Int, x: Int, color: Int, mode: Int): Int {
    if (y < 0 || y >= 19 || x < 0 || x >= 19 || arr[y][x] != color) return 0

    var cnt = 1
    val ny = y + dy[mode]
    val nx = x + dx[mode]

    cnt += check(ny, nx, color, mode)

    return cnt
}


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var flag = false

    val N = br.readLine().toInt()
    for(i in 0 until N) {
        var (y, x) = br.readLine().split(" ").map { it.toInt() }
        y--; x--
        if(i % 2 == 0) arr[y][x] = 1
        else arr[y][x] = 2

        for(j in 0..6 step 2){
            if(check(y, x, arr[y][x], j) + check(y, x, arr[y][x], j+1) == 6) {
                flag = true
                println("${i + 1}")
                break
            }
        }
        if(flag) break
    }

    if(!flag) println("-1")

    br.close()
    bw.close()
}