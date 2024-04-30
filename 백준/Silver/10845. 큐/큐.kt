import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();

    val queue = LinkedList<String>();
    (1..N).forEach() {
        val op = br.readLine().split(" ");

        if(op[0]=="push") {
            queue.offer(op[1]);
        }
        if(op[0]=="pop") {
            if(queue.isEmpty()) bw.write("-1\n");
            else {
                bw.write(queue.poll()+"\n");
            }
        }
        if(op[0]=="size") {
            bw.write(queue.size.toString() + "\n");
        }
        if(op[0]=="empty") {
            if(queue.isEmpty()) bw.write("1\n");
            else bw.write("0\n");
        }
        if(op[0]=="front") {
            if(queue.isEmpty()) bw.write("-1\n");
            else bw.write(queue.peekFirst()+"\n");
        }
        if(op[0]=="back") {
            if(queue.isEmpty()) bw.write("-1\n");
            else bw.write(queue.peekLast()+"\n");
        }
    }

    br.close();
    bw.flush();
    bw.close();
}