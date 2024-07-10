import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val arr = br.readLine().trim().split(" ").map { it.toLong() }.reversed()

    var speed = 0L
    arr.forEach {
        if(speed > it) {
            speed = findSpeed(it, speed)
        }
        else {
            speed = it
        }
    }

    println("$speed")

    br.close()
    bw.close()
}

fun findSpeed(num: Long, min: Long) = if(min % num == 0L) min else min + (num - min%num) 