import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M) = br.readLine().split(" ").map{ it.toInt() }

    val set = HashSet<String>()
    for(i in 0 until N) {
        val word = br.readLine()
        set.add(word)
    }

    for(i in 0 until M) {
        val words = br.readLine().split(",")
        words.forEach {
            set.remove(it)
        }

        bw.write("${set.size}\n")
    }

    br.close()
    bw.flush()
    bw.close()
}