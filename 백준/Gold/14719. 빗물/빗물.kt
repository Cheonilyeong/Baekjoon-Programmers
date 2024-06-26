import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (H, W) = br.readLine().split(" ").map { it.toInt() }
    val arr = br.readLine().split(" ").map { it.toInt() }

    var ret = 0
    for(i in 0 until H) {
        var pre = -1
        for(j in 0 until W) {
            if(pre == -1 && arr[j] >= i+1) {
                pre = j
            }
            else if(pre != -1 && arr[j] >= i+1) {
                ret += (j-pre-1)
                pre = j
            }
        }
    }

    println("$ret")
}