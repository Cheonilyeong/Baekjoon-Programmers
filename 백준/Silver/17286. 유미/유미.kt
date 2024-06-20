import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.pow
import kotlin.math.abs
import kotlin.math.sqrt

val v = ArrayList<Pair<Int,Int>>()
val visited = Array<Int>(3) {it -> 0}
var ret = Double.MAX_VALUE

fun go(x: Int, y: Int, cnt: Int, sum: Double) {
    if(cnt == 3) {
        ret = minOf(ret, sum)
        return
    }

    for(i in 0 until 3) {
        if(visited[i] == 1) continue
        visited[i] = 1
        val dist = sqrt((abs(x-v[i].first)*abs(x-v[i].first) + abs(y-v[i].second)*abs(y-v[i].second)).toDouble())
        go(v[i].first, v[i].second, cnt+1, sum+dist)
        visited[i] = 0
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (x, y) = br.readLine().split(" ").map { it.toInt() }

    for(i in 0 until 3) {
        val(xx, yy) = br.readLine().split(" ").map { it.toInt() };
        v.add(Pair(xx, yy))
    }

    go(x, y, 0, 0.0)
    println("${ret.toInt()}")
}