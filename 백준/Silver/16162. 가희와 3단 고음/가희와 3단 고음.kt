import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, A, D) = br.readLine().trim().split(" ").map { it.toLong() }
    val arr = br.readLine().trim().split(" ").map { it.toLong() }

    var m = A - D
    var count = 0
    arr.forEach {
        if (it == m + D) {
            m += D
            count++
        }
    }

    println(count)
}