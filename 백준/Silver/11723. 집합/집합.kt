import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();
    val S = BooleanArray(21);

    (1..N).forEach {
        val op = br.readLine().split(" ");

        if(op[0]=="add") {
            val num = op[1].toInt();
            S[num] = true;
        }
        if(op[0]=="remove") {
            val num = op[1].toInt();
            S[num] = false;
        }
        if(op[0]=="check") {
            val num = op[1].toInt();
            if(S[num]) bw.write(1.toString());
            else bw.write(0.toString());
            bw.newLine();
        }
        if(op[0]=="toggle") {
            val num = op[1].toInt();
            if(S[num]) S[num] = false;
            else S[num] = true;
        }
        if(op[0]=="all") {
            for(i in 1..20) {
                S[i] = true;
            }
        }
        if(op[0]=="empty") {
            for(i in 1..20) {
                S[i] = false;
            }
        }
    }

    br.close();
    bw.flush();
    bw.close();
}