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
    Order order = new Order(ipod, quantity);
    @Test public void InStockTesting() {
        order.fill(mwh);
        assertEquals(1, mwh.removeCalled);
        assertEquals(ipod, mwh.removeProduct);
        assertEquals(quantity, mwh.removeQuantity);
    }
    @Test public void OutOfStockTesting() {
        mwh.returnFromHasInventory = false;
        order.fill(mwh);
        assertEquals(0, mwh.removeCalled);
    }
    @Test public void EventTesting() {
        var meb = new MockEventBus();
        var rwh = new RealWarehouse(meb);
        rwh.addProduct(ipod, quantity + 1);
        order.fill(rwh);
        assertTrue(meb.asyncCalled);
        assertFalse(meb.syncCalled);
        assertEquals(ipod, meb.product);
        assertEquals(quantity, meb.quantity);
    }
    class MockEventBus implements EventBus {
        boolean asyncCalled, syncCalled;
        String product;
        int quantity;
        @Override
        public void postAsync(String product, int quantity) {
            asyncCalled = true;
            this.product = product;
            this.quantity = quantity;
        }
        @Override
        public void postSync(String product, int quantity) {
            syncCalled = true;
            this.product = product;
            this.quantity = quantity;
        }
    }
}
