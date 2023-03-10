package org.demo;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
//Data Store
public class WriteNumbers implements IWriteNumbers {
    private PrintWriter out;
    WriteNumbers() {
        try {
            out = new PrintWriter("numbers.txt");
        } catch (FileNotFoundException e) {
            new RuntimeException(e.getMessage());
        }
    }
    public void write(int n) {
        out.println(n);
    }
    public void close() {
        out.close();
        out = null;
    }
}
