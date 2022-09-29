/*
* author : junhoo jeon
* date : 2022-09-29
* description : basic rpg game
*/

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//�÷��̾�� ������ ü��, ���ݷ�, ���� ����
	int player_hp = 100;
	int player_atk = 10;
	int player_def = 8;
	
	int monster_hp = 80;
	int monster_atk = 10;
	int monster_def = 8;

	srand(time(NULL));

	while (1) { //��ȣ�� �̸� ���� �ݱ�
		//player status
		printf("player status==========\n");
		printf("- player HP = $d\n", player_hp);
		printf("- player ATK = $d\n", player_atk);
		printf("- player DEF = $d\n", player_def);
		printf("=======================\n");

		//monster status
		printf("monster status==========\n");
		printf("- monster HP = $d\n", monster_hp);
		printf("- monster ATK = $d\n", monster_atk);
		printf("- monster DEF = $d\n", monster_def);
		printf("=======================\n");

		//menu
		printf("menu==========\n");
		printf("1. Attack");
		printf("2. Defense");
		printf("3. Run");

		int choice;
		scanf("%d", &choice);

		if (choice == 1) { //atk
			int damage = player_atk - monster_def;
			int is_critcal = rand() % 2; //����� 0 or 1 ��, T or F�� �������� ������
			
			if (is_critcal) damage *= 2;

			printf("Hit the monster with damage $d\n", damage);
			monster_hp -= damage;
		}

		else if(choice == 2) { //def
			int damage = monster_atk - player_def;
			int is_critcal = rand() %2;

			if (is_critcal) damage *= 2;

			printf("Got damage %d from monster", damage);
			player_hp -= damage;
		}

		else if (choice == 3) {
			printf("Bye Bye");
			break;
		}
		else {
			printf("Wrong number");
			continue; //���� �����̿� �ִ� ���� ������ �ǵ��ư�
		}

		if (player_hp <= 0) {
			printf("You Lose");
			break;
		}

		if (monster_hp <= 0) {
			printf("You Win");
			break;
		}
	}


	return 0;
}