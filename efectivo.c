#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get the change we own from the user
    int pesos;
    do
    {
        pesos = get_int("Vuelto: ");
    }
    while (pesos < 0);
    // set the kind of coins but in Spanish
    int veintemil, diezmil, cincomil, mil, quinientos, cien, cincuenta, diez, billetes, monedas;
    veintemil = 0;
    diezmil = 0;
    cincomil = 0;
    mil = 0;
    quinientos = 0;
    cien = 0;
    cincuenta = 0;
    diez = 0;
    billetes = 0;
    monedas = 0;

    // counts how many 20 lucas
    while (pesos > 20000)
    {
        pesos = pesos - 20000;
        billetes++;
        veintemil++;
    }
    // counts how many 10 lucas
    while (pesos < 20000 && pesos > 9999)
    {
        pesos = pesos - 10000;
        billetes++;
        diezmil++;
    }
    // counts how many 5 lucas
    while (pesos < 10000 && pesos > 4999)
    {
        pesos = pesos - 5000;
        billetes++;
        cincomil++;
    }
    // counts how many mil
    while (pesos < 5000 && pesos > 999)
    {
        pesos = pesos - 1000;
        billetes++;
        mil++;
    }
    // cuantos 500
    while (pesos < 1000 && pesos > 499)
    {
        pesos = pesos - 500;
        monedas++;
        quinientos++;
    }

    // cuantos 100
    while (pesos < 500 && pesos > 99)
    {
        pesos = pesos - 100;
        monedas++;
        cien++;
    }

    // cuantos 50
    while (pesos < 100 && pesos > 49)
    {
        pesos = pesos - 50;
        monedas++;
        cincuenta++;
    }

    // cuantos 10

    while (pesos < 50 && pesos > 9)
    {
        pesos = pesos - 10;
        monedas++;
        diez++;
    }

    // se redondea a 10 o 0
    while (pesos < 10 && pesos > 0)
    {
        if (pesos > 4)
        {
            pesos = 0;
            monedas++;
            diez++;
        }
        else
        {
            pesos = 0;
        }
    }
    // prints the whole amount of coins needed to pay
    printf("Total de billetes: %i\n", billetes);
    printf("Total de monedas: %i\n", monedas);
    printf("$20.000: %i\n", veintemil);
    printf("$10.000: %i\n", diezmil);
    printf("$5.000: %i\n", cincomil);
    printf("$1.000: %i\n", mil);
    printf("$500: %i\n", quinientos);
    printf("$100: %i\n", cien);
    printf("$50: %i\n", cincuenta);
    printf("$10: %i\n", diez);

}