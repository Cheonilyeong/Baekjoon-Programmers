import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val str = br.readLine()
    val ret = str.toCharArray().sortedByDescending { it }

    ret.forEach { bw.write("$it") }

    br.close()
    bw.flush()
    bw.close()
}