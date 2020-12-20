//Omar

#include <stdlib.h>

#include <time.h>

#include <stdio.h>

 

int shuffle(int cards[])

{

    int a;

    int b;

    int c4rds[52];

    for (b = 0; b < 52; b++)

        c4rds[b] = (b/13+3)*100 + b%13 + 1;

 

    srand(time(NULL));

    for (b = 0; b < 52; b++)

    {

        do

        {

            a = rand() % 52;

        }

        while (c4rds[a] == 0);

        cards[b] = c4rds[a];

        c4rds[a] = 0;

    }

    return 0;

}

 

int con(int x)

{

    if ((x%100==11) ||(x%100==12) ||(x%100==13)) return (x/100)*100+10;

    else return x;

}

 

void pic(int aum)

{

    char d;

    int j;

    d = aum / 100;

    j = aum % 100;

    switch (j)

    {

        case 1:

        {

            printf("A,");

            break;

        }

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:

        case 9:

        case 10:

        {

            printf("%2d, ", j);

            break;

        }

        case 11:

        {

            printf("J, ");

            break;

        }

        case 12:

        {

            printf("Q, ");

            break;

        }

        case 13:

        {

            printf("K, ");

            break;

        }

    }

}

 

int go()

{

    int g;

    int usum=0;

    int wsum=0;

    int ucards[5]={0};

    int wcards[5]={0};

    int cxrds[52];

    char up;

    char d;

    

    printf("Hello! Welcome to Blackjack! "

    "You can use Ctrl+C to abort ");

    do

    {

        up = getchar();

    }

    while (up != '\n');

        printf("\n");

    

    shuffle(cxrds);

 

    ucards[0]=cxrds[0];

    ucards[1]=cxrds[1];

    wcards[0]=cxrds[2];

    wcards[1]=cxrds[3];

 

    printf("CPU cards:\n");

    pic(wcards[0]);

    printf("\n");

    printf("Your cards:\n");

    pic(ucards[0]);

    pic(ucards[1]);

    

    g = 0;

    for (g = 0; g < 2; g++)

    {

        if (ucards[g]%100 == 1)

        {

            printf("\nPick a value for Ace, Press 'Y' for 11 or 'N' for 1 :\n", g+1);

            do{

                d = getchar();

            } while (d!='y' && d!='n');

            

            if (d == 'y')

            {

                printf("\n11 for Ace\n");

                usum = usum + 11;

            }

            else if(d == 'n')

            {

                printf("\n1 for Ace\n");

                usum = usum +1;

            }

        }

        else if (con(ucards[g]) %100 ==10) usum = usum + 10;

        else usum = usum + ucards[g]%100;

        

        if (usum > 21)

        {

            printf("\nValue of Your Cards: %d\n\n",usum);

            printf("CPU wins!\n");

            return 1;

        }

        else if (usum == 21)

        {

            printf("\nValue of Your Cards: %d\n\n",usum);

            printf("\nYou win!\n");

            return 0;

        }

    }

    printf("\nValue of Your Cards: %d\n\n",usum);

    

    g=0;

    for (g = 0; g < 3; g++)

    {

        char j = 'n';

        

        printf("\nWould you like more cards? Y or N:\n");

        do

        {

            j = getchar();

        } while (j!='y' &&j!='n');

        

        if (j=='y')

        {

            printf("\nDealer dealt you another card.\n");

            ucards[g+2] = cxrds[g+4];

            printf("\nYour new card is:\n", g+3);

            pic(ucards[g+2]);

            

            if (ucards[g+2]%100 == 1)

            {

                printf("\nPick a value of Ace %d,'Y' for 11 or 'N' for 1:\n", g+3);

                do{

                    d = getchar();

                }

                while (d!='y' && d!='n');

                if (d == 'y')

                {

                    printf("You've picked 11 for Ace.\n");

                    usum = usum + 11;

                }

                else if(d == 'n')

                {

                    printf("You've picked 1 for Ace.\n");

                    usum = usum +1;

                }

            }

            else if (con(ucards[g+2]) %100 ==10) usum = usum + 10;

            else usum = usum + ucards[g+2]%100;

            

            if (usum > 21)

            {

                printf("\nValue of your cards now:%d\n\n", usum);

                printf("CPU wins!!\n");

                return 1;

            }

            else if (usum == 21)

            {

                printf("\nValue of your cards now:%d\n\n", usum);

                printf("You win!!\n");

                return 0;

            }

            else printf("\nValue of your cards now:%d\n\n", usum);

        }

        else

        {

            printf("\nValue of your cards now:%d\n\n", usum);

            break;

        }

    }

    if (g == 3)

    {

        printf("You win!\n");

        return 0;

    }

    

    printf("CPU cards:\n");

    pic(wcards[0]);

    pic(wcards[1]);

 

    if (wcards[0]%100 + wcards[1]%100 == 2)

    {

        wsum=12;

        printf("\nValue of CPU cards: %d\n\n", wsum);

    }

    else if ((con(wcards[0]))%100 + (con(wcards[1]))%100 ==1)

    {

        wsum=21;

        printf("\nValue of CPU cards: %d\n\n", wsum);

        printf("CPU wins!\n");

        return 1;

    }

    else if (wcards[0]%100==1 || wcards[1]%100==1)

    {

        wsum=(wcards[0] + wcards[1])%100+(rand()%2)*10;

        printf("\nValue of CPU cards: %d\n\n", wsum);

    }

    else

    {

        wsum = (con(wcards[0]))%100 + (con(wcards[1]))%100;

        printf("\nValue of CPU cards: %d\n\n", wsum);

    }

    

    for (g=0; g<3 && wsum<17; g++)

    {

        wcards[g+2] = cxrds[g+7];

        printf("CPU card %d is:\n", g+3);

        pic(wcards[g+2]);

        

        if (wcards[g+2]%100 == 1)

        {

            if (wsum+11 <= 21)

            {

                printf("CPU picked their ace to be 11\n");

                wsum = wsum+11;

                printf("\nValue of CPU cards: %d\n\n", wsum);

            }

            else

            {

                printf("CPU picked their ace to be 1\n");

                wsum = wsum+1;

                printf("\nValue of CPU cards: %d\n\n", wsum);

            }

        }

        else

        {

            wsum = wsum + con(wcards[g+2])%100;

            printf("\nValue of CPU cards: %d\n\n", wsum);

        }

    }

    if (g == 3)

    {

        printf("CPU wins!\n");

        return 1;

    }

    

    if (wsum>21 || usum > wsum)

    {

        printf("You win!\n");

        return 0;

    }

    else if (usum == wsum)

    {

        printf("It's a tie! \n");

        return 3;

    }

    else if (usum < wsum)

    {

        printf("CPU wins! \n");

        return 1;

    }

        

    return 3;

}

 

int main()

{

    char again;

    

    go();

    

    printf("\n Play Again?? Input 'y' or 'n': \n");

    do{

        again = getchar();

    }

    while (again!='y' && again!='n');

   

    if (again == 'y')

    {

        printf("\n Run it back\n");

        main();

    }

    return 0;

}
