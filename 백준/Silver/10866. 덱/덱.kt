import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();

    val dequeue = ArrayDeque<String>();

    (1..N).forEach() {
        val op = br.readLine().split(" ");

        if(op[0]=="push_front") {
            dequeue.addFirst(op[1]);
        }
        if(op[0]=="push_back") {
            dequeue.addLast(op[1]);
        }
        if(op[0]=="pop_front") {
            if(dequeue.isEmpty()) bw.write("-1\n");
            else {
                bw.write(dequeue.pollFirst()+"\n");
            }
        }
        if(op[0]=="pop_back") {
            if(dequeue.isEmpty()) bw.write("-1\n");
            else {
                bw.write(dequeue.pollLast()+"\n");
            }
        }
        if(op[0]=="size") {
            bw.write(dequeue.size.toString() + "\n");
        }
        if(op[0]=="empty") {
            if(dequeue.isEmpty()) bw.write("1\n");
            else bw.write("0\n");
        }
        if(op[0]=="front") {
            if(dequeue.isEmpty()) bw.write("-1\n");
            else bw.write(dequeue.peekFirst()+"\n");
        }
        if(op[0]=="back") {
            if(dequeue.isEmpty()) bw.write("-1\n");
            else bw.write(dequeue.peekLast()+"\n");
        }
    }

    br.close();
    bw.flush();
    bw.close();
}