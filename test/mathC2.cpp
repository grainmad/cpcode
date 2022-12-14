#include <bits/stdc++.h>
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
using namespace std;

/*
燃油 0
混动 1
两驱 0
四驱 1
*/
int curtime;
int cntback;
struct Car {
	int id, fuel, drive, pos;// 编号，燃油类型，驱动类型，当前所处74区域代码(0则不属于任何区域)
};
map<int,Car> car;

vector<vector<int>> record; // record[i][j] i秒编号位j+1的车所在位置

// 车道数据结构

struct Park {
	int id;// 0 没有车 非0则为车编号
	int status; //0 停止，1 移动
	int stoptime; //车在移动时的停止的时间点
	int num; //进车序号，从返回车道返回后会重新编号。
};

//下标 0, 1, 2, 3, 5, 6 都是进车道，4 是返回车道
vector<vector<Park>> lane(7, vector<Park> (10));
/*
lane[i][0] 是10车道
lane[i][9] 是1车道
*/

// lane 中个对象的索引映射的区域代码
int code[7][10] ={
	{110, 19, 18, 17, 16, 15, 14, 13, 12, 11},
	{210, 29, 28, 27, 26, 25, 24, 23, 22, 21},
	{310, 39, 38, 37, 36, 35, 34, 33, 32, 31},
	{410, 49, 48, 47, 46, 45, 44, 43, 42, 41},
	{710, 79, 78, 77, 76, 75, 74, 73, 72, 71},
	{510, 59, 58, 57, 56, 55, 54, 53, 52, 51},
	{610, 69, 68, 67, 66, 65, 64, 63, 62, 61}
};


/* 
	涂装-PBS出车口 Area0
*/
queue<int> area0;
/*
	PBS-总装接车口 Area3
*/
vector<int> area3;

/*
	接车横车机 Area1
	接车横车机有4中状态，分别是 空闲 0， 接车 1， 送车 2，归位 3
	每一秒, 接车横车机会根据当前状态为空闲或者状态到期而采取行动
	当为空闲时 
		返回道10与涂装-PBS出车口都没有车则车机不操作。
		否则优先从返回道10接车，其次从涂装-PBS出车口接车，
		修改当前状态为接车，修改状态到期时间，修改横车机的目标车道。
	当为接车时且状态到期时
		修改状态为送车，修改状态到期时间，修改横车机的目标车道（确定送车位置，（随机））。
		修改出口或返回道状态，修改车所属区域。
	当为送车时且状态到期时
		修改状态为归位，修改状态到期时间，修改横车机的目标车道
		修改送车道状态，修改车所属区域
	当为归位状态且状态到期时
		修改状态为空闲，修改状态到期时间无穷，修改横车机的目标车道
*/ 
struct Area1 {
	int status; //状态
	int car; // 横车机上的车
	int current_palce; // 当前的所在的车道
	int next_place; // 目标车道
	int status_deadline; // 状态结束时间
} area1;
/*
	送车横车机 Area2
	送车横车机有4中状态，分别是 空闲 0， 接车 1， 送车 2，归位 3
	每一秒, 接车横车机会根据当前状态为空闲或者状态到期而采取行动
	当为空闲时 
		先到达车道1的优先选择，所以我们将按照先后顺序到达车道1的车辆加入队列中。
		若队列为空，直接结束行动。
		否则取出队首车辆，修改状态为接车，修改横车机目标车道为队首车辆车道，设置状态终止时间
	当为接车时且状态到期时
		修改状态为送车，修改状态到期时间，修改横车机目标车道为返回车道或PBS-总装接车口（随机）
		修改所接车道状态，修改车所属区域。
	当为送车时且状态到期时
		修改状态为归位，修改状态到期时间，
		修改送车道或PBS-总装接车口状态，修改车所属区域
	当为归位且状态到期时
		修改状态为空闲，状态到期时间为无穷，修改横车机的目标车道。
*/ 
struct Area2 {
	int status;
	int car;
	int current_palce;
	int next_place;
	int status_deadline;
} area2;

void get_data() {
	int id, fuel, drive;
	while (cin >> id >> fuel >> drive) {
		car[id] = {id, fuel, drive, -1};
	}
}

void init() {
	curtime = 0;
	cntback = 0;
	for (int i=1; i<=car.size(); i++) {
		area0.push(i);
	}
	area1 = {0, 0, 3, -1, -1};
	area2 = {0, 0, 3, -1, -1};
	area3.clear();
	record.clear();
}

