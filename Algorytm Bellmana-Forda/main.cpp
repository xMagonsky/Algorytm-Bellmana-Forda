#include "pliki.h"
#include <iostream>


int main() {
	wczytanyGraf dane = wczytajGraf("graf.txt");
	if (dane.error != "") {
		std::cout << dane.error;
		return 1;
	}


	return 0;
}
