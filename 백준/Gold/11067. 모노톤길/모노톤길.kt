import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()

    repeat(T) {
        val N = br.readLine().toInt()

        val adj = Array<ArrayList<Int>>(100004) {ArrayList<Int>()}
        repeat(N) {
            val (x, y) = br.readLine().split(" ").map{ it.toInt() }
            adj[x].add(y)
        }

        adj.forEach{
            it.sort()
        }

        var x = -1
        var y = 0
        var num = 0
        val cafe = HashMap<Int, Pair<Int,Int>>()

        while(num != N) {
            if(adj[x+1].size == 0) {
                x++
            } 
            else if(adj[x+1].size == 1) {
                x++
                cafe[++num] = Pair(x,y)
            }
            else {
                if(adj[x+1].first() == y) {
                    x++
                    for(i in 0 until adj[x].size) {
                        y = adj[x][i]
                        cafe[++num] = Pair(x,y)
                    }
                }
                else if(adj[x+1].last() == y) {
                    x++
                    for(i in adj[x].size-1 downTo 0) {
                        y = adj[x][i]
                        cafe[++num] = Pair(x,y)
                    }
                }
            }
        }

        val findCafe = br.readLine().split(" ").map{ it.toInt() }
        for(i in 1 until findCafe.size) {
            bw.write("${cafe[findCafe[i]]!!.first} ${cafe[findCafe[i]]!!.second} \n")
        }
    }

    br.close()
    bw.flush()
    bw.close()
}