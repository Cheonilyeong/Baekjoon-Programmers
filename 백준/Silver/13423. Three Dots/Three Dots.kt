import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().trim().toInt()

    repeat(T) { t ->

        val N = br.readLine().trim().toInt()
        val arr = br.readLine().trim().split(" ").map { it.toLong() }.sorted()

        val set = arr.toMutableSet()

        var count = 0
        for(a in arr.indices) {
            for(b in (a + 1)..arr.lastIndex) {
                if(set.contains(arr[b] + arr[b] - arr[a])) count++
            }
        }
        println(count)
    }

}