import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    val list = ArrayList<Int>()
    for(i in 0 until N) {
        val num = br.readLine().split(" ").map{ it.toInt() }
        for(j in 0 until N) {
            list.add(num[j])
        }
    }
    list.sort()

    println("${list[N*N-N]}")

    br.close()
    bw.close()
}