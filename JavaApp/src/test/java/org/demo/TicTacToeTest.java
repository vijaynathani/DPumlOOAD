package org.demo;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class TicTacToeTest {
    TicTacToe t = new TicTacToe();
    @Test
    public void allRowElementsAreSame() {
        assertFalse(t.over());
        t.setO(0,0);
        assertFalse(t.over());
        t.setO(0,1);
        assertFalse(t.over());
        t.setO(0,2);
        assertTrue(t.over());
    }
    //Write other tests for
    //    game over when all column elements are same
    //    game over when all left diagonal elements are same
    //    game over when all right diagonal elements are same
    //    game over when there is a tie or "no winner"
}

