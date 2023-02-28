#include "OrderWareHouse.h"
namespace feb28 {
	bool RealWarehouse::hasInventory(const std::string& product, int quantity) {
		return inStock(product) >= quantity;
	}
	void RealWarehouse::remove(const std::string& product, int quantity) {
		products[product] = inStock(product) - quantity;
		if (inStock(product) <= 1) //Warning: the quantity used here can change frequently
			events->PostAsync(product, quantity);
		else
			events->PostSync(product, quantity);
	}
	int RealWarehouse::inStock(const std::string& product) {
		return products[product];
	}
	void RealWarehouse::addProduct(const std::string& product, int quantity) {
		products.insert({ product,quantity });
	}
	void Order::fill(IWarehouse* warehouse) {
		if (warehouse->hasInventory(product, quantity))
		{
			warehouse->remove(product, quantity);
			filled = true;
		}
	}
}