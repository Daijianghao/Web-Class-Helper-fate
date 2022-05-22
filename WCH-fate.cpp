#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;

ifstream fin;
ofstream fout;
struct WCH_Time {
	int Year {};
	int Month {};
	int Day {};
	int Hour {};
	int Minute {};
	int Second {};
	int WeekDay {};
	string Name {};
};
WCH_Time WCH_GetTime() {
	// Get current time and return a WCH_Time object.
	WCH_Time NowTime;
	time_t rawtime;
	struct tm *ptminfo;
	time(&rawtime);
	ptminfo = localtime(&rawtime);
	NowTime.Year = ptminfo -> tm_year + 1900;
	NowTime.Month = ptminfo -> tm_mon + 1;
	NowTime.Day = ptminfo -> tm_mday;
	NowTime.Hour = ptminfo -> tm_hour;
	NowTime.Minute = ptminfo -> tm_min;
	NowTime.Second = ptminfo -> tm_sec;
	NowTime.Name = "NULL";
	return NowTime;
}

// === basic existing init on up ===

int WCH_rand(int x, int y) {
    // get a rand number from[x,y]
    // (default have already use "srand")
    return (long long)rand() % (y - x + 1) + x;
}
string WCH_print_space(int x) {
    // output a quantity of spaces
    string str = "";
    for (int i = 1; i <= x; i++) {
        str.push_back(' ');
    }
    return str;
}
const string chg_fort[7] = {"", "����", "��", "��ƽ", "С��", "�м�", "��"};
pair <string, string> chg_lucky[35], chg_unluc[35];
void init_fate() {
    chg_lucky[0].fir = "���½���";
    chg_lucky[0].sec = "";
    chg_lucky[1].fir = "д����";
    chg_lucky[1].sec = "�ǳ����Ĳ�";
    chg_lucky[2].fir = "���";
    chg_lucky[2].sec = "����ؾ��쳤";
    chg_lucky[3].fir = "�������̹���·";;
    chg_lucky[3].sec = "RP++";
    chg_lucky[4].fir = "������";
    chg_lucky[4].sec = "���Ե�״̬Ҳ�ܺ�";
    chg_lucky[5].fir = "ˢ��";
    chg_lucky[5].sec = "��ΪŰ���ħ";
    chg_lucky[6].fir = "�ع�����";
    chg_lucky[6].sec = "���������������";
    chg_lucky[7].fir = "д��ҵ";
    chg_lucky[7].sec = "����д��д��ȫ��";
    chg_lucky[8].fir = "�μ�ģ����";
    chg_lucky[8].sec = "����AKŰȫ��";
    chg_lucky[9].fir = "˯��";
    chg_lucky[9].sec = "���㾫����������ս";
    chg_lucky[10].fir = "��chunithm";
    chg_lucky[10].sec = "�����";
    chg_lucky[11].fir = "����";
    chg_lucky[11].sec = "������ڵıӻ�";
    chg_lucky[12].fir = "Ĥ�ݴ���";
    chg_lucky[12].sec = "������Ĺ⻷��ҫ";
    chg_lucky[13].fir = "ϴ��";
    chg_lucky[13].sec = "����ûϴ���ˣ�";
    chg_lucky[14].fir = "�������WA����";
    chg_lucky[14].sec = "��һ�ξͿ���AC��";
    chg_lucky[15].fir = "��ҹ";
    chg_lucky[15].sec = "�����վ��ǿ�����ɵ�";
    chg_lucky[16].fir = "������";
    chg_lucky[16].sec = "�϶���ǣ�֣�";
    chg_lucky[17].fir = "����";
    chg_lucky[17].sec = "����ȫ�ᣬ�ɵ�ȫ��";
    chg_lucky[18].fir = "���п���";
    chg_lucky[18].sec = "��һ��ͱ�������";
    chg_lucky[19].fir = "��������";
    chg_lucky[19].sec = "���������";
    chg_lucky[20].fir = "�Է�";
    chg_lucky[20].sec = "���������Ǹ�";
    chg_lucky[21].fir = "�Ͽ�";
    chg_lucky[21].sec = "100%����";
    chg_lucky[22].fir = "װ��";
    chg_lucky[22].sec = "ǫ�������";
    chg_lucky[23].fir = "ѧϰ��ѧ";
    chg_lucky[23].sec = "�����̫�ɰ���";
    chg_lucky[24].fir = "�ɲ�";
    chg_lucky[24].sec = "Ҫ���ö�Money";
    chg_lucky[25].fir = "��Bվ";
    chg_lucky[25].sec = "��������";
    chg_lucky[26].fir = "������Ȧ";
    chg_lucky[26].sec = "������������";
    chg_lucky[27].fir = "װ��";
    chg_lucky[27].sec = "������˾���";
    chg_lucky[28].fir = "������";
    chg_lucky[28].sec = "��������";
    chg_lucky[29].fir = "��sdvx";
    chg_lucky[29].sec = "������";
    chg_lucky[30].fir = "����";
    chg_lucky[30].sec = "һ·˳��";
    chg_unluc[0].fir = "���½���";
    chg_unluc[0].sec = "";
    chg_unluc[1].fir = "д����";
    chg_unluc[1].sec = "���ܻ�����";
    chg_unluc[2].fir = "���";
    chg_unluc[2].sec = "�ᱻ����";
    chg_unluc[3].fir = "�������̹���·";
    chg_unluc[3].sec = "�ᱻ��";
    chg_unluc[4].fir = "������";
    chg_unluc[4].sec = "������������ϲ��ɱ���";
    chg_unluc[5].fir = "ˢ��";
    chg_unluc[5].sec = "����WA";
    chg_unluc[6].fir = "�ع�����";
    chg_unluc[6].sec = "Խ��Խ��";
    chg_unluc[7].fir = "д��ҵ";
    chg_unluc[7].sec = "�Ͽν�����Щ����";
    chg_unluc[8].fir = "�μ�ģ����";
    chg_unluc[8].sec = "ע�ⱬ��";
    chg_unluc[9].fir = "˯��";
    chg_unluc[9].sec = "������ȥ˯����";
    chg_unluc[10].fir = "��chunithm";
    chg_unluc[10].sec = "����״̬����";
    chg_unluc[11].fir = "����";
    chg_unluc[11].sec = "���ڲ�֪��ɶ�Ͳ�����";
    chg_unluc[12].fir = "Ĥ�ݴ���";
    chg_unluc[12].sec = "���������";
    chg_unluc[13].fir = "ϴ��";
    chg_unluc[13].sec = "��������";
    chg_unluc[14].fir = "�������WA����";
    chg_unluc[14].sec = "Ȼ�������TLE";
    chg_unluc[15].fir = "��ҹ";
    chg_unluc[15].sec = "����";
    chg_unluc[16].fir = "������";
    chg_unluc[16].sec = "�϶���ǣ�֣�";
    chg_unluc[17].fir = "����";
    chg_unluc[17].sec = "���׻ᱻץ";
    chg_unluc[18].fir = "���п���";
    chg_unluc[18].sec = "������ֻ��50Byte";
    chg_unluc[19].fir = "��������";
    chg_unluc[19].sec = "���ĵ�����ȫ�Ի�����";
    chg_unluc[20].fir = "�Է�";
    chg_unluc[20].sec = "С�ı��ְ�";
    chg_unluc[21].fir = "�Ͽ�";
    chg_unluc[21].sec = "������������";
    chg_unluc[22].fir = "װ��";
    chg_unluc[22].sec = "������";
    chg_unluc[23].fir = "ѧϰ��ѧ";
    chg_unluc[23].sec = "�����֪��ɶ������";
    chg_unluc[24].fir = "�ɲ�";
    chg_unluc[24].sec = "Ȼ�����첢û�в���";
    chg_unluc[25].fir = "��Bվ";
    chg_unluc[25].sec = "�ᱻ��������";
    chg_unluc[26].fir = "������Ȧ";
    chg_unluc[26].sec = "�ᱻ��������Ĥ��";
    chg_unluc[27].fir = "װ��";
    chg_unluc[27].sec = "��ʶ��";
    chg_unluc[28].fir = "������";
    chg_unluc[28].sec = "ƥ�䵽һȺ�����";
    chg_unluc[29].fir = "��sdvx";
    chg_unluc[29].sec = "����״̬����";
    chg_unluc[30].fir = "����";
    chg_unluc[30].sec = "·;���ܿ���";
}