void update_record() {
	vector<int> temp;
	for (auto& i:car) {
		temp.push_back(i.second.pos);
	}
	record.emplace_back(temp);
}

void update_lane(int x) { //更新车道
	for (int j=8; j>=0; j--) {
		auto& curlane = lane[x];
		if (curlane[j].id == 0) continue;//没车跳过
		if (curlane[j].status == 0 && (curlane[j+1].id == 0 || curlane[j+1].status == 1)) {//当前车停止，下一车位无车或车在移动，当前车就可以移动	
			curlane[j].status = 1;
			curlane[j].stoptime = curtime+9;
		} else if (curlane[j].status == 1 && curlane[j].stoptime == curtime) {//移动且到期
			curlane[j+1] = curlane[j];
			curlane[j+1].status = 0;
			curlane[j] = {0,0,0,0};
			car[curlane[j+1].id].pos = code[x][j+1];
			if (j+2<10 && (curlane[j+2].id == 0 || curlane[j+2].status == 1)) {//移动后下一位没车或车在移动，需要继续移动
				curlane[j+1].status = 1;
				curlane[j+1].stoptime = curtime+9;
			}
		} 
	}
}
void update_bclane() { //更新返回车道
	auto& bclane = lane[4];
	for (int i=1; i<10; i++) {
		if (bclane[i].id == 0) continue;
		if (bclane[i].status == 0 && (bclane[i-1].id == 0 || bclane[i-1].status == 1)) {
			bclane[i].status = 1;
			bclane[i].stoptime = curtime+9;
		} else if (bclane[i].status == 1 && bclane[i].stoptime == curtime) {
			bclane[i-1] = bclane[i];
			bclane[i-1].status = 0;
			bclane[i] = {0, 0, 0, 0};
			car[bclane[i-1].id].pos = code[4][i-1];
			if (i-2>=0 && (bclane[i-2].id == 0 || bclane[i-2].status == 1)) {
				bclane[i-1].status = 1;
				bclane[i-1].stoptime = curtime+9;
			}
		}
	}
}

void update_area1() {
	while (area1.status == 0 || area1.status_deadline == curtime) {
		switch (area1.status) {
			case 0: {
				// 		当为空闲时 
				// 先到达车道1的优先选择，所以我们将按照先后顺序到达车道1的车辆加入队列中。
				// 若队列为空，直接结束行动。
				vector<Area1> v;
				if (lane[4][0].id) {//返回道10 有车
					v.push_back({1, 0, 3, 4, curtime+3});
				} 
				if (area0.size()) { //涂装-PBS出车口 有车
					v.push_back({1, 0, 3, 3, curtime});
				} 
				if (lane[4][0].id==0 && area0.empty()) return ;//空闲且无车可接，保持空闲
				area1 = v[rand()%v.size()];
				break;
			}
			case 1: {
				//当为接车时且状态到期时
				//修改状态为送车，修改状态到期时间，修改横车机的目标车道（确定送车位置，（随机））。
				//修改出口或返回道状态，修改车所属区域。
				//确定空位
				std::vector<int> v;
				for (int i:{0,1,2,3,5,6}) {
					if (lane[i][0].id) continue;
					v.push_back(i);
				}
				int aim = v[rand()%v.size()]; // 随机选择的可用车道
				int choseCar; //所接到的车
				if (area1.next_place==4) {//选择返回车道的车
					choseCar = lane[4][0].id;
					lane[4][0] = {0, 0, 0, 0};
					update_bclane();
				} else { //选择出车口的车
					choseCar = area0.front();
					area0.pop();
					if (area0.size()) car[area0.front()].pos = 0;
				}
				car[choseCar].pos = 1;
				area1 = {2, choseCar, area1.next_place, aim, curtime + 3*abs(aim-area1.next_place)};
				break;
			}
			case 2: {
				// 	当为送车时且状态到期时
				// 修改状态为归位，修改状态到期时间，修改横车机的目标车道
				// 修改送车道状态，修改车所属区域
				lane[area1.next_place][0] = {area1.car, 0, 0, curtime};
				if (lane[area1.next_place][1].id == 0 || lane[area1.next_place][1].status == 1) {
					lane[area1.next_place][0].status = 1;
					lane[area1.next_place][0].stoptime = curtime + 9;
				}
				car[area1.car].pos = code[area1.next_place][0];
				area1 = {3, 0, area1.next_place, 3, curtime + 3*abs(3-area1.next_place)};
				break;
			}
			case 3: {
				area1 = {0, 0, 3, -1, -1};
				break;
			}
		}
	}
}

