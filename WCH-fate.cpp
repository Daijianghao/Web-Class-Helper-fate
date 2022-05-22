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
const string chg_fort[7] = {"", "大凶", "凶", "中平", "小吉", "中吉", "大吉"};
pair <string, string> chg_lucky[35], chg_unluc[35];
void init_fate() {
    chg_lucky[0].fir = "万事皆凶";
    chg_lucky[0].sec = "";
    chg_lucky[1].fir = "写作文";
    chg_lucky[1].sec = "非常有文采";
    chg_lucky[2].fir = "搞基";
    chg_lucky[2].sec = "友谊地久天长";
    chg_lucky[3].fir = "扶老奶奶过马路";;
    chg_lucky[3].sec = "RP++";
    chg_lucky[4].fir = "开电脑";
    chg_lucky[4].sec = "电脑的状态也很好";
    chg_lucky[5].fir = "刷题";
    chg_lucky[5].sec = "成为虐题狂魔";
    chg_lucky[6].fir = "重构代码";
    chg_lucky[6].sec = "代码质量明显提高";
    chg_lucky[7].fir = "写作业";
    chg_lucky[7].sec = "都会写，写的全对";
    chg_lucky[8].fir = "参加模拟赛";
    chg_lucky[8].sec = "可以AK虐全场";
    chg_lucky[9].fir = "睡觉";
    chg_lucky[9].sec = "养足精力，明日再战";
    chg_lucky[10].fir = "打chunithm";
    chg_lucky[10].sec = "你虹了";
    chg_lucky[11].fir = "祭祀";
    chg_lucky[11].sec = "获得祖宗的庇护";
    chg_lucky[12].fir = "膜拜大神";
    chg_lucky[12].sec = "接受神犇光环照耀";
    chg_lucky[13].fir = "洗澡";
    chg_lucky[13].sec = "你多久没洗澡了？";
    chg_lucky[14].fir = "继续完成WA的题";
    chg_lucky[14].sec = "下一次就可以AC了";
    chg_lucky[15].fir = "熬夜";
    chg_lucky[15].sec = "事情终究是可以完成的";
    chg_lucky[16].fir = "泡妹子";
    chg_lucky[16].sec = "肯定能牵手！";
    chg_lucky[17].fir = "考试";
    chg_lucky[17].sec = "考的全会，蒙的全对";
    chg_lucky[18].fir = "背诵课文";
    chg_lucky[18].sec = "看一遍就背下来了";
    chg_lucky[19].fir = "体育锻炼";
    chg_lucky[19].sec = "身体棒棒哒";
    chg_lucky[20].fir = "吃饭";
    chg_lucky[20].sec = "人是铁饭是钢";
    chg_lucky[21].fir = "上课";
    chg_lucky[21].sec = "100%消化";
    chg_lucky[22].fir = "装弱";
    chg_lucky[22].sec = "谦虚最好了";
    chg_lucky[23].fir = "学习珂学";
    chg_lucky[23].sec = "珂朵莉太可爱了";
    chg_lucky[24].fir = "纳财";
    chg_lucky[24].sec = "要到好多Money";
    chg_lucky[25].fir = "上B站";
    chg_lucky[25].sec = "愉悦身心";
    chg_lucky[26].fir = "发朋友圈";
    chg_lucky[26].sec = "分享是种美德";
    chg_lucky[27].fir = "装逼";
    chg_lucky[27].sec = "获得众人敬仰";
    chg_lucky[28].fir = "玩网游";
    chg_lucky[28].sec = "犹如神助";
    chg_lucky[29].fir = "打sdvx";
    chg_lucky[29].sec = "您暴了";
    chg_lucky[30].fir = "出行";
    chg_lucky[30].sec = "一路顺风";
    chg_unluc[0].fir = "万事皆宜";
    chg_unluc[0].sec = "";
    chg_unluc[1].fir = "写作文";
    chg_unluc[1].sec = "可能会离题";
    chg_unluc[2].fir = "搞基";
    chg_unluc[2].sec = "会被掰弯";
    chg_unluc[3].fir = "扶老奶奶过马路";
    chg_unluc[3].sec = "会被讹";
    chg_unluc[4].fir = "开电脑";
    chg_unluc[4].sec = "意外的死机故障不可避免";
    chg_unluc[5].fir = "刷题";
    chg_unluc[5].sec = "容易WA";
    chg_unluc[6].fir = "重构代码";
    chg_unluc[6].sec = "越改越乱";
    chg_unluc[7].fir = "写作业";
    chg_unluc[7].sec = "上课讲了这些了吗";
    chg_unluc[8].fir = "参加模拟赛";
    chg_unluc[8].sec = "注意爆零";
    chg_unluc[9].fir = "睡觉";
    chg_unluc[9].sec = "翻来覆去睡不着";
    chg_unluc[10].fir = "打chunithm";
    chg_unluc[10].sec = "今天状态不好";
    chg_unluc[11].fir = "祭祀";
    chg_unluc[11].sec = "祖宗不知干啥就不鸟你";
    chg_unluc[12].fir = "膜拜大神";
    chg_unluc[12].sec = "被大神鄙视";
    chg_unluc[13].fir = "洗澡";
    chg_unluc[13].sec = "当心着凉";
    chg_unluc[14].fir = "继续完成WA的题";
    chg_unluc[14].sec = "然而变成了TLE";
    chg_unluc[15].fir = "熬夜";
    chg_unluc[15].sec = "爆肝";
    chg_unluc[16].fir = "泡妹子";
    chg_unluc[16].sec = "肯定能牵手！";
    chg_unluc[17].fir = "考试";
    chg_unluc[17].sec = "作弊会被抓";
    chg_unluc[18].fir = "背诵课文";
    chg_unluc[18].sec = "记忆力只有50Byte";
    chg_unluc[19].fir = "体育锻炼";
    chg_unluc[19].sec = "消耗的能量全吃回来了";
    chg_unluc[20].fir = "吃饭";
    chg_unluc[20].sec = "小心变胖啊";
    chg_unluc[21].fir = "上课";
    chg_unluc[21].sec = "反正你听不懂";
    chg_unluc[22].fir = "装弱";
    chg_unluc[22].sec = "被看穿";
    chg_unluc[23].fir = "学习珂学";
    chg_unluc[23].sec = "珂朵莉不知干啥不理你";
    chg_unluc[24].fir = "纳财";
    chg_unluc[24].sec = "然而今天并没有财运";
    chg_unluc[25].fir = "上B站";
    chg_unluc[25].sec = "会被教练发现";
    chg_unluc[26].fir = "发朋友圈";
    chg_unluc[26].sec = "会被当做卖面膜的";
    chg_unluc[27].fir = "装逼";
    chg_unluc[27].sec = "被识破";
    chg_unluc[28].fir = "玩网游";
    chg_unluc[28].sec = "匹配到一群猪队友";
    chg_unluc[29].fir = "打sdvx";
    chg_unluc[29].sec = "今天状态不好";
    chg_unluc[30].fir = "出行";
    chg_unluc[30].sec = "路途可能坎坷";
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
        fout << "               §" << chg_fort[fate] << "§" << endl;
        for (int i = 1; i <= 2; i++) {
            int rand_luc, rand_unl;
            if (fate == 1) rand_luc = (i == 1 ? 0 : 31);
            else rand_luc = WCH_rand(1, 30);
            if (fate == 6) rand_unl = (i == 1 ? 0 : 31);
            else rand_unl = WCH_rand(1, 30);
            fout << (fate == 1 ? "    " : "宜：" ) << chg_lucky[rand_luc].fir;
            fout << WCH_print_space(20 - (int)chg_lucky[rand_luc].fir.size()) << (fate == 6 ?"    " : " 凶：") << chg_unluc[rand_unl].fir << endl;
            fout << "    " << chg_lucky[rand_luc].sec;
            fout << WCH_print_space(20 - (int)chg_lucky[rand_luc].sec.size()) << "     " << chg_unluc[rand_unl].sec << endl;
        }
        fout.close();
    }
    fin.close();
    fin.open("data/fate.dat");
    string res;
    getline(fin, res);
    cout << WCH_print_space(11) << now.Year << " 年 " << now.Month << " 月 " << now.Day << " 日 " << endl;
    cout << WCH_print_space(9) << "你已经在 WCH 打卡了 " << fate_cnt << " 天" << endl;
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