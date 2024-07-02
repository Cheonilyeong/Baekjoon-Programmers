import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.HashMap

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()

    repeat(n) {
        val land = br.readLine().trim().split(" ").map { it.toLong() }
        val map = HashMap<Long,Int>()
        var ret = Long.MAX_VALUE
        for(i in 0 until land[0]) {
            map[land[i.toInt()+1]] = (map[land[i.toInt()+1]] ?: 0) + 1
            if(map[land[i.toInt()+1]]!! > (land[0]/2)) ret = land[i.toInt()+1]
        }

        if(ret == Long.MAX_VALUE) bw.write("SYJKGW\n")
        else bw.write("$ret\n")
    }

    br.close()
    bw.flush()
    bw.close()
}