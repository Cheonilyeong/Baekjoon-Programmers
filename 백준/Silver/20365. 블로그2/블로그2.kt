import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val arr = br.readLine().trim()

    var pre = ' '
    val map = mutableMapOf(
        'B' to 0,
        'R' to 0
    )
    arr.forEach {
        if (pre != it) {
            map[it] = map[it]!! + 1
            pre = it
        }
    }

    println("${min(map['B']!!, map['R']!!) + 1}")
}