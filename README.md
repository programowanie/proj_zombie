# Jantos Sebastian Henryk 

Projekt jest symulacją apokalipsy zombie. Symulacja opiera się na obiektach reprezentujących kraje. W każdym kraju znajdują się ludzie, na których własne statystyki mają wpływ także czynniki kraju (mocno uproszczone do siły, zręczności obywateli oraz środowiska, czy sprzyja wirusowi czy nie). Co kilka tur wirus rozprzestrzenia się sam z siebie zarażając kolejną osobę. W każdej turze - odpowiednik dnia - dochodzi do starcia między człowiekiem i zombie. Gdy wygrywa człowiek, zombie umiera, zaś gdy wygrywa zombie - zamienia tego człowieka w zombie. 

Zombie mają tu pewną przewagę, tym bardziej że nie zadają obrażeń, więc jeśli kogoś zamienią to ma on 100% HP, jednak w zamian mają dużą mniejszą szansę na trafienie (wygranie). Ludzi podzieliłem na trzy rodzaje: przeciętnych, wojskowych (lepsze statystyki ataków) oraz naukowców (są bezbronni, ich jedynym zadaniem jest praca nad lekiem). Zombie także dzielą się na trzy rodzaje: przeciętne, berserk (wyprowadza kilka ciosów naraz co daje mu większą szansę na zwycięstwo - odpowiednik wojskowych) oraz kamikaze (znikoma szansa na wygranie, ale po śmierci "wybuchają" zarażając kilka osób z otoczenia).

Szukanie leku opiera się na losowaniu naukowców, którzy jeśli będą mieć szczęście, poczynią postępy w badaniach, odejmując od (sztywno ustalonego pułapu) 10 000 pkt ilość punktów odpowiadającej ich inteligencji. Gdy wartość badań osiągnie 0, to lek jest gotowy. Wtedy lek z szansą 50/50 jest co turę rozpylany i ma szanse uleczyć kilka zombie naraz. Poprzez uleczenie rozumiem przywrócenie ich do ludzkiej postaci, jednak tylko do postaci przeciętnej (upraszam w ten sposób element trwania leczenia, osłabienie itd).

Symulacja będzie przyjmować dane wejściowe: n oznaczające ilość krajów w symulacji oraz: populację, liczbę naukowców, liczbę żołnierzy, liczbę zombie.

populacja = przeciętni + naukowcy + żołnierze + zombie

Aby łatwiej było podać większe ilości danych wejściowych, wszystkie liczby poza n będą wczytywane z pliku .txt.

