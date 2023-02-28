package org.demo;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class M3OrderWarehouseTest {
    class MockWarehouse implements Warehouse {
        int removeCalled, removeQuantity;
        String removeProduct;
        boolean returnFromHasInventory = true;
        @Override
        public boolean hasInventory(String product, int quantity) {
            return returnFromHasInventory;
        }
        @Override
        public void remove(String product, int quantity) {
            removeCalled++;
            removeProduct = product;
            removeQuantity = quantity;
        }
    }
    MockWarehouse mwh = new MockWarehouse();
    String ipod = "ipod";
    int quantity = 50;
    @Test public void InStockTesting() {
        Order order = new Order(ipod, quantity);
        order.fill(mwh);
        assertEquals(1, mwh.removeCalled);
        assertEquals(ipod, mwh.removeProduct);
        assertEquals(quantity, mwh.removeQuantity);
    }
    @Test public void OutOfStockTesting() {
        Order order = new Order(ipod, quantity);
        mwh.returnFromHasInventory = false;
        order.fill(mwh);
        assertEquals(0, mwh.removeCalled);
    }
}
