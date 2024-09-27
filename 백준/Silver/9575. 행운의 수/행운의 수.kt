import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().trim().toInt()

    repeat(T) { t ->
        val arr = Array(3) { mutableListOf<Int>() }
        repeat(3) { index ->
            val N = br.readLine().trim().toInt()
            val num = br.readLine().trim().split(" ").map { it.toInt() }
            arr[index].addAll(num)
        }

        val set = mutableSetOf<String>()
        repeat(arr[0].size) { i ->
            repeat(arr[1].size) { j ->
                repeat(arr[2].size) { k ->
                    val num = (arr[0][i] + arr[1][j] + arr[2][k]).toString()
                    if(num.none{ it != '5' && it != '8'}) set.add(num)
                }
            }
        }

        println(set.size)
    }
}