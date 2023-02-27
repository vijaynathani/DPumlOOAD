package org.demo;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class FindPrimesTest {
    FindPrimes sut = new FindPrimes(new Mock());
    int numberReceived;

    class Mock implements IWriteNumbers {
        @Override
        public void write(int n) {
            numberReceived = n;
        }
        @Override
        public void close() {
        }
    }
    @Test
    public void test_prime_number_written() {
        sut.process(7);
        assertEquals(7, numberReceived);
    }
    @Test
    public void test_nonprime_number_ignored() {
        sut.process(25);
        assertEquals(0, numberReceived);
    }
}
