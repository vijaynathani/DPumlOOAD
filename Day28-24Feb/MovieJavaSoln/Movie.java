package d1Refactoring.anSolution;
public class Movie {
	protected final String _title;
	private Price _priceCode;
	public Movie(String title, Price priceCode) {
		_title = title;
		_priceCode = priceCode;
	}
	public Price getPriceCode() {
		return _priceCode;
	}
	public void setPriceCode(Price arg) {
		_priceCode = arg;
	}
	public String getTitle() {
		return _title;
	}
	int getFrequentRenterPoints(int daysRented) {
		return _priceCode.getFrequentRenterPoints(daysRented);
	}
	public double getCharge(int daysRented) {
		return _priceCode.getCharge(daysRented);
	}
}
