# Algorytm Bellmana-Forda w C++

To repozytorium zawiera implementację algorytmu **Bellmana-Forda** w języku C++, który znajduje najkrótsze ścieżki od zadanego wierzchołka do wszystkich innych wierzchołków w grafie. Program działa na grafie zapisanym w pliku wejściowym i oblicza najkrótsze ścieżki dla wierzchołków podanych w innym pliku wejściowym.

## Funkcje
- **Reprezentacja grafu**: Graf jest reprezentowany jako lista sąsiedztwa z wagami krawędzi. Obsługiwane są zarówno krawędzie skierowane, jak i nieskierowane.
- **Format wejściowy**: Program korzysta z dwóch plików wejściowych – jeden zawiera graf, drugi listę wierzchołków, dla których mają zostać obliczone najkrótsze ścieżki.
- **Obliczanie najkrótszej ścieżki**: Algorytm Bellmana-Forda oblicza najkrótsze ścieżki i obsługuje przypadki z cyklem o ujemnej wadze.
- **Wyniki**: Wyniki są zapisywane w pliku wyjściowym, w którym znajdują się najkrótsze ścieżki od zadanych wierzchołków.
- **Obsługa przypadków brzegowych**: Jeśli wierzchołek nie istnieje w grafie lub wykryty zostanie cykl o ujemnej wadze, program odpowiednio obsłuży te przypadki.


## Format plików wejściowych

### Plik grafu (graph.txt)
Każda linia reprezentuje krawędź z określoną wagą:
- Krawędź skierowana: `u -> v : waga`
- Krawędź nieskierowana: `u - v : waga`

Przykład:

```
3 -> 2 : 54.5
12 -> 3 : 4.5
2 -> 5 : 34.65
5 -> 3 : 2.4
3 -> 12 : 1.00
```

### Plik z wierzchołkami (vertices.txt)
Każda linia zawiera jeden wierzchołek, dla którego obliczane będą najkrótsze ścieżki:

```
2
6
12
```

## Argumenty wiersza poleceń

Program może być uruchomiony z następującymi argumentami wiersza poleceń:

```
./bellman_ford -g <plik_grafu> -w <plik_wierzcholkow> -o <plik_wyjsciowy>
```

- `-g <plik_grafu>`: Określa plik wejściowy z grafem.
- `-w <plik_wierzcholkow>`: Określa plik z wierzchołkami, dla których mają zostać obliczone najkrótsze ścieżki.
- `-o <plik_wyjsciowy>`: Określa plik wyjściowy, w którym zapisane zostaną wyniki.

## Format wyjściowy

Plik wyjściowy zawiera najkrótsze ścieżki dla każdego wierzchołka z pliku wejściowego:

Przykład:

```
wierzcholek startowy: 2
2 -> 5 -> 3 : 37.05
2 -> 5 : 34.65
2 -> 5 -> 3 -> 12 : 38.05

wierzcholek startowy: 6
brak wierzcholka 6 w grafie

wierzcholek startowy: 12
12 -> 3 : 4.5
12 -> 3 -> 2 : 59.0
12 -> 3 -> 2 -> 5 : 93.65
```

Jeśli zostanie wykryty cykl o ujemnej wadze, program zapisze odpowiednią informację w pliku wynikowym.

## Szczegóły algorytmu

Algorytm Bellmana-Forda działa poprzez iteracyjne relaksowanie wszystkich krawędzi grafu. Obsługuje grafy z ujemnymi wagami krawędzi oraz wykrywa cykle o ujemnej wadze.

## Kroki:
1. Zainicjuj odległości wszystkich wierzchołków jako nieskończoność, z wyjątkiem wierzchołka startowego, którego odległość wynosi 0.
2. Dla każdego wierzchołka, zrelaksuj wszystkie krawędzie. Powtarzaj ten proces dla wszystkich wierzchołków.
3. Jeśli którakolwiek krawędź może być jeszcze zrelaksowana po |V|-1 iteracjach, graf zawiera cykl o ujemnej wadze.
