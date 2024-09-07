import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    var arr = br.readLine().trim().split(" ").map { it.toLong() }.sorted()

    var max = 0L

    if(arr.size % 2 == 1) {
        max = arr.last()
        arr = arr.dropLast(1)
    }

    repeat(N/2) {
        max = max(max, arr[it] + arr[arr.lastIndex-it])
    }

    println(max)
}