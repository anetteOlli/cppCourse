## Oppgave 1:

I oppgave a) og b) skal du jobbe videre med klassen Fraction fra leksjonen.

a) Lag funksjoner slik at vi kan skrive fraction1 – 5 og 5 – fraction1. Utvid main.cpp slik at du får prøvd dette. Hint:
Den ene funksjonen kan ikke være en medlemsfunksjon.

b) Teori: Forklar hvordan 5 - 3 - fraction1 - 7 - fraction2 blir tolket. Hvilke versjoner av operatoren - blir brukt?

## Oppgave 2:

Du skal lage en klasse med en heltallstabell (std::vector) som datamedlem. Den skal inneholde forskjellige tall. Tallene skal ikke være sortert på noen bestemt måte. Vi sier at vi har en mengde, og vi kaller klassen Set.

Du skal lage medlemsfunksjoner for operasjonene nedenfor. Medlemsfunksjonene skal enten være konstruktører eller operatorer.

Implementer følgende operasjoner:

* å lage en ny, tom mengde
* å finne unionen av to mengder. Funksjonen skal altså lage en ny mengde som inneholder alle elementene som er i hver enkelt av de to mengdene. Men husk at dersom et element er i begge mengdene, skal det likevel forekomme bare en gang i resultatmengden. Eksempel: Unionen av {1, 4, 3} og {4, 7} er lik {1, 4, 3, 7}.
* å legge et nytt tall inn i en mengde. Dersom tallet fins fra før, skal det ikke skje noe.
* å sette en mengde lik en annen mengde
* å skrive ut en mengde

Lag et lite program (main.cpp) slik at du får prøvd ut det du har laget.