/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

/**
Funkcja wypisuje na ekran wektor liczb całkowitych.
@param  v wektor liczb całkowitych
*/
void print_v(const std::vector<int>& v);

/**
Funkcja zapisuje wektor do pliku.
@param  v wektor liczb całkowitych
@param fout strumień do pliku wyjściowego
*/
void print_f(const std::vector<int>& v, std::ofstream& fout);

/**
Funkcja wypisuje na ekran nieuporządkowaną mapę.
Używana do wypisywania grafu.
@param  mv nieuporządkowana mapa liczb całkowitych i wektorów liczb całkowitych.
*/
void print_mv(const std::unordered_map<int, std::vector<int>>& mv);

/**
Funkcja tworzy mapę visited liczb całkowitych i wartości logicznych do sprawdzania, które wierzchołki zostały odwiedzone.
@param  mv graf
@return mapa nieuporządkowana liczb całkowitych i wartości logicznych visited
*/
std::unordered_map<int, bool> visited_map1(std::unordered_map<int, std::vector<int>>& mv);


/**
Funkcja czyta z pliku graf do nieuporządkowanej mapy, w której klucz to wierzchołek, a wartość - wektor sąsiadów.
@param  fin strumień do pliku wejściowego
@param graph1 graf
*/
void read(std::ifstream& fin, std::unordered_map<int, std::vector<int>>& graph1);


/**
Funkcja przy użyciu algorytmu Depth-first Search znajduje w grafie wszystkie cykle zawierające dany wierzchołek
i wypisuje je na ekran oraz do pliku wyjściowego.
@param graph1 graf
@param v wierzchołek początkowy
@param w wierzchołek aktualny
@param stack wektor w roli stosu śledzący cykle
@param visited mapa przechowująca informację, czy dany wierzchołek był już odwiedzony
@param fout strumień do pliku wyjściowego
*/
void DFS(std::unordered_map<int, std::vector<int>>& graph1,
	int v, int w, std::vector<int>& stack, std::unordered_map<int, bool>& visited, std::ofstream& fout);


#endif // !FUNKCJE_H

