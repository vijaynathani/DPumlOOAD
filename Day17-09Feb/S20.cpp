
class InchToPointConvertor {
    const static int POINTS_PER_INCH = 72;
    static float convertFromInchesToPoints(float quantity) {
        return quantity * POINTS_PER_INCH;
    }
};
