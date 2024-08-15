import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    val arr = Array<IntArray>(N) { IntArray(N) }

    repeat(N) { y ->
        val num = br.readLine().split(" ").map { it.toInt() }
        repeat(N) { x ->
            arr[y][x] = num[x]
        }
    }

    println(go(0,0, N, arr))
}

fun go(y: Int, x: Int, n: Int, arr: Array<IntArray>): Int {
    val num = ArrayList<Int>()

    if(n == 1) return arr[y][x]
    if(n == 2) {
        num.add(arr[y][x])
        num.add(arr[y+1][x])
        num.add(arr[y][x+1])
        num.add(arr[y+1][x+1])
    }
    else {
        num.add(go(y, x, n/2, arr))
        num.add(go(y+n/2, x, n/2, arr))
        num.add(go(y, x+n/2, n/2, arr))
        num.add(go(y+n/2, x+n/2, n/2, arr))
    }

    return num.sorted()[1]
}
