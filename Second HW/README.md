<h1>Proiectarea algoritmilor</h1>
<h2>Tema 2</h2>
<ul>
    <li><h3>Problema 1</h3>
     În această problema am creat în primă fază graful de intersecție dintre cele
două grafuri diferite, după care aplic algoritmul DFS pe acest graf de intersecție.
Voi sorta în ordine descrescătoare nodurile în funcție de timpul de finalizare pentru 
a realiza o sortare topologică validă. În ultimul loop calculez numărul de căi de la nodul 1
până la fiecare vecin V al nodului U prin utilizarea programării dinamice. La fiecare calcul
al acestei sume aplic modulo pentru a rămâne în limitele problemei.
<ul><li>Complexitatea acestei rezolvări este dominată de găsirea graficului de intersecție.
Căutarea fiind una liniară are o complexitate de O(m<sup>2</sup>). Complexitatea spațială
a rezolvării este O(M + N) dată de graful de intersecție și arrayul utilizat pentru dp,
dar și de stivă și vectorul nodes.</li></ul>

</li>
    <li><h3>Problema 2</h3>
Pentru această problema am utilizat o lista de adiacență pentru a reprezenta graful
 și un map pentru a ține evidența gradului interior al fiecărui nod. Am aplicat 
sortarea topologică pe acest graf pentru a calcula numărul maxim de orașe vizitabile 
pentru fiecare nod. Acest lucru se face prin utilizarea programării dinamice, actualizez 
acest număr pentru fiecare vecin al unui nod procesat. Din acest motiv <b>maxCities[start] = 1</b>
deoarece minimul vizitat este mereu orașul din care se pleacă. În final, după ce se termină toate
actualizările programării dinamice valoarea din <b>maxCities[end]</b> va avea numărul maxim de orașe vizitabile.
    <ul><li>Complexitatea temporală a programului este O(N + M) deoarece vizităm fiecare nod iar cea 
spațială este de asemenea O(N + M).</li></ul></li>
    <li><h3>Problema 3</h3>
      În prima instanța am folosit două liste de adiacentă, una pentru graful
normal iar alta pentru graful invers. Am aplicat algoritmul Dijkstra pentru a
determina distanțele de la X și Y la toate celelalte noduri din graful inițial
iar apoi am folosit graful invers pentru a calcula distanțele de la nodul Z la
toate celelate noduri. În ultimul <b>for loop</b> am verificat dacă suma
distanțelor de la X la V, de la Y la V și de la V la Z este mai mică decât cea
găsită la pasul anterior. Dacă se găsește o distanță mai mică se actualizazeaza
valoarea minimă.
<ul><li>Complexitatea temporală a programului este O(M log N) dată de algoritmul
Dijkstra iar cea spațială este O(M + N)xz.</li></ul></li>
</ul>