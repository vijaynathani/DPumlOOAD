package d1Refactoring.anSolution;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.summingDouble;
import static java.util.stream.Collectors.summingInt;
import java.util.LinkedList;
import java.util.List;

class Customer {
	private final String _name;
	private final List<Rental> _rentals = new LinkedList<>();
	public Customer(String name) {
		_name = name;
	};
	public void addRental(Rental arg) {
		_rentals.add(arg);
	}
	public String getName() {
		return _name;
	}
	public String statement() {
		String result = "Rental Record for " + getName() + "\n";
		// for (Rental each : _rentals) {
		// result += "\t" + each.getMovie().getTitle() + "\t"
		// + String.valueOf(each.getCharge()) + "\n";
		// }
		result += _rentals.stream().map(e -> "\t" + e.getMovie().getTitle() + "\t" + e.getCharge() + "\n")
				.collect(joining());
		// add footer lines
		result += "Amount owed is " + String.valueOf(getTotalCharge()) + "\n";
		result += "You earned " + String.valueOf(getFrequentRenterPoints())
				+ " frequent renter points";
		return result;
	}
	private double getTotalCharge() {
		// double totalAmount = 0;
		// for (Rental each : _rentals)
		// totalAmount += each.getCharge();
		// return totalAmount;
		return _rentals.stream().collect(summingDouble(Rental::getCharge));

	}
	private int getFrequentRenterPoints() {
		// int frequentRenterPoints = 0;
		// for (Rental each : _rentals)
		// frequentRenterPoints += each.getFrequentRenterPoints();
		// return frequentRenterPoints;
		return _rentals.stream().collect(summingInt(Rental::getFrequentRenterPoints));
	}
}
