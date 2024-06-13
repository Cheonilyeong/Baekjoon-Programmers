import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

var R = 0
var C = 0
val dy = listOf(-1, 0, 1, 0)
val dx = listOf(0, 1, 0, -1)
val map = Array<CharArray>(255) {CharArray(255)}
val visited = Array<IntArray>(255) {IntArray(255)}

fun dfs(y: Int, x: Int): Pair<Int,Int> {

    var o = 0
    var v = 0

    if(map[y][x] == 'o') o++
    if(map[y][x] == 'v') v++

    for(i in 0 until 4) {
        val ny = y + dy[i]
        val nx = x + dx[i]
        if(ny<0 || ny>=R || nx<0 || nx>=C) continue
        if(visited[ny][nx] > 0 || map[ny][nx] == '#') continue
        visited[ny][nx] = 1
        val result = dfs(ny,nx)
        o += result.first
        v += result.second
    }

    return Pair(o,v)
}

fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val RC = br.readLine().split(" ").map{it.toInt()}
    R = RC[0]
    C = RC[1]

    for(i in 0 until R) {
        val a = br.readLine()
        a.forEachIndexed { index, c ->
            map[i][index] = c
        }
    }

    var oCnt = 0
    var vCnt = 0

    for(i in 0 until R) {
        for(j in 0 until C) {
            if(map[i][j] == '#') continue
            if(visited[i][j] > 0) continue
            visited[i][j] = 1
            val result = dfs(i, j)
            if(result.first > result.second) oCnt += result.first
            else vCnt += result.second
        }
    }

    println("$oCnt $vCnt")
    br.close()
    bw.close()
}