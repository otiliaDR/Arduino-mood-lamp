# Arduino-mood-lamp
## Introducere
În dorința de a crea un proiect util și plăcut, am ales să realizez o lampă de atmosferă cu Arduino pentru camera mea. Această lampă nu numai că oferă iluminare eficientă, ci aduce și o notă personalizată de culoare și atmosferă în spațiul meu personal. În acest document, voi detalia componentele și funcționalitățile proiectului, oferind o imagine clară asupra procesului de construcție și a rezultatului final.

## Materiale necesare
## Componente electronice:
* # Placă Arduino Nano - platforma de dezvoltare pentru gestionarea funcțiilor și comenzilor.
* # Senzor Ultrasonic (HC-SR04) - măsoară distanța și ajustează culorile lampii în funcție de aceasta.
* # Receptor Infraroșu (IR) - permite controlul culorilor lampii cu ajutorul unei telecomenzi infraroșii.
* # LED RGB - emite lumină într-o gamă variată de culori, permițând personalizarea atmosferei.
* # Rezistențe - necesare pentru a limita curentul prin LED-uri și a proteja componentele.
## Alte materiale:
* # Breadboard și fire de conexiune - pentru prototipare și conexiuni temporare între componente.
* # Carcasă și suport pentru lampă - protejează componentele și oferă un aspect estetic.
* # Telecomandă IR - pentru controlul culorilor lampii de la distanță.
* # Cablu USB - pentru conectarea plăcii Arduino la computer pentru programare și alimentare.
## Funcționalitate
Mood Lamp-ul meu este proiectat pentru a reflecta starea mea de spirit și pentru a oferi un ambient personalizat. Am integrat un receptor IR pentru a putea gestiona culorile în funcție de preferința de moment, utilizând o telecomandă. Astfel, pot selecta culoarea dorită folosind tastele 0-9. De asemenea, am adăugat un senzor Ultrasonic, astfel încât atunci când nu sunt aproape, lampa să rămână într-o singură nuanță - alb. Când distanța se micșorează sub acest număr, lampa trece în modul RGB, permițând personalizarea culorilor.
