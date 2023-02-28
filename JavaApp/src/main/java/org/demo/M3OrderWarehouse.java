package org.demo;
import java.util.HashMap;
import java.util.Map;

//Exercise for proxy pattern
interface Warehouse {
    boolean hasInventory(String product, int quantity);
    void remove(String product, int quantity);
}

interface EventBus {
    void postAsync(String product, int quantity);
    void postSync(String product, int quantity);
}

class RealWarehouse implements Warehouse {
    public RealWarehouse(EventBus events) {
        this.events = events;
    }
    @Override public boolean hasInventory(String product, int quantity) {
        return inStock(product) >= quantity;
    }
    @Override public void remove(String product, int quantity) {
        products.put(product, inStock(product) - quantity);
        if (inStock(product) <= 1) // Warning: inStock quantity used here can change frequently
            events.postAsync(product, quantity);
        else
            events.postSync(product, quantity);
    }
    private int inStock(String product) {
        Integer quantity = products.get(product);
        return quantity == null ? 0 : quantity;
    }
    public void addProduct(String product, int quantity) {
        products.put(product, quantity);
    }
    private final Map<String, Integer> products = new HashMap<>();
    private final EventBus events;
}

class Order {
    public Order(String product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }
    public void fill(Warehouse warehouse) {
        if (warehouse.hasInventory(product, quantity)) {
            warehouse.remove(product, quantity);
            filled = true;
        }
    }
    public boolean isFilled() {
        return filled;
    }
    private boolean filled = false;
    private final String product;
    private final int quantity;
}

/*
Write the following tests for class Order by mocking out Warehouse
1) Testing In Stock:
      - Create an order for "ipod", 50 pieces
      - Pass warehouse to ensure that order can be fulfilled
      - Ensure that remove function was called of warehouse with right parameters ONCE only.
2) Testing out of stock:
      - create an order for "ipod", 50 pieces
      - Pass warehouse to ensure that order cannot be fulfilled.
      - Ensure that remove function was NEVER called of warehouse
3) Testing Events passed successfully
      - Create an order for "ipod", 50 pieces
      - Pass RealWarehouse object to ensure that order can be fulfilled
      - Mock out the Eventbus
      - Ensure that either async or sync function of Eventbus is called with right parameters.
Write the above test by creating mocks.
*/
public class M3OrderWarehouse {
}
