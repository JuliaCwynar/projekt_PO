# projekt_PO

Projekt, który na podstawie backtrackingu rozwiązuje plansze sudoku.
-Pliki wejściowe to liczby, które po sfromatowaniu tworzą plansze sudoku w ilości 28001;
-3 pliki o różnych rozszerszeniach - txt, csv, xlsx. Każde są czytane w inny sposób, ze względu na sposób ich zapisu w pliku wejściowym;
-Program zawiera klasę SudokuBoard, która przechowuje planszę sudoku jako wektor oraz przeładowane operatory potrzebne w dalszym działaniu programu;
-Program zawiera klasę SudokuSolver, która na podstawie backtrackingu rozwiązuje planszą oraz zapisuje czas jej rozwiązania;
-Program główny oblicza statystyki dotyczące czasu rozwiązywania plansz (najkrótsze i najdłuższe czasy rozwiązań, średnia, mediana, odchylenie standardowe)
-Program główny oblicza statystyki związane z liczbami w wejściowych nierozwiązanych planszach sudoku - ilość występowania konkretnej liczby w poszczególnym rzędzie, kolumnie, kwadracie 3x3 oraz ilość wystąpienia liczby ogółem we wszystkich planszach;
-Program daje możliwość rozwiązania konrketnej planszy sudoku z 28001 dostępnych, wyświetla plansze przed i po rozwiązaniu oraz jej czas rozwiązania;
