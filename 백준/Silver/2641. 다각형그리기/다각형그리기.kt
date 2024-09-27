import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().trim().toInt()
    val answer = br.readLine().trim().split(" ")
    val answer2 = answer.map {
        when (it) {
            "1" -> "3"
            "2" -> "4"
            "3" -> "1"
            "4" -> "2"
            else -> {}
        }
    }

    val M = br.readLine().trim().toInt()

    val result: MutableList<List<String>> = mutableListOf()
    repeat(M) {
        val arr = br.readLine().trim().split(" ")
        repeat(arr.size) {
            val newArr = arr.takeLast(arr.size-it) + arr.take(it)

            if(newArr == answer || newArr == answer2 || newArr == answer.reversed() || newArr == answer2.reversed()) {
                result.add(arr)
            }
        }
    }

    println(result.size)
    println(result.joinToString("\n") { it.joinToString(" ") })
}