#include <iostream>



char pos = 'x';
int x = 0;
int y = 0;
int limite = 10;
int cont = 0;
int gdx = 3, gdy = 3;
int adx = 9, ady = 9;
int mdx = 7, mdy = 2;
int edx = 2, edy = 8;


int readmovimiento()
{
    int mov;
    printf("Arriba [1] \nAbajo[2] \nIzquierda[3]\nDerecha [4]\nIngresa tu siguiente movimiento:");
    scanf_s("%d", &mov);
    return mov;
}
void comprobarvida(int& vidas) {
    if (vidas > 0)
    {

    }
    else
    {
        printf("Game over");
        exit(0);
    }
}
void outofmap()
{
    printf("Saliste del mapa :( intenta de nuevo y elige otra direccion \n");
}
bool inmap(int x, int y, int limite) {
    return (x >= 0 && y >= 0 && x < limite && y < limite);
}
void imprimirMapa(char map[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}
void moverminijuego(int& x, int& y, char identificador, bool resuelto, char map[10][10])
{
    if (resuelto) {
        return;
    }
    int newx = x;
    int newy = y;
    int movimiento = rand() % 4;

    switch (movimiento)
    {
    case 0: newx -= 1;
        break;
    case 1: newx += 1;
        break;
    case 2: newy -= 1;
        break;
    case 3: newy += 1;
        break;
    }

    if (inmap(newx, newy, limite) && map[newx][newy] != 'x' && map[newx][newy] == '-')
    {
        map[x][y] = '-';
        x = newx;
        y = newy;
        map[x][y] = identificador;
    }

}
void movertodoslosminijuegos(char map[10][10], bool& g, bool& a, bool& m, bool& e)
{
    moverminijuego(gdx, gdy, 'g', g, map);
    moverminijuego(adx, ady, 'a', a, map);
    moverminijuego(mdx, mdy, 'm', m, map);
    moverminijuego(edx, edy, 'e', e, map);
}
void pista(int& vidas, const int& contmin) {
    char pista;
    printf("Deseas una pista por una vida? (s/n): ");
    scanf_s(" %c", &pista);
    if (pista == 's')
    {
        vidas--;
        switch (contmin)
        {
        case 0:printf("Es un animal\n");
            printf("Te quedan %d vidas\n", vidas);
            break;
        case 1:printf("Es un sentimiento\n");
            printf("Te quedan %d vidas\n", vidas);
            break;
        case 2:
            printf("Es muy dificil, lo siento no hay pistas :(\n");
            printf("Te quedan %d vidas\n", vidas);
            break;
        case 3:
            printf("Ha sido un buen juego\n");
            printf("Te quedan %d vidas\n", vidas);
            break;
        }
    }


}
void minijuego1(int& vidas, int contmin)
{
    printf("                                                          *Primer minijuego*\nNivel:Facil\n");
    pista(vidas, contmin);
    char word[4] = { 'l', 'o', 'r','o' };
    char adv[4];
    for (int i = 0; i < 4; i++)
    {
        adv[i] = '_';
        printf(" %c", adv[i]);
    }
    printf("\n");

    while (vidas > 0)
    {
        char letra;
        bool letracorrecta = false;
        bool frasecorrecta = true;
        printf("Ingresa una letra: ");
        scanf_s(" %c", &letra);

        for (int i = 0; i < 4; i++)
        {
            if (word[i] == letra)
            {
                adv[i] = letra;
                letracorrecta = true;
            }
        }
        if (!letracorrecta) {
            vidas--;
        }

        for (int i = 0; i < 4; i++)
        {
            printf("%c ", adv[i]);
        }
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            if (word[i] != adv[i])
            {
                frasecorrecta = false;
                break;
            }
        }
        if (frasecorrecta)
        {
            system("cls");
            printf("Felicidades, completaste el nivel facil y ganaste 2 vidas. ¡Te quedan 3 mapas por completar!");
            vidas += 2;
            break;
        }
        printf("Te quedan %d vidas\n", vidas);

    }
    printf("\n");

}
void minijuego2(int& vidas, int contmin)
{
    printf("                                                          *Segundo minijuego*\nNivel:Intermedio\n");
    pista(vidas, contmin);
    char word[4] = { 'o', 'd', 'i' , 'o' };
    char adv[4];
    for (int i = 0; i < 4; i++)
    {
        adv[i] = '_';
        printf("%c", adv[i]);
    }
    printf("\n");
    while (vidas > 0)
    {
        char letra;
        bool letracorrecta = false;
        bool frasecorrecta = true;
        printf("Ingresa una letra: ");
        scanf_s(" %c", &letra);
        for (int i = 0; i < 4; i++)
        {
            if (word[i] == letra)
            {
                adv[i] = letra;
                letracorrecta = true;
            }
        }
        if (!letracorrecta) {
            vidas--;
        }
        for (int i = 0; i < 4; i++)
        {
            printf("%c ", adv[i]);
        }
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            if (word[i] != adv[i])
            {
                frasecorrecta = false;
                break;
            }
        }
        if (frasecorrecta)
        {
            system("cls");
            printf("Felicidades, completaste el nivel intermerdio y ganaste 2 vidas. ¡Te quedan 2 mapas por completar!");
            vidas += 2;
            break;
        }
        printf("Te quedan %d vidas\n", vidas);

    }
    printf("\n");


}
void minijuego3(int& vidas, int contmin)
{
    printf("                                                          *Tercer minijuego*\nNivel:Dificil\n");
    pista(vidas, contmin);
    char word[7] = { 'd', 'i', 'f' , 'i', 'c','i','l' };
    char adv[7];
    char letra;
    for (int i = 0; i < 7; i++)
    {
        adv[i] = '_';
        printf("%c", adv[i]);
    }
    printf("\n");
    while (vidas > 0)
    {
        bool letracorrecta = false;
        bool frasecorrecta = true;
        printf("Ingresa una letra: ");
        scanf_s(" %c", &letra);
        for (int i = 0; i < 7; i++)
        {
            if (word[i] == letra)
            {
                adv[i] = letra;
                letracorrecta = true;
            }
        }
        if (!letracorrecta) {
            vidas--;
        }
        for (int i = 0; i < 7; i++)
        {
            printf("%c ", adv[i]);
        }
        printf("\n");
        for (int i = 0; i < 7; i++)
        {
            if (word[i] != adv[i])
            {
                frasecorrecta = false;
                break;
            }
        }
        if (frasecorrecta)
        {
            system("cls");
            printf("Felicidades, completaste el nivel dificil y ganaste 2 vidas. ¡Te queda 1 mapa por completar!");
            vidas += 2;
            break;
        }
        printf("Te quedan %d vidas\n", vidas);

    }
    printf("\n");

}
void minijuego4(int& vidas, int contmin)
{
    printf("                                                          *Ultimo minijuego*\nNivel:Ingles\n");
    pista(vidas, contmin);
    char word[4] = { 'g', 'a', 'm' , 'e' };
    char adv[4];
    for (int i = 0; i < 4; i++)
    {
        adv[i] = '_';
        printf("%c", adv[i]);
    }
    printf("\n");
    while (vidas > 0)
    {
        char letra;
        bool letracorrecta = false;
        bool frasecorrecta = true;
        printf("Ingresa una letra: ");
        scanf_s(" %c", &letra);
        for (int i = 0; i < 4; i++)
        {
            if (word[i] == letra)
            {
                adv[i] = letra;
                letracorrecta = true;
            }
        }
        if (!letracorrecta) {
            vidas--;
        }
        for (int i = 0; i < 4; i++)
        {
            printf("%c ", adv[i]);
        }
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            if (word[i] != adv[i])
            {

                frasecorrecta = false;
                break;
            }
        }
        if (frasecorrecta)
        {
            system("cls");
            break;
        }
        printf("Te quedan %d vidas\n", vidas);

    }
}
void iniciarmapa(char map[10][10]) {
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j) {
            map[i][j] = '-';
        }
    }
}
void actualizarmovimiento(char map[10][10], bool& a, bool& g, bool& m, bool& e, int& vidas, int& contmin, int& contmov)
{
    while (pos != 'a' && pos != 'g' && pos != 'm' && pos != 'e')
    {
        int mov = readmovimiento();

        switch (mov)
        {
        case 1:
            x--;
            if (inmap(x, y, limite))
            {
                map[x + 1][y] = '-';
                pos = map[x][y];
                map[x][y] = 'x';
                contmov++;
                system("cls");
            }
            else
            {
                system("cls");
                outofmap();
                x++;
            }
            break;
        case 2:
            x++;
            if (inmap(x, y, limite))
            {
                map[x - 1][y] = '-';
                pos = map[x][y];
                map[x][y] = 'x';
                contmov++;
                system("cls");
            }
            else
            {
                system("cls");
                outofmap();
                x--;
            }
            break;
        case 3:
            y--;
            if (inmap(x, y, limite))
            {
                map[x][y + 1] = '-';
                pos = map[x][y];
                map[x][y] = 'x';
                contmov++;
                system("cls");
            }
            else
            {
                system("cls");
                outofmap();
                y++;
            }
            break;
        case 4:
            y++;
            if (inmap(x, y, limite))
            {
                map[x][y - 1] = '-';
                pos = map[x][y];
                map[x][y] = 'x';
                contmov++;
                system("cls");
            }
            else
            {
                system("cls");
                outofmap();
                y--;
            }
            break;

        }


        if ((pos == 'g' || pos == 'a' || pos == 'm' || pos == 'e'))
        {
            if (contmin == 0)
            {
                minijuego1(vidas, contmin);
                if (pos == 'g')
                {
                    g = true;
                    map[gdx][gdy] = '-';
                }
                if (pos == 'a')
                {
                    a = true;
                    map[adx][ady] = '-';
                }
                if (pos == 'm')
                {
                    m = true;
                    map[mdx][mdy] = '-';
                }
                if (pos == 'e')
                {
                    e = true;
                    map[edx][edy] = '-';
                }
                contmin++;
                pos = 'x';
                map[x][y] = 'x';
                imprimirMapa(map);
                break;
            }
            else if (contmin == 1)
            {
                minijuego2(vidas, contmin);
                if (pos == 'g')
                {
                    g = true;
                    map[gdx][gdy] = '-';
                }
                if (pos == 'a')
                {
                    a = true;
                    map[adx][ady] = '-';
                }
                if (pos == 'm')
                {
                    m = true;
                    map[mdx][mdy] = '-';
                }
                if (pos == 'e')
                {
                    e = true;
                    map[edx][edy] = '-';
                }
                contmin++;
                pos = 'x';
                map[x][y] = 'x';
                imprimirMapa(map);
                break;
            }
            else if (contmin == 2)
            {
                minijuego3(vidas, contmin);
                if (pos == 'g')
                {
                    g = true;
                    map[gdx][gdy] = '-';
                }
                if (pos == 'a')
                {
                    a = true;
                    map[adx][ady] = '-';
                }
                if (pos == 'm')
                {
                    m = true;
                    map[mdx][mdy] = '-';
                }
                if (pos == 'e')
                {
                    e = true;
                    map[edx][edy] = '-';
                }
                contmin++;
                pos = 'x';
                map[x][y] = 'x';
                imprimirMapa(map);
                break;
            }
            else if (contmin == 3)
            {
                minijuego4(vidas, contmin);
                if (pos == 'g')
                {
                    g = true;
                    map[gdx][gdy] = '-';
                }
                if (pos == 'a')
                {
                    a = true;
                    map[adx][ady] = '-';
                }
                if (pos == 'm')
                {
                    m = true;
                    map[mdx][mdy] = '-';
                }
                if (pos == 'e')
                {
                    e = true;
                    map[edx][edy] = '-';
                }
                contmin++;
                map[x][y] = 'x';
                imprimirMapa(map);
                break;
            }

        }
        if (contmov % 2 == 0) {
            movertodoslosminijuegos(map, g, a, m, e);
        }



        imprimirMapa(map);

    }
}

