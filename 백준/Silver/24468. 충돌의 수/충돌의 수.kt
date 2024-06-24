import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (L, N, T) = br.readLine().split(" ").map{ it.toInt() }
    val bolls = ArrayList<Pair<Int,String>>(N)
    val box = IntArray(L+1)
    for(i in 0 until N) {
        val (S, C) = br.readLine().split(" ")
        bolls.add(Pair(S.toInt(),C))
        box[S.toInt()]++
    }

    var cnt = 0
    for(i in 0 until T) {
        for(j in 0 until N) {
            if(bolls[j].second.equals("R")) {
                box[bolls[j].first]--
                box[bolls[j].first+1]++
                if(bolls[j].first+1 == L) bolls[j] = Pair(bolls[j].first+1, "L")
                else bolls[j] = Pair(bolls[j].first+1, "R")
            }
            else {
                box[bolls[j].first]--
                box[bolls[j].first-1]++
                if(bolls[j].first-1 == 0) bolls[j] = Pair(bolls[j].first-1, "R")
                else bolls[j] = Pair(bolls[j].first-1, "L")
            }
        }

        for(j in 0 until L) {
            if(box[j] == 2) cnt++
        }
    }

    println("$cnt")

    br.close()
    bw.close()
}