import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val array = IntArray(N)

    val num = br.readLine().split(" ").map { it.toInt() }
    for(i in 0 until N) {
        array[i] = num[i]
    }

    var ret = 0
    array.sortedByDescending { it }.forEachIndexed { index, i ->
        ret = maxOf(ret, i+index+2)
    }

    println("$ret")

    br.close()
    bw.close()
}