int main()
{
    char map[10][10];
    bool g = false;
    bool a = false;
    bool m = false;
    bool e = false;
    int vidas = 7;
    int contmov = 0;
    int contmin = 0;
    printf("Bienvenido al mapa, dirigete a las diferentes posiciones en el mapa y completa los minijuegos para ganar\nEmpiezas con 5 vidas, cada error te resta una vida y por cada minijuego que completes ganaras 2 vidas extra, suerte\n");
    iniciarmapa(map);
    map[gdx][gdy] = 'g';
    map[adx][ady] = 'a';
    map[mdx][mdy] = 'm';
    map[edx][edy] = 'e';
    map[0][0] = 'x';
    imprimirMapa(map);
    /*Primer ejecutable del juego*/ 
    actualizarmovimiento(map, g, a, m, e, vidas, contmin, contmov);
    comprobarvida(vidas);
    actualizarmovimiento(map, g, a, m, e, vidas, contmin, contmov);
    comprobarvida(vidas);
    actualizarmovimiento(map, g, a, m, e, vidas, contmin, contmov);
    comprobarvida(vidas);
    actualizarmovimiento(map, g, a, m, e, vidas, contmin, contmov);
    comprobarvida(vidas);
    printf("\nCompletaste el juego en %d movimientos y te quedaron %d vidas, felicidades!", contmov, vidas);
}