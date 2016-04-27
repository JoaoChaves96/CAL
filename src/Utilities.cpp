#include "Utilities.h"

/**
 * Checks if a passenger has exceeded the maximum waiting time (30min)
 */
bool exceedsTime(Reservation r1, Reservation r2){
	int MAX_WAIT = 30;
	int fulltime1 = r1.getArrivalDate().getHour() * 60 + r1.getArrivalDate().getMin();
	int fulltime2 = r2.getArrivalDate().getHour() * 60 + r2.getArrivalDate().getMin();

	if (abs(fulltime1- fulltime2) > MAX_WAIT)
		return true;

	return false;
}
