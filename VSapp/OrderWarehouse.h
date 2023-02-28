#pragma once
#include <map>
#include <string>
namespace feb28 {
	class IWarehouse
	{
	public:
		virtual bool hasInventory(const std::string& product, int quantity) = 0;
		virtual void remove(const std::string& product, int quantity) = 0;
		virtual ~IWarehouse() {}
	};

	class IEventBus
	{
	public:
		virtual void PostAsync(const std::string& product, int quantity) = 0;
		virtual void PostSync(const std::string& product, int quantity) = 0;
		virtual ~IEventBus() {}
	};

	class RealWarehouse : public IWarehouse
	{
		IEventBus* events;
		std::map<std::string, int> products;
		int inStock(const std::string& product);
	public:
		bool hasInventory(const std::string& product, int quantity);
		void remove(const std::string& product, int quantity);
		RealWarehouse(IEventBus* ev) : events{ ev } {	}
		void addProduct(const std::string& product, int quantity);
	};

	class Order
	{
		const std::string product;
		const int quantity;
		bool filled;
	public:
		Order(const std::string& p, int q) : product{ p }, quantity(q), filled(false) { }
		void fill(IWarehouse* warehouse);
		bool isFilled() { return filled; }
	};
}
