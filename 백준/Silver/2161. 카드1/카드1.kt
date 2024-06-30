import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    val queue = LinkedList<Int>()
    for(i in 1..N) queue.add(i)

    while(queue.size != 1) {
        print("${queue.poll()} ")
        queue.addLast(queue.pollFirst())
    }
    print("${queue.pollFirst()} ")
}