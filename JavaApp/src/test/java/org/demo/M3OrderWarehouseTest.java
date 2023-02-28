package org.demo;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class M3OrderWarehouseTest {
    class MockWarehouse implements Warehouse {
        int removeCalled, removeQuantity;
        String removeProduct;
        @Override
        public boolean hasInventory(String product, int quantity) {
            return true;
        }
        @Override
        public void remove(String product, int quantity) {
            removeCalled++;
            removeProduct = product;
            removeQuantity = quantity;
        }
    }
    @Test public void InStockTesting() {
        MockWarehouse mwh = new MockWarehouse();
        String ipod = "ipod";
        int quantity = 50;
        Order order = new Order(ipod, quantity);
        order.fill(mwh);
        assertEquals(1, mwh.removeCalled);
        assertEquals(ipod, mwh.removeProduct);
        assertEquals(quantity, mwh.removeQuantity);
    }
}
