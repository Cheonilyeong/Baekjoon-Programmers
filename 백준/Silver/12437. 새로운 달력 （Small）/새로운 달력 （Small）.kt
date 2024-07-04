import java.awt.image.DataBufferDouble
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()
    for(i in 1..T) {
        val (a, b, c) = br.readLine().trim().split(" ").map{ it.toInt() }

        var week = 1
        var dayOfWeek = 0
        var day = 0

        repeat(a * b) {
            if(day == b) {
                day = 1
                if(dayOfWeek != c) week++
            }
            else day++

            if(dayOfWeek == c) {
                dayOfWeek = 1
                week++
            }
            else dayOfWeek++
        }

        println("Case #$i: $week")
    }
}