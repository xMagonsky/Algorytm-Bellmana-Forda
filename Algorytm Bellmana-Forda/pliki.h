#include <string>
#include <vector>
#include <unordered_map>


struct Krawedz {
	unsigned int wierzcholekDocelowy;
	double koszt;
};
typedef std::vector<std::vector<Krawedz>> Graf;

struct wczytanyGraf {
	Graf graf;
	std::unordered_map<int, int> idPlikoweNaProgram;
	std::vector<int> idProgramNaPlikowe;
	std::string error = "";
};


wczytanyGraf wczytajGraf(const std::string& nazwaPliku);
