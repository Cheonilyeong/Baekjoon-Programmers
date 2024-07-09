import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val N = br.readLine().toInt()
    val (M, K) = br.readLine().split(" ").map { it.toInt() }
    val pen = br.readLine().split(" ").map { it.toInt() }.toList().sortedDescending()

    var cnt = 0
    var ret = 0
    for(i in pen) {
        if(cnt >= M*K) break
        cnt += i
        ret++
    }

    
    println("${if(cnt >= M*K)ret else "STRESS"}")

    br.close()
}