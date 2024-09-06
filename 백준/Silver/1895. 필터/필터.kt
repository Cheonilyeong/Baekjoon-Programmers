import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (R, C) = br.readLine().trim().split(" ").map { it.toInt() }

    val arr = Array(R) { IntArray(C) }

    repeat(R) { y ->
        val line = br.readLine().trim().split(" ").map { it.toInt() }
        repeat(C) { x ->
            arr[y][x] = line[x]
        }
    }

    val T = br.readLine().toInt()

    var count = 0
    repeat(R-2) { y ->
        repeat(C-2) { x ->

            val list = mutableListOf<Int>()
            for(a in (0..2)) {
                for(b in (0..2)) {
                    list.add(arr[y+a][x+b])
                }
            }
            list.sort()

            if(list[4] >= T) count++
        }
    }

    println(count)
}