import java.io.BufferedReader
import java.io.InputStreamReader

var ret = 0

fun go(num: Int) {
    if(num == 1) return

    if(num % 2 == 1) {
        go(num/2)
        go(num/2+1)
        ret += ((num/2) * (num/2+1))
    }
    else {
        go(num/2)
        go(num/2)
        ret += ((num/2) * (num/2))
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val N = br.readLine().toInt()
    go(N)

    println("${ret}")

    br.close()
}