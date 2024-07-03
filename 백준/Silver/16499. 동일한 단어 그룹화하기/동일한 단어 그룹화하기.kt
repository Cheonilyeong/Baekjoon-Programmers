import java.io.BufferedReader
import java.io.InputStreamReader

fun check(cnt1: Array<Int>, cnt2: Array<Int>):Boolean {
    for(i in 0..25) {
        if(cnt1[i] != cnt2[i]) return false
    }
    return true
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val N = br.readLine().toInt()

    val arr = ArrayList<Array<Int>>()
    val visited = BooleanArray(N)

    repeat(N) {
        val str = br.readLine()

        val cnt = Array<Int>(30) {0}
        str.forEach { c ->
            cnt[c-'a']++
        }

        arr.add(cnt)
    }

    var ret = 0

    for(i in 0 until N) {
        if(visited[i]) continue
        for(j in i+1 until N) {
            if(check(arr[i], arr[j])) {
                visited[j] = true
            }
        }
        ret++
    }

    println("${ret}")

    br.close()
}