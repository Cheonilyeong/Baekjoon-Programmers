import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val arr = br.readLine().toCharArray()
    val map = HashMap<Char,MutableList<Int>>()
    arr.forEachIndexed { index, c ->
        map.getOrPut(c) { mutableListOf() }.add(index)
    }

    var ret = 0
    for(i in 'A'..'Z') {
        for(j in i..'Z') {
            if(map[i]!![0] < map[j]!![0] && map[i]!![1] > map[j]!![0] && map[i]!![1] < map[j]!![1]) ret++
            if(map[i]!![0] > map[j]!![0] && map[i]!![0] < map[j]!![1] && map[i]!![1] > map[j]!![1]) ret++
        }
    }
    println("$ret")

    br.close()
    bw.close()
}