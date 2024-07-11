import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var ret = 0
    val car1 = ArrayList<String>()
    val car2 = ArrayList<String>()
    val map = mutableMapOf<String, Int>()

    val N = br.readLine().toInt()
    repeat(N) {
        val num = br.readLine()
        car1.add(num)
    }
    repeat(N) {
        val num = br.readLine()
        car2.add(num)
        map[num] = it
    }

    car1.forEachIndexed { index, car ->
        val a = map[car]!!
        val set = mutableSetOf<String>()
        for(i in 0 until a) {
            set.add(car2[i])
        }

        var flag = true
        for(i in 0 until index) {
            if(set.contains(car1[i])) continue
            else flag = false
        }

        if(flag == false) ret++
    }

    println("$ret")

    br.close()
    bw.close()
}