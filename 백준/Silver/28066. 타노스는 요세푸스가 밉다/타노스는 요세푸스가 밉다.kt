import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, K) = br.readLine().trim().split(" ").map { it.toInt() }

    val queue = LinkedList<Int>()
    (1..N).forEach { queue.add(it) }

    while(true) {

        if(queue.size <= K) {
            println("${queue.poll()}")
            break
        }
        else {
            val first = queue.poll()
            queue.add(first)

            repeat(K-1) {
                queue.pop()
            }
        }
    }
}