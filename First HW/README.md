© Dima Cosmin Alexandru 324CA
<h1>Tema Proiectarea Algoritmilor</h1>

<h4>In cadrul acestei teme am avut de implementat: </h3>
<ul> 
<li>Colorare.cpp</li>
<li>Compresie.cpp</li>
<li>Criptat.cpp</li>
<li>Oferta.cpp</li>
<li>Servere.cpp</li>
</ul>


<ul> 
<li><h3>Colorare.cpp</h3></li>

In cadrul aceste probleme am parcurs vectorul de perechi. La inceput, in
functie de ce element se afla pe primul loc Horizontal sau Vertical am
initializat variabila result. Result va fi 6 daca avem H pe prima pozitie
pentru ca deoarece am 2 dreptunghiuri orizontale am 3 posibilitati pt primul * 
2 posibilitati pentru al doilea = 6. Pentru vertical am 3 deoarece poate avea
3 posibiltati deoarece nu stim daca va avea altul V sau H langa. Acestea sunt
ulterior inmultite cu 3 respectiv 2 la puterea counter. Functia de ridicare
la putere este una generica de exponentiere rapida la care am adaugat modulul.
<br>Complexitatea este O(n), iar cea temporala este O(1).

<li><h3>Compresie.cpp</h3></li>

Pentru aceasta problema am iterat in ambii vectori alternativ folosind un
while. Folosesc sume partiale pentru a calcula un rolling sum. In cazul in
care sumele sunt egale adun la counter o unitate, counter care reprezinta
dimensiunea vectorului pe care trebuie sa o returnez. La final am adaugat
doua while-uri in care se intra in cazul in care raman elemente neadunate
din vectori. La final daca sumele sunt egale si diferite de zero adun inca 1
la counter. La final returnez fie -1 fie counterul.
<br>Complexitatea temporala este este O(n), iar pentru cea temporala nu am stocat
nicaieri alte informatii.

<li><h3>Criptat.cpp</h3></li>
Pentru criptat nu mi-am dat seama de rezolvarea eficienta a problemei asa ca
ales sa folosesc metoda <strong>Brute Force</strong>. Am creat fiecare
combinatie de parola si am verificat. La final am returnat cel mai lung cuvant
care respecta conditia din enunt.

<li><h3>Oferta.cpp</h3></li>
Aici am folosit coneptul de programare dinamica pentru a stoca sumele.
Complexitatea temporala est O(n) iar cea spatiala este de asemenea O(n)
pentru ca am folosit vectorul de programare dinamica. Metoda mea functioneaza
prin a verifica toate cele 3 metode de grupare a produselor, iar apoi adauga
in vectorul de DP acest rezultat. La final, ultimul element din DP va fi
suma pe care noi o cautam.

<li><h3>Servere.cpp</h3></li>
Pentru aceasta problema am folosit o cautare binara care gaseste puterea la
care trebuie sa fie alimentate toate serverele. Initial left si right sunt
minimul si maximul din al doilea vector. La fiecare iteratie a while-ului
verific daca mid-ul pe care l-am gasit este mai eficient / ineficient decat
mid + precizia aleasa. Aceasta verificare se face prin utilizarea a doua
for-uri care folosesc formula precizata din enunt pe care am implementat-o
in alta functie. In final modific left si right in functie de rezultatele 
celor doua for-uri.<br>
Complexitatea temporala a programului este O(nlog(n))
</ul>