#include "pliki.h"
#include <fstream>
#include <unordered_map>


bool pustaLinia(std::string line) {
	for (int i = 0; i < line.size(); i++) {
		if (!std::isspace(line[i]))
			return false;
	}
	return true;
}

void wczytajGraf(const std::string& nazwaPliku) {
	Graf graf;

	std::ifstream plik(nazwaPliku);

	if (!plik.is_open())
		return;

	//uwagi techniczne
	unsigned int indexWierzcholka = 0;
	std::unordered_map<int, int> idPlikoweNaProgram;
	std::vector<int> idProgramNaPlikowe;


	std::string linia;
	while (std::getline(plik, linia)) {
		//jak pusta linia to przej do kolejnej linii
		if (pustaLinia(linia))
			continue;

		//usuwanie bialych znakow z linii
		std::string nowaLinia;
		for (auto& znak : linia) {
			if (!std::isspace(znak))
				nowaLinia += znak;
		}
		linia = nowaLinia;


		size_t strzalka = linia.find("->");
		size_t dwukropek = linia.find(':');

		unsigned int zWierzcholkaPlikowego = stoi(linia.substr(0, strzalka));
		unsigned int doWierzcholkaPlikowego = stoi(linia.substr(strzalka + 2, dwukropek - strzalka - 2));
		double koszt = stod(linia.substr(dwukropek + 1));
		

		if (idPlikoweNaProgram.find(zWierzcholkaPlikowego) == idPlikoweNaProgram.end()) {
			idPlikoweNaProgram[zWierzcholkaPlikowego] = indexWierzcholka;
			idProgramNaPlikowe.push_back(zWierzcholkaPlikowego);
			graf.push_back({});
			indexWierzcholka++;
		}
		unsigned int zWierzcholka = idPlikoweNaProgram[zWierzcholkaPlikowego];

		if (idPlikoweNaProgram.find(doWierzcholkaPlikowego) == idPlikoweNaProgram.end()) {
			idPlikoweNaProgram[doWierzcholkaPlikowego] = indexWierzcholka;
			idProgramNaPlikowe.push_back(doWierzcholkaPlikowego);
			graf.push_back({});
			indexWierzcholka++;
		}
		unsigned int doWierzcholka = idPlikoweNaProgram[doWierzcholkaPlikowego];

		graf[zWierzcholka].push_back(Krawedz{doWierzcholka, koszt});
	}
}
