#include "Utilities.h"

bool exceedstime(Reservation r1, Reservation r2){
	int fulltime1 = r1.getArrivalDate().getHour() * 60 + r1.getArrivalDate().getMin();
	int fulltime2 = r2.getArrivalDate().getHour() * 60 + r2.getArrivalDate().getMin();

	if (abs(fulltime1- fulltime2) > MAX_WAIT)
		return false;

	return true;
}
