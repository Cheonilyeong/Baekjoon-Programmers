import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, K) = br.readLine().trim().split(" ").map { it.toInt() }

    val arr = br.readLine().trim().split(" ").map{it.toInt()}.toList().sorted()

    println("${arr[K-1]}")

    br.close()
    bw.close()
}