void update_area2() {
	while (area2.status == 0 || area2.status_deadline == curtime) {
		switch (area2.status) {
			case 0: {
				// 		当为空闲时 
				// 先到达车道1的优先选择，所以我们将按照先后顺序到达车道1的车辆加入队列中。
				// 若队列为空，直接结束行动。
				// 否则取出队首车辆，修改状态为接车，修改横车机目标车道为队首车辆车道，设置状态终止时间
				std::vector<Area2> v;
				for (int i:{0,1,2,3,5,6}) {
					if (lane[i].back().id) {
						v.push_back({1,0,3,i,abs(i-3)*3+curtime});
					}
				}
				if (v.empty()) return ;//无车可选
				area2 = v[rand()%v.size()];
				break;
			}
			case 1: {
				// 		当为接车时且状态到期时
				// 修改状态为送车，修改状态到期时间，修改横车机目标车道为返回车道或PBS-总装接车口（随机）
				// 修改所接车道状态，修改车所属区域。
				int choseCar = lane[area2.next_place].back().id;
				lane[area2.next_place].back() = {0,0,0,0};
				update_lane(area2.next_place);
				car[choseCar].pos = 2;
				int next_place;
				if (lane[4].back().id) next_place = 3;
				else next_place = rand()%2?4:3;
				if (next_place == 4) cntback++;
				area2 = {2, choseCar, area2.next_place, next_place, 3*abs(area2.next_place-next_place)+curtime};
				break;
			}
			case 2: {
				// 	当为送车时且状态到期时
				// 修改状态为归位，修改状态到期时间，
				// 修改送车道或PBS-总装接车口状态，修改车所属区域	
				if (area2.next_place == 3) { //出口
					if (area3.size()) car[area3.back()].pos = -1;
					area3.push_back(area2.car);
					car[area2.car].pos = 3;
				} else {
					lane[4].back() = {area2.car, 0, 0, 0};
					car[area2.car].pos = code[4][9];
					if (lane[4][8].id == 0 || lane[4][8].status == 1) {
						lane[4].back().status = 1;
						lane[4].back().stoptime = curtime+9;
					}
				}
				area2 = {3, 0, area2.next_place, 3, 3*abs(3-area2.next_place)+curtime};
				break;
			}
			case 3: {
				area2 = {0, 0, 3, -1, -1};
				break;
			}
		}
	}
}


void score() {
	cout << "final sequence: ";
	for (int i:area3) cout << i << " ";
	cout << "\n";
	
	int fuel_score = 100;
	// 燃油 0
	// 混动 1
	// 计算每连续两辆混动车身之间的非混动车身数，不等于2则扣1分
	int p = -1; //前一辆混动的位置
	for (int i=0; i<area3.size(); i++) {
		if (car[area3[i]].fuel == 1) {
			if (p != -1) {
				if (i-p-1 != 2) fuel_score--;
			}
			p = i;
		}
	}
	cout << "fuel_score: " << fuel_score << "\n";

	int drive_score = 100;
	// 两驱 0
	// 四驱 1
	//判断每一分快中的四驱车型与两驱车型之比是否满足1:1, 若不满足，则扣1分
	int cnt0=0, cnt1=0;
	int h = car[area3[0]].drive;
	for (int i=0; i<area3.size(); i++) {
		if (i-1>=0 && car[area3[i]].drive==h && car[area3[i-1]].drive != h) {
			if (cnt1 != cnt0) drive_score--;
			cnt1 = cnt0 = 0;
		}
		if (car[area3[i]].drive) cnt1++;
		else cnt0++;
	}
	if (cnt1 != cnt0) drive_score--;

	cout << "dirve_score: " << drive_score << "\n";	

	int back_score = 100- cntback;
	cout << "back_score: " << back_score << "\n";	

	double time_score = 100-0.01*(curtime-9*car.size()-72);
	cout << "time_score: " << time_score << "\n";

	double final_score = fuel_score*0.4+drive_score*0.3+back_score*0.2+time_score*0.1;
	cout << "final_score: " << final_score << "\n";
}

