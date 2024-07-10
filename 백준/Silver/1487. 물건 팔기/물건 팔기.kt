import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().trim().toInt()

    val arr = Array<Pair<Int,Int>>(N) {Pair(0,0)}

    for(i in 0 until N) {
        val (a, b) = br.readLine().split(" ").map{ it.toInt() }
        arr[i] = Pair(a,b)
    }

    var max = Int.MIN_VALUE // 이익
    var min = Int.MAX_VALUE // 가격
    arr.forEach {

        var cost = it.first
        var sum = 0
        for(a in arr) {
            if(a.first >= cost && cost > a.second) {
                sum += (cost - a.second)

                if(sum > max) {
                    max = sum
                    min = cost
                }
                else if(sum == max) {
                    min = minOf(min, cost)
                }
            }
        }
    }



    println("${if(max > 0) min else "0"  }")

    br.close()
    bw.close()
}