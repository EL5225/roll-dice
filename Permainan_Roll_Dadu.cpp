#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cctype>

void roll(std::string p1, std::string p2);
void rollDadu(int kondisiGiliran2, std::string pl1, std::string pl2);
void rolling(std::string pertama, std::string kedua);
void hasil(int result1, int result2, std::string first, std::string second);

int main()
{
    bool loopMenu = true;
    char mulaiGame;
    std::string player1;
    std::string player2;

    do
    {
        system("clear");
        srand(time(NULL));

        std::cout << "=============== Permainan Roll Dadu ===============\n";

        std::cout << "Aturan : " << std::endl;
        std::cout << "Terdapat dua player yang akan bertanding\n";
        std::cout << "dengan cara mendapatkan angka dadu terbesar.\n";

        std::cout << "\nMulai game ? (y/t) : ";
        std::cin >> mulaiGame;

        if (mulaiGame == 'y' || mulaiGame == 'Y')
        {
            system("clear");

            std::cout << "============================" << std::endl;
            std::cout << "Selamat datang di Permainan!" << std::endl;
            std::cout << "============================" << std::endl;

            std::cout << "\nMasukan nama player 1 : ";
            std::cin >> player1;

            std::cout << "Masukan nama player 2 : ";
            std::cin >> player2;

            roll(player1, player2);

            loopMenu = true;

            std::cout << "\n=========================================" << std::endl;
            std::cout << "============PERMAINAN BERAKHIR===========" << std::endl;
            std::cout << "=========================================\n"
                      << std::endl;
        }

        else if (mulaiGame == 't' || mulaiGame == 'T')
        {
            loopMenu = true;

            system("clear");

            std::cout << "\n==============================================";
            std::cout << "\nKeluar Permainan!" << std::endl;
            std::cout << "Permainan Berakhir!" << std::endl;
        }

        else
        {
            system("clear");

            std::cout << "\n==============================================";
            std::cout << "\nPilihan tidak tersedia!" << std::endl;
            std::cout << "\nTekan untuk melanjutkan . . ." << std::endl;
            system("read");

            loopMenu = false;
        }

    } while (loopMenu == false);

    std::cout << "\n=========================================\n";

    return 0;
}

//=========================================================================================================/

void roll(std::string p1, std::string p2)
{
    system("clear");

    srand(time(NULL));

    int gil;
    int giliranPlayer1;
    int giliranPlayer2;
    int kondisiGiliran;
    char gil2;
    bool memilih = true;
    bool giliran = true;

    std::cout << "\n============================" << std::endl;
    std::cout << "Menentukan Giliran Roll Dadu";
    std::cout << "\n============================" << std::endl;
    std::cout << "Aturan : " << std::endl;
    std::cout << "Pilih angka 1 atau 2" << std::endl;
    std::cout << "Nanti akan di roll antara 1 dan 2" << std::endl;
    std::cout << "Player yang menebak angka dengan benar akan mulai duluan" << std::endl;

    std::cout << "==========================================================" << std::endl;

    do
    {
        memilih = true;

        std::cout << p1 << " silahkan memilih angka (1 / 2) : ";
        std::cin >> giliranPlayer1;

        std::cout << p2 << " silahkan memilih angka (1 / 2) : ";
        std::cin >> giliranPlayer2;

        if (giliranPlayer1 == giliranPlayer2 || giliranPlayer1 > 2 || giliranPlayer2 > 2 || giliranPlayer1 < 1 || giliranPlayer2 < 1)
        {
            std::cout << "\nTidak valid!\n";
            system("read");

            memilih = false;
        }

    } while (memilih == false);

    do
    {
        giliran = true;

        std::cout << "\nMasukan R untuk roll angka : ";
        std::cin >> gil2;
        if (gil2 == 'r' || gil2 == 'R')
        {
            srand(time(NULL));
            gil = (rand() % 2) + 1;
            std::cout << "\nAngka yang keluar : " << gil << std::endl;

            if (gil == giliranPlayer1)
            {
                std::cout << p1 << " giliran pertama\n";
                std::cout << p2 << " giliran kedua";

                kondisiGiliran = 1;
            }

            else if (gil == giliranPlayer2)
            {
                std::cout << p2 << " giliran pertama\n";
                std::cout << p1 << " giliran kedua";

                kondisiGiliran = 2;
            }
        }

        else
        {
            giliran = false;
        }

    } while (giliran == false);

    std::cout << std::endl;

    rollDadu(kondisiGiliran, p1, p2);
}

