#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 50    // �̦h��J���
#define MAX_SPECIAL_UNITS 5    // �S����Ӽ�

int main() {
	char su[MAX_SPECIAL_UNITS][3] = { "�U", "��", "��", "��", "��" }; // �S����
	/* �U�B���B���B�ʡB���B��B���B���B��B���B���B�� */

	char input[MAX_INPUT + 1];
	char output[MAX_INPUT * 4 + 1];
	char output_tmp[MAX_INPUT * 4 + 1];
	output[0] = '\0';
	char tmp_ch[5];

	printf("��J���ԧB�Ʀr:\n");
	scanf("%s", input);
	/* ����Ū�쪺�r��s�� input �o�Ӱ}�C�̭��A�ܩ�input�n�h���A�ھڧƱ檺��ƽվ�MAX_INPUT
	 * �o�ӼƦr�j�p�|�v�T��output�}�C���j�p�A�Ҧp��J10��Ʀr�A�̦h�i��n��X20�Ӥ���r
	 * �@�Ӥ���n���char�Ӧs�A�ҥH�ܤ֭n10*4��char�A�h�[�@��char�O���F��'\0'��ܵ����@*/

	int i, cnt_su, cnt_nu;
	/* cnt_su�����{�b�n��X "�B", "��", "�a"
	 * cnt_nu�����{�b�n��X "�U", "��", "��", "��", "��" */

	for (i = (strlen(input) - 1), cnt_su = 0, cnt_nu = 0; i >= 0; i--) {
	/* �p�P�ڭ̥��`�Ʀ�ƪ���k�q�Ӧ�ƶ}�l�� �A�ҥHi�q(strlen(input) - 1)�r����ݶ}�l���e��
	 * strlen(input) �O�Ψӭp��input�r�ꪺ���סA�Ҧp��Jabc�hstrlen(input)=3 */

		tmp_ch [0] = '\0';
		output_tmp[0] = '\0';
		/* tmp_ch �O�ΨӼȦs�ثe�ƨ쪺�Ʀr��������X�A�ܩ�p������ݤ@�U�d��
		 * �Ҧp�B�ڭ̿�J123�A�h� "����", "�L�B", "��" �T�դ��e�A�{���O�q�᭱�}�l�ݡA�ҥH�L�ݨ쪺�r��O321
		 * �ҥH�ݭn��ثe�����쪺��X���Ȧs�_�ӡA��Ū��U�@�ռƦr�A��o�ǼƦr����m���output�諸�a��
		 * �Ĥ@��: Ū��3�Atmp_ch = "��"�Aoutput = "��"
		 * �ĤG��: Ū��2�Atmp_ch = "�L�B"�Aoutput = "�L�B ��"
		 * �ĤT��: Ū��1�Atmp_ch = "����"�Aoutput = "���� �L�B ��"
		 * tmp_ch [0] = '\0'; �O���i���M�Ű}�C����k�A���S���u���M��
		 * �u�O�Ĥ@��char�Y�������Ÿ��A�����L�X�ӷ|��Ŧr��ĪG�@��*/

		/* ���U�ӷ|�Ψ�sprintf()�o�Ө禡��printf()�ܹ��A�Ϊk�]�X�G�@��
		 * �t�O�b��L����r�ꪽ���q�X�ӡA�ӬO��r��s����w���}�C�̭�
		 * �Ҧp�B�ڭ̭n�L�X hello world!�A�ڭ̷|�gprintf("hello world!");
		 * �Y���Q�����L�X�ӡA�ӷQ�s�b�Y�}�C char out[50] �����ܡA�ڭ̷|�gsprintf(out, "hello world!");
		 * ��ɭԷQ�L�X�o�Ӧr��ɡA�N�����L�Xout�r�� printf("%s", out); �Y�i*/

		/* �B�z�B�J�@: ����X�ثeŪ�쪺�Ʀr�������j�g����r�A�N�L�Ȧs��tmp_ch�� */
		switch (input[i]) {
			case '0':
				//sprintf(tmp_ch, "�s");
			break;
			case '1':
			sprintf(tmp_ch, "��");
			break;
			case '2':
			sprintf(tmp_ch, "�L");
			break;
			case '3':
			sprintf(tmp_ch, "��");
			break;
			case '4':
			sprintf(tmp_ch, "�v");
			break;
			case '5':
			sprintf(tmp_ch, "��");
			break;
			case '6':
			sprintf(tmp_ch, "��");
			break;
			case '7':
			sprintf(tmp_ch, "�m");
			break;
			case '8':
			sprintf(tmp_ch, "��");
			break;
			case '9':
			sprintf(tmp_ch, "�h");
			break;
			default:
			printf("��J���~!\n");	// �u���J�¼Ʀr�r��A�_�h���_
			system("pause");
			exit(1);
		}

		/* �B�z�B�J�G: ��J�������Ʀr���
		 * �P�_��k�O(cnt_nu%4)�A�]������Ʀr4�Ӭ��@�աA��"�B", "��", "�a"�o�T�ӳ��C�@�����|���A�ҥH���D�X�ӳB�z
		 * �C�@��cnt_nu���n+1�A�ҥH�j����ݭncnt_nu++ */
		if ((cnt_nu%4) > 0) {
			if (input[i] != '0') {	/* �p�GŪ��Ʀr'0'�h�ӽ�����X�F��A�ҥH(input[i] != '0')�~�~��*/
				switch(cnt_nu%4) {
				/* �]���B�z�B�J�@�w�g��n�j�g�Ʀr�F�A�ҥH�o�̥u�n��W���Y�i */
					case 1: // �B
					sprintf(tmp_ch, "%s�B", tmp_ch);
					break;
					case 2:// ��
					sprintf(tmp_ch, "%s��", tmp_ch);
					break;
					case 3:// �a
					sprintf(tmp_ch, "%s�a", tmp_ch);
					break;
					default:
					printf("��J���~!\n");
					system("pause");
					exit(1);
				}

				/* ��o�̤w�g�B�z���o�@����tmp_ch�F�A���U�ӧ⥦���output���諸��m */
				sprintf(output_tmp, "%s", output);
				sprintf(output, "%s%s", tmp_ch, output_tmp);
			}
		} else {	/* �p�G��줣�O"�B", "��", "�a"�A�h�B�z�B�J�G����o�� */
			if (i == (strlen(input) - 1)) {	/* �o�O�Ӧ�A�ҥH�᭱�S���[��� */
				sprintf(output, "%s", tmp_ch);	/* ������ioutput�Y�i */
			} else {	/* �p�G���O�Ӧ�A�h�C4�Ӧ�Ƨ��ܤ@���A�w�q�bchar su[MAX_SPECIAL_UNITS][3]�o�Ӱ}�C*/
				/* ��cnt_su�����ثe������쪺��m�A�C��+1�A�|�Χ��ҥH�Y����j���Ʀr�n�B�z�A�Хܱ��p�ק�̤W���w�q���F�� */
				sprintf(tmp_ch, "%s%s", tmp_ch, su[cnt_su]);
				sprintf(output_tmp, "%s", output);
				sprintf(output, "%s%s", tmp_ch, output_tmp);
				cnt_su++;
			}
		}
		cnt_nu++;
	}

	/* ��o�̥����Ʀr�B�z�����A�L�Xoutput */
	printf("��X����Ʀr:\n%s", output);
	return 0;
}