void formate_score() {
	freopen("完全随机附件2.csv", "a", stdout);
	int fuel_score = 100;
	// 燃油 0
	// 混动 1
	// 计算每连续两辆混动车身之间的非混动车身数，不等于2则扣1分
	int p = -1; //前一辆混动的位置
	for (int i=0; i<area3.size(); i++) {
		if (car[area3[i]].fuel == 1) {
			if (p != -1) {
				if (i-p-1 != 2) fuel_score--;
			}
			p = i;
		}
	}
	cout << fuel_score << ", ";

	int drive_score = 100;
	// 两驱 0
	// 四驱 1
	//判断每一分快中的四驱车型与两驱车型之比是否满足1:1, 若不满足，则扣1分
	int cnt0=0, cnt1=0;
	int h = car[area3[0]].drive;
	for (int i=0; i<area3.size(); i++) {
		if (i-1>=0 && car[area3[i]].drive==h && car[area3[i-1]].drive != h) {
			if (cnt1 != cnt0) drive_score--;
			cnt1 = cnt0 = 0;
		}
		if (car[area3[i]].drive) cnt1++;
		else cnt0++;
	}
	if (cnt1 != cnt0) drive_score--;

	cout << drive_score << ", ";	

	int back_score = 100- cntback;
	cout << back_score << ", ";	

	double time_score = 100-0.01*(curtime-9*car.size()-72);
	cout << time_score << ", ";

	double final_score = fuel_score*0.4+drive_score*0.3+back_score*0.2+time_score*0.1;
	cout << final_score << ", ";
	for (int i:area3) cout << i << " ";
	cout << "\n";
}


void formate_print() {
	freopen("result22.csv", "w", stdout);
	int n = record.size(), m = record[0].size();
	for (int i=0; i<n; i++) {
		cout << "," << i;
	}
	cout << "\n";
	for (int i=0; i<m; i++) {
		cout << i+1;
		for (int j=0; j<n; j++) {
			cout << ",";
			if (record[j][i] != -1) cout << record[j][i]; 
		}
		cout << "\n";
	}
}

void print1() {
	cout << "current time: " << curtime << "\n";
	for (auto& i:car) {
		cout << "id: " << i.second.id << " pos: " << i.second.pos << ", ";
	}
	cout << "\n";
}

void print2() {
	cout << "current time: " << curtime << "\n";
	map<int,int> mp;
	for (auto& i:car) {
		// cout << "id: " << i.second.id << " pos: " << i.second.pos << ", ";
		int pos = i.second.pos, id = i.second.id;
		if (pos != -1) mp[pos] = id;
	}
	cout << " area0:" << setw(4) << (mp.count(0)?to_string(mp[0]):"");
	cout << " area1:" << setw(4) << (mp.count(1)?to_string(mp[1]):"");
	cout << " area2:" << setw(4) << (mp.count(2)?to_string(mp[2]):"");
	cout << " area3:" << (mp.count(3)?to_string(mp[3]):"") << "\n";
	// status;
	// int car;
	// int current_palce;
	// int next_place;
	// int status_deadline;
	cout << "area1 info  status:" << area1.status << " car:" << area1.car << " current_palce:" << area1.current_palce 
	<< " next_place:" << area1.next_place << " status_deadline:" << area1.status_deadline << "\n";
	cout << "area2 info  status:" << area2.status << " car:" << area2.car << " current_palce:" << area2.current_palce 
	<< " next_place:" << area2.next_place << " status_deadline:" << area2.status_deadline << "\n";
	for (int i=6; i>=0; i--) {
		for (int j=0; j<10; j++) {
			cout << " [" << i+1 << "]["<<10-j<<"]:";
			if (mp.count(code[i][j])) {
				cout << setw(4) << mp[code[i][j]];
			} else cout << setw(4) << "";
		}
		cout << "\n";
	}
	cout << endl;
}

int simulate() {

	
	while (area3.size() < car.size()) {
		//6条进车道更新
		for (int i:{0,1,2,3,5,6}) {
			update_lane(i);
		}
		//返车道更新
		update_bclane();
		update_area1();
		update_area2();
		update_record();
		// print2();
		// print1();
		curtime++;
	}
}

int main() {
	srand(time(0));//以当前时间作为随机种子
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("in2.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	get_data();	
	for (int i=0; i<100; i++) {
		init();
		simulate();
		formate_score();
	}
	
	// formate_print();
	return 0;
}