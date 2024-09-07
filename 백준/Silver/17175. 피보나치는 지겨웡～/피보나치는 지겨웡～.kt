import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val fibo = LongArray(55)

    fibo[0] = 1
    fibo[1] = 1
    repeat(55) {
        if(it - 2 < 0) return@repeat
        fibo[it] = (fibo[it - 1] % 1000000007 + fibo[it - 2] % 1000000007 + 1) % 1000000007
    }

    println(fibo[N])
}