//=========================================================================================================/

void rollDadu(int kondisiGiliran2, std::string pl1, std::string pl2)
{
    std::string kondisiRoll;

    std::cout << "\n============================" << std::endl;
    std::cout << "Permainan Roll Dadu Dimulai!";
    std::cout << "\n============================" << std::endl;

    if (kondisiGiliran2 == 1)
    {
        std::cout << "Giliran pertama   : " << pl1 << std::endl;
        std::cout << "Giliran Kedua     : " << pl2 << std::endl;
        std::cout << "\nMulai rolling? (masukan apa saja) : ";
        std::cin >> kondisiRoll;
        rolling(pl1, pl2);
    }

    else if (kondisiGiliran2 == 2)
    {
        std::cout << "Giliran pertama   : " << pl2 << std::endl;
        std::cout << "Giliran Kedua     : " << pl1 << std::endl;
        std::cout << "\nMulai rolling? (masukan apa saja) : ";
        std::cin >> kondisiRoll;
        rolling(pl2, pl1);
    }
}

//=========================================================================================================/

void rolling(std::string pertama, std::string kedua)
{
    srand(time(NULL));

    int ronde = 0;
    int dadu2 = 0;
    char pilihRonde;
    int dadu = 0;
    int hasil1 = 0;
    int hasil2 = 0;
    bool kondisiRonde = true;

    do
    {
        srand(time(NULL));

        std::cout << std::endl;
        std::cout << pertama << " sedang rolling dadu . . ." << std::endl;
        sleep(3);
        dadu = rand() % 6 + 1;
        std::cout << "Angka dadu : " << dadu << std::endl;
        hasil1 += dadu;

        std::cout << std::endl;
        std::cout << kedua << " sedang rolling dadu . . ." << std::endl;
        sleep(3);
        dadu2 = rand() % 6 + 1;
        std::cout << "Angka dadu : " << dadu2 << std::endl;
        hasil2 += dadu2;

        if (ronde == 2)
        {
            kondisiRonde = true;

            hasil(hasil1, hasil2, pertama, kedua);

            break;
        }

        else if (ronde <= 2)
        {

            do
            {
                kondisiRonde = true;

                std::cout << "\nApakah ingin lanjut ronde berikutnya? (maksimal 3 kali)" << std::endl;
                std::cout << "Ya/Tidak (y/t) : ";
                std::cin >> pilihRonde;

                if (pilihRonde == 'y' || pilihRonde == 'Y')
                {

                    ronde++;

                    kondisiRonde = true;
                }

                else if (pilihRonde == 't' || pilihRonde == 'T')
                {
                    kondisiRonde = true;

                    hasil(hasil1, hasil2, pertama, kedua);

                    ronde = 3;
                }

                else
                {
                    kondisiRonde = false;
                }
            } while (kondisiRonde == false);
        }
    } while (ronde <= 2);
}

//=========================================================================================================/

void hasil(int result1, int result2, std::string first, std::string second)
{
    std::cout << std::endl;

    std::cout << first << " mendapatkan : " << result1 << " angka dadu!\n";
    std::cout << second << " mendapatkan : " << result2 << " angka dadu!\n";

    if (result1 > result2)
    {
        std::cout << "\n=========================================" << std::endl;
        std::cout << "================SELAMAT!=================\n";
        std::cout << std::endl;
        std::cout << first << " telah memenangkan permainan!\n";
        std::cout << "\n=========================================" << std::endl;
    }

    else if (result1 < result2)
    {
        std::cout << "\n=========================================" << std::endl;
        std::cout << "================SELAMAT!=================\n";
        std::cout << std::endl;
        std::cout << second << " telah memenangkan permainan!\n";
        std::cout << "\n=========================================" << std::endl;
    }

    else if (result1 == result2)
    {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "==============PERMAINAN SERI!=============\n";
        std::cout << "\nTidak ada yang memenangkan permainan!\n";
        std::cout << "\n==========================================" << std::endl;
    }
}

//=========================================================================================================/