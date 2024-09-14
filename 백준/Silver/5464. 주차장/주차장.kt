import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M) = br.readLine().trim().split(" ").map { it.toInt() }

    val price = IntArray(N)
    repeat(N) {
        price[it] = br.readLine().trim().toInt()
    }

    val weight = IntArray(M)
    repeat(M) {
        weight[it] = br.readLine().trim().toInt()
    }

    val arr = IntArray(N) {-1}
    val queue = LinkedList<Int>()
    var sum = 0
    repeat(M*2) {
        var car = br.readLine().trim().toInt()

        if(car > 0) {
            val index = arr.indexOfFirst { it == -1 }

            if(index != -1) {
                arr[index] = car
            } else {
                queue.add(car)
            }
        } else {
            car = abs(car)
            val index = arr.indexOfFirst { it == car }

            arr[index] = -1
            sum += price[index] * weight[car - 1]

            while(queue.isNotEmpty()) {
                val index2 = arr.indexOfFirst { it == -1 }

                if(index2 != -1) {
                    arr[index2] = queue.poll()
                } else {
                    break
                }
            }
        }
    }

    println(sum)
}