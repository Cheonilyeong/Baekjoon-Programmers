import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().trim().toLong()
    val arr = br.readLine().trim().split(" ").map { it.toLong() }

    var speed = 1L
    var sum = 1L
    for(index in arr.lastIndex-1 downTo 0) {
        if(arr[index] >= speed + 1) {
            speed++
            sum += speed
        } else if(arr[index] == speed) {
            sum += speed
        } else {
            speed = arr[index]
            sum += arr[index]
        }
    }

    println(sum)
}