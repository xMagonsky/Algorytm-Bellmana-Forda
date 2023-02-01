#include <string>
#include <vector>

struct Krawedz {
	unsigned int wierzcholekDocelowy;
	double koszt;
};
typedef std::vector<std::vector<Krawedz>> Graf;


void wczytajGraf(const std::string& nazwaPliku);
