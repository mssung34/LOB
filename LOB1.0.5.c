#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//전역변수
int bokiHp = 1500, maxBokiHp = 1500;
int bokiMp = 100, maxBokiMp = 100;
int hpPotion = 3, mpPotion = 3;
int minBokiDam = 200, maxBokiDam = 500;
int bokiExp = 0, maxBokiExp = 100;
int bokiLevel = 1;

int dead = 0;

//함수 전방선언
int GameStart();
void Prologue();
int BattlePhase();
int BattlePhaseTwo();
int BattlePhaseThree();
int Boss();
void GetPotion();
int UsePotion(int whenUse);
void Dead();
void GetExp(int exp);
void LevelUp();
int Run();
void Ending();

int GameStart()
{
    char start = 0;

    while (1)
    {
        system("clear");
        printf("\n");
        printf("      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("      ┃                                                         ┃\n");
        printf("      ┃⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ┃\n");
        printf("      ┃⠀⠀⠀⠀⠘⠟⠛⢻⣿⠛⠟⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣴⣶⣶⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⣶⣶⣷⣶⣶⣶⣶⣾⣶⣶⣶⣶⡄⠀  ┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠿⠛⠉⠉⠉⠛⢿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠀⠀⠈⢸⣿⠉⠉⠉⠉⠉⠉⠀  ⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀  ⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⢸⣿⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣿⠀⠀⠀⠀⠀⠀  ⠀⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⢺⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀  ⠀⠀⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣧⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀  ⠀⠀⠀⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀⠀⠀⢼⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⣀⣾⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀  ⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣦⣤⣀⣀⣀⣴⣴⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀  ⠀⠀┃\n");
        printf("      ┃⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠙⠛⠻⠿⠟⠛⠋⠁⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀  ⠀⠀┃\n");
        printf("      ┃         ┌────────────┐           ┌────────────┐         ┃\n");
        printf("      ┃         │게임 시작(q)│           │게임 종료(e)│         ┃\n");
        printf("      ┃         └────────────┘           └────────────┘         ┃\n");
        printf("      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        scanf(" %c", &start);

        if (start == 'q')
            break;
        else if (start == 'e')
            return 1;
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(2);
        }
    }
}

void Prologue()
{
    char skip = 0;

    system("clear");

    printf("\n\n\n\t e ) 프롤로그 보기\tq ) 스킵\n");
    scanf(" %c", &skip);

    while (1)
    {
        if (skip == 'q')
        {
            break;
        }
        else if (skip == 'e')
        {
            system("clear");
            printf("\n\n\n");
            printf("\t평화로운 코딩왕국의 변방 작은 마을 아이오티마을\n\n");
            sleep(2);
            printf("\t그곳에는 \033[0;36m복이\033[0;37m라는 모험왕이 있었는데...\n\n");
            sleep(2);
            printf("\t어느 날 시장에 나간 \033[0;36m복이\033[0;37m\n\n");
            sleep(2);
            printf("\t시장에 붙어있는 벽보를 보게되고...\n\n");
            sleep(2);
            system("clear");
            printf("\n\n\n");
            printf("\t\t             < 왕명 >\n");
            printf("\t\t   ┌──────────────────────────┐\n");
            printf("\t\t   │ \033[0;35m마왕\033[1;31m리우홍걸\033[0;37m에게         │\n");
            printf("\t\t   │ 납치된 \033[1;35m어쩔다 공주\033[0;37m를     │\n");
            printf("\t\t   │ 구출해오는 사람에게는    │\n");
            printf("\t\t   │ 용사의 칭호, 보상 하사함 │\n");
            printf("\t\t   ├──────────────────────────┤\n");
            printf("\t\t   │ 장소 : 꿈꾸는 강의실     │\n");
            printf("\t\t   │ 토벌대상 : \033[0;35m마왕 \033[1;31m리우홍걸\033[0;37m │\n");
            printf("\t\t   │ 구출대상 : \033[1;35m어쩔다 공주\033[0;37m   │\n");
            printf("\t\t   ├──────────────────────────┤\n");
            printf("\t\t   │            직인 : 어상혁 │\n");
            printf("\t\t   └──────────────────────────┘\n");
            sleep(5);
            system("clear");
            printf("\n\n\n");
            printf("\t이 벽보를 본 \033[0;36m복이\033[0;37m는 \033[1;35m어쩔다 공주\033[0;37m를 구하기 위해\n");
            sleep(2);
            printf("\t모험에 떠나 꿈꾸는 강의실 입구에 다다르는데...\n\n");
            sleep(2);
            printf("\t꿈꾸는 강의실에는 \033[0;35m마왕\033[1;31m 리우홍걸\033[0;37m이 기다리고 있었다!!\n\n");
            sleep(2);
            printf("\t\033[1;31m리우홍걸\033[0;37m : 꿈꾸는 강의실 어딘가에 있는 나를 찾아와\n");
            sleep(2);
            printf("\t쓰러뜨린다면 여기 \033[1;35m어쩔다 공주\033[0;37m를 돌려주도록 하겠다!!!\n\n");
            sleep(2);
            printf("\t\033[0;35m마왕 \033[1;31m리우홍걸\033[0;37m이 품에서 보라색 구체를 꺼낸다.\n\n");
            sleep(2);
            printf("\t구체가 빛나더니 \033[1;35m어쩔다 공주\033[0;37m가 비춰졌다.\n\n");
            sleep(2);
            printf("\t\033[1;35m어쩔다 공주\033[0;37m : 용사님 살려주세요~~~\n\n");
            sleep(2);
            printf("\t구체에서 다시 빛이나더니 \033[1;31m리우홍걸\033[0;37m이 눈앞에서 사라졌다.\n\n");
            sleep(2);
            printf("\t\033[0;36m복이\033[0;37m : \033[1;35m어쩔다 공주\033[0;37m 제가 꼭 구해드릴게요!!!\n\n");
            sleep(2);
            printf("\t꿈꾸는 강의실이 울리게 \033[0;36m복이\033[0;37m가 외친다!!!\n");
            sleep(2);
            system("clear");
            break;
        }
    }
}

int Run()
{
    srand(time(NULL));

    int runProbability = 0;

    runProbability = rand() % 3 + 1;

    if (runProbability == 1)
    {
        printf("\n\t도망실패\n");
        sleep(2);
    }
    else if (runProbability == 2)
    {
        printf("\n\t도망실패\n");
        sleep(2);
    }
    else
    {
        printf("\n\t도망성공\n");
        sleep(2);
        return 1;
    }
}//end Run

void Dead() //죽었을 때 호출되는 함수
{
    system("clear");

    bokiHp = 0;
    dead = 1;

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                              ┃\n");
    printf("┃                                                              ┃\n");
    printf("┃                                                              ┃\n");
    printf("┃      \033[0;31m    ■ ■ ■       ■ ■ ■       ■   ■     ■ ■ ■ ■ ■    \033[0;37m     ┃\n");
    printf("┃       \033[0;31m ■       ■   ■       ■   ■   ■   ■   ■           \033[0;37m      ┃\n");
    printf("┃       \033[0;31m ■           ■       ■   ■   ■   ■   ■        \033[0;37m         ┃\n");
    printf("┃        \033[0;31m■     ■ ■   ■ ■ ■ ■ ■   ■   ■   ■   ■ ■ ■ ■ ■       \033[0;37m  ┃\n");
    printf("┃        \033[0;31m■       ■   ■       ■   ■   ■   ■   ■           \033[0;37m      ┃\n");
    printf("┃       \033[0;31m ■       ■   ■       ■   ■   ■   ■   ■              \033[0;37m   ┃\n");
    printf("┃         \033[0;31m ■ ■ ■     ■       ■   ■   ■   ■   ■ ■ ■ ■ ■      \033[0;37m   ┃\n");
    printf("┃                                                              ┃\n");
    printf("┃        \033[0;31m  ■ ■ ■     ■       ■   ■ ■ ■ ■ ■   ■ ■ ■ ■         \033[0;37m  ┃\n");
    printf("┃        \033[0;31m■       ■   ■       ■   ■           ■       ■       \033[0;37m  ┃\n");
    printf("┃        \033[0;31m■       ■     ■   ■     ■           ■       ■      \033[0;37m   ┃\n");
    printf("┃        \033[0;31m■       ■     ■   ■     ■ ■ ■ ■ ■   ■ ■ ■ ■     \033[0;37m      ┃\n");
    printf("┃        \033[0;31m■       ■     ■   ■     ■           ■       ■      \033[0;37m   ┃\n");
    printf("┃        \033[0;31m■       ■       ■       ■           ■       ■       \033[0;37m  ┃\n");
    printf("┃         \033[0;31m ■ ■ ■         ■       ■ ■ ■ ■ ■   ■       ■     \033[0;37m    ┃\n");
    printf("┃                                                              ┃\n");
    printf("┃                                                              ┃\n");
    printf("┃                                                              ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
} // end Dead

void GetExp(int exp)
{
    // exp는 BattlePhase()에서 몬스터의 체력을 받음
    int bokiExpPlus = 0;

    bokiExpPlus = exp / 100 * 2;
    bokiExp += bokiExpPlus;

    printf("%d만큼의 경험치를 획득했습니다.\n", bokiExpPlus);

    sleep(2);

    if (bokiExp >= maxBokiExp)
    {
        LevelUp();
    }
} // end GetExp

void LevelUp()
{
    int bokiHpPlus = 0, bokiMpPlus = 0;

    srand(time(NULL));

    system("clear");

    bokiHpPlus = (maxBokiHp / 10) * (rand() % 5 + 2);
    bokiMpPlus = (maxBokiMp / 10) * (rand() % 5 + 2);

    bokiLevel++;
    bokiExp -= maxBokiExp;
    maxBokiExp += 20;
    minBokiDam += 20;
    maxBokiDam += 30;
    maxBokiHp += bokiHpPlus;
    maxBokiMp += bokiMpPlus;

    printf("\n");
    printf("                  \033[0;33mLevelUp ! ! !\n\n");
    printf("               \033[0;31mHp\033[0;37m:%d 증가 / \033[0;34mMp\033[0;37m:%d 증가\n", bokiHpPlus, bokiMpPlus);
    printf("	\033[0;33m 최소대미지\033[0;37m : 30 /\033[0;33m 최대대미지\033[0;37m : 20 상승 \n");
    printf("┌───────────────────\033[0;36m능력치\033[0;37m───────────────────┐\n");
    printf("│                                            │\n");
    printf("│ \033[0;33m   레벨 : %d      \033[0;37m                          │\n", bokiLevel);
    printf("│                                            │\n");
    printf("│   \033[0;31m Hp : %d       \033[0;34m       Mp : %d       \033[0;37m  │\n", maxBokiHp, maxBokiMp);
    printf("│                                            │\n");
    printf("│  \033[0;33m  최소대미지 : %d      최대대미지 : %d \033[0;37m │\n", minBokiDam, maxBokiDam);
    printf("│                                            │\n");
    printf("└────────────────────────────────────────────┘\n");

    sleep(5);
} // end LevelUp

void GetPotion()
{
    int getPotion = 0;
    int getHpPotion = 0, getMpPotion = 0;

    srand(time(NULL));

    getHpPotion = rand() % 3;
    getMpPotion = rand() % 2;
    getPotion = getHpPotion + getMpPotion;

    if (getHpPotion == 0)
    {
        printf("\n");
        printf("아무것도 획득하지 못했다.\n");
        sleep(2);
    }
    else
    {
        system("clear");
        printf("\033[1;33m     ♩♪             \n");
        printf(" ∵        |            \n");
        printf("       \\  |  /       \n");
        printf("       \\ \\ / /       \n");
        printf("   ─ ─━  - -  ━─ ─    \n");
        printf("       / / \\ \\       \n");
        printf(" ♪♩    /  |  \\       \n");
        printf("          |          ∴   \n");
        printf("                 ♩♪     \n");
        printf("\n");
        printf("                              |        ♩    \n");
        printf("                           \\  |  /     ∵  \n");
        printf("                           \\ \\ / /       \n");
        printf("                       ─ ─━  - -  ━─ ─    \n");
        printf("                           / / \\ \\       \n");
        printf("                     ♪♩    /  |  \\       \n");
        printf("                              |             \n");
        printf("                        ∴            ♩♪    \033[0;37m \n");
        printf("축하합니다~~!! \n\n");
        if (getHpPotion == 0)
        {
            printf("\033[0;34mMp\033[0;37m포션 %d개를 얻었다.\n", getMpPotion);
            sleep(2);
        }
        else if (getMpPotion == 0)
        {
            printf("\033[0;31mHp\033[0;37m포션 %d개를 얻었다.\n", getHpPotion);
            sleep(2);
        }
        else
        {
            printf("\033[0;31mHp\033[0;37m포션 %d개, \033[0;34mMp\033[0;37m포션 %d개를 었었다.\n", getHpPotion, getMpPotion);
            sleep(2);
        }
    }

    hpPotion += getHpPotion;
    mpPotion += getMpPotion;
    printf("\n현재 소지 포션은 \033[0;31mHp\033[0;37m포션은 %d개 \033[0;34mMp\033[0;37m포션은 %d개 입니다.\n\n", hpPotion, mpPotion);
    sleep(2);
} // end GetPosion

int UsePotion(int whenUse)
{
    srand((unsigned)time(NULL));

    int usePotion = 0;

    if (whenUse == (int)'h')
    {
        if (hpPotion == 0)
        {
            printf("포션이 없어 사용할 수 없습니다.\n");
            sleep(2);
            return 0;
        }
        else
        {
            printf("\033[0;31mHP\033[0;37m포션을 사용합니다.\n");
            sleep(2);
            bokiHp += (maxBokiHp / 10) * (rand() % 8 + 3);
            if (bokiHp > maxBokiHp)
            {
                bokiHp = maxBokiHp;
            }
            hpPotion -= 1;
            return 0;
        }
    }
    else if (whenUse == (int)'m')
    {
        if (mpPotion == 0)
        {
            printf("포션이 없어 사용할 수 없습니다.\n");
            sleep(2);
        }
        else
        {
            printf("\033[0;34mMP\033[037m포션을 사용합니다.\n");
            sleep(2);
            bokiMp += maxBokiMp - bokiMp;
            mpPotion -= 1;
        }
    }
    else
    {
        while (1)
        {
            system("clear");
            printf("\n \033[0;31m     %d/%d\n", bokiHp, maxBokiHp);
            printf("Hp:");
            for (int i = 0; i < bokiHp * 10 / maxBokiHp; i++)
                printf("■ ");
            for (int i = 0; i < 10 - bokiHp * 10 / maxBokiHp; i++)
                printf("□ ");
            printf("\n \033[0;34m     %d/%d\n", bokiMp, maxBokiMp);
            printf("Mp:");
            for (int i = 0; i < bokiMp * 10 / maxBokiMp; i++)
                printf("■ ");
            for (int i = 0; i < 10 - bokiMp * 10 / maxBokiMp; i++)
                printf("□ ");
            printf("\033[1;36m\n");
            printf("┏────────────────────┓\n");
            printf("│                    │\n");
            printf("│\033[0;37m 1)\033[0;31mHp\033[0;37m포션  2)\033[0;34mMp\033[0;37m포션\033[1;36m │\n");
            printf("│\033[0;37m  ( %d개)    ( %d개) \033[1;36m │\n", hpPotion, mpPotion);
            printf("│                    │\n");
            printf("┗────────────────────┛\033[0;37m\n");
            printf("①  \033[0;31mHP\033[0;37m포션 사용하기\n");
            printf("②  \033[0;34mMP\033[0;37m포션 사용하기\n");
            printf("③  \033[1;36m포션가방 \033[0;37m닫기\n");
            printf("선택 : ");
            scanf("%d", &usePotion);

            if (usePotion == 1)
            {
                if (hpPotion == 0)
                {
                    printf("포션이 없어 사용할 수 없습니다.\n");
                }
                else
                {
                    printf("\033[0;31mHP\033[0;37m포션을 사용합니다.\n");
                    bokiHp += (maxBokiHp / 10) * (rand() % 8 + 3);
                    if (bokiHp > maxBokiHp)
                    {
                        bokiHp = maxBokiHp;
                    }
                    hpPotion -= 1;
                }
            }
            else if (usePotion == 2)
            {
                if (mpPotion == 0)
                {
                    printf("포션이 없어 사용할 수 없습니다.\n");
                }
                else
                {
                    printf("\033[0;34mMP\033[037m포션을 사용합니다.\n");
                    bokiMp += maxBokiMp - bokiMp;
                    mpPotion -= 1;
                }
            }
            else if (usePotion == 3)
            {
                printf("\033[1;36m포션가방\033[0;37m을 닫습니다.\n");
                sleep(1);
                break;
            }
            else
            {
                printf("잘못된 입력입니다.\n");
                sleep(1);
                continue;
            }
            sleep(2);
        }
    }

} // end potionSelect

int BattlePhase()
{
    srand((unsigned)time(NULL));

    int mobHp = 0, maxMobHp = 0;
    int mobAtt = 0, mobSkill = 777;
    int mobA_S = 0, mobText = 0;
    int slt = 0;
    int bokiAtt = 0, bokiSkill = 0;
    int succes_Run = 0;

    maxMobHp = rand() % 5 + 1;
    maxMobHp *= 1000; //몹의 체력 랜덤 설정
    mobHp = maxMobHp;

    system("clear");
    mobText = rand() % 2 + 1;
    if (mobText == 1)
    {
        printf("\n\n\n\t내가 누군지 궁금하시다면\n\n\t대답해 드리는게 인지상정");
        sleep(1);
        printf("\n\n\t이 세계를 파괴하기위해\n\n\t이 세계의 평화를 부수기위해");
        sleep(1);
        printf("\n\n\t사랑과 진실 어둠을 뿌리고다니는\n\n\t실습실의 감초 귀염둥이 악당!");
        sleep(1);
        printf("\n\n\t페페 ! !");
        sleep(1);
    }
    else if (mobText == 2)
    {
        printf("\n\n\n\t이 싸움이 끝나면...\n\t암컷 개구리에게 고백할거야..\n");
        sleep(1);
        printf("\n\t꼭 돌아가기로 약속햇으니...\n\t이 싸움이 끝나면 잔뜩 놀아주겠다고..\n");
    }
    mobText = 0;
    sleep(2);
    printf("\n");
    while (mobHp > 0)
    {
        system("clear");
        printf("                         (\033[0;34m슬픈 \033[0;32m개구리 페페\033[0;37m)\n");
        printf("\033[0;31m                             %d/%d\n", mobHp, maxMobHp);
        printf("                     Hp:");
        for (int k = 0; k < mobHp * 10 / maxMobHp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - mobHp * 10 / maxMobHp; k++)
            printf("□ ");
        printf("\033[0;37m\n");
        printf("\033[0;032m                  ⣿⣿⣿⣿⣿⣿⣿⠟⠋⠉⠁⠈⠉⠙⠻⢿⡿⠿⠛⠋⠉⠙⠛⢿⣿⣿⣿⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣿⣿⠟⠁⠀⠀⢀⣀⣀⣀⣀⡀⠀⢆⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣿⠃⠀⠀⠠⠊⠁⠀⠀⠀⠀⠈⠑⠪⡖⠒⠒⠒⠒⠒⠒⠶⠛⠿⣿⣿⣿\n");
        printf("                  ⣿⣿⡿⡇⠀⠀⠀⠀⠀⠀⡠⢔⡢⠍⠉⠉⠩⠭⢑⣤⣔⠲⠤⠭⠭⠤⠴⢊⡻⣿\n");
        printf("                  ⡿⠁⢀⠇⠀⠀⠀⣤⠭⠓⠊⣁⣤⠂⠠⢀⡈⠱⣶⣆⣠⣴⡖⠁⠂⣀⠈⢷⣮⣹\n");
        printf("                  ⠁⠀   ⠀⠀⠈⠉⢳⣿⣿⣿⡀⠀⠀⢀⣀⣿⡿⢿⣿⣇⣀⣥⣤⠤⢼⣿⣿\n");
        printf(" ⠀⠀⠀⠀⠀⠀                 ⠀⠀⠀⢸⡟⠑⠚⢹⡟⠉⣑⠒⢺⡇⡀⠀⡹⠀⠀⣀⣴⣽⣿⣿\n");
        printf(" ⠀⠀⠀⠀⠀⠀                 ⠀⠀⠀⢸⡇⠀⠀⣿⠒⠉⠀⠀⢠⠃⠈⠙⠻⣍⠙⢻⡻⣿⣿⣿\n");
        printf(" ⠀⠀⠀                 ⠀⠀⠀⠀⠀⣀⣘⡄⠀⠀⢸⡇⠀⠀⠀⠘⡇⠀⠀⠀⠘⡄⠀⢱⢸⣿⣿\n");
        printf(" ⠀                 ⠀⠀⠀⠠⡀⠀⠾⣟⣻⣛⠷⣶⣼⣥⣀⣀⣀⠀⢧⠀⠀⠀⠠⣧⣀⣼⣴⢽⣿\n");
        printf(" ⠀⠀⠀⠀                 ⠀⠈⠉⠁⠀⠹⡙⠛⠷⣿⣭⣯⣭⣟⣛⣿⣿⣿⣛⣛⣿⣭⣭⣾⣿⣿\n");
        printf("                  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡀⠀⠀⣇⠀⠉⠉⠉⡏⠉⠙⠛⠛⡿⣻⣯⣷⣿⣿⣿\n");
        printf("                  ⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢸⠀⠀⠀⡸⠁⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣿⣶⣶⣦⣤⣤⣤⣷⣤⣄⣈⣆⣤⣤⣧⣶⣷⣿⡻⣿⣿⣿⣿⣿⣿⣿⣿\033[0;37m\n");
        printf(" -------------------------------------------------------------\n");
        printf("                         \033[0;36m      복이\n");
        printf("\033[0;31m               %d/%d       \033[0;34m              %d/%d\n", bokiHp, maxBokiHp, bokiMp, maxBokiMp);
        printf("      \033[0;31m Hp:");
        for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
            printf("□ ");
        printf("     \033[0;34m Mp:");
        for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
            printf("□ ");
        printf("\033[0;37m\n\n");
        printf("                 \033[0;33m    대미지 : %d ~ %d\033[0;37m\n\n", minBokiDam, maxBokiDam);
        printf("        1 ) 일반공격 2 ) 마법공격 3 ) 포션사용 4 ) 빤스런\n");
        printf("                          선택 : ");
        scanf(" %d", &slt);
        printf("\n");

        while (1) //복이의 일반공격 대미지 설정
        {
            bokiAtt = rand() % maxBokiDam + 1;
            if (bokiAtt > maxBokiDam || bokiAtt < minBokiDam)
                continue;
            else
                break;
        }

        bokiSkill = maxMobHp * 0.2;

        while (1) //몬스터의 공격 대미지 설정
        {
            mobAtt = rand() % 300 + 1;
            if (mobAtt > 300 || mobAtt < 100)
                continue;
            else
                break;
        }

        mobA_S = rand() % 10 + 1;

        if (slt == 1) //일반공격
        {
            system("clear");
            printf("\n");
            printf("       ░░░░░░░░░░\n");
            printf("▒░░████████████████████▒\n");
            printf("         ░░█████████████████▒░░░░░░\n");
            printf("                  ░░░░░░░░░\n");
            printf("복이의 일반공격 ! ! !\n");
            printf("%d의 데미지를 입혔다.\n\n", bokiAtt);
            mobHp -= bokiAtt;
            sleep(2);
        }
        else if (slt == 2) //마법공격
        {
            printf("복이의 마법공격 ! ! !\n");
            if (bokiMp >= 20)
            {
                system("clear");
                printf("\n");
                printf("         ░▒▓▓█▓▓▓▒░░\n");
                printf("       ░▒▓░ ░▓█░  ▒▓░░\n");
                printf("      ░▓░  ░█ ░▓    ▒▒░\n");
                printf("     ▒▒   ░▒   ▒░    ░▓░\n");
                printf("    ▒▒    ░▒   ▓░     ▓░\n");
                printf("   ░▓    ░█      █░    ░▒\n");
                printf("   ▓░░░░░▓░░░░░░░░▓▒▒▒▒▒█░\n");
                printf("  ░█    ▒▒        ▒▒    ▓▒\n");
                printf("  ▒░▓  ░▓          ▓░  ░▒▓░\n");
                printf("  ▒ ▒░░▓            █░ ▓ ▒░\n");
                printf("  ▓  ▓▒▒             ▓▓░ ▒▒\n");
                printf("  ▓  ░▓              ░▒  ░▒\n");
                printf("  ▓  ▓▒░             █▓░ ░▒\n");
                printf("  ▓ ▒░░▓             ░░▓░▒░\n");
                printf("  ▓░▓  ░▓           ▓░ ░▓▓░\n");
                printf("  ░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█▓\n");
                printf("  ░▓░   ░▓░░░░░░░░░▒░░░░▒▒\n");
                printf("   ▒▒    ░▓       █░    ▓░\n");
                printf("   ░▓░    ░▒     ▒░    ▓░\n");
                printf("    ░▓    ░▓     ▓    ▒▒\n");
                printf("     ░▓░   ░█   █░  ░▓▒\n");
                printf("      ░▒▓░  ░▒ ░░  ▒▓░\n");
                printf("        ░▒▓▒▒▓░█▒▓▓░░\n");
                printf("           ░▒▒▒▒░░\n");
                printf("Mp %d(을)를 소모하였다.\n", 20);
                printf("%d의 대미지를 주었다.\n\n", bokiSkill);
                bokiMp -= 20;
                mobHp -= bokiSkill;
                sleep(2);
            }
            else
            {
                printf("Mp가 부족합니다.\n\n");
                continue;
            }
        }
        else if (slt == 3) //포션 사용
        {
            UsePotion(slt);
            continue;
        }
        else if (slt == 4) //빤스런
        {
            succes_Run = Run();
            if (succes_Run == 1)
            {
                return 2;
                break;
            }
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(1);
            continue;
        }

        if (mobHp > 0)
        {
            if (mobA_S >= 2)
            {
                system("clear");
                printf("     █   █   █\n");
                printf("     ██  ██  ██\n");
                printf("      █   █   █\n");
                printf("      █  ██   █\n");
                printf("      █  ██  ██\n");
                printf("     ██  ██  ██\n");
                printf("    ███ ██  ███\n");
                printf("   ███ ██  ███\n");
                printf("  ██  ██  ██\n");
                printf(" ██  ██  ██\n");
                printf("██  █   ██\n");
                printf("\033[0;34m슬픈 \033[0;32m개구리 페페\033[0;37m의 공격 ! !\n");
                printf("%d의 대미지를 입었다.\n\n", mobAtt);
                bokiHp -= mobAtt;
            }
            else
            {
                system("clear");
                printf("  ▓     ▒▓    ▒      ░\n");
                printf("   ░   ░ ▓   ░ ░    ▒░\n");
                printf("   ░   ▓ ░   ▒ █    ▒\n");
                printf("    █     ░ █      ░\n");
                printf("     ░▓   ▓ ░   ░  █\n");
                printf("     ░█   ░     █ ░\n");
                printf("      ▒    █    ░ ▓\n");
                printf("                 ▒░\n");
                printf("\n");
                printf("\n");
                printf("     ░               ▓█\n");
                printf("    ▒░       ▒░     ▓ ░\n");
                printf("  ░▒ █      ░ ▓    ░   █\n");
                printf("  ░  █     ░   ░   ▓   ░░\n");
                printf("  ▓       ░░   █  ▓     ░\n");
                printf(" ▒    ░   ▓     ░ ░    ░▓\n");
                printf(" ░      █▒      █▓     ░░░\n");
                printf("▓        ░       ░       █\n");
                printf("\033[0;34m슬픈 \033[0;32m개구리 페페\033[0;37m의 물어뜯기 ! ! !\n");
                printf("%d의 대미지를 입었다.\n", mobSkill);
                bokiHp -= mobSkill;
            }
        }

        if (bokiHp <= 0)
        {
            printf("\n\n");
            printf("복이의 Hp가 0이 되었다");
            printf("\n\n");
            sleep(2);
            Dead();
            return 0;
        }
        sleep(2);
    }

    // mobHp <= 0 일시 실행
    if (slt != 4)
    {
        for (int i = 0; i < 5; i++)
        {
            system("clear");
            printf("\033[0;032m                  ⣿⣿⣿⣿⣿⣿⣿⠟⠋⠉⠁⠈⠉⠙⠻⢿⡿⠿⠛⠋⠉⠙⠛⢿⣿⣿⣿⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣿⣿⠟⠁⠀⠀⢀⣀⣀⣀⣀⡀⠀⢆⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣿⠃⠀⠀⠠⠊⠁⠀⠀⠀⠀⠈⠑⠪⡖⠒⠒⠒⠒⠒⠒⠶⠛⠿⣿⣿⣿\n");
            printf("                  ⣿⣿⡿⡇⠀⠀⠀⠀⠀⠀⡠⢔⡢⠍⠉⠉⠩⠭⢑⣤⣔⠲⠤⠭⠭⠤⠴⢊⡻⣿\n");
            printf("                  ⡿⠁⢀⠇⠀⠀⠀⣤⠭⠓⠊⣁⣤⠂⠠⢀⡈⠱⣶⣆⣠⣴⡖⠁⠂⣀⠈⢷⣮⣹\n");
            printf("                  ⠁⠀   ⠀⠀⠈⠉⢳⣿⣿⣿⡀⠀⠀⢀⣀⣿⡿⢿⣿⣇⣀⣥⣤⠤⢼⣿⣿\n");
            printf(" ⠀⠀⠀⠀⠀⠀                 ⠀⠀⠀⢸⡟⠑⠚⢹⡟⠉⣑⠒⢺⡇⡀⠀⡹⠀⠀⣀⣴⣽⣿⣿\n");
            printf(" ⠀⠀⠀⠀⠀⠀                 ⠀⠀⠀⢸⡇⠀⠀⣿⠒⠉⠀⠀⢠⠃⠈⠙⠻⣍⠙⢻⡻⣿⣿⣿\n");
            printf(" ⠀⠀⠀                 ⠀⠀⠀⠀⠀⣀⣘⡄⠀⠀⢸⡇⠀⠀⠀⠘⡇⠀⠀⠀⠘⡄⠀⢱⢸⣿⣿\n");
            printf(" ⠀                 ⠀⠀⠀⠠⡀⠀⠾⣟⣻⣛⠷⣶⣼⣥⣀⣀⣀⠀⢧⠀⠀⠀⠠⣧⣀⣼⣴⢽⣿\n");
            printf(" ⠀⠀⠀⠀                 ⠀⠈⠉⠁⠀⠹⡙⠛⠷⣿⣭⣯⣭⣟⣛⣿⣿⣿⣛⣛⣿⣭⣭⣾⣿⣿\n");
            printf("                  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡀⠀⠀⣇⠀⠉⠉⠉⡏⠉⠙⠛⠛⡿⣻⣯⣷⣿⣿⣿\n");
            printf("                  ⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢸⠀⠀⠀⡸⠁⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣿⣶⣶⣦⣤⣤⣤⣷⣤⣄⣈⣆⣤⣤⣧⣶⣷⣿⡻⣿⣿⣿⣿⣿⣿⣿⣿\033[0;37m\n");
            usleep(300000);
            system("clear");
            usleep(300000);
        }
        system("clear");

        printf("\n\n\n\t\033[0;34m슬픈 \033[0;32m개구리 페페\033[0;37m를 물리쳤다.\n");

        sleep(2);

        GetPotion();

        GetExp(maxMobHp);
    }

    //몬스터의 체력 랜덤 수치 적용
    // 1회씩 턴제공격
    //몬스터 처치 시 경험치 획득
} // end BattlePhase

int BattlePhaseTwo()
{
    srand((unsigned)time(NULL));

    int mob2Hp = 0, maxMob2Hp = 0;
    int mob2Att = 0, mob2Skill = 777;
    int mob2A_S = 0, mob2Text = 0;
    int slt2 = 0;
    int bokiAtt2 = 0, bokiSkill2 = 0;
    int succes_Run2 = 0;

    maxMob2Hp = rand() % 5 + 1;
    maxMob2Hp *= 1000; //몹의 체력 랜덤 설정
    mob2Hp = maxMob2Hp;

    system("clear");
    mob2Text = rand() % 2 + 1;
    if (mob2Text == 1)
    {
        printf("\n\n\n\tonly Death only Death\n\t(사뿐사뿐)\n");
        sleep(1);
        printf("\n\tlisten listen I cant listen\n\t(듣자듣자하니 못들어주겠구만)\n\n");
        sleep(1);
        printf("\tI can church you\n\t(나는 너를 처치하러한다)\n\n");
    }
    else if (mob2Text == 2)
    {
        printf("\n\n\n\tsee see I cant see\n");
        printf("\t(도저히 못봐주겠구만)\n\n");
        sleep(1);
        printf("\tlook look hani scarf look?\n");
        printf("\t(보자보자 하니 보자기로 보이나?\n\n");
        sleep(1);
        printf("\tlive live star star saghwang I meet\n");
        printf("\t살다살다 별별 상황을 다 당하는구만\n\n");
        sleep(1);
        printf("\tturn on B\n");
        printf("\t(비켜)\n\n");
    }
    sleep(2);

    printf("\n");
    while (mob2Hp > 0)
    {
        system("clear");
        printf("                         (\033[0;31m화난 \033[0;45m근육맨\033[0;37m)\n");
        printf("\033[0;31m                             %d/%d\n", mob2Hp, maxMob2Hp);
        printf("                     Hp:");
        for (int k = 0; k < mob2Hp * 10 / maxMob2Hp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - mob2Hp * 10 / maxMob2Hp; k++)
            printf("□ ");
        printf("\n");
        printf("\n");
        printf("            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢀⣤⣶⣶⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀       ⢸⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀                  ⠀⠀⠀⠀⠀⠀⠀⠀   ⠰⣾⣿⣿⣿⢿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀                  ⠀⠀⠀⠀⠀   ⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀                  ⠀⠀⠀	   ⠀⢀⣤⣶⣿⣿⣿⣿⣷⣿⣿⣿⣷⣦⣀⣀⣀⣀⡀⠀⠀⠀⠀\n");
        printf("⠀⠀             	     ⠀⠀⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀\n");
        printf("⠀                    ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀\n");
        printf("                  ⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄\n");
        printf("                  ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇\n");
        printf("                  ⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣿⠿⠋⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠈⠻⣿⣿⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣷⡀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠈⣻⣿⣿⣿\n");
        printf("                  ⣿⣿⣿⣿⡇⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣸⣿⣿⣿⣿\n");
        printf("                  ⢹⣿⣿⡿⠁⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⢸⣿⣿⣿⣿\n");
        printf("                  ⢨⣿⣿⡇⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠘⣿⣿⣿⠇\n");
        printf("                  ⠸⣿⣿⣧⡄⠀⠀⢀⣿⣿⡿⣿⠍⢙⠭⡛⣹⣽⣼⣿⣿⣷⠀⠀⠀⢀⣿⣿⣿⡀\033[0;37m\n");
        printf(" -------------------------------------------------------------\n");
        printf("                         \033[0;36m      복이\n");
        printf("\033[0;31m               %d/%d       \033[0;34m              %d/%d\n", bokiHp, maxBokiHp, bokiMp, maxBokiMp);
        printf("      \033[0;31m Hp:");
        for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
            printf("□ ");
        printf("     \033[0;34m Mp:");
        for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
            printf("□ ");
        printf("\033[0;37m\n\n");
        printf("                 \033[0;33m    대미지 : %d ~ %d\033[0;37m\n\n", minBokiDam, maxBokiDam);
        printf("        1 ) 일반공격 2 ) 마법공격 3 ) 포션사용 4 ) 빤스런\n");
        printf("                          선택 : ");
        scanf(" %d", &slt2);
        printf("\n");

        while (1) //복이의 일반공격 대미지 설정
        {
            bokiAtt2 = rand() % maxBokiDam + 1;
            if (bokiAtt2 > maxBokiDam || bokiAtt2 < minBokiDam)
                continue;
            else
                break;
        }

        bokiSkill2 = maxMob2Hp * 0.2;

        while (1) //몬스터의 공격 대미지 설정
        {
            mob2Att = rand() % 300 + 1;
            if (mob2Att > 300 || mob2Att < 100)
                continue;
            else
                break;
        }

        mob2A_S = rand() % 10 + 1;

        if (slt2 == 1) //일반공격
        {
            system("clear");
            printf("\n");
            printf("       ░░░░░░░░░░\n");
            printf("▒░░████████████████████▒\n");
            printf("         ░░█████████████████▒░░░░░░\n");
            printf("                  ░░░░░░░░░\n");
            printf("복이의 일반공격 ! ! !\n");
            printf("%d의 데미지를 입혔다.\n\n", bokiAtt2);
            mob2Hp -= bokiAtt2;
            sleep(2);
        }
        else if (slt2 == 2) //마법공격
        {
            printf("복이의 마법공격 ! ! !\n");
            if (bokiMp >= 20)
            {
                system("clear");
                printf("\n");
                printf("         ░▒▓▓█▓▓▓▒░░\n");
                printf("       ░▒▓░ ░▓█░  ▒▓░░\n");
                printf("      ░▓░  ░█ ░▓    ▒▒░\n");
                printf("     ▒▒   ░▒   ▒░    ░▓░\n");
                printf("    ▒▒    ░▒   ▓░     ▓░\n");
                printf("   ░▓    ░█      █░    ░▒\n");
                printf("   ▓░░░░░▓░░░░░░░░▓▒▒▒▒▒█░\n");
                printf("  ░█    ▒▒        ▒▒    ▓▒\n");
                printf("  ▒░▓  ░▓          ▓░  ░▒▓░\n");
                printf("  ▒ ▒░░▓            █░ ▓ ▒░\n");
                printf("  ▓  ▓▒▒             ▓▓░ ▒▒\n");
                printf("  ▓  ░▓              ░▒  ░▒\n");
                printf("  ▓  ▓▒░             █▓░ ░▒\n");
                printf("  ▓ ▒░░▓             ░░▓░▒░\n");
                printf("  ▓░▓  ░▓           ▓░ ░▓▓░\n");
                printf("  ░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█▓\n");
                printf("  ░▓░   ░▓░░░░░░░░░▒░░░░▒▒\n");
                printf("   ▒▒    ░▓       █░    ▓░\n");
                printf("   ░▓░    ░▒     ▒░    ▓░\n");
                printf("    ░▓    ░▓     ▓    ▒▒\n");
                printf("     ░▓░   ░█   █░  ░▓▒\n");
                printf("      ░▒▓░  ░▒ ░░  ▒▓░\n");
                printf("        ░▒▓▒▒▓░█▒▓▓░░\n");
                printf("           ░▒▒▒▒░░\n");
                printf("Mp %d(을)를 소모하였다.\n", 20);
                printf("%d의 대미지를 주었다.\n\n", bokiSkill2);
                bokiMp -= 20;
                mob2Hp -= bokiSkill2;
                sleep(2);
            }
            else
            {
                printf("Mp가 부족합니다.\n\n");
                continue;
            }
        }
        else if (slt2 == 3) //포션 사용
        {
            UsePotion(slt2);
            continue;
        }
        else if (slt2 == 4) //빤스런
        {
            succes_Run2 = Run();
            if (succes_Run2 == 1)
            {
                return 2;
                break;
            }
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(1);
            continue;
        }

        if (mob2Hp > 0)
        {
            if (mob2A_S >= 2)
            {
                system("clear");
                printf("     █   █   █\n");
                printf("     ██  ██  ██\n");
                printf("      █   █   █\n");
                printf("      █  ██   █\n");
                printf("      █  █   █\n");
                printf("     █  █   █\n");
                printf("\033[0;31m화난 \033[0;45m근육맨\033[0;37m의 공격 ! !\n");
                printf("%d의 대미지를 입었다.\n\n", mob2Att);
                bokiHp -= mob2Att;
            }
            else
            {
                system("clear");
                printf("  ▓     ▒▓    ▒      ░\n");
                printf("   ░   ░ ▓   ░ ░    ▒░\n");
                printf("   ░   ▓ ░   ▒ █    ▒\n");
                printf("    █     ░ █      ░\n");
                printf("     ░▓   ▓ ░   ░  █\n");
                printf("     ░█   ░     █ ░\n");
                printf("      ▒    █    ░ ▓\n");
                printf("                 ▒░\n");
                printf("\033[0;31m화난 \033[0;45m근육맨\033[0;37m의 할퀴기 ! ! !\n");
                printf("%d의 대미지를 입었다.\n", mob2Skill);
                bokiHp -= mob2Skill;
            }
        }

        if (bokiHp <= 0)
        {
            printf("\n\n");
            printf("복이의 Hp가 0이 되었다");
            printf("\n\n");
            sleep(2);
            Dead();
            return 0;
        }
        sleep(2);
    }

    // mob2Hp <= 0 일시 실행
    if (slt2 != 4)
    {
        for (int i = 0; i < 5; i++)
        {

            system("clear");
            printf("⠀                  ⠀⠀⠀⠀⠀⠀⠀⠀	⠀  ⠀⢀⣤⣶⣶⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀                 ⠀⠀⠀⠀⠀⠀⠀	⠀ ⠀⢸⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀                  ⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠰⣾⣿⣿⣿⢿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀                  ⠀⠀⠀⠀⠀	 ⠀⠀⢀⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀                  ⠀⠀⠀	   ⠀⢀⣤⣶⣿⣿⣿⣿⣷⣿⣿⣿⣷⣦⣀⣀⣀⣀⡀⠀⠀⠀⠀\n");
            printf("⠀⠀             	       ⠀⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀\n");
            printf("⠀                   ⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀\n");
            printf("                  ⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄\n");
            printf("                  ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇\n");
            printf("                  ⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣿⠿⠋⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠈⠻⣿⣿⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣷⡀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠈⣻⣿⣿⣿\n");
            printf("                  ⣿⣿⣿⣿⡇⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣸⣿⣿⣿⣿\n");
            printf("                  ⢹⣿⣿⡿⠁⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⢸⣿⣿⣿⣿\n");
            printf("                  ⢨⣿⣿⡇⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠘⣿⣿⣿⠇\n");
            printf("                  ⠸⣿⣿⣧⡄⠀⠀⢀⣿⣿⡿⣿⠍⢙⠭⡛⣹⣽⣼⣿⣿⣷⠀⠀⠀⢀⣿⣿⣿⡀\n");
            usleep(300000);
            system("clear");
            usleep(300000);
        }

        // mob2Hp <= 0 일시 실행
        printf("\n\n\n\t\033[0;31m화난 \033[0;45m근육맨\033[0;37m 물리쳤다.\n");

        GetPotion();

        GetExp(maxMob2Hp);
    }

    //몬스터의 체력 랜덤 수치 적용
    // 1회씩 턴제공격
    //몬스터 처치 시 경험치 획득
} // end BattlePhase

int BattlePhaseThree()
{
    srand((unsigned)time(NULL));

    int mob3Hp = 0, maxMob3Hp = 0;
    int mob3Att = 0, mob3Skill = 777;
    int mob3A_S = 0, mob3Text = 0;
    int slt3 = 0;
    int boki3Att = 0, boki3Skill = 0;

    maxMob3Hp = rand() % 5 + 1;
    maxMob3Hp *= 1000; //몹의 체력 랜덤 설정
    mob3Hp = maxMob3Hp;

    system("clear");
    mob3Text = rand() % 2 + 1;
    if (mob3Text == 1)
    {
        printf("\n\n\n\t날 주먹밥 머리라고 부르지 마!!\n");
        sleep(1);
        printf("\n\t내가 선배님이니까\n\n");
        sleep(1);
        printf("\t내가 너희보다 쿵후를 배우기 시작했잖아 그러니까 선배지\n");
        sleep(1);
    }
    else if (mob3Text == 2)
    {
        printf("\n\n\n\t어디한번 달려보실까~~!!\n");
        sleep(1);
        printf("\t내가 얼마나 용감하게 적과 싸웠는지\n");
        sleep(1);
        printf("\t수지한테 꼭 전해줘\n");
        sleep(1);
        printf("\t덤벼라~~!!\n\n");
        sleep(2);
    }
    sleep(2);

    printf("\n");
    while (mob3Hp > 0)
    {
        system("clear");
        printf("                         (\033[0;31m울보 \033[0;45m훈발놈\033[0;37m)\n");
        printf("\033[0;31m                             %d/%d\n", mob3Hp, maxMob3Hp);
        printf("                     Hp:");
        for (int k = 0; k < mob3Hp * 10 / maxMob3Hp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - mob3Hp * 10 / maxMob3Hp; k++)
            printf("□ ");
        printf("\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠖⠛⠿⣿⣿⣿⣿⡿⠟⠳⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠉⢀⠁⠀⣁⠀⠀⠀⠀⠀⢈⣈⡐⠙⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⢀⢀⡔⠁⠠⠊⠀⠀⠀⠀⣁⠀⠀⢠⠊⠀⠀⠀⠁⠄⠈⠆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠰⠁⢰⠀⠀⠀⠀⠀⠀⠀⠀⠉⣀⣀⠈⠀⠀⠀⠀⠀⠀⠀⢸⠈⠑⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⢀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠈⠂⣀⡱⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠃⠠⠈⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣦⣀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⢀⣠⣮⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⢹⠙⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢻⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠈⡄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠛⠛⠃⠛⠛⠛⠛⢻⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⢸⠀⠀⠀⠀⠀⢰⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣎⢤⠀⠀⠀⠀⠀⠸⠂⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀\n");
        printf("\t\t⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf(" -------------------------------------------------------------\n");
        printf("                         \033[0;36m      복이\n");
        printf("\033[0;31m               %d/%d       \033[0;34m              %d/%d\n", bokiHp, maxBokiHp, bokiMp, maxBokiMp);
        printf("      \033[0;31m Hp:");
        for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
            printf("□ ");
        printf("     \033[0;34m Mp:");
        for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
            printf("□ ");
        printf("\033[0;37m\n\n");
        printf("                 \033[0;33m    대미지 : %d ~ %d\033[0;37m\n\n", minBokiDam, maxBokiDam);
        printf("        1 ) 일반공격 2 ) 마법공격 3 ) 포션사용 4 ) 빤스런\n");
        printf("                          선택 : ");
        scanf(" %d", &slt3);
        printf("\n");

        while (1) //복이의 일반공격 대미지 설정
        {
            boki3Att = rand() % maxBokiDam + 1;
            if (boki3Att > maxBokiDam || boki3Att < minBokiDam)
                continue;
            else
                break;
        }

        boki3Skill = maxMob3Hp * 0.2;

        while (1) //몬스터의 공격 대미지 설정
        {
            mob3Att = rand() % 300 + 1;
            if (mob3Att > 300 || mob3Att < 100)
                continue;
            else
                break;
        }

        mob3A_S = rand() % 10 + 1;

        if (slt3 == 1) //일반공격
        {
            system("clear");
            printf("\n");
            printf("       ░░░░░░░░░░\n");
            printf("▒░░████████████████████▒\n");
            printf("         ░░█████████████████▒░░░░░░\n");
            printf("                  ░░░░░░░░░\n");
            printf("복이의 일반공격 ! ! !\n");
            printf("%d의 데미지를 입혔다.\n\n", boki3Att);
            mob3Hp -= boki3Att;
            sleep(2);
        }
        else if (slt3 == 2) //마법공격
        {
            printf("복이의 마법공격 ! ! !\n");
            if (bokiMp >= 20)
            {
                system("clear");
                printf("\n");
                printf("         ░▒▓▓█▓▓▓▒░░\n");
                printf("       ░▒▓░ ░▓█░  ▒▓░░\n");
                printf("      ░▓░  ░█ ░▓    ▒▒░\n");
                printf("     ▒▒   ░▒   ▒░    ░▓░\n");
                printf("    ▒▒    ░▒   ▓░     ▓░\n");
                printf("   ░▓    ░█      █░    ░▒\n");
                printf("   ▓░░░░░▓░░░░░░░░▓▒▒▒▒▒█░\n");
                printf("  ░█    ▒▒        ▒▒    ▓▒\n");
                printf("  ▒░▓  ░▓          ▓░  ░▒▓░\n");
                printf("  ▒ ▒░░▓            █░ ▓ ▒░\n");
                printf("  ▓  ▓▒▒             ▓▓░ ▒▒\n");
                printf("  ▓  ░▓              ░▒  ░▒\n");
                printf("  ▓  ▓▒░             █▓░ ░▒\n");
                printf("  ▓ ▒░░▓             ░░▓░▒░\n");
                printf("  ▓░▓  ░▓           ▓░ ░▓▓░\n");
                printf("  ░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█▓\n");
                printf("  ░▓░   ░▓░░░░░░░░░▒░░░░▒▒\n");
                printf("   ▒▒    ░▓       █░    ▓░\n");
                printf("   ░▓░    ░▒     ▒░    ▓░\n");
                printf("    ░▓    ░▓     ▓    ▒▒\n");
                printf("     ░▓░   ░█   █░  ░▓▒\n");
                printf("      ░▒▓░  ░▒ ░░  ▒▓░\n");
                printf("        ░▒▓▒▒▓░█▒▓▓░░\n");
                printf("           ░▒▒▒▒░░\n");
                printf("Mp %d(을)를 소모하였다.\n", 20);
                printf("%d의 대미지를 주었다.\n\n", boki3Skill);
                bokiMp -= 20;
                mob3Hp -= boki3Skill;
                sleep(2);
            }
            else
            {
                printf("Mp가 부족합니다.\n\n");
                continue;
            }
        }
        else if (slt3 == 3) //포션 사용
        {
            UsePotion(slt3);
            continue;
        }
        else if (slt3 == 4) //빤스런
        {
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(1);
            continue;
        }

        if (mob3Hp > 0)
        {
            if (mob3A_S >= 2)
            {
                system("clear");
                printf("   ⠀⠀ ⠀⠀⠀⠀⠀⢀⡤⣚⡉⠐⠀⠠⠀⠁⠀⠀⠀⠀ \n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡞⣿⢥⡀⠉⢂⠀⢀⠐⠀⠁⠀⠀⡀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠋⠉⠈⠀⠹⣆⠀⠉⠂⠤⠀⣂⣀⣀⡀\n");
                printf("⠀⠀⠀⠀⠀⠀⢀⣠⠟⠁⠀⠀⠀⠀⠀⢻⠄⠀⠀⠀⠀⠀⠈⠀⠀\n");
                printf("⠀⠀⢠⢴⠒⠏⠟⣙⠀⠠⠤⠀⣄⡀⡀⠀⢢⡀⢠⢄⠀⠀⠀⡀⣀\n");
                printf("⠀⠀⢸⢀⢀⡄⡆⠅⠀⠀⠀⠀⠈⠛⠉⠹⠳⠃⠚⢟⡀⣲⣒⡉⠀\n");
                printf("⠀⠀⢸⣜⣴⣞⣿⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠈⠉⠛⠊⠻\n");
                printf("⠀⠀⠀⠙⢿⣷⣼⡆⠀⠀⠀⠀⠀⠀⠘⠭⢐⣠⠖⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠈⠛⣷⡁⠀⠀⠀⠀⠆⠖⠖⠤⡀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠘⣿⣦⣀⠀⠀⠀⠀⠀⠀⠈⢲⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣦⣄⡄⡀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣷⣶⣤⣤⣀⣠⣀⣀⣀⣀⣀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
                printf("\033[0;31m울보 \033[0;45m훈발놈\033[0;37m의 공격 ! !\n");
                printf("%d의 대미지를 입었다.\n\n", mob3Att);
                bokiHp -= mob3Att;
            }
            else
            {
                system("clear");
                printf(" ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠉⠀⠀⠀⠀⠈⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⡿⠿\n");
                printf(" ⣿⣿⣿⣿⣿⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿\n");
                printf(" ⣿⣿⣿⣿⡿⠓⡈⠀⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⡀⠀⠀⠀⠙⢿⣿⣿⣿⣿\n");
                printf(" ⣿⣿⣿⡟⠂⠁⠀⠄⠀⠈⠐⠂⠀⠀⠀⠐⠂⠉⠀⠀⠈⠀⠀⠀⠀⠈⢿⣿⣿⣿\n");
                printf(" ⣿⣿⡿⠀⠀⠀⠀⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⡀⠄⠐⠂⠀⠀⠠⡀⠀⠈⣿⣿⣿\n");
                printf(" ⣿⣿⠇⠠⠄ ⣀⡀⣀⣂⠀⢦⢀⡀⠄⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⢄⡠⠋⠀⠈\n");
                printf(" ⣿⣿⠀⠀⠀⠀⠀⣀⣀⣥⣴⣌⡙⠂⠀⠐⠤⠤⠄⠀⢀⠀⠀⠀⠀⠐⠀⠀⠀⠀\n");
                printf(" ⣿⣿⡆⠀⠀⠀⠀⠀⠀⣍⠉⡩⠛⠓⠦⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf(" ⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf(" ⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣭⣶⣠⣤⣴\n");
                printf(" ⣿⣿⣿⣿⣿⣿⣷⣮⣍⣀⡀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣾⣿⣿⣿⣿⣿⣿⡿\n");
                printf("\033[0;31m울보 \033[0;45m훈발놈\033[0;37m의 눈치보내기 ! ! !\n");
                printf("%d의 대미지를 입었다.\n", mob3Skill);
                bokiHp -= mob3Skill;
            }
        }

        if (bokiHp <= 0)
        {
            printf("\n\n");
            printf("복이의 Hp가 0이 되었다");
            printf("\n\n");
            sleep(2);
            Dead();
            return 0;
        }
        sleep(2);
    }

    if (slt3 != 4)
    {
        for (int i = 0; i < 5; i++)
        {
            system("clear");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠖⠛⠿⣿⣿⣿⣿⡿⠟⠳⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠉⢀⠁⠀⣁⠀⠀⠀⠀⠀⢈⣈⡐⠙⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⡔⠁⠠⠊⠀⠀⠀⠀⣁⠀⠀⢠⠊⠀⠀⠀⠁⠄⠈⠆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠰⠁⢰⠀⠀⠀⠀⠀⠀⠀⠀⠉⣀⣀⠈⠀⠀⠀⠀⠀⠀⠀⢸⠈⠑⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⢀⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠈⠂⣀⡱⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠃⠠⠈⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣦⣀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⢀⣠⣮⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠙⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢻⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠛⠛⠃⠛⠛⠛⠛⢻⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⢸⠀⠀⠀⠀⠀⢰⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣎⢤⠀⠀⠀⠀⠀⠸⠂⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀\n");
            printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
            usleep(300000);
            system("clear");
            usleep(300000);
        }

        // mob3Hp <= 0 일시 실행
        printf("\n\n\n\t\033[0;31m울보 \033[0;45m훈발놈\033[0;37m 물리쳤다.\n");

        GetPotion();

        GetExp(maxMob3Hp);
    }

    //몬스터의 체력 랜덤 수치 적용
    // 1회씩 턴제공격
    //몬스터 처치 시 경험치 획득
} // end BattlePhase

int Boss()
{
    srand((unsigned)time(NULL));
    int bossHp = 50000, maxBossHp = 50000;
    int bossAtt = 0, bossSkillRan = 0, bossSkillOne = 5500, bossSkillTwo = 6000, bossSkillThree = 0, bossSkillFour = 0;
    int bossSkillPer = 0;
    int bossText = 0;

    int bokiAtt = 0, bokiSkill = 2000;

    int slt = 0;

    int k = 0;

    system("clear");
    bossText = rand() % 2 + 1;
    if (bossText == 1)
    {
        printf("\n\n\n\t둘리보다 고길동이 불쌍해지면\n");
        sleep(1);
        printf("\n\t너도 어른이 되는 거란다.\n\n");
        sleep(1);
        printf("\t하지만 이제 둘리를 알면 어른이란다.\n\n");
    }
    else if (bossText == 2)
    {
        printf("\n\n\n\t종로로 갈까요~~♪ \n\n");
        sleep(1);
        printf("\t명동으로 갈까요~~♩ \n\n");
        sleep(1);
        printf("\t차라리 청량리로 갈까요~~♬ \n\n");
        sleep(1);
        printf("\t오늘 저질맛좀 봐라!!\n");
        sleep(1);
        printf("\t이요옷~~!!\n\n");
    }
    sleep(2);

    while (bossHp > 0)
    {
        printf("                        (\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m)\n");
        printf("\033[0;31m                             %d/%d\n", bossHp, maxBossHp);
        printf("                     Hp:");
        for (k = 0; k < bossHp * 55 / maxBossHp; k++)
        {
            printf("■ ");
            if (k == 10 || k == 21 || k == 32 || k == 43)
                printf("\n                        ");
        }
        for (int j = 0; j < 55 - bossHp * 55 / maxBossHp; j++)
        {
            printf("□ ");
            if (j == 10 - k || j == 21 - k || j == 32 - k || j == 43 - k)
                printf("\n                        ");
        }
        printf("\033[0;37m\n\n");
        printf("                  ⠀⠀ \033[1;30m ⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⠀\033[0;37m⠀⠀⢏⣿⣿⡵⡀\n");
        printf("                  ⠀  \033[1;30m⠀⠀⠀⣠⣮⣷⣿⣿⣿⣿⣷⣄⣄⠀⠀⠀\033[0;37m⠀⠈⢞⣿⣿⡵⡀\n");
        printf("                \033[1;30m     ⠀⠀⡠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣏⢦⣤⡀⠀\033[0;37m⠀⠀⠫⣻⣿⣾⢄\n");
        printf("          \033[1;30m           ⠀⣔⣿⣿⣿⣿⣿⣿⠿⣿⠻⢟⣿⣿⣿⣿⣿⡆⠀\033[0;37m⠀⠀⠑⡿⣿⣯⢆\n");
        printf("        \033[1;30m            ⢰⣸⢿⣻⢟⠃⠉⠉⠀⡠⠤⠸⣸⣿⣿⣿⡳⠁⠀⠀\033[0;37m⠀⠀⡨⠺⠿⠇⢓⡄\n");
        printf("         \033[1;30m           ⠧⠊⠁\033[1;31m⠘⣖⣳⠠⣶⣋⡹⠁\033[1;30m⠛⣩⢻⠋⠀\033[0;33m⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⢾\n");
        printf("⠀        \033[0;33m          ⠀⢠⠂⠁⠓⠒⠊⠀⡠⠤⡀⢠⠀⠚⠀⠀⠀⠀⠀⡠⠊⢀⠤⡤⣔⠩⠼\n");
        printf("                   ⠀⠀⢇⠀⠀⢀⡠⢔⣪⠠⠖⠇⡘⠀⠀⠀⢀⠄⠒⠉⢀⠔⠁⠀⣧⢞⠮⠭⠵\n");
        printf("⠀                 ⠀  ⠘⠒⠉⣾⣀⣀⠀⣀⣀⠦⠗\033[1;34m⠹⠙⠃\033[0;33m⠁⠀⡠⠔⡡⠔⠒⠉⡨⢴⢹⣿⣏⡆\n");
        printf("⠀              \033[1;34m     ⠀⠀⠀⡸⠉⠀⠀⠁⠀⠀⠀⠀⣇⡠⡄\033[0;33m⡶⠯⠔⠈⠀⠀⡠⠊⠀\033[0;37m⠀⡿⣿⣿⡇\n");
        printf("               \033[1;34m     ⠀⠀⢀⠇⠀⠀⠀⠀⢀⣀⠤⡤⠵⠊⢸\033[0;33m⠀⡠⠤⠤⠐⠉⠀⠀\033[0;37m⠀⠀⣷⣿⢿⡇\n");
        printf("               \033[1;34m    ⠀⠀⢀⠃⠀⢀⣀⣀⣀⣠⣀⣀⣿⠉⠉⠉\033[0;33m⠉\n");
        printf(" -------------------------------------------------------------\n");
        printf("                         \033[0;36m      복이\n");
        printf("\033[0;31m               %d/%d       \033[0;34m              %d/%d\n", bokiHp, maxBokiHp, bokiMp, maxBokiMp);
        printf("      \033[0;31m Hp:");
        for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
            printf("□ ");
        printf("     \033[0;34m Mp:");
        for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
            printf("■ ");
        for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
            printf("□ ");
        printf("\033[0;37m\n\n");
        printf("                 \033[0;33m    대미지: %d~%d\033[0;37m\n\n", minBokiDam, maxBokiDam);
        printf("        1 ) 일반공격 2 ) 마법공격 3 ) 포션사용 4 ) 빤스런\n");
        printf("                          선택 : ");
        scanf(" %d", &slt);

        while (1) //복이의 일반공격 대미지 설정
        {
            bokiAtt = rand() % maxBokiDam + 1;
            if (bokiAtt > maxBokiDam || bokiAtt < minBokiDam)
                continue;
            else
                break;
        }

        while (1) //보스 공격 대미지 설정
        {
            bossAtt = rand() % 5000 + 1;
            if (bossAtt > 5000 || bossAtt < 1000)
                continue;
            else
                break;
        }

        bossSkillPer = rand() % 5 + 1;
        bossSkillThree = (bokiHp / 10) * bossSkillPer; // 복이 현재체력의 10 ~ 50% 대미지

        while (1)
        {
            bossSkillPer = rand() % 7 + 1;
            if (bossSkillPer < 3)
                continue;
            else
                break;
        }

        bossSkillFour = (bokiHp / 10) * bossSkillPer;

        if (slt == 1) //일반공격
        {
            system("clear");
            printf("\n");
            printf("       ░░░░░░░░░░\n");
            printf("▒░░████████████████████▒\n");
            printf("         ░░█████████████████▒░░░░░░\n");
            printf("                  ░░░░░░░░░\n");
            printf("복이의 일반공격 ! ! !\n");
            printf("%d의 데미지를 입혔다.\n\n", bokiAtt);
            bossHp -= bokiAtt;
            sleep(2);
        }
        else if (slt == 2) //마법공격
        {
            printf("복이의 마법공격 ! ! !\n");
            if (bokiMp >= 20)
            {
                system("clear");
                printf("\n");
                printf("         ░▒▓▓█▓▓▓▒░░\n");
                printf("       ░▒▓░ ░▓█░  ▒▓░░\n");
                printf("      ░▓░  ░█ ░▓    ▒▒░\n");
                printf("     ▒▒   ░▒   ▒░    ░▓░\n");
                printf("    ▒▒    ░▒   ▓░     ▓░\n");
                printf("   ░▓    ░█      █░    ░▒\n");
                printf("   ▓░░░░░▓░░░░░░░░▓▒▒▒▒▒█░\n");
                printf("  ░█    ▒▒        ▒▒    ▓▒\n");
                printf("  ▒░▓  ░▓          ▓░  ░▒▓░\n");
                printf("  ▒ ▒░░▓            █░ ▓ ▒░\n");
                printf("  ▓  ▓▒▒             ▓▓░ ▒▒\n");
                printf("  ▓  ░▓              ░▒  ░▒\n");
                printf("  ▓  ▓▒░             █▓░ ░▒\n");
                printf("  ▓ ▒░░▓             ░░▓░▒░\n");
                printf("  ▓░▓  ░▓           ▓░ ░▓▓░\n");
                printf("  ░█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█▓\n");
                printf("  ░▓░   ░▓░░░░░░░░░▒░░░░▒▒\n");
                printf("   ▒▒    ░▓       █░    ▓░\n");
                printf("   ░▓░    ░▒     ▒░    ▓░\n");
                printf("    ░▓    ░▓     ▓    ▒▒\n");
                printf("     ░▓░   ░█   █░  ░▓▒\n");
                printf("      ░▒▓░  ░▒ ░░  ▒▓░\n");
                printf("        ░▒▓▒▒▓░█▒▓▓░░\n");
                printf("           ░▒▒▒▒░░\n");
                printf("Mp %d(을)를 소모하였다.\n", 20);
                printf("%d의 대미지를 주었다.\n\n", bokiSkill);
                bokiMp -= 20;
                bossHp -= bokiSkill;
                sleep(2);
            }
            else
            {
                printf("Mp가 부족합니다.\n\n");
                continue;
            }
        }
        else if (slt == 3) //포션 사용
        {
            UsePotion(slt);
            continue;
        }
        else if (slt == 4) //빤스런
        {
            printf("\n어쩔다공주를 눈앞에 두고 도망칠 수는 없다.\n");
            sleep(2);
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(1);
            continue;
        }

        if (bossHp > 0) //보스의 턴
        {
            bossSkillRan = rand() % 100 + 1;

            if (bossSkillRan < 5)
            {
                system("clear");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 베기!!!!\n");
                printf("공격이 빗나갔다!!!\n");
            }
            else if (bossSkillRan > 5 && bossSkillRan < 50)
            {
                system("clear");
                printf("               █\n");
                printf("               ██\n");
                printf("                █\n");
                printf("               ██\n");
                printf("               ██\n");
                printf("              ██\n");
                printf("            ███\n");
                printf("           ██\n");
                printf("          ██\n");
                printf("         █\n");
                printf("        █\n");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 베기!!!!\n");
                printf("%d의 대미지를 입었다.\n\n", bossAtt);
                bokiHp -= bossAtt;
            }
            else if (bossSkillRan > 50 && bossSkillRan < 70)
            {
                system("clear");
                printf("     █\n");
                printf("    █          █\n");
                printf("    ██        ██\n");
                printf("     █        ██\n");
                printf("     ██      ██\n");
                printf("      ██     ██\n");
                printf("      ███   ██\n");
                printf("        █████\n");
                printf("         ███\n");
                printf("       ██████\n");
                printf("      ██    ███\n");
                printf("     ██       ██\n");
                printf("    █           █\n");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 삼재검법!!!!\n");
                printf("%d의 대미지를 입었다.\n", bossSkillOne);
                bokiHp -= bossSkillOne;
            }
            else if (bossSkillRan > 70 && bossSkillRan < 85)
            {
                system("clear");
                printf("                         █░\n");
                printf("                        ░▒░          ░\n");
                printf("                        █░▒         ░█\n");
                printf("                       ▒░ █░        ▓▓\n");
                printf("                      ░█  ░░       ▒▒▓\n");
                printf("                      █░   ▒      ░▓ ▒\n");
                printf("            ░░       ░▓    █░     ▓░ ░\n");
                printf("            ▓▒      ░█     ▓░    ▒▒\n");
                printf("           ░█▓      ▒▒     ▒░    ▓░\n");
                printf("           ▒▒▓     ░█       █   ░▓\n");
                printf("           ▓ ▓     ▒░       █░  ▓░\n");
                printf("          ░█ ▒░   ░█        ▒░ █\n");
                printf("          ░▓ ░▓   ▓          ░▒\n");
                printf("          ▓  ░█  ░▓          █░\n");
                printf("         ░█   ▒  ▓            ▓░\n");
                printf("  ██████████████████████████████▒▒▒▒▒\n");
                printf("  ░▒▒░░░▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▓▒\n");
                printf("   ▓░    ▒█             ▓▒\n");
                printf("  ░▓     ░▒              ░\n");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 태산십팔반검!!!!");
                printf("%d의 대미지를 입었다.\n", bossSkillTwo);
                bokiHp -= bossSkillTwo;
            }
            else if (bossSkillRan > 85 && bossSkillRan < 95)
            {
                system("clear");
                printf("         ░\n");
                printf("░        ▓▓\n");
                printf("░▓      ░█▓      ░\n");
                printf(" ▓      ▒█▓     ░░\n");
                printf(" ░▓     ▒█▓     ▒░\n");
                printf("  ▒▒    ▒█▓    ░▓\n");
                printf("  ░▓    ▒██░  ░█▒\n");
                printf("   ▓▓░  ▒██░ ░▒█\n");
                printf("    █▓  ▒██░░▓█▒\n");
                printf("    ░██▒▒██░▓█▓\n");
                printf("     ░▓██████▒\n");
                printf("      ░▓████▓\n");
                printf("      ░▓█████▒\n");
                printf("    ▒▒██▓██▓███▓▒░░\n");
                printf("   ▒████░▒██▒  ▒█████\n");
                printf("▓██▒▒░  ▒██▒\n");
                printf("        ▒██▒\n");
                printf("        ░██░\n");
                printf("        ░█▓\n");
                printf("         ░░\n");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 탈명연환삼선검!!!!\n");
                printf("%d의 대미지를 입었다.\n", bossSkillThree);
                bokiHp -= bossSkillThree;
            }
            else if (bossSkillRan > 95)
            {
                system("clear");
                printf("█░  ▓█░   ░▒████\n");
                printf("▒█  ░▓█░ ░█▓░░█░\n");
                printf("░█░   ▒█▒█▒  ▓▓\n");
                printf(" ▓▓   ░▓█▒  ░█░\n");
                printf(" ░█░  ░█▓█░ ▒▓    ░▓\n");
                printf("░ ▒▒  █▒ ▓█░█▒  ░░█▒\n");
                printf("█▓▓█▓▓█▓░ ▓▓█░  ▓█▓▓\n");
                printf("▓████████████░░█████\n");
                printf(" ░▓███░ ░░▒███████░\n");
                printf("  ░▓██░░▒█████░ ▒███\n");
                printf("    ▓███▒▓██░█▒   ░░\n");
                printf("░▒▓██▓█▓▓██░ ▒█░\n");
                printf("██░░█░▓██▒█░  █░\n");
                printf("░  ░██▓████░  ░█\n");
                printf("  ▒██░ ░████░ ░█░\n");
                printf("▓█▓░█░  ▒█░▒█▓░▓▓\n");
                printf("▓░  █░  ▒██░ ▓█▒█░\n");
                printf("    █░  ▒▒█▒  ░▓█▓\n");
                printf("    █░  █░░█░   ▒██\n");
                printf("    █░ ░█░ ▒█    █\n");
                printf("\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 백변천환형산운무십삼식!!!!\n");
                printf("%d의 대미지를 입었다.\n", bossSkillFour);
                bokiHp -= bossSkillFour;
            }
        }

        if (bokiHp <= 0)
        {
            printf("\n\n");
            printf("복이의 Hp가 0이 되었다");
            printf("\n\n");
            sleep(2);
            Dead();
            return 0;
        }
        sleep(2);
    }

    // mobHp <= 0 일시 실행
    Ending();
} // end Boss

void Ending()
{
    int endingchoice = 0;
    system("clear");
    printf("\n\n\n\t\t\033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m을 쓰려뜨렸다!!!!!\n");
    sleep(2);
    system("clear");
    printf("\n\n\n\t\t눈앞에 깊고 어두컴컴한 계단이 생겼다...\n\n");
    printf("\t\t   1 ) 내려간다   2 ) 가지않는다\n\n");
    printf("\t\t\t선택 : ");
    scanf(" %d", &endingchoice);
    system("clear");
    if (endingchoice == 1)
    {
        printf("\n\n\n\t\t\t터벅...");
        sleep(2);
        printf("터벅...\n");
        sleep(2);
        system("clear");
        printf("\n\n\n\t눈 앞에 모순되게도 장소와 어울리지않게\n\t아름답게 잘 꾸며진 칠흑색의 문이 보인다.\n\n");
        sleep(2);
        printf("\t문에 손을 갖다대니 \n\t끼익... 하는 과장스럽다고도 할수 있는 소리와 함께 문이 열린다.\n\n");
        sleep(2);
        printf("\t그 안으로 몸을 옮긴 복이는\n\t나즈막히 그가 찾던사람의 이름을 부른다.\n\n");
        sleep(2);
        system("clear");
        printf("\n\n\n\t\t\033[0;36m복이\033[0;37m : \033[1;35m어쩔다공주\033[0;37m!!");
        sleep(2);
        printf("    \033[1;35m어쩔다공주\033[0;37m?!!\n\n");
        sleep(2);
        printf("\t하지만 그가 애타게 찾던 사람의 목소리는 들려오지 않고\n\t되려 더 크게 불러보지만 대답은 들려오지 않는다..\n\n");
        sleep(2);
        printf("\t\033[0;31m결국 여기까지 왔구나... 모험왕 \033[0;36m복이\033[0;37m..\033[0;37m\n\n");
        sleep(2);
        printf("\t끈적하고도 기분나쁜 목소리가 복이의 귓가에 들려온다.\n\n");
        sleep(2);
        printf("\t\033[0;36m복이\033[0;37m : 누구ㄴ...\n\n");
        sleep(2);
        printf("\t          \033[0;31m??? : 백변천환형산운무십삼식..\033[0;37m\n\n");
        sleep(2);
        printf("\t\033[0;36m복이\033[0;37m의 말이 차마 나오기도 전 들려온 음성과 함께\n\t\033[0;36m복이\033[0;37m의 몸은 차갑게 식어갔다...\n\n");
        sleep(2);
        system("clear");
        printf("\n\n\n\t\t\t Ending 1 ) 의문의 죽음");
        sleep(2);
    }

    else if (endingchoice == 2)
    {
        printf("\n\n\n\t\033[0;36m복이\033[0;37m : 드디어 끝난건가....\n\n");
        usleep(500000);
        printf("\t말이 끝나려는 찰나 \033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 몸이 빛나기 시작했다\n\n");
        sleep(2);
        printf("\t복이는 의문감과 함께 빛나는곳으로 다가가기 시작한다.\n\n");
        sleep(2);
        printf("\t빛의 근원지앞에 서게 된 \033[0;36m복이\033[0;37m의 눈에 비친 그것은...\n\n");
        sleep(2);
        printf("\t차갑게 식은 \033[1;35m어쩔다공주\033[0;37m였다...\n\n");
        sleep(2);
        system("clear");
        printf("\n\n\n\t\033[0;36m복이\033[0;37m : 이게 어떻게...\n\n");
        sleep(2);
        printf("\t\033[0;36m복이\033[0;37m의 정신은 무너져갔고...\n\t곧이어 자신의 상황을 부정하기 시작한다.\n\n");
        sleep(2);
        printf("\t\033[0;36m복이\033[0;37m : 아니야.. 이건 아니야....\n\n");
        sleep(2);
        printf("\t                            \033[0;31m??? : 백변천환형산운무십삼식..\033[0;37m\n\n");
        sleep(2);
        printf("\t끈적하고 기분나쁜 목소리와 함께 \033[0;36m복이\033[0;37m의 몸이 차갑게 식어갔다.\n\n");
        sleep(2);
        printf("\t\033[0;31m귀찮군...\033[0;37m\n\n\t모든것을 귀찮게 여기는듯한 말과 함께\n\t\033[0;35m마왕 \033[1;31m 리우홍글\033[0;37m은 나지막히 한마디를 더 내뱉는다.\n\n");
        sleep(2);
        printf("\t\033[0;35m마왕\033[1;31m 리우홍글\033[0;37m : 부활하라 \033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m...\n\n");
        sleep(2);
        printf("\t\033[0;35m마왕\033[1;31m 리우홍글\033[0;37m의 말을 끝으로 어쩔다공주의 모습은\n\t모험왕 복이가 저지했던 \033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m의 모습으로 변해갔다.\n\n");
        sleep(2);
        printf("\t그곳에 남은것은 싸늘하게 식은 \033[0;36m복이와 \033[0;31m죽음의 사도\033[1;31m 리우홍글\033[0;37m뿐이었다...\n\n");
        sleep(2);
        system("clear");
        printf("Ending 2) 불쾌한 진실\n");
        sleep(2);
    }

    system("clear");
    system("clear");
    printf("\n\n\n\t-코딩왕국-\n\n\t어상혁 : 이번 지원자도 실패인가...\n\n");
    sleep(2);
    printf("\t신하1: 며칠째 연락이 닫지 않는것을 보면 그런거같습니다 폐하.\n\n");
    sleep(2);
    printf("\t어상혁: 그런것같군.. 다른 지원자를 모집하라\n\n");
    sleep(2);
    printf("\t신하 일동 : 예 폐하!\n\n");
    sleep(2);
} // end Ending

int main(void)
{
    srand((unsigned)time(NULL));

    int boki = 0; //복이 위치
    int nom1Die = 0, nom2Die = 0, nom3Die = 0, mob = 0;
    int boss = 0, nom1 = 0, nom2 = 0, nom3 = 0;
    int bossPer = 0;
    int floor = 0;
    int clearMob = 0;
    char move;
    int gameS = 0;


    gameS = GameStart();
    if (gameS == 1)
        return 0;

    Prologue();
    system("clear");

    while (!dead)
    {
        if (mob == 0)
        {
            while (1) //몬스터 랜덤위치에 3마리 생성
            {
                nom1 = rand() % 95 + 1;
                nom2 = rand() % 95 + 1;
                nom3 = rand() % 95 + 1;
                if (nom1 > 3 && nom2 > 3 && nom3 > 3)
                {
                    if (nom1 != nom2 && nom1 != nom3 && nom2 != nom3 && nom1 != boki && nom2 != boki && nom3 != boki)
                    {
                        nom1Die = 0;
                        nom2Die = 0;
                        nom3Die = 0;
                        mob = 3;
                        break;
                    }
                }
            }
        }

        system("clear");
        printf("\n");
        printf("   \033[0;31mTHE\033[0;33m LEGENO\033[0;35m OF \033[0;36mBOKI\n\n");

        for (int i = 0; i < 10; i++) // 10x10 생성
        {
            printf(" ");
            for (int j = 0; j < 10; j++)
            {
                if (i == boki / 10 && j == boki % 10)
                    printf("\033[0;36m● \033[0;37m");
                else if (i == boss / 10 && j == boss % 10)
                    printf("\033[0;37m★ ");
                else if (i == nom1 / 10 && j == nom1 % 10)
                {
                    if (nom1Die == 0)
                        printf("\033[0;31m■ \033[0;37m");
                    else
                        printf("○ ");
                }
                else if (i == nom2 / 10 && j == nom2 % 10)
                {
                    if (nom2Die == 0)
                        printf("\033[0;31m■ \033[0;37m");
                    else
                        printf("○ ");
                }
                else if (i == nom3 / 10 && j == nom3 % 10)
                {
                    if (nom3Die == 0)
                        printf("\033[0;31m■ \033[0;37m");
                    else
                        printf("○ ");
                }
                else
                    printf("○ ");
            }
            if (i == 0)
                printf("\033[0;33m  Lv.%d   대미지 : %d ~ %d\033[0;37m", bokiLevel, minBokiDam, maxBokiDam);
            if (i == 2)
                printf("\033[0;31m      %d/%d\033[0;37m", bokiHp, maxBokiHp);
            if (i == 3)
            {
                printf("\033[0;31m  HP:");
                for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
                    printf("■ ");
                for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
                    printf("□ ");
                printf("\033[0;37m");
            }
            if (i == 4)
                printf("\033[0;34m      %d/%d\033[0;37m", bokiMp, maxBokiMp);
            if (i == 5)
            {
                printf("\033[0;34m  MP:");
                for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
                    printf("■ ");
                for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
                    printf("□ ");
                printf("\033[0;37m");
            }
            if (i == 7)
                printf("       [Inventory]");
            if (i == 8)
                printf("\033[0;31m       Hp포션\033[0;37m   %d개", hpPotion);
            if (i == 9)
                printf("\033[0;34m       Mp포션\033[0;37m   %d개", mpPotion);
            printf("\n");
        }
        printf("\n\033[0;33m   ");
        for (int k = 0; k < bokiExp * 13 / maxBokiExp; k++)
            printf("■ ");
        for (int k = 0; k < 13 - bokiExp * 13 / maxBokiExp; k++)
            printf("□ ");
        printf("\n\t EXP: %d/%d\033[0;37m", bokiExp, maxBokiExp);
        printf("\n      w  \t\n");
        printf("    a   d\t    h) \033[0;31mHp포션\033[0;37m 사용\n"); //플레이어에게 입력받을 값 출력
        printf("      s  \t    m) \033[0;34mMp포션\033[0;37m 사용\n");
        scanf(" %c", &move);

        if (move == 'a')
        {
            if (boki <= 0 + floor)
            {
                continue;
            }
            boki--;
        }
        else if (move == 'd')
        {
            if (boki >= 9 + floor)
            {
                continue;
            }
            boki++;
        }
        else if (move == 'w')
        {
            if (floor <= 0)
            {
                continue;
            }
            floor -= 10;
            boki -= 10;
        }
        else if (move == 's')
        {
            if (floor > 80)
            {
                continue;
            }
            floor += 10;
            boki += 10;
        } //상하좌우 입력에 따른 복이 위치 이동
        else if (move == 'h')
        {
            UsePotion((int)move);
            continue;
        }
        else if (move == 'm')
        {
            UsePotion((int)move);
            continue;
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            sleep(1);
            continue;
        }

        if (boki == nom1 || boki == nom2 || boki == nom3) // 적과 조우시 맵 깜빡거림
        {
            for (int l = 0; l < 5; l++)
            {
                system("clear");
                printf("\n");
                printf("   \033[0;31mTHE\033[0;33m LEGENO\033[0;35m OF \033[0;36mBOKI\n\n");

                for (int i = 0; i < 10; i++) // 10x10 생성
                {
                    printf(" ");
                    for (int j = 0; j < 10; j++)
                    {
                        if (i == boki / 10 && j == boki % 10)
                            printf("\033[0;36m● \033[0;37m");
                        else if (i == boss / 10 && j == boss % 10)
                            printf("\033[0;37m★ ");
                        else if (i == nom1 / 10 && j == nom1 % 10)
                        {
                            if (nom1Die == 0)
                                printf("\033[0;31m■ \033[0;37m");
                            else
                                printf("○ ");
                        }
                        else if (i == nom2 / 10 && j == nom2 % 10)
                        {
                            if (nom2Die == 0)
                                printf("\033[0;31m■ \033[0;37m");
                            else
                                printf("○ ");
                        }
                        else if (i == nom3 / 10 && j == nom3 % 10)
                        {
                            if (nom3Die == 0)
                                printf("\033[0;31m■ \033[0;37m");
                            else
                                printf("○ ");
                        }
                        else
                            printf("○ ");
                    }
                    if (i == 0)
                        printf("\033[0;33m  Lv.%d   대미지 : %d ~ %d\033[0;37m", bokiLevel, minBokiDam, maxBokiDam);
                    if (i == 2)
                        printf("\033[0;31m      %d/%d\033[0;37m", bokiHp, maxBokiHp);
                    if (i == 3)
                    {
                        printf("\033[0;31m  HP:");
                        for (int k = 0; k < bokiHp * 10 / maxBokiHp; k++)
                            printf("■ ");
                        for (int k = 0; k < 10 - bokiHp * 10 / maxBokiHp; k++)
                            printf("□ ");
                        printf("\033[0;37m");
                    }
                    if (i == 4)
                        printf("\033[0;34m      %d/%d\033[0;37m", bokiMp, maxBokiMp);
                    if (i == 5)
                    {
                        printf("\033[0;34m  MP:");
                        for (int k = 0; k < bokiMp * 10 / maxBokiMp; k++)
                            printf("■ ");
                        for (int k = 0; k < 10 - bokiMp * 10 / maxBokiMp; k++)
                            printf("□ ");
                        printf("\033[0;37m");
                    }
                    if (i == 7)
                        printf("       [Inventory]");
                    if (i == 8)
                        printf("\033[0;31m       Hp포션\033[0;37m   %d개", hpPotion);
                    if (i == 9)
                        printf("\033[0;34m       Mp포션\033[0;37m   %d개", mpPotion);
                    printf("\n");
                }
                printf("\n\033[0;33m   ");
                for (int k = 0; k < bokiExp * 13 / maxBokiExp; k++)
                    printf("■ ");
                for (int k = 0; k < 13 - bokiExp * 13 / maxBokiExp; k++)
                    printf("□ ");
                printf("\n\t EXP: %d/%d\033[0;37m", bokiExp, maxBokiExp);
                printf("\n      w  \t\n");
                printf("    a   d\t    h) \033[0;31mHp포션\033[0;37m 사용\n"); //플레이어에게 입력받을 값 출력
                printf("      s  \t    m) \033[0;34mMp포션\033[0;37m 사용\n");
                usleep(300000);
                system("clear");
                usleep(300000);
            }
        }

        if (boki == nom1)
        {
            if (nom1Die == 0)
            {
                if (bokiLevel >= 10)
                {
                    bossPer = rand() % 10 + 1;
                    if (bossPer == 1)
                        Boss();
                    else
                    {
                        clearMob = BattlePhase();
                        if (clearMob == 2)
                        {
                        }
                        else
                        {
                            nom1Die++;
                            mob--;
                        }
                    }
                }
                else
                {
                    clearMob = BattlePhase();
                    if (clearMob == 2)
                    {
                    }
                    else
                    {
                        nom1Die++;
                        mob--;
                    }
                }
            }
        }
        else if (boki == nom2)
        {
            if (nom2Die == 0)
            {
                if (bokiLevel >= 10)
                {
                    bossPer = rand() % 10 + 1;
                    if (bossPer == 1)
                        Boss();
                    else
                    {
                        clearMob = BattlePhaseTwo();
                        if (clearMob == 2)
                        {
                        }
                        else
                        {
                            nom2Die++;
                            mob--;
                        }
                    }
                }
                else
                {
                    clearMob = BattlePhaseTwo();
                    if (clearMob == 2)
                    {
                    }
                    else
                    {
                        nom2Die++;
                        mob--;
                    }
                }
            }
        }
        else if (boki == nom3)
        {
            if (nom3Die == 0)
            {
                if (bokiLevel >= 10)
                {
                    bossPer = rand() % 10 + 1;
                    if (bossPer == 1)
                        Boss();
                    else
                    {
                        clearMob = BattlePhaseThree();
                        if (clearMob == 2)
                        {
                        }
                        else
                        {
                            nom2Die++;
                            mob--;
                        }
                    }
                }
                else
                {
                    clearMob = BattlePhaseThree();
                    if (clearMob == 2)
                    {
                    }
                    else
                    {
                        nom2Die++;
                        mob--;
                    }
                }
            }
        }
    }
    return 0;
} // end main