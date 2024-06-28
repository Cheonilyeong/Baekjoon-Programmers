import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val adj = IntArray(1004)
val visited = BooleanArray(1004)
var mx = Int.MIN_VALUE
var ret = 0

fun dfs(now: Int): Int {

    var sum = 1

    val next = adj[now]
    if(visited[next]) return sum

    visited[next] = true
    sum += dfs(next)
    visited[next] = false

    return sum
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    for(i in 0 until N) {
        val num =  br.readLine().toInt()
        adj[i] = num-1
    }

    for(i in 0 until N) {
        visited[i] = true
        val result = dfs(i)
        if(result > mx) {
            mx = result
            ret = i+1
        }
        visited[i] = false
    }

    println("$ret")

    br.close()
    bw.close()
}