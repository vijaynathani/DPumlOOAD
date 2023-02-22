package org.demo;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;
public class NumberTest {
    @Test
    public void test_for_odd_numbers() {
        var on = new Number(5);
        assertTrue(on.isOdd());
    }
}
