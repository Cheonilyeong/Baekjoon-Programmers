import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

// N, E, S, W
val dy = listOf(-1, 0, 1, 0)
val dx = listOf(0, 1, 0, -1)
val dir = hashMapOf("N" to 0, "E" to 1, "S" to 2, "W" to 3)

var ret = 0

fun go(y: Int, x: Int, d: String, arr: Array<IntArray>, boo: Array<BooleanArray>, cnt: Int) {
    if(cnt == 0) return

    val ny = y + dy[dir[d]!!]
    val nx = x + dx[dir[d]!!]

    if(boo[y][x]) {
        if(cnt == 1) return
        if(ny<0 || ny>=arr.size || nx<0 || nx>=arr[0].size) return
        go(ny, nx, d, arr, boo, cnt-1)
    }
    else {
        boo[y][x] = true
        ret++
        if(ny<0 || ny>=arr.size || nx<0 || nx>=arr[0].size) return
        go(ny, nx, d, arr, boo, maxOf(cnt-1, arr[y][x]-1))
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M, R) = br.readLine().split(" ").map { it.toInt() }
    val arr = Array<IntArray>(N) { IntArray(M) }
    val boo = Array<BooleanArray>(N) { BooleanArray(M) }

    for(i in 0 until N) {
        val line = br.readLine().split(" ").map { it.toInt() }
        line.forEachIndexed { index, j -> arr[i][index] = j }
    }

    repeat(R) {
        // 공격
        val attack = br.readLine().split(" ")
        var Y = attack[0].toInt()-1; var X = attack[1].toInt()-1
        val D = attack[2]
        go(Y, X, D, arr, boo, 1)

        // 수비
        val defence = br.readLine().split(" ").map { it.toInt() }
        Y = defence[0]-1; X = defence[1]-1
        boo[Y][X] = false
    }

    bw.write("$ret\n")
    for(i in 0 until N) {
        for(j in 0 until M) {
            bw.write("${if(boo[i][j]) "F" else "S"} ")
        }
        bw.write("\n")
    }

    br.close()
    bw.flush()
    bw.close()
}