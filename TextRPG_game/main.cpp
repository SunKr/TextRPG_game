#include <iostream>
#include <time.h>



enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};


enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};


enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SIZE 32

struct _tagInventory
{
	int iGold;

};

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB	eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagInventory tInventory;

};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};


using namespace std;

int main()
{

	srand((unsigned int)time(0));

	// ���� �����Ҷ� �÷��̾� ���� ����
	// �÷��̾� �̸��� �Է¹޴´�.
	_tagPlayer tPlayer = {};

	cout << "�̸� :";
	cin.getline(tPlayer.strName,NAME_SIZE - 1);
	
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. ��� " << endl;
		cout << "2. �ü� " << endl;
		cout << "3. ������ " << endl;
		cout << "������ �����ϼ��� :";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;

	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	// iJob�� int�� ������ Ÿ���� ���� �ʾ� Ÿ���� �����ֱ� ����  
	// iJob�տ� enumŸ��(JOB)���� ����ȯ
	tPlayer.eJob = (JOB)iJob; 
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "���");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "�ü�");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "������");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}

	//���͸� �����Ѵ�.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};


	// ��� ����
	strcpy_s(tMonsterArr[0].strName, "���");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// �巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	while (true)
	{
		system("cls");


		cout << "****************  Lobby  ************" << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�޴��� �����ϼ���";

		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		// ����
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "****************  Map  ************" << endl;
				cout << "1. ���� " << endl;
				cout << "2  ���� " << endl;
				cout << "3. ����� " << endl;
				cout << "4. �ڿ����� " << endl;
				cout << "���� �����ϼ��� : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				// �ڷ� ���� ��� (�޴�â���� ������)
				if (iMenu == MT_BACK)
					break;

				// ������ �޴����� 1�� ���ָ� ���� �迭�� �ε���
				// �ش���� ���� ����
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					switch (iMenu)
					{
					case MT_EASY:
						cout << "****************  Easy  ************" << endl;
						break;
					case MT_NORMAL:
						cout << "****************  NORMAL  ************" << endl;
						break;
					case MT_HARD:
						cout << "****************  HARD  ************" << endl;
						break;
					}

					//Player ������ ������ش�.
					cout << "============== Player ====================" << endl;
					cout << "�̸� : " << tPlayer.strName << "\t����" <<
						tPlayer.strJobName << endl;
					cout << "���� : " << tPlayer.iLevel << "\t����ġ :" <<
						tPlayer.iExp << endl;
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t���� : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "�������  : " << tPlayer.tInventory.iGold << "Gold" << endl << endl;

					//���� ���� ���
					cout << "============== Monster ====================" << endl;
					cout << "�̸� : " << tMonster.strName << "\t����" <<
						tMonster.iLevel << endl;
					cout << "���ݷ� : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t���� : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t���� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "ȹ�� ����ġ :" << tMonster.iExp << "\tȹ���� : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl<< endl;
				
				
					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ���  :";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{ 
						// 15 - 5 => 10 + 1 ������ 10 ���� ���� + 5�� �ϸ� 5���� 15 ������ �������� �޴´�.
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) +
							+tPlayer.iAttackMin;
					}
						break;
					}

					if (iMenu == BATTLE_BACK)
						break;
				
				}
				

			}



			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "�߸� �����Ͽ����ϴ�." << endl;
			break;
		}



	}



	return 0;
}