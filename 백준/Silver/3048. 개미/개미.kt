import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.Collections.swap

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N1, N2) = br.readLine().split(" ").map{ it.toInt() }
    val ant1 = br.readLine().reversed()
    val ant2 = br.readLine()
    val T = br.readLine().toInt()

    val antList = ArrayList<Pair<Char,String>>()
    ant1.forEach { c ->
        antList.add(Pair(c, "left"))
    }
    ant2.forEach { c ->
        antList.add(Pair(c, "right"))
    }

    repeat(T) {
        var i = 0
        while(i < N1+N2-1) {
            if(antList[i].second == "left" && antList[i+1].second == "right") {
                val(t1, t2) = antList[i]
                antList[i] = antList[i+1]
                antList[i+1] = Pair(t1,t2)
                i++
            }
            i++
        }
    }

    antList.forEach() {
        print("${it.first}")
    }

    br.close()
    bw.flush()
    bw.close()
}