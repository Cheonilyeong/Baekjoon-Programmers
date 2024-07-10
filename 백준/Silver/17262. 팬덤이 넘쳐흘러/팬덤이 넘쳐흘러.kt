import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    var maxLeft = Int.MIN_VALUE
    var minRight = Int.MAX_VALUE
    repeat(N) {
        val (left, right) = br.readLine().split(" ").map { it.toInt() }
        maxLeft = maxOf(maxLeft, left)
        minRight = minOf(minRight, right)
    }

    println("${if(maxLeft <= minRight) "0" else (maxLeft - minRight)}")

    br.close()
    bw.close()
}

fun findSpeed(num: Long, min: Long) = (min + (num - min%num))