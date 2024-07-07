import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val N = br.readLine().toInt()
    val nums = br.readLine().split(" ").map { it.toInt() }.toSortedSet().joinToString(" ")

    println("$nums")

    br.close()
}