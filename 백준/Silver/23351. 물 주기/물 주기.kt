import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val input = br.readLine().split(" ").map { it.toInt() }
    val N = input[0]
    val K = input[1]
    val A = input[2]
    val B = input[3]

    val arr = IntArray(N) {K}
    var index = 0
    var day = 1
    while(true) {
        if(index == N) index = 0

        repeat(A) {
            arr[index++] += B
        }

        repeat(N) {
            arr[it]--
        }

        if(arr.contains(0)) {
            println(day)
            break
        }

        day++
    }
}