void WCH_calcu_fate() {
    init_fate();
    int fate, lucky, unluc;
    fin.open("data/fate.dat");
    WCH_Time now, past;
    int fate_cnt = 0;
    now = WCH_GetTime();
    if (fin.is_open()) {
        fin >> past.Year >> past.Month >> past.Day >> fate_cnt;
    }
    if (!fin.is_open()||!(now.Year == past.Year && now.Month == past.Month && now.Day == past.Day)) {
        fin.close();
        fout.open("data/fate.dat");
        fout << now.Year << " " << now.Month << " " << now.Day << " " << ++fate_cnt << endl;
        fate = WCH_rand(1,6);
        fout << "               ��" << chg_fort[fate] << "��" << endl;
        for (int i = 1; i <= 2; i++) {
            int rand_luc, rand_unl;
            if (fate == 1) rand_luc = (i == 1 ? 0 : 31);
            else rand_luc = WCH_rand(1, 30);
            if (fate == 6) rand_unl = (i == 1 ? 0 : 31);
            else rand_unl = WCH_rand(1, 30);
            fout << (fate == 1 ? "    " : "�ˣ�" ) << chg_lucky[rand_luc].fir;
            fout << WCH_print_space(20 - (int)chg_lucky[rand_luc].fir.size()) << (fate == 6 ?"    " : " �ף�") << chg_unluc[rand_unl].fir << endl;
            fout << "    " << chg_lucky[rand_luc].sec;
            fout << WCH_print_space(20 - (int)chg_lucky[rand_luc].sec.size()) << "     " << chg_unluc[rand_unl].sec << endl;
        }
        fout.close();
    }
    fin.close();
    fin.open("data/fate.dat");
    string res;
    getline(fin, res);
    cout << WCH_print_space(11) << now.Year << " �� " << now.Month << " �� " << now.Day << " �� " << endl;
    cout << WCH_print_space(9) << "���Ѿ��� WCH ���� " << fate_cnt << " ��" << endl;
    while (getline(fin, res)) {
        cout << res << endl;
    }
    fin.close();
}
int main() {
    srand(time(NULL));
    WCH_calcu_fate();
    return 0